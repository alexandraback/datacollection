#include <iostream>
using namespace std;

int T, N;

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> N;
        int A = 0, U = 0;
        char c;

        for(int s=0; s<=N; s++){
            cin >> c;
               
            if(c > '0' && U < s){
                A += s - U;
                U = s;
            }

            U += c-'0';
        }

        cout << "Case #" << t << ": " << A << "\n";
    }
}
