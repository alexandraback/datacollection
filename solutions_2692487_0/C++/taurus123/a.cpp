#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int b[105];
int main()
{
    int T;
    int a,n;
	//freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
        scanf("%d%d",&a,&n);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        sort(b,b+n);
        int ans=200;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(a>b[i])a+=b[i];
            else{
                if(cur+n-i<ans)ans=cur+n-i;
                int tmp=a;
                int cnt=0;
				if(tmp==1){cur=200;break;}
                while(tmp<=b[i])
                {
                    tmp=tmp*2-1;
                    cnt++;
                }
                cur+=cnt;
                a=tmp+b[i];
            }
        }
		if(cur<ans)ans=cur;
        if(ans==200)ans=0;
        printf("Case #%d: %d\n",cas,ans);

    }
    return 0;
}
