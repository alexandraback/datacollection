#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    long long cnt;
    int id;
}a[105], b[105], c[105];
int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T, n, m, i, j,k, cas=1;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++)
        scanf("%lld%d", &a[i].cnt, &a[i].id);
        for(i=0; i<m; i++)
        scanf("%lld%d", &b[i].cnt, &b[i].id);
        if(n==1){
            long long sum=0;
            for(i=0; i<m; i++){
                if(b[i].id==a[0].id){
                    sum+=b[i].cnt;
                }
            }
            if(sum>a[i].cnt)sum=a[i].cnt;
            printf("Case #%d: %lld\n", cas++, sum);
        }
        else if(n==2){
            long long sum=0;
            if(a[0].id==a[1].id){
                a[0].cnt+=a[1].cnt;
                for(i=0; i<m; i++){
                    if(b[i].id==a[0].id){
                        sum+=b[i].cnt;
                    }
                }
                if(sum>a[i].cnt)sum=a[i].cnt;
                printf("Case #%d: %lld\n", cas++, sum);
                continue;
            }
            long long sum1=0, sum2=0, ans=0;
            for(i=0; i<m; i++){
                for(j=0; j<i; j++)
                if(a[0].id==b[j].id)sum1+=b[j].cnt;
                if(sum1>a[0].cnt)sum1=a[0].cnt;
                for(j=i; j<m; j++)
                if(a[1].id==b[j].id)sum2+=b[j].cnt;
                if(sum2>a[1].cnt)sum2=a[1].cnt;
                if(sum1+sum2>ans)ans=sum1+sum2;
            }
            printf("Case #%d: %lld\n", cas++, ans);
        }
        else {
            long long ans=0;
            memcpy(c, b, sizeof(c));
            for(i=0; i<m; i++)
            for(k=i; k<m; k++){
                memcpy(b, c, sizeof(c));
                long long sum1=0, sum2=0, sum3=0;
                //if(i==2&&k==2){printf("%d\n", b[i].cnt);}
                for(j=0; j<i; j++){
                    //if(i==2&&k==2){printf("%d %lld\n", a[0].id, b[j].cnt);}
                if(a[0].id==b[j].id)sum1+=b[j].cnt;

                }

                if(sum1<a[0].cnt&&b[i].id==a[0].id){
                    //if(i==2&&k==2){printf("%d %d %d\n", sum1,b[i].cnt,a[0].cnt);}
                    if(sum1+b[i].cnt>a[0].cnt){
                        b[i].cnt-=(a[0].cnt-sum1); sum1=a[0].cnt;

                    }
                    else {
                        sum1+=b[i].cnt;
                        b[i].cnt=0;
                    }
                }
                if(sum1>a[0].cnt)sum1=a[0].cnt;
                //if(i==2&&k==2){printf("%d\n", b[i].cnt);}
                for(j=i; j<k; j++)
                if(a[1].id==b[j].id)sum2+=b[j].cnt;
                if(sum2<a[1].cnt&&b[k].id==a[1].id){
                    if(sum2+b[k].cnt>a[1].cnt){
                        b[k].cnt-=(a[1].cnt-sum2); sum2=a[1].cnt;
                    }
                    else {
                        sum2+=b[k].cnt;
                        b[k].cnt=0;
                    }
                }
                if(sum2>a[1].cnt)sum2=a[1].cnt;
                for(j=k; j<m; j++)
                if(a[2].id==b[j].id)sum3+=b[j].cnt;
                if(sum3>a[2].cnt)sum3=a[2].cnt;
                if(sum1+sum2+sum3>ans)ans=sum1+sum2+sum3;
                //if(i==2&&k==2){printf("%d %d %d\n", sum1, sum2, sum3);}
            }
            printf("Case #%d: %lld\n", cas++, ans);

        }
    }
    return 0;
}
