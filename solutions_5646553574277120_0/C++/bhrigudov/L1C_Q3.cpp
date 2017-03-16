#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define s(n) scanf("%d",&n)
#define sl(n) scanf("%ld",&n)
#define sll(n) scanf("%lld",&n)
#define p(n) printf("%d ",n)
#define pl(n) printf("%ld ",n)
#define pll(n) printf("%lld\n",n)
#define fo(i,a,b) for(i=a;i<b;i++)
#define rf(i,a,b)	for(i=a;i>=b;i--)
# define toint(n)	(n-'0')
typedef long long ll;


int main()
{
	//freopen("C-small-attempt1.in","r",stdin);
    //freopen("C-small-attempt1.out","w",stdout);
    int t,z,v,i,d,c;
    int a[32],ins[32];
    bool all[32];
    ll ans;
    
    s(t);
    fo(z,1,t+1)
   	{
   		ans=0;

   		s(c), s(d), s(v);
   		//fo(i,1,d+1)
   		//	all[i]=0;

   		fo(i,0,d){
   			s(a[i]);
   			all[a[i]]=1; }

   		/*sort(a,a+d);

   		for(i=1;((i<a[0])&&(i<v)),i++)
   		{
   			a[d++]=i;
   			ans++;
   			all[i]=1;
   		}

   		sort(a,a+d);

   		for(i=1;i<=v;i++)
   		{
   			if(all[i]==0)
   			{
   				Can(i,a,d);
   			}	
   		}*/

   		fo(i,0,d)
   			v-=a[i];

		printf("Case #%d: %d\n",z,v);
	}
	return 0;
}