#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;



int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        string pancakes;
        cin >> pancakes;
        pancakes += '+';
        
        int ans = 0;
        for(int i=0;i+1<pancakes.length();i++){
            if(pancakes[i]!=pancakes[i+1]) ans++;
        }
        cout << "Case #" << t << ": " << ans << endl;    
    }

    return 0;
}