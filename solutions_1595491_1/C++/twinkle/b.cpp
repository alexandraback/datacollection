#include <iostream>
using namespace std;

int main(){
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    int T,n,s,p,ans,tmp,Case = 0;
    cin >> T;
    while(T --){
        cin >> n >> s >> p ;
        ans = 0;
        for(int i = 1;i <= n; i ++){
            cin >> tmp;
            if(tmp == 0 && p > 0)continue;
            if(tmp == 1 && p > 1)continue;
            if(p*3 - tmp <= 2)
                ans ++;
            else
                if(p*3 - tmp <= 4 && s > 0){
                    s --;
                    ans ++;
                }
        }
        cout <<"Case #"<<++Case<< ": "<<ans << endl;

    }
    return 0;
}
