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
        vector<int> freq(2501, 0);
        int N;
        cin >> N;
        
        for(int i=0;i<(2*N-1)*N;i++){
            int x;
            cin >> x;
            freq[x]++;
        }
        
        
        vector<int> ans;
        for(int i=1;i<=2500;i++) if(freq[i]%2==1) ans.push_back(i);
        cout << "Case #" << t << ":";
        for(int i=0;i<ans.size();i++) cout << " " << ans[i];
        cout << endl;
    }

    return 0;
}