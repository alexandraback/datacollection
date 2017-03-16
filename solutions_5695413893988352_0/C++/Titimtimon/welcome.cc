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

    long long n;
    cin >> n;
    
    long long cnt[10];
    
    string s1 = "ZWXGSHVFIO";
    
    
    
    for (long long i1 = 0; i1 < n; i1++) {
        string s1,s2;
        cin >> s1 >> s2;
        
        pair <long long,long long> ans[3];
        
        for (long long j = 0; j < 3; j++)
            ans[j] = mp(-1,-1);
        ans[0] = mp(0,0);
        
        for (long long j = 0; j < s1.length(); j++) {
            
                    pair <long long,long long> ans2[3];

        for (long long j = 0; j < 3; j++)
            ans2[j] = mp(-1,-1);
            
            for (long long k = '0'; k <= '9'; k++)
                if (s1[j] == '?' || s1[j] == k)
                for (long long l = '0'; l <= '9'; l++)
                    if (s2[j] == '?' || s2[j] == l)
                        for (long long x = 0; x < 3; x++) 
                            if (ans[x].first != -1)
                            {
                                long long x1 = ans[x].first;
                                long long x2 = ans[x].second;
                                
                                
                                x1 = x1*10+k-'0';
                                x2 = x2*10+l-'0';
//                                cout << j << " " << x1 << " " << x2 << "!\n";
//                                cout << ans2[1].first << " " << ans2[1].second << "\n";
                                if (x1 == x2) {                                    
                                    if (ans2[0].first == -1 || abs(ans2[0].first-ans2[0].second) > abs(x1-x2)
                                            || (abs(ans2[0].first-ans2[0].second) == abs(x1-x2))&&(ans2[0].first > x1)
                                            || (abs(ans2[0].first-ans2[0].second) == abs(x1-x2))&&(ans2[0].first == x1)&&(ans2[0].second > x2)
                                            )
                                        ans2[0] = mp(x1,x2);
                                }
                                if (x1 > x2) {
                                    if (ans2[1].first == -1 || abs(ans2[1].first-ans2[1].second) > abs(x1-x2)
                                            || (abs(ans2[1].first-ans2[1].second) == abs(x1-x2))&&(ans2[1].first > x1)
                                            || (abs(ans2[1].first-ans2[1].second) == abs(x1-x2))&&(ans2[1].first == x1)&&(ans2[1].second > x2)
                                            )
                                        ans2[1] = mp(x1,x2);
                                }
                                if (x1 < x2) {
                                    if (ans2[2].first == -1 || abs(ans2[2].first-ans2[2].second) > abs(x1-x2)
                                            || (abs(ans2[2].first-ans2[2].second) == abs(x1-x2))&&(ans2[2].first > x1)
                                            || (abs(ans2[2].first-ans2[2].second) == abs(x1-x2))&&(ans2[2].first == x1)&&(ans2[2].second > x2)
                                            )
                                        ans2[2] = mp(x1,x2);
                                }
                                
//                                cout << ans2[1].first << " " << ans2[1].second << "\n";
                                
                                
                               
                        
                            }
                    
                     for (long long j = 0; j < 3; j++) {
                                    ans[j] = ans2[j];
//                                    cout << ans[j].first << " " << ans[j].second << "\n";
                     }
//                    cout << "---------\n";
                        
                                

                    
        }
        
        
                                pair <long long,long long> real_ans = mp(-1,-1);
                                
                                
                                for (long long j = 0; j < 3; j++) 
                                    if (ans[j].first != -1)
                                    if (real_ans.first == -1 ||
                                        abs(real_ans.first-real_ans.second) > abs(ans[j].first-ans[j].second) ||
                                            (abs(real_ans.first-real_ans.second) == abs(ans[j].first-ans[j].second) && real_ans.first > ans[j].first) ||
                                            (abs(real_ans.first-real_ans.second) == abs(ans[j].first-ans[j].second) && real_ans.first == ans[j].first && real_ans.second > ans[j].second)
                                    )
                                        real_ans = ans[j];
                                
                                
                                    pair <long long, long long> ra = real_ans;
                                
                                string x1 = "";
                                long long cnt = 0;
                                while (real_ans.first > 0) {
                                    char ch = '0';
//                                    char ch = (char)(real_ans.first%10)-'0';
                                    ch += real_ans.first % 10;
                                    real_ans.first /= 10;
                                    cnt++;
                                    x1 = ch+x1;
                                }
                                for (long long j = 0; j < s1.length()-cnt; j++)
                                    x1 = '0'+x1;
                                
                                string x2 = "";
                                cnt = 0;
                                while (real_ans.second > 0) {
                                    char ch = '0';
//                                    char ch = (char)(real_ans.first%10)-'0';
                                    ch += real_ans.second % 10;
                                    real_ans.second /= 10;
                                    cnt++;
                                    x2 = ch+x2;
                                }
                                for (long long j = 0; j < s1.length()-cnt; j++)
                                    x2 = '0'+x2;
                                cout << "Case #" << i1+1 << ": " << x1 << " " << x2 << "\n";
                                
//                                int res = abs(ra.first-ra.second);
//                                
//                                if (s1.length() == 3) {
//                                    for (int i = 0; i <= 999; i++)
//                                        
//                                            if ((i/100 == s1[0]-'0' || s1[0] == '?')&&
//                                                    (i/10%10 == s1[1]-'0' || s1[1] == '?')
//                                                    &&
//                                                    (i%10 == s1[2]-'0' || s1[2] == '?')
//                                                    ) 
//                                                
//                                                for (int j = 0; j <= 999; j++)
//                                                    if ((j/100 == s2[0]-'0' || s2[0] == '?')&&
//                                                    (j/10%10 == s2[1]-'0' || s2[1] == '?')
//                                                    &&
//                                                    (j%10 == s2[2]-'0' || s2[2] == '?')
//                                                    ) 
//                                                        if (res == abs(i-j)
//                                                        && ra.first > i
//                                                                
//                                                                )
//                                                cout << i << " " << j << " || " << ra.first << " " << ra.second << "!\n";
//                                }
                               
        
        
        
    }
    
    
    
    return 0;
}