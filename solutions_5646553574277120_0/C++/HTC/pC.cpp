#include <iostream>
using namespace std;
long long data[105];
int main(){
    long long C;
    int T,D,V,ans,k;
    long long nowMAX=0;
    cin >> T;
    for(int ca=1;ca<=T;ca++){
        cin >> C >> D >> V;
        for(int i=0;i<D;i++){
            cin >> data[i];
        }
        k = 0;
        ans = 0;
        if(data[0] != 1){
            ans = 1;
        }else{
            k = 1;
        }
        nowMAX = C;

        while(nowMAX < V){
                //cout <<"nowMAX: "<< nowMAX <<"\n";
            if(k < D){
                if(nowMAX+1 >= data[k]){
                    nowMAX = nowMAX + C*data[k];
                    k++;
                }else{
                    nowMAX = nowMAX + (nowMAX+1) * C;
                    ans++;
                }
            }else{
                nowMAX = nowMAX + (nowMAX+1) * C;
                ans++;
            }
        }
        cout << "Case #" << ca << ": " << ans <<"\n";
    }
    return 0;
}
