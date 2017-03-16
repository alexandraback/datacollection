#include<iostream>
using namespace std;

#define _min(x,y) ((x)<(y)?(x):(y))

struct data{
     long long num;
     int type;
};

data box[103];
data toy[103];

int n,m;

long long res;

int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("data.out","w",stdout);
    
    int t;
    cin>>t;
    int ca;
    for(ca=1;ca<=t;ca++){
        cin>>n>>m;
        int i,j,k,l;
        for(i=0;i<n;i++){
            scanf("%I64d%d",&box[i].num,&box[i].type);
//            printf("%I64d\n",box[i].num);
        }
        for(i=0;i<m;i++){
            scanf("%I64d%d",&toy[i].num,&toy[i].type);
        }
        i=0;
        for(j=1;j<n;j++)
          if(box[j].type==box[i].type)
            box[i].num+=box[j].num;
          else{
             i++;
             box[i]=box[j];
          }
        n=i+1;
        i=0;
        for(j=1;j<m;j++)
          if(toy[j].type==toy[i].type)
            toy[i].num+=toy[j].num;
          else{
             i++;
             toy[i]=toy[j];
          }
        m=i+1;
        res=0;
/*        cout<<n<<" "<<m<<endl;
        for(i=0;i<m;i++){
            printf("%I64d %d\n",toy[i].num,toy[i].type);
//            printf("%I64d\n",box[i].num);
        }*/
        //1
        long long sum=0;      
        for(i=0;i<n;i++){
           sum=0;
           for(j=0;j<m;j++)
             if(toy[j].type==box[i].type){
                 sum+=toy[j].num;
             }
           if(res<_min(box[i].num,sum))
              res=_min(box[i].num,sum);
        }
//         printf("%I64d\n",res);
        //2
        long long sum1=0;
        if(n>=2){
        
        for(i=0;i<n;i++)
          for(j=i+1;j<n;j++){
             if(box[i].type==box[j].type){
                 sum=0;
                 data tmpbox;
                 tmpbox.num=box[i].num+box[j].num;
                 tmpbox.type=box[i].type;
                 for(k=0;k<m;k++)
                     if(toy[k].type==tmpbox.type){
                         sum+=toy[k].num;
                     }
                   if(res<_min(tmpbox.num,sum))
                      res=_min(tmpbox.num,sum);
             }
             else{
             for(k=0;k<m-1;k++){
                 sum=sum1=0;
                 for(l=0;l<=k;l++)
                   if(toy[l].type==box[i].type)
                      sum+=toy[l].num;
                 for(l=k+1;l<m;l++)
                   if(toy[l].type==box[j].type)
                      sum1+=toy[l].num;
                 sum=_min(sum,box[i].num);
                 sum1=_min(sum1,box[j].num);
                 if(res<sum1+sum)
                   res=sum1+sum;
//                  printf("%d %d %d %I64d\n",i,j,k,res);
             }
             }
          }
        }
//        printf("%I64d\n",res);
        //3
        long long sum2=0;
        if(n>=3){
        
        for(i=0;i<m-2;i++)
          for(j=i+1;j<m-2;j++){
             sum=sum1=sum2=0;
             for(l=0;l<=i;l++)
               if(toy[l].type==box[0].type)
                      sum+=toy[l].num;
             for(l=i+1;l<=j;l++)
               if(toy[l].type==box[1].type)
                      sum1+=toy[l].num;
             for(l=j+1;l<m;l++)
               if(toy[l].type==box[2].type)
                      sum2+=toy[l].num;
             sum=_min(sum,box[0].num);
             sum1=_min(sum1,box[1].num);
             sum2=_min(sum2,box[2].num);
             if(res<sum1+sum+sum2)
                   res=sum1+sum+sum2;
          }
        }
        printf("Case #%d: %I64d\n",ca,res);
    }
}
