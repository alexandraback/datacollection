#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<string,char> P;
int a[26];
P mp[10] = {{"ZERO",'Z'},{"TWO",'W'},{"FOUR",'U'},{"SIX",'X'},{"EIGHT",'G'},
 {"ONE",'O'}, {"THREE",'R'} ,{"FIVE",'F'},{"SEVEN",'S'} ,{"NINE",'E'}};

void solve()
{
    int T,cnt = 0;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        memset(a,0,sizeof a);
        for(int i = 0; i < s.length(); ++i)
        {
            a[s[i] - 'A']++;
        }
        vector<int> vec;
        for(int i = 0; i < 10; ++i)
        {
            int tp = (i < 5) ? i * 2 : (i - 4) * 2 - 1;
            int c = mp[i].second - 'A';
            while(a[c])
            {
                vec.push_back(tp);
                string c = mp[i].first;
                for(int j = 0; j < c.length(); ++j)
                {
                    a[c[j] - 'A']--;
                }
            }
        }
        sort(vec.begin(),vec.end());
        printf("Case #%d: ",++cnt);
        for(int i = 0; i < vec.size(); ++i)
            printf("%d",vec[i]);
        puts("");
    }
}

int main() {
    freopen("in","r",stdin);
    freopen("A.out","w",stdout);
    solve();
    return 0;
}
