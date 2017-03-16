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
	freopen("output1.txt","w",stdout);
    int t, r, c, w;
	cin >> t;
	for (int i = 0; i<t; i++)
	{
		int res = 0;
		cin >> r >> c >> w;
 
 
		res = c / w *r;
 
		res += w - 1;
		if (c%w != 0)
			res++;
		cout << "Case #" << i + 1 << ": " << res << endl;
	}
    fclose(stdout);
    return 0;
}


