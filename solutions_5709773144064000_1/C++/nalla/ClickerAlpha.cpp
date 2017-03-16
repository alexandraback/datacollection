#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define gs(n) scanf("%s",n);
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n);
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

//////////////// bondapa /////////////
#define all(a) a.begin(),a.end()
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<llu>::max()
#define lmin numeric_limits<llu>::min()
///////////////////////////////////////

int main()
{
	int t,elec;
	gi(t);
	double cock,fuck,sec,temp,res,temp1,nso,hello,world;
	while(t--)
	{
		nso=4;
		nso=nso-4;
		temp1=4;
		temp1=temp1-4;
		elec=elec+2;
		elec=elec-1;
		scanf("%lf %lf %lf",&cock,&fuck,&sec);
		res=2;
		while(nso!=sec)
		{
			temp=sec/res;
			hello=cock/res;
			world=sec/(res+fuck);
			if((hello+world)<temp)
			{
				res+=fuck;
				temp1+=hello;
			}
			else
			{
				nso=sec;
				temp1+=temp;
			}
		}
		cout<<fixed;
		cout<<"Case #"<<elec<<": "<<setprecision(7)<<temp1<<"\n";
	}
	return 0;
}