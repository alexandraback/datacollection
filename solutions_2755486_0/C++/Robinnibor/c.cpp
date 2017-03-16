#include<stdio.h>
#include<cstring>

#define F 1500000

int h[3000002];

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int cases,i,j,ii,cc;
    int dd[1002],dp[1002],ds[1002],w[1002],e[1002],s[1002],n[1002],N,d[1002],ats[1002];
    int an,date;
    scanf("%d",&cases);
    for(cc=1;cc<=cases;cc++){
        scanf("%d",&N);
        for(i=1;i<=N;i++){
            scanf("%d%d%d%d%d%d%d%d",&d[i],&n[i],&w[i],&e[i],&s[i],&dd[i],&dp[i],&ds[i]);
            if(dp[i]==0)fprintf(stderr,"cc=%d i=%d dp==0\n",cc,i);
            ats[i]=0;
        }
        memset(h,0,sizeof(h));
        date=0;
        an=0;
        bool end=false;
        while(!end){
            
            for(i=1;i<=N;i++)if(date>=d[i] && (date-d[i])%dd[i]==0 && ats[i]<n[i]){
                //fprintf(stderr,"date=%d i=%d\n",date,i);
                bool at=false;
                //fprintf(stderr,"w %d  e%d\n",w[i]+ats[i]*dp[i],e[i]+ats[i]*dp[i]);
                for(j=w[i]+ats[i]*dp[i];j<e[i]+ats[i]*dp[i];j++){
                    //fprintf(stderr,"s=%d h[%d]=%d\n",s[i],j,h[j+F]);
                    if(h[j+F]<s[i])at=true;
                    
                }
                if(at)an++;
            }
            //if(cc==4 && date==5586)fprintf(stderr,"here\n");
            for(i=1;i<=N;i++)if(date>=d[i] && (date-d[i])%dd[i]==0 && ats[i]<n[i]){
                //fprintf(stderr,"fx i=%d\n",i);
                for(j=w[i]+ats[i]*dp[i];j<e[i]+ats[i]*dp[i];j++){
                    if(h[j+F]<s[i])h[j+F]=s[i];
                    //fprintf(stderr,"fx s=%d h[%d]=%d\n",s[i],j,h[j+F]);
                }
                ats[i]++;
                s[i]+=ds[i];
            }
            date++;
            end=true;
            for(i=1;i<=N;i++)if(ats[i]<n[i])end=false;
        }
        //fprintf(stderr,"Case #%d: %d\n",cc,an);
        printf("Case #%d: %d\n",cc,an);
    }
    
    return 0;
}
