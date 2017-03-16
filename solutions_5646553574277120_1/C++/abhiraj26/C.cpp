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
int a[50000],b[50000];
int main()
{
    freopen("C-large.in","r",stdin);
	freopen("abhi_fuck.txt","w",stdout);
        int i,k,t,c,d,v,s;
        cin>>t;
        for(i=1;i<=t;i++)
        {
            cin>>c>>d>>v;
            for(s=0;s<d;s++)
            {
                cin>>a[s];
            }
            int f,l=0;
            long long int j,sum=0;
            for(j=1;j<=v;j=j+sum)
            {   f=0;
                    if(binary_search(a,a+d,j))
                        {sum+=c*j;
                        }
                    if(j<=sum)
                    {
                        f=1;
                    }
                if(f==0)
                {
                    a[d]=j;
                    b[l]=j;
                    l++;
                    sum+=c*j;
                }
            }
            printf("Case #%d: %d\n",i,l);
        }
	return 0;
}
