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
struct comb{
	int x,y,z;
};
comb A[30], B[30], sol[30];
int viz1[4][4];
int viz2[4][4];
int viz3[4][4];
int s, z,a,b,c,k,nrbits;
int tests, rs;

bool check()
{
	bool q=1;
	memset(viz1, 0, sizeof(viz1));
	memset(viz2, 0, sizeof(viz2));
	memset(viz3, 0, sizeof(viz3));
	for(int i=1; i<=s && q; ++i)
	{
		int x=B[i].x, y=B[i].y, z=B[i].z;
		if(viz1[x][y]+1<=k && viz2[y][z]+1<=k && viz3[x][z]+1<=k)
			viz1[x][y]++, viz2[y][z]++, viz3[x][z]++;
		else
			q=false;
	}
	return q;
}

void read()
{
	cin>>tests;
	for(int t=1; t<=tests; ++t)
	{
		rs=0;
		cout<<"Case #"<<t<<": ";
		cin>>a>>b>>c>>k;
		
		if(a==3 && b==3 && c==3)
		{
			if(k>=3)
			{
				cout<<"27\n";
				for(int i=1; i<=3; ++i)
				for(int j=1; j<=3; ++j)
				for(int l=1; l<=3; ++l)
					cout<<i<<" "<<j<<" "<<l<<"\n";
			}
			if(k==2)
			{
				cout<<"18\n1 1 1\n1 1 3\n1 2 1\n1 2 2\n1 3 2\n1 3 3\n2 1 1\n2 1 2\n2 2 2\n2 2 3\n2 3 1\n2 3 3\n3 1 2\n3 1 3\n3 2 1\n3 2 3\n3 3 1\n3 3 2\n";
			}
			if(k==1)
			{
				cout<<"9\n1 1 2\n1 2 1\n1 3 3\n2 1 1\n2 2 3\n2 3 2\n3 1 3\n3 2 2\n3 3 1\n";
			}

		}else{
		
			z=0;
			for(int i=1; i<=a; ++i)
				for(int j=1; j<=b; ++j)
					for(int l=1; l<=c; ++l){
						comb n;
						n.x=i, n.y=j, n.z=l;
						A[++z]=n;
					}
			for(int i=1; i<1<<(z); ++i){
				s=0;
				nrbits=0;
				for(int j=0; j<z; ++j)
					if(i&(1<<j)){
						nrbits++;
						B[++s]=A[j+1];
					}
				if(nrbits>rs){
					if(check() && s>rs)
					{
						for(int j=1; j<=s; ++j)
							sol[j]=B[j];
						rs=s;
					}
				}
			}
			cout<<rs<<"\n";
			for(int i=1; i<=rs; ++i)
				cout<<sol[i].x<<" "<<sol[i].y<<" "<<sol[i].z<<"\n";
		}
	}
}

int main()
{
	read();
	return 0;
}