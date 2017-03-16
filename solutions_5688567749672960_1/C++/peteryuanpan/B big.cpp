//Hello. I'm Peter.
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
#define peter cout<<"i am peter"<<endl
#define input freopen("data.txt","r",stdin)
#define randin srand((unsigned int)time(NULL))
#define INT (0x3f3f3f3f)*2
#define LL (0x3f3f3f3f3f3f3f3f)*2
#define MAXN 100010
#define N
#define M 17
int r,c,n;
int main(){
    input;
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        printf("Case #%d: ",kase);
        scanf("%d%d%d",&r,&c,&n);
        int now=c>>1;
        if(c&1) now+=1;
        bool add=false;
        int num1=0,num2=0,num3=0;
        for(int i=1;i<=r;i++){
            num1+=now;
            if(i==1||i==r){
                num3+=c-now;
            }
            else if(!(i&1)) num3+=2;
            
            if(!add) now--,add=true;
            else now++,add=false;
        }
        if(!(r&1)) num2=2,num3-=2;
        int ans=0;
        printf("r=%d c=%d n=%d num1=%d num2=%d num3=%d\n",r,c,n,num1,num2,num3);
        if(n>num1){
            n-=num1;
            if(n<=num2) ans+=n*2;
            else{
                n-=num2;
                ans+=num2*2;
                if(n<=num3) ans+=n*3;
                else{
                    n-=num3;
                    ans+=num3*3;
                    ans+=n*4;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

























