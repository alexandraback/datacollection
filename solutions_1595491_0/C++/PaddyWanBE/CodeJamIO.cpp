#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

bool reverse(int i,int j) { return (i>j); }

class CodeJamIO
{
	private:

		string append(const char* a, const char* b)
		{
			string c(a);
			c += b;
			return c;
		}
	public:

		CodeJamIO(const char* naam) : sc(append(naam, ".in").c_str()), ps(append(naam, ".out").c_str())
		{
			if(!sc.is_open() || !ps.is_open())
				throw "foutje";
			index = 0;
			sc >> size;
			//init
			next();
		}

		virtual ~CodeJamIO()
		{
		}

		void print()
		{
			ps << "Case #" << index << ": " << ss.str() << std::endl;
			ss.str("");
		}

		bool hasMore()const
		{
			return index < size;
		}

		void close()
		{
			sc.close();
			ps.close();
		}

	private:
		ifstream sc;
		ofstream ps;
		stringstream ss;
		int index;
		int size;

	public:

		void next()
		{
			//data
			sc >> N >> S >> p;
			t = new int[N];
			for(int i = 0; i < N; i++)
				sc >> t[i];
			//end data
			index++;
		}

		void solve()
		{
			//calc
			std::sort(t, t+N,reverse);
			int i = 0; //bigger
			while(i < N && ((t[i]+2)/3) >= p) 
				i++;
			int s = S;
			while(i < N && s>0 && ((t[i]+4)/3) >= p && t[i] >= 2) 
			{
				i++;
				s--;
			}
			ss << i;
			delete[] t;
			print();
		}
	private:
		//data
		int N;//the number of Googlers
		int S;//the number of surprising triplets of scores
		int p;
		int* t;
};

using namespace std;

int main()
{
	CodeJamIO cd("B-small-attempt0");
	cd.solve();
	while(cd.hasMore())
	{
		cd.next();
		cd.solve();
	}
	cd.close();
	return 0;
}
