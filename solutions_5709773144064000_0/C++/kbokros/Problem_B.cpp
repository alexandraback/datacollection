///////////////////////////////////////////////////////////////////////////////
// TESTING PARAMETERS
const char* FILENAME="B%d.in";
int FILE_FROM = 0;
int FILE_TO = 0;

//#ifdef GCONF_MSSTL_TUNING
#define _SECURE_SCL 0
#define _SCL_SECURE_NO_DEPRECATE
#define _HAS_ITERATOR_DEBUGGING 0
//#endif

//#undef _HAS_EXCEPTIONS
//#define _HAS_EXCEPTIONS 0

#include <set>
#include <vector>
#include <map>	
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <limits>
#include <memory>

template <class T>
inline const T& min(const T& a,const T& b)
{
	return (a < b)? a : b ;
}

template <class T>
inline const T& max(const T& a,const T& b)
{
	return (a > b)? a : b ;
}

#define VECTOR std::vector
#define LIST   std::list
#define SET    std::set
#define MAP    std::map
#define MULTIMAP std::multimap
#define DEQUE  std::deque
#define STACK  std::stack
#define PAIR   std::pair
#define AUTO_PTR std::auto_ptr

#define foreach(TYPE, CONT, ITER) for(TYPE::iterator ITER=(CONT).begin(); ITER != (CONT).end(); ++ITER)
#define foreach_const(TYPE, CONT, ITER) for(TYPE::const_iterator ITER=(CONT).begin(); ITER != (CONT).end(); ++ITER)

const bool OUT_FILE = true;
FILE *FILE_OUT;

char* GetString(__int64 value)
{
	char buffer[4096];
	char* c=buffer;
	while (value || c==buffer)
	{
		*(c++)='0'+(value%10);
		value /= 10;
	}
	*c=0;
	--c;
	char *c2=buffer;
	for (;c2<c;++c2,--c)
	{
		char ct=*c2;
		*c2=*c;
		*c=ct;
	}
	return buffer;
}

///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////

class CookieState
{
public:
	CookieState() :
		time_(0),
		cookies_(0),
		cookie_rate_(kCookieRate) {
	}

	CookieState(double time, double cookies, double cookie_rate) :
		time_(time),
		cookies_(cookies),
		cookie_rate_(cookie_rate) {
	}

	double GetTargetTime(double X) const
	{
		return time_ + (X-cookies_)/cookie_rate_;
	}

	const CookieState& BuyFarm(double C, double F) const
	{
		return CookieState(GetTargetTime(C), 0, cookie_rate_+F);
	}

private:
	static const double kCookieRate;

	double time_;
	double cookies_;
	double cookie_rate_;
};

const double CookieState::kCookieRate = 2.0;

void ProcessFile(FILE* fin)
{
	int T;
	fscanf(fin, "%d", &T);
	for (int test_case=0; test_case<T; ++test_case)
	{
		double C, F, X, best_time;
		fscanf(fin, "%lf %lf %lf", &C, &F, &X);

		CookieState state;
		while (true)
		{
			CookieState state_if_we_buy_a_farm = state.BuyFarm(C, F);
			best_time = state.GetTargetTime(X);
			double best_time_if_we_buy_a_farm = state_if_we_buy_a_farm.GetTargetTime(X);
			// there's no reason to buy a farm
			if (best_time_if_we_buy_a_farm>=best_time)
				break;
			state = state_if_we_buy_a_farm;
		}

		fprintf(FILE_OUT, "Case #%d: %lf\n", test_case+1, best_time);
	}
}

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	char fileName[256];
	printf ("Which file: ");
	fgets ( fileName, 256, stdin );
	if (fileName[0]>13)
	{
		int i = atoi (fileName);
		FILE_FROM = FILE_TO = i;
	}
	for (int file_from=FILE_FROM; file_from<=FILE_TO; ++file_from)
	{
		sprintf(fileName, FILENAME, file_from);
		FILE *fin = fopen(fileName, "r");
		if (!fin)
		{
			printf("!!! CANNOT INF FILE %s", fileName);
			continue;
		} else {
			printf("Processing file: %s ...\n", fileName);
		}
		if (OUT_FILE)
		{
			char fileNameOut[256];
			sprintf(fileNameOut, "%s.out", fileName);
			FILE_OUT = fopen(fileNameOut, "w");
		} else
		{
			FILE_OUT = stdout;
		}
		ProcessFile(fin);
		fclose(fin);
		if (OUT_FILE)
			fclose(FILE_OUT);
	}
	printf("\nREADY!!!\n");
	getc(stdin);
	return 0;
}
