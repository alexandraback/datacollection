#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <cmath>
#include <numeric>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <queue>
#include <stack>
#include <list>
using namespace std;

string alphabet[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int layer[3][5] = { {2,6,0,8,4},
                    {5,9,7,3,-1} ,
                    {1,-1,-1,-1,-1} };
char signature[] = "ZNWHUFXSGI";
int T;
int cnt[26];


int main() {
    int cases = 1;
    cin >> T;
    while( T-- ) {
        string s;
        cin >> s;
        
        memset(cnt,0,sizeof(cnt));
        for(size_t i = 0 ; i < s.size();i++  ) {
            cnt[s[i]-'A']++;
        }
        
        //for(int i = 0 ; i < 26; i++ ){
        //    cout << char('A'+i) << ":" <<  cnt[i] << endl;
        //}
        
        vector<int> ans;
        for(int i = 0 ; i < 3; i++ ) {
            for(int j = 0 ; layer[i][j] >= 0 ; j++ ) {
                int nowCheck = layer[i][j];
                //cout << "nowCheck: " << nowCheck << endl;
                //cout << "count: " <<cnt[signature[nowCheck]-'A'] << endl;
                for(int k = 0 ; k < cnt[signature[nowCheck]-'A'] ; k++ ) {
                    ans.push_back(nowCheck);
                }
                int minuscnt = cnt[signature[nowCheck]-'A'];
                for(int k = 0 ; k < alphabet[nowCheck].size(); k++ ) {
                    //cout << "minus: " << int(alphabet[nowCheck][k]-'A') << endl;
                    cnt[alphabet[nowCheck][k]-'A'] -= minuscnt;
                }
                //for(int k = 0 ; k < 26; k++ ){
                //    cout << char('A'+k) << ":" <<  cnt[k] << endl;
                //}
                //getchar();
            }
        }
        sort(ans.begin(),ans.end());
        cout << "Case #" << cases++ << ": ";
        for(int i = 0 ; i < ans.size();i++ ) cout << ans[i];
        cout << endl;
    }
    return 0;
}