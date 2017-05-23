#include<stdio.h>

int main()
{
    freopen("sb.in","r",stdin);
    freopen("sb.out","w",stdout);
    int cases,cc,S,p,t[102],N,i;
    int s1,s2,s3;
    int sups,nors;
    scanf("%d",&cases);
    for(cc=1;cc<=cases;cc++){
        scanf("%d%d%d",&N,&S,&p);
        sups=nors=0;
        for(i=1;i<=N;i++){
            scanf("%d",&t[i]);
            bool yn,ys; //normal, suprise
            yn=ys=false;
            for(s1=0;s1<=10;s1++)for(s2=s1;s2<=s1+2;s2++)for(s3=s2;s3<=s1+2;s3++){
                if(s1+s2+s3==t[i] && s3>=p){
                    if(s3==s1+2)ys=true;
                    else yn=true;
                }
            }
            if(yn)nors++;
            else if(ys)sups++;
        }
        int an=nors;
        if(sups>=S)an+=S;
        else an+=sups;
        //fprintf(stderr,"nors=%d sups=%d\n",nors,sups);
        printf("Case #%d: %d\n",cc,an);
    }
    
    
    return 0;
}
