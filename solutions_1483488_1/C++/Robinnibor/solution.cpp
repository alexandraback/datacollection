#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

int check[2000002]={0};

int main()
{
    freopen("lc.in","r",stdin);
    freopen("lc.out","w",stdout);
    int cases,cc,A,B,i,j,ii;
    scanf("%d",&cases);
    //FILE *ftest=fopen("check.out","w");
    for(cc=1;cc<=cases;cc++){
        memset(check,0,sizeof(check));
        scanf("%d%d",&A,&B);
        int an=0;
        for(i=A;i<=B;i++){
            char ss[22],s1[22];
            int x=i,len;
            bool first=true;
            len=0;
            if(x==0)s1[len++]='0';
            while(x>0){
                s1[len++]=x%10+'0';
                x/=10;
            }
            for(j=0;j<len;j++)ss[len-j-1]=s1[j];
            ss[len]=0;
            
            //fprintf(stderr,"ftest=%d\n",ftest);
            for(j=1;j<=len-1;j++){
                for(ii=len-1;ii>=1;ii--)swap(ss[ii],ss[ii-1]);
                int temp=atoi(ss);
                //fprintf(stderr,"temp=%d\n",temp);
                if(A<=temp && temp<=B && temp!=i && ss[0]!='0'){// && temp<i{
                    if(check[temp]!=i)an++;
                    check[temp]=i;
                    //fprintf(stderr,"%d %d\n",temp,i);
                    //first=false;
                }
            }        
            //if(!first)fprintf(stderr,"  %d\n",i);
        }
        printf("Case #%d: %d\n",cc,an/2);
    }
    
    return 0;
}
