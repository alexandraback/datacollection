#include <iostream>
using namespace std;

typedef long long ll;

int T, C, D, V;
ll cv[128];

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> C >> D >> V;

        for(int i=0; i<D; i++)
            cin >> cv[i];
        sort(cv, cv+D);

        int ans = 0;
        ll cur = 0;
        for(int i=0; cur<V;){
            if(i<D && cv[i] <= cur+1){
                cur += C * cv[i];
                i++;
            }
            else{
                cur += C * (cur+1);
                ans++;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

}
