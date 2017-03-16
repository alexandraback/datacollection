#include<bits/stdc++.h>
#define Mod 1000000007
using namespace std;
#define ll long long int
#define gc getchar
#define pc putchar

inline ll getn()
{
  ll n=0, c=gc();

  while(c < '0' || c > '9') c = gc();

  while(c >= '0' && c <= '9')
   n = (n<<3) + (n<<1) + c - '0', c = gc();

  return n;
}
inline void fastWrite(ll a)
{
   char snum[20];
   ll i=0;

   do
    {
     snum[i++]=a%10+48;
     a=a/10;
   }while(a!=0);

   i=i-1;

   while(i>=0)
    pc(snum[i--]);

   pc('\n');
}
int find(int r,int c,int w)
{
	if(w==c)
		return c;
	else
	{
		return (ceil((c*1.0)/w) -1 + w);
	}
}
int main()
{   freopen("inpu.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		int result=0,N,r,c,w;
 
		scanf("%d %d %d",&r,&c,&w);
		result = find(r,c,w);
 
			printf("Case #%d: %d\n",++cas,result);
 
	}
    fclose(stdout);
    return 0;
}


