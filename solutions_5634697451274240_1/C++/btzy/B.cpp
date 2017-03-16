#include <cstdio>
#include <cstring>
using namespace std;
int t;
char s[200];
int main(){
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf(" ");
        scanf("%s",s);
        int n=strlen(s);
        bool l=true;
        int c=0;
        for(--n;n>=0;--n){
            bool k=(s[n]=='+');
            if(l^k){
                ++c;
                l=k;
            }
        }
        printf("Case #%d: %d\n",i+1,c);
    }
}

