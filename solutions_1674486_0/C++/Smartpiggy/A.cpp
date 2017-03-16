#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// ===== template code begin =========
typedef long long int64;
typedef unsigned long long uint64;

const double PI=acos(-1.0);

#define SIZE(X) ((int)(X.size()))
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline bool isPrimeNumber(T n)
{if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}

bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
bool isDigit(char c){return c>='0' && c<='9';}
char toLower(char c){return (isUpper(c))?(c+32):c;}
char toUpper(char c){return (isLower(c))?(c-32):c;}

template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};
template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
// ============= template code end ============


struct Node
{
	Node()
	{
		HasParent = false;
	}

	bool		HasParent;
	vector<int>	SubNodes;
};

int N;
vector<Node>	NODES;
bitset<1001>	BITS;

bool Find(int idx)
{
	if (BITS[idx])
		return true;

	BITS[idx] = true;

	Node& node =NODES[idx];

	for (int i=0; i<node.SubNodes.size(); i++)
	{
		if (Find(node.SubNodes[i]))
			return true;
	}

	return false;
}

void Solve()
{
	cin>>N;
	NODES.clear();
	NODES.resize(N);

	for (int i=0; i<N; i++)
	{
		int M;
		cin>>M;

		for (int j=0; j<M; j++)
		{
			int a;
			cin>>a;
			NODES[i].SubNodes.push_back(a-1);
			NODES[a-1].HasParent = true;
		}
	}

	for (int i=0; i<N; i++)
	{
		if (!NODES[i].HasParent)
		{
			BITS.reset();
			if (Find(i))
			{
				cout<<"Yes";
				return;
			}
		}
	}

	cout<<"No";
}

void main()
{
	#define PBM	"A"

	//freopen (PBM".in","r",stdin);
	
	freopen (PBM"-small-attempt0.in","r",stdin);freopen(PBM"-small-attempt0.out","w",stdout);
	//freopen (PBM"-small-attempt1.in","r",stdin);freopen(PBM"-small-attempt1.out","w",stdout);
	//freopen (PBM"-small-attempt2.in","r",stdin);freopen(PBM"-small-attempt2.out","w",stdout);
	//freopen (PBM"-small-attempt3.in","r",stdin);freopen(PBM"-small-attempt3.out","w",stdout);
	//freopen (PBM"-small-attempt4.in","r",stdin);freopen(PBM"-small-attempt4.out","w",stdout);
	//freopen (PBM"-small-attempt5.in","r",stdin);freopen(PBM"-small-attempt5.out","w",stdout);
	
	//freopen (PBM"-large.in","r",stdin);freopen(PBM"-large.out","w",stdout);

	int caseCount;
	cin >> caseCount;
	std::getline(cin, string());

	for (int i=0; i<caseCount; i++)
	{
		cout<<"Case #"<<i+1<<": ";
		Solve ();
		cout<<endl;
	}

	return;
}
