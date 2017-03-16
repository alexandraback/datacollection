#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int n,s,p;
        scanf("%d%d%d",&n,&s,&p);
        int cnt=0,c2=0;
        while(n--){
            int a;
            scanf("%d",&a);
            if(a%3==0){
                a/=3;
                if(a>=p)cnt++;
                else if(a-1>=0&&a+1<=10&&a+1>=p)c2++;
            }else if(a%3==1){
                a/=3;
                if(a+1<=10&&a+1>=p)cnt++;
            }else{
                a/=3;
                if(a+1<=10&&a+1>=p)cnt++;
                else if(a+2<=10&&a+2>=p)c2++;
            }
        }
        printf("Case #%d: %d\n",cas++,cnt+min(c2,s));
    }
}

