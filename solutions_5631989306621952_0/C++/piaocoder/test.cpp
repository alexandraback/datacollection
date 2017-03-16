#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t = 1;
    scanf("%d",&T);
    while(T--){
        string str,ans = "",tmp;
        cin>>str;
        int len = str.size();
        ans += str[0];
        for(int i = 1; i < len; ++i){
            if(str[i] >= ans[0]){
                tmp = ans;
                ans = "";
                ans = ans + str[i] + tmp;
            }
            else
                ans += str[i];
        }
        printf("Case #%d: ",t++);
        cout<<ans<<endl;
    }
    return 0;
}
