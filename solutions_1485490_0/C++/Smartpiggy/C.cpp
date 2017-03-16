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
	int64 Type;
	int64 Count;
};

int64 N, M, R;
vector<Node>	AsmN;
vector<Node>	AsmM;

bool End(int64 idxN, int64 idxM, int64 usedN, int64 usedM)
{
	return (idxN >= N) || (idxM >=M) || (idxN==N-1 && usedN == AsmN[idxN].Count) || (idxM==M-1 && usedM == AsmM[idxM].Count);
}

void Move (int64 idxN, int64 idxM, int64 usedN, int64 usedM, int64 total)
{
	if (End(idxN, idxM, usedN, usedM))
	{
		if (total>R)
			R =total;
		return;
	}

	int64 leftN =AsmN[idxN].Count-usedN;
	int64 leftM =AsmM[idxM].Count-usedM;
	int64 get =min(leftN, leftM);

	if (AsmN[idxN].Type == AsmM[idxM].Type)
	{
		usedN += get;
		if (usedN == AsmN[idxN].Count)
		{
			idxN ++;
			usedN =0;
		}

		usedM += get;
		if (usedM == AsmM[idxM].Count)
		{
			idxM ++;
			usedM =0;
		}

		Move (idxN, idxM, usedN, usedM, total+get);
		return;
	}

	//usedN += get;
	//if (usedN == AsmN[idxN].Count)
	//{
	//	idxN ++;
	//	usedN =0;
	//}
	Move (idxN+1, idxM, 0, usedM, total);

	//usedM += get;
	//if (usedM == AsmM[idxM].Count)
	//{
	//	idxM ++;
	//	usedM =0;
	//}
	Move (idxN, idxM+1, usedN, 0, total);
}

void Solve()
{
	R =0;
	cin>>N>>M;
	AsmN.clear();
	AsmM.clear();

	for (int64 i=0; i<N; i++)
	{
		Node node;
		cin>>node.Count;
		cin>>node.Type;
		AsmN.push_back(node);
	}
	for (int64 i=0; i<M; i++)
	{
		Node node;
		cin>>node.Count;
		cin>>node.Type;
		AsmM.push_back(node);
	}

	Move(0, 0, 0, 0, 0);

	cout<<R;
}

void main()
{
	#define PBM	"C"

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
