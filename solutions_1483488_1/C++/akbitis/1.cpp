#include <map>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>


using namespace std;

long int temp,i,j,k,T;

#define CASE while(T--)
#define FOR(I,A,B) for(I=A;I<B;I++)
#define REP(i,n) FOR(i,0,n)
#define FORR(I,J,K) for(I=J;I>K;I--)
#define JAM(N) printf("Case #%ld: ",N)
#define INPUT(A) freopen(A,"r",stdin);
#define OUTPUT(A) freopen(A,"w",stdout);

#define EXP 1e-10
#define INF	(int)1e9

#define F first
#define S second


typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef unsigned long long ULL;

#define DEB cout<<"DEB"<<endl;
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%ld",&n)
#define sll(n) 					scanf("%I64d",&n)
#define sf(n) 					scanf("%f",&n)
#define slf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)

int next(){
    char c;int num=0;
    c=getchar_unlocked();
    while(!(c>='0' && c<='9')) c=getchar_unlocked();
    while(c>='0' && c<='9'){
        num=(num<<3)+(num<<1)+c-'0';
        c=getchar_unlocked();
    }
    return num;
}

//main code is here

main()
{
	INPUT("C-large.in");
	sl(T);
	//T=1;
	k=1;
	CASE
	{
		JAM(k++);
		int a,b,ans=0,z;
		cin>>a>>b;
		for(i=a;i<b;i++)
		{
			int t[10]={0},size=0;
			temp=i;
			while(temp)
			{
				t[size++]=temp%10;
				temp/=10;
			}
			
			//for(i=0;i<size;i++)cout<<t[i]<<" ";
			//cout<<endl<<"s"<<size<<endl;
			//size--;
			VI vec;
			for(j=size-2;j>=0;j--)
			{	
				int cur=0;
				//cout<<t[j]<<endl;
				if(t[j]==0) continue;
				for(z=j;z!=(j+1+size)%size;z=(z-1+size)%size)
				{
					cur=cur*10+t[z];
				}
				//cout<<cur<<endl;
				cur=cur*10+t[z];
				//cout<<cur<<endl;
				if(b >= cur && cur > i && i>=a) vec.push_back(cur);
			}
			std::sort(vec.begin(), vec.end());
			vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
			ans+=vec.size();
		}
		cout<<ans<<endl;
	}
	return 0;
}