#include <cstdio>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int N,n,ss,fri;
    char c;
    int s[1100];
    scanf("%d",&N);
    for(int k=1;k<=N;k++){
        scanf("%d ",&n);
        for(int i=0;i<=n;i++){
            scanf("%c",&c);
            s[i]=c-'0';
        }
        ss=0;
        fri=0;
        for(int i=1;i<=n;i++){
            ss+=s[i-1];
            if(i>ss){
                fri+=i-ss;
                ss=i;
            }
        }
        printf("Case #%d: %d\n",k,fri);
    }
    return 0;
}
