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
int p10[10];
int main(){
    int t,cas=1,i,j;
    p10[0]=1;
    for(i=1;i<10;i++)p10[i]=p10[i-1]*10;
    scanf("%d",&t);
    while(t--){
        int a,b,c=0,l=0;
        scanf("%d%d",&a,&b);
        while(a>=p10[l])l++;
        for(i=a;i<=b;i++){
            set<int> x;
            for(j=1;j<l;j++){
                int r=i/p10[j]+(i%p10[j])*p10[l-j];
                if(r>i&&r<=b&&x.find(r)==x.end()){
                    x.insert(r);
                    c++;
                }
            }
        }
        printf("Case #%d: %d\n",cas++,c);
    }
}

