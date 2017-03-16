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
    freopen("C-small-attempt1.in","r",stdin);
	freopen("abhi.txt","w",stdout);
        int i,j,k,t,c,d,v,a[15];
        cin>>t;
        for(i=1;i<=t;i++)
        {
            cin>>c>>d>>v;
            for(j=0;j<d;j++)
            {
                cin>>a[j];
            }
            sort(a,a+d);
            int f,b[30],l=0,sum=0;
            for(j=1;j<=v;j++)
            {   f=0;
                for(k=0;k<d+l;k++)
                {
                    if(binary_search(a,a+d+l,j))
                        {sum+=j;
                        }
                    if(j<=sum||j-a[k]==0)
                    {
                        f=1;
                    }
                    else
                    {
                        f=0;
                    }
                    if(f==1)
                        break;
                }
                if(f==0)
                {
                    b[l]=j;
                    a[d+l]=j;
                    l++;
                    sum+=j;
                  //  cout<<j<<" ";
                    sort(a,a+d+l);
                }
                //cout<<sum<<endl;
            }
            printf("Case #%d: %d\n",i,l);
        }
	return 0;
}
