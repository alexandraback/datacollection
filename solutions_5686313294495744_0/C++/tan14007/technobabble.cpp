#include <bits/stdc++.h>
#define X first
#define Y second
#define PI pair<int,int>
using namespace std;
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
map <string,int> dei,deo;
string sa,sb;
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf(" %d",&t);
	for(l=1;l<=t;l++){
		printf("Case #%d: ",l);
		scanf(" %d",&n);
		z=0;
		dei.clear();
		deo.clear();
		for(i=0;i<n;i++){
			cin>>sa>>sb;
			if(dei[sb]&&deo[sa])z++;
			dei[sb]++;
			deo[sa]++;
		}
		printf("%d\n",z);
	}
	return 0;
}