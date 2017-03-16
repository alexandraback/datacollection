#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    int *F;
    for(int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        int N, S, p;
        cin >> N >> S >> p;
        F = new int[N];
        for(int i=0; i<N; i++){
            cin >> F[i];
        }
        int sum=0;
        int min1;
        if(p == 0) min1 = -1;
        else if(p==1) min1 = 0;
        else min1 = 3*(p-1);
        int min2;
        if(p == 0) min2 = -1;
        else if(p==1) min2 = 0;
        else if(p==2) min2 = 1;
        else min2 = 3*p-5;
        for(int i=0; i<N; i++){
            if(F[i] > min1) sum++;
            else if(S>0 && F[i] > min2){
                sum++;
                S--;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}

