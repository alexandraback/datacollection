#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <set>
#include <queue>

#define mp make_pair
#define ll long long
#define pb push_back

using namespace std;

int main() {
    
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    int cnt[10];
    
    string s1 = "ZWXGSHVFIO";
    
    
    
    for (int i1 = 0; i1 < n; i1++) {
        string s;
        cin >> s;
        
        for (int i = 0; i < 10; i++)
        cnt[i] = 0;
                
        for (int j = 0; j < s.length(); j++)
            for (int k = 0; k < 10; k++)
                if (s[j] == s1[k])
                    {
                    cnt[k]++;
                    }
        
        vector <char> ans;
        
        for (int i = 0; i < cnt[0]; i++) {
            ans.pb('0');
            cnt[9] --;
        }
        
        for (int i = 0; i < cnt[1]; i++) {
            ans.pb('2');
            cnt[9] --;
        }
        
        for (int i = 0; i < cnt[2]; i++) {
            ans.pb('6');
            cnt[4] --;
            cnt[8] --;
        }
        for (int i = 0; i < cnt[3]; i++) {
            ans.pb('8');
            cnt[5] --;
            cnt[8] --;
        }
        for (int i = 0; i < cnt[4]; i++) {
            ans.pb('7');
            cnt[6] --;            
        }
        for (int i = 0; i < cnt[5]; i++) {
            ans.pb('3');
             
        }
        for (int i = 0; i < cnt[6]; i++) {
            ans.pb('5');
            cnt[7] --;            
            cnt[8] --;            
        }
        for (int i = 0; i < cnt[7]; i++) {
            ans.pb('4');
            cnt[9] --;                        
        }
        for (int i = 0; i < cnt[8]; i++) {
            ans.pb('9');
            
        }
        for (int i = 0; i < cnt[9]; i++) {
            ans.pb('1');
            
        }
        
        sort(ans.begin(),ans.end());
        cout << "Case #" << i1+1 << ": ";
        for (int i = 0; i < ans.size(); i++)        
            cout << ans[i];
         cout << "\n";
            
    }
    
    
    
    return 0;
}