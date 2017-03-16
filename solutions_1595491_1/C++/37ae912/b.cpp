
#include <cstdio>

int d[110];


int main()
{
    int cs;
    int i=0;
    scanf("%d",&cs);
    while(i++<cs){
        printf("Case #%d: ",i);

       int n,s,p;
       scanf("%d%d%d",&n,&s,&p);
        int cnt=0;
        int ans=0;
        int zero=0;
        for(int j=0;j<n;++j){
            scanf("%d",d+j);
            if( d[j]%3==0){
                d[j] = d[j]/3>=p ? -1: d[j];
            } 
            else{
                d[j] = (d[j]+2)/3>=p? -1:d[j]; 
            }
        }

        for(int j=0;j<n;++j){
            if( d[j]%3==1 )continue;
            if( d[j]%3==0)
                if(d[j]/3>0 && d[j]/3+1>=p && s>0)
                    s--,d[j]=-1;
                    
            if( d[j]%3==2)
                if(d[j]/3+2>=p && s>0)
                    s--,d[j]=-1;
        }

        for(int j=0;j<n;++j)
            if(d[j]==-1)ans++;

        printf("%d\n",ans);
        /*
        if(ans+s>=cnt)
            ans = cnt;
        else
            ans +=s;
        */

    }


    return 0;
}
