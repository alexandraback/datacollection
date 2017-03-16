#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    int sl;
    char S[1005];
    string res;
    scanf("%d\n",&T);
    for(int t=1;t<=T;t++){
        scanf("%s",S);
        sl=strlen(S);
        res=S[0];
        for(int i=1;i<sl;i++){
            if(res[0]>S[i]) res+=S[i];
            else res=S[i]+res;
        }
        printf("Case #%d: %s\n",t,res.c_str());
    }
    return 0;
}
