#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000
char letter[10] = {'Z', 'W', 'U', 'X' , 'G', 'O', 'S', 'V', 'N', 'T'};
int digit[10] = {0, 2, 4, 6, 8, 1, 7, 5, 9, 3};
string words[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int main () {
    ios_base::sync_with_stdio(false);
    freopen("C:\\in.txt","r", stdin);
    //freopen("C:\\GCJ_2016_b\\out.txt","w", stdout);
    int TC;
    cin >> TC;
    int cas = 1;
    while(TC--){
        int arr[26];
        memset(arr, 0, sizeof(arr));
        string s;
        cin >> s;
        for(int i=0; i<s.size(); ++i){
            arr[s[i] -'A' ]++;
        }
        vector<int> res;
        for(int i=0; i<10; ++i){
            int le = letter[i] - 'A';
            int di = digit[i];
            while(arr[le]){
                for(int k =0; k<words[di].size(); ++k){
                    arr[words[di][k]- 'A' ]--;
                }
                res.push_back(di);
            }
        }
        sort(res.begin(), res.end());
        cout << "Case #" << cas++ << ": ";
        for(int i=0; i<res.size(); ++i){
            cout << res[i];
        }
        cout << endl;

    }
    return 0;
}
