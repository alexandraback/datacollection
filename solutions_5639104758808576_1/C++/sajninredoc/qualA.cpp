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
        int SM;
        cin >> SM;
        string s;
        cin >> s;
        vector<int> aud(SM+1, 0);
        for(int i=0;i<=SM;i++) aud[i] = s[i]-'0';
        
        int total = 0;
        int deficit = 0;
        for(int i=0;i<=SM;i++){
            if(i>total){
                deficit = max(deficit, i-total);
            }
            total += aud[i];
        } 
        
        cout << "Case #" << t << ": " << deficit << endl;    
    }

    return 0;
}