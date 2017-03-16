#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int casos;
    cin >> casos;
    for(int caso = 1 ; caso <= casos ; caso++){
        int A, B, K;
        cin >> A >> B >> K;
        int c = 0;
        for(int i = 0 ; i < A ; i++){
            for(int j = 0 ; j < B ; j++){
                int x = i&j;
                if(x < K){
                    c++;
                }
            }
        }
        cout << "Case #" << caso <<": "<< c << endl;
    }
    return 0;
}
