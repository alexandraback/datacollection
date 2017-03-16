#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        int N;
        cin >> N;
        vector<double> s(N);
        double X = 0;
        vector<double> m(N, -1);
        for(int i=0;i<N;i++){
                cin >> s[i];
                X += s[i];
        }
        
        cout << "Case #" << t << ": ";
        bool negativos = 1;
        double compX = X;
        int compN = N;
        while(negativos){
            negativos = 0;
            for(int i=0;i<N;i++) if(m[i] != 0){
                m[i] = ((X+compX-s[i])/(compN-1)-s[i]) / (X+X/(compN-1))*100;
                if(m[i] < 0){
                        negativos = 1;
                        compX -= s[i];
                        m[i] = 0;
                        compN--;
                }
            }
        }
        for(int i=0;i<N;i++)
                cout << fixed << setprecision(8) << m[i] << ((i!=N-1)?" ":"");
        cout << endl;
    }
}
