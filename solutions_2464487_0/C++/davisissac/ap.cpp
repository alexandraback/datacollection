

#include<iostream>
# include <cmath>
# include <algorithm>
# include <cstdio>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <stack>
# include <set>
# include <list>
# include <deque>
# include <functional>
# include <ctime>
using namespace std;

#define DEBUG



#ifdef DEBUG
#define D(x) cout<<#x<<"="<<x<<" "
#define DN(x)  cout<<#x<<"="<<x<<"\n"
#define DA(a,n) cout<<#a<<"=["; printarray(a,n); cout<<"]\n"
#define DAR(a,n,s) cout<<#a<<"["<<s<<"-"<<s+n-1<<"]=["; printarray(a,n,s); cout<<"]\n"
#define DPR(fmt, ...) \
	do { printf(fmt, ## __VA_ARGS__); } while (0)
#else
#define D(x) 
#define DN(x)
#define DA(a,n) 
#define DAR(a,n,s)
#define DPR(fmt, ...) \
	do { } while (0)
#endif


// Useful constants
#define inf                         (long long)1e9
#define eps		(double)1e-9
# define mod 1000000007
# define pi  3.14159265358979323846

#define sz(a)                       ((int)(a.size()))


//STL output ********************************
template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{
	bool first = true;
	os << "[";
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(!first)
			os << ", ";
		os << v[i];
		first = false;
	}
	return os << "]";
}


	
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{
	bool first = true;
	os << "[";
	for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
	{
		if(!first)
			os << ", ";
		os << *ii ;
		first = false;
	}
	return os << "]";
}
//*****************************************
//printing array
template<typename T,typename T2>
void printarray(T  a[],T2 sz,T2 beg=0)
{
	for(T2 i=beg;i<beg+sz;i++) cout<<a[i]<<" ";
}
//*********************************8
long long a,l;
bool sum(long long n)
{
	long long s=(2*a+(n-1)*4);
	double rh=((double)l)*2.0/n;
	return s<=rh;
}

//follwng fn returns the highest int btw low and hi inclusive which satisfies conditn given by fn cond
//assumption: cond is non-increasing
//if the ret val does not sat cond,then no val in rang satisfies the condn
template <class T>
T bin_srch_rang_hi(T low,T hi,bool (*cond)(T))
{
	T mid=ceil((low+hi)/2.0);
	//D(mid);
	
	while(low<hi)
	{
		if((*cond)(mid))
		{
			low=mid;
		}
		else
		{
			hi=mid-1;
		}
		//D(low);
		//D(hi);
	
		mid=ceil((low+hi)/2.0);

	}
	return mid;
	
}

int main()
{
	int t,q;
	int i,j;
	int n,m,casen=0;
	scanf("%d",&t);
	while(++casen<=t)
	{
		//START
		long long r;
		scanf("%lld",&r);
		scanf("%lld",&l);
		a=2*r+1;			
		long long resn=bin_srch_rang_hi<long long> (0,1000000000000000000,sum);
	
		printf("Case #%d: ",casen);
		printf("%lld ",resn);
		
		printf("\n");
	}
	return 0;
}	

