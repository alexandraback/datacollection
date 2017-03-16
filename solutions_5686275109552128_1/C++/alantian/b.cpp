#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sp_time(int a, int b){
    int r;
    if ( a % b == 0 )
        r = a / b;
    else
        r = a / b + 1;
    return r-1;
}

int solve(int N, vector<int> P){
    int max_v = *max_element(P.begin(),P.end());
    int answer = max_v;

    for( int eat_time = 1; eat_time < max_v; eat_time++ ){
        int split_time = 0;
        for( auto v:P )
            split_time += sp_time(v,eat_time);
        answer = min(answer, split_time + eat_time);
    }

    return answer;
}

int main(){
    int T;
    cin >> T;

    for( int C = 1; C <= T; C++ ){
        int N;
        cin >> N;

        vector<int> P = vector<int>(N,0);
        for( int i = 0; i < N; i++ )
            cin >> P[i];

        int answer = solve(N, P);

        cout << "Case #" << C << ": " << answer << endl;
    }
    return 0;
}
