#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int TC;
    
    cin >> TC;
    
    int N;
    bool ok;
    char c[50];
    int S[50],P[50],a,b;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> N;
        
        for(int i = 0;i < N;++i)
            cin >> c[i] >> S[i] >> P[i];
        
        ok = true;
        double ans = -1;
        
        for(int i = 0;i < N;++i){
            for(int j = i + 1;j < N;++j){
                for(int k = 0;k < N;++k){
                    if(k == i || k == j) continue;
                    
                    if((S[k] >= S[i] && S[k] >= S[j]) && (S[k] > S[i] || S[k] > S[j]) && P[k] + 5 <= max(P[i],P[j])){
                        //cout << i << " " << j << " " << k << endl;
                        double t = 0;
                        
                        if(S[k] > S[i]){
                            double t2 = (P[i] - P[k] - 5.0) / (S[k] - S[i]);
                            
                            if(t2 > t){
                                t = t2;
                                a = i;
                                b = j;
                            }
                        }
                        
                        if(S[k] > S[j]){
                            double t2 = (P[j] - P[k] - 5.0) / (S[k] - S[j]);
                            
                            if(t2 > t){
                                t = t2;
                                a = j;
                                b = i;
                            }
                        }
                        
                        double pi = P[i] + t * S[i];
                        double pj = P[j] + t * S[j];
                        
                        if(S[i] > S[j]){
                            b = i;
                            a = j;
                        }else{
                            b = j;
                            a = i;
                        }
                        /*cout << pi << " " << pj << endl;
                        cout << "a = " << a << ", b = " << b << endl;
                        cout << S[k] << " " << S[b] << endl;*/
                        if(S[b] == S[k] && P[b] < P[k]) continue;
                        
                        if(abs(pi - pj) < 5 || (S[a] < S[b] && (S[k] == S[b] || (S[k] > S[b]  && (double)(P[a] - P[b] - 5)/ (S[b] - S[a]) < (double)(P[b] + 5 - P[k]) / (S[k] - S[b]))))){
                            if(ok) ans = t;
                            else ans = min(ans,t);
                            //cout << i << " " << j << " " << k << " " << t << endl;
                            ok = false;
                        }
                    }
                }
            }
        }
        
        cout << "Case #" << tc << ": ";
        
        if(ok) cout << "Possible";
        else cout << fixed << setprecision(6) << ans;
        
        cout << '\n';
    }
    
    return 0;
}
