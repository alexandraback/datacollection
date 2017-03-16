#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10000000 + 100;
const int RANGE = 1000000;

ifstream input;
ofstream output;

bool vst[MAXN];
int step[MAXN];

int flip(int x)
{
	int ret = 0;
	while (x)
	{
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}

bool everDec;

int Q[MAXN];
int Prev[MAXN];
int cnt;
void checkNadd(int x, int & r, int from)
{
	if (!vst[x]) 
	{
		Prev[x] = from;
		if (x < from)
		{
			everDec = true;
			output << from << ' ' << x << endl;
		}
		vst[x] = true;
		step[x] = step[from] + 1;
		Q[++r] = x;
		if (x <= RANGE) cnt++;
	}
}
void init()
{
	//output << flip(12345) << endl;
	everDec = false;
	memset(vst, 0, sizeof(vst));
	int f = 0, r = 0;
	vst[1] = true;
	Q[0] = 1;
	step[1] = 1;
	cnt = 1;
	while (cnt < RANGE)
	{
		int x = Q[f++];
		checkNadd(x + 1, r, x);
		checkNadd(flip(x), r, x);
	}
	//output << everDec << endl;
}

void printPath(int x)
{
	if (x==1) output << 1 << endl;
	else
	{
		output << x << " -> ";
		printPath(Prev[x]);
	}
}

void singleCase(int case_num)
{
	int N;
	input >> N;
	//output << endl;
	output << "Case #" << case_num + 1 << ": " << step[N] << endl;
	//printPath(N);
}

int main()
{
	input.open("A-small.in");
	output.open("A.out");
	init();
	int T;
	input >> T;
	for (int i=0; i<T; i++)
		singleCase(i);

	return 0;
}