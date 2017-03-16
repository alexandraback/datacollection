#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define S(a) scanf("%d",&(a))
#define P(a) printf("%d",(a))
using namespace std;
int main(){
    int tc,cs=1,mt,n,c,BT;
    S(tc);
    while(tc--){
        c=0;
        S(mt);S(n);
        BT=mt;
        int a[n];
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(BT<=a[i]){
                if(BT+BT-1>a[i])
                    BT+=BT-1+a[i];
                c++;
            }
            else
                BT+=a[i];
        }
        printf("Case #%d: %d\n",cs++,c);
    }
}
