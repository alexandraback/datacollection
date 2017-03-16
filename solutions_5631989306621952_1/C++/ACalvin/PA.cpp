#include<cstdio>
#include<cstring>
using namespace std;
const int N = 10005;
char s[N];
char res[N];
void solve(){
    scanf("%s",s);
    int pre = -1;
    int l,r;
    l = r = 5000;
    l --;
    for(int i = 0 ;  s[i] != '\0' ; i ++){
        if(s[i] >= pre){
            res[l --] = s[i];
            pre = s[i];
        }
        else{
            res[r ++] = s[i];
        }
    }
    l ++;
    res[r] = '\0';
    printf("%s\n",res + l);
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int _,txt = 1;
    scanf("%d",&_);
    while(_--){
        printf("Case #%d: ",txt ++);
        solve();
    }
    return 0;
}
