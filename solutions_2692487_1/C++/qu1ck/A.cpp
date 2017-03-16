#include <cstdio>
#include <algorithm>


using namespace std;

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int ncase;
    scanf("%d",&ncase);
    for(int C=1;C<=ncase;C++){
        int a,n;
        scanf("%d%d",&a,&n);
        int b[101];
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        sort(b,b+n);
        int ans=n;
        if(a==1){
            ans=n;
        }else{
            for(int cut=0;cut<ans;cut++){
                int s=a;
                int c=0;
                for(int i=0;i<n-cut;i++){
                    while(s<=b[i]){
                        s+=s-1;
                        c++;
                    }
                    s+=b[i];
                }
                if(ans>cut+c)ans=cut+c;
            }
        }
        printf("Case #%d: %d\n",C,ans);
    }
    return 0;
}