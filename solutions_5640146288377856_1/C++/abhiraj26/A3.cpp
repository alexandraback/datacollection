#include<cstdio>
#include<iostream>
#include<vector>
#include<utility>
#include<string.h>
#include<algorithm>
#include<cmath>

#define LL long long int
#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
	freopen("abc_lets.txt","w",stdout);
    int x,t,n,i,j,r,c,w;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>r>>c>>w;
        x=c/w;
        if(w!=1&&w!=c&&c%w==0)
        printf("Case #%d: %d\n",i+1,(r-1)*x+(x+w-1));
        else if(w!=1&&w!=c)
        printf("Case #%d: %d\n",i+1,(r-1)*x+(x+w));
        else if(w==1)
        printf("Case #%d: %d\n",i+1,r*c);
        else if(w==c)
            printf("Case #%d: %d\n",i+1,c+r-1);
    }
	return 0;
}
