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
	double mat[2000],mat2[2000];int t,i,j,n,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++){scanf("%lf",&mat2[i]);}
		for(i=0;i<n;i++){scanf("%lf",&mat[i]);}
		sort(mat2,mat2+n);
		sort(mat,mat+n);
		int temp=0,temp1=0;
		temp=1;
		temp=temp-1;
		temp1=1;
		temp1=temp1-1;
		i=0;j=0;
		while(i<n&&j<n)
		{
			if(mat2[i]>mat[j])
			{
				temp++;
				i++;
				j++;
			}
			else
			i++;
		}
		i=0;j=0;
		while(i<n&&j<n)
		{
			if(mat2[i]<mat[j])
			{
				temp1++;
				i++;
				j++;
			}
			else
				j++;
		}
		printf("Case #%d: %d %d\n",k,temp,n-temp1);
	}
	return 0;
}