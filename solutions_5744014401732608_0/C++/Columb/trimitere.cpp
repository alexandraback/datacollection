// Template v2
#define pb push_back
#define mp make_pair
#define det(a,b,c,d)  (a*d-b*c)
#define first x
#define second y
#define lsb(x) x & -x
#define PI   3.14159265358979323846
#include<fstream>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<algorithm>
#include<string.h>
#include<stack>
#include<set>
#include <bitset>
using namespace std;
  
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PKK;
// primes less than 100
const int PRIM[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; const int CMAX = 100069;
const int MOD1 = 10039;
const int MOD2 = 10067;
const int MOD3 = 10429;
const int P = 73;
const int NMAX = 30;
const double EPS = 1e-7;
const int INF16 = 320000;
const int INF = 2*1e9 + 6661369;
const LL INF64 = LL(1e18);
const int dx[]={-1,1,0,0};
const int dy[]={0,0,1,-1};

ifstream cin("trimitere.in");
ofstream cout("trimitere.out");

int tests;
LL n, m;
void read()
{
	cin>>tests;
	for(int t=1; t<=tests; ++t)
	{
		cin>>n>>m;
		cout<<"Case #"<<t<<": ";
		if(m>(1LL<<(n-2)))
			cout<<"IMPOSSIBLE\n";
		else{
			cout<<"POSSIBLE\n";
			if(m==1)
			{
				for(int i=1; i<=n; ++i)
				{
					for(int j=1; j<=n; ++j)
					{
						if(i==1 && j==n)
							cout<<1;
						else
							cout<<0;
					}
					cout<<"\n";
				}
			}
			else
				if(m==(1LL<<(n-2)))
				{
					for(int i=1; i<=n; ++i)
					{
						for(int j=1; j<=n; ++j)
						{
							if(j>i && i!=n)
								cout<<1;
							else
								cout<<0;
						}
						cout<<"\n";
					}
				}else
				{
					m<<=1;
					for(int i=1; i<=n; ++i)
					{
						for(int j=1; j<=n; ++j)
						{
							if(j!=n){
								if(j>i)
									cout<<1;
								else
									cout<<0;
							}
							else
							{
								if(m&(1LL<<(i-1)))
									cout<<1;
								else
									cout<<0;
							}
						}
						cout<<"\n";
					}
				}
		}
	}
}

int main()
{
	read();
	return 0;
}