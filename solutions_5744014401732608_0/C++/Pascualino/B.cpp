#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int, PII> PIII;
typedef pair<PII, PII> PIIII;

#define x first
#define y second

int main(){
    int T;
    cin >> T;
    long pow2[64];
    pow2[0] = 1;
    for(int i=1;i<64;i++) pow2[i] = pow2[i-1]*2;
    for(int t=1;t<=T;t++){
        int B, M;
        cin >> B >> M;

        cout << "Case #" << t << ": ";

        if(M > pow2[B-2]){
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            for(int i=0;i<B;i++){
                bool all = i == 0 || M > pow2[i-1];
                if(all) M -= (i == 0 ? 1 : pow2[i-1]);
                bool line[B];
                for(int j=B-1;j>=0;j--){
                    if(i == B-1){
                        line[j] = 0;
                    }
                    else if(i == 0){
                        line[j] = (j != 0 ? 1 : 0);
                    } else if(all){
                        if(j != 0 && (j == B-1 || j < i)){
                            line[j] = 1;
                        } else {
                            line[j] = 0;
                        }
                    } else {
                        if(j != 0 && (j < i && M > pow2[j-1])){
                            line[j] = 1;
                            M -= pow2[j-1];
                        } else {
                            line[j] = 0;
                        }
                    }
                }
                if(!all && M == 1){
                   line[B-1] = 1;
                   M--;
                }
                for(int j=0;j<B;j++){
                    cout << line[j];
                }
                cout << endl;
            }
        }



    }
}
