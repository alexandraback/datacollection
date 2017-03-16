#include<cstdio>
#include<iostream>
int main()
{
    freopen("AR.in","r",stdin);
	freopen("AR.out","w",stdout);
	long long int r,p,fp,ring;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
            ring=0;
            fp=0;
            scanf("%lld %lld",&r,&p);
            while(p>=fp)
            {
                 fp+=(r+r+1);
                 if(fp<=p)
                    ring++;
                 r=r+2;
            }
            printf("Case #%d: %lld\n",i+1,ring);
     }
}
