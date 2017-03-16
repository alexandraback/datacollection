#include<stdio.h>
main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int con[300];
    int r[300];
    for(int p=1;p<=t;p++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            r[i]=0;
            }
        int y=n;
        double sum=0;
        double tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&con[i]);
            sum+=con[i];
            }
        tmp=sum;
        printf("Case #%d: ",p);
        double re=sum*2/y;
        for(int i=0;i<n;i++){
            if(re-con[i]<0){
                //tmp-=con[i];
                y--;
                r[i]=1;
                tmp-=con[i];
                }
            
            }
        re=(sum+tmp)/y;
        //printf("%lf\n",sum);
        //printf("%lf\n",re);
        for(int i=0;i<n;i++){
            if(re-con[i]>0){
                printf("%.6lf ",(re-con[i])/sum*100); 
                }
            else{
                printf("0 ");
                }
            }
        printf("\n");
        }
    }
