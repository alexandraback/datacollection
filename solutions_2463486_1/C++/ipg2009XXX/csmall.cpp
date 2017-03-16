
//Imp header files
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <fstream>
using namespace std;

//defined I/O
#define si(n) scanf("%d",&n)
#define sli(n) scanf("%ld",&n)
#define slli(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define GetLine(n) getline(cin,n);
#define ss(n) scanf("%s",n)
#define pi(n) printf("%d",n)
#define pli(n) printf("%ld",n)
#define plli(n) printf("%lld",n)
#define pf(n) printf("%lf",n)
#define ps(n) printf("%s",n)
#define newLine printf("\n")
#define space printf(" ")
#define SWAP(a,b,t) t=a,a=b,b=t
#define Loop(i,a,n) for(__typeof(n) i(a); i<n; i++)
#define ULL unsigned long long int
#define LL long long int 

#define MOD 1000000007
//Imp functions
int gcd(int a, int b){if(b == 0)return a;else return gcd(b,a % b);}

#define get getchar_unlocked
inline int scan()
{
	int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}


ULL mkc[49]={1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001, 1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002, 2001002,10000001,10011001,10100101,10111101,11000011,11011011,11100111,11111111,20000002};






int main()
{
	//freopen("C-large-1.in","r",stdin);
	//freopen("output.in","w",stdout);
	
	ULL list[49];
	
	for(int i=0;i<49;i++)
	{
		list[i]=pow(mkc[i],2);
	}
	
	
	int t;
	t=scan();
	
	ULL a,b;
	int p=0;
	while(t--)
	{
		++p;
		int count=0;
		cin>>a>>b;
		
		for(int i=0;i<49;i++)
		{
		//	cout<<list[i]<<endl;
			if(list[i]>=a && list[i]<=b)
			count++;
			
		}
		printf("Case #%d: %d\n",p,count);
		
		
		
	}
	
	
	
	return 0;
}
