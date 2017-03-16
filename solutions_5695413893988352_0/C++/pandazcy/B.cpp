#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int T,t,n,m;
char s[2][30];
int num[2][110];
void solve(int pos){
    int l1,l2,l3,r1,r2,r3,k1,k2,k3;
    l1=l2=l3=0;
    r1=r2=r3=9;
    if(s[pos][1]!='?')
        l1=r1=s[pos][1]-'0';
    if(s[pos][2]!='?')
        l2=r2=s[pos][2]-'0';
    if(s[pos][3]!='?')
        l3=r3=s[pos][3]-'0';
    //printf("%d %d %d %d %d %d\n",l1,r1,l2,r2,l3,r3);
    for(k1=l1;k1<=r1;k1++)
        for(k2=l2;k2<=r2;k2++)
            for(k3=l3;k3<=r3;k3++){
                 num[pos][++num[pos][0]]=k1*100+k2*10+k3;
                 //if(pos==0)
                 //   printf("%d %d %d\n",0,num[pos][0],num[pos][num[pos][0]]);
            }

}
void print2(int num){
    if(n==3){
        if(num<10)
            printf("00%d",num);
        else if(num<100)
            printf("0%d",num);
        else
            printf("%d",num);
    }
    else if(n==2){
        if(num<10)
            printf("0%d",num);
        else
            printf("%d",num);
    }
    else
       printf("%d",num);

}
void print(int a,int b){
    printf("Case #%d: ",t);
    print2(a);
    printf(" ");
    print2(b);
    printf("\n");
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);    //数据读入
    freopen("out.txt","w",stdout);  //数据输出
    int i,j,k,ans1,ans2,a,b;
    bool flag0,flag1;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        n=strlen(s[0]+1);
        num[0][0]=num[1][0]=0;
        if(n==1){
            s[0][3]=s[0][1];s[0][1]=s[0][2]='0';
            s[1][3]=s[1][1];s[1][1]=s[1][2]='0';
        }
        else if(n==2){
            s[0][3]=s[0][2];s[0][2]=s[0][1];s[0][1]='0';
            s[1][3]=s[1][2];s[1][2]=s[1][1];s[1][1]='0';
        }
        flag0=flag1=0;
        if(s[0][1]=='?' &&s[0][2]=='?' &&s[0][3]=='?')
            flag0=1;
        if(s[1][1]=='?' &&s[1][2]=='?' &&s[1][3]=='?')
            flag1=1;
        if(!flag0)
            solve(0);
        if(!flag1)
            solve(1);
        if(flag0 && flag1)
            print(0,0);
        else if(flag0){
            print(num[1][1],num[1][1]);
        }
        else if(flag1)
            print(num[0][1],num[0][1]);
        else{
            ans1=1000;ans2=3000;
            for(i=1;i<=num[0][0];i++){
                a=num[0][i];
                //printf("%d\n",a);
                for(j=1;j<=num[1][0];j++){
                    b=num[1][j];
                    if(abs(a-b)<abs(ans1-ans2)){
                        ans1=a;
                        ans2=b;
                    }
                    else if(abs(a-b)==abs(ans1-ans2)){
                        if(a<ans1){
                            ans1=a;
                            ans2=b;
                        }
                        else if(a==ans1)
                            ans2=min(ans2,b);
                    }
                }
            }
            //printf("%d %d\n",ans1,ans2);
            print(ans1,ans2);
        }
    }

}
