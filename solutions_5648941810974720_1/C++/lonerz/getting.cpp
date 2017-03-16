#include <bits/stdc++.h>
using namespace std;

int cnt[26];
map<string,int>m;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("Aans1.out","w",stdout);
    int t;
    cin >> t;
    m["ZERO"]=0, m["ONE"]=1, m["TWO"]=2, m["THREE"]=3, m["FOUR"]=4, m["FIVE"]=5, m["SIX"]=6, m["SEVEN"]=7, m["EIGHT"]=8, m["NINE"]=9;
    for(int IN=0; IN<t; ++IN){
        string a;
        cin >> a;
        vector<char>l;
        for(int i=0; i<a.size(); ++i) l.push_back(a[i]);
        sort(l.begin(),l.end());
        for(int i=0; i<l.size(); ++i) cnt[l[i]-'A']++;
        string ans="";
        if(cnt[25]){
            while(cnt[25]){
                --cnt[25];
                --cnt['E'-'A'];
                --cnt['R'-'A'];
                --cnt['O'-'A'];
                ans += m["ZERO"]+'0';
            }
        }
        if(cnt['W'-'A']){
            while(cnt['W'-'A']){
                --cnt['W'-'A'];
                --cnt['T'-'A'];
                --cnt['O'-'A'];
                ans += 2+'0';
            }
        }
        if(cnt['X'-'A']){
            while(cnt['X'-'A']){
                --cnt['X'-'A'];
                --cnt['I'-'A'];
                --cnt['S'-'A'];
                ans += 6+'0';
            }
        }
        if(cnt['U'-'A']){
            while(cnt['U'-'A']){
                --cnt['U'-'A'];
                --cnt['F'-'A'];
                --cnt['O'-'A'];
                --cnt['R'-'A'];
                ans += 4+'0';
            }
        }
        if(cnt['G'-'A']){
            while(cnt['G'-'A']){
                --cnt['G'-'A'];
                --cnt['E'-'A'];
                --cnt['I'-'A'];
                --cnt['H'-'A'];
                --cnt['T'-'A'];
                ans += 8+'0';
            }
        }
        if(cnt['F'-'A']){
            while(cnt['F'-'A']){
                --cnt['F'-'A'];
                --cnt['I'-'A'];
                --cnt['V'-'A'];
                --cnt['E'-'A'];
                ans += 5+'0';
            }
        }
        if(cnt['I'-'A']){
            while(cnt['I'-'A']){
                --cnt['N'-'A'];
                --cnt['I'-'A'];
                --cnt['N'-'A'];
                --cnt['E'-'A'];
                ans += 9+'0';
            }
        }
        if(cnt['V'-'A']){
            while(cnt['V'-'A']){
                --cnt['S'-'A'];
                --cnt['E'-'A'];
                --cnt['V'-'A'];
                --cnt['E'-'A'];
                --cnt['N'-'A'];
                ans += 7+'0';
            }
        }
        if(cnt['O'-'A']){
            while(cnt['O'-'A']){
                --cnt['O'-'A'];
                --cnt['N'-'A'];
                --cnt['E'-'A'];
                ans += 1+'0';
            }
        }
        if(cnt['T'-'A']){
            while(cnt['T'-'A']){
                --cnt['T'-'A'];
                --cnt['H'-'A'];
                --cnt['R'-'A'];
                --cnt['E'-'A'];
                --cnt['E'-'A'];
                ans += 3+'0';
            }
        }
        sort(ans.begin(),ans.end());
        cout << "Case #" << IN+1 << ": " << ans << endl;
    }
}
