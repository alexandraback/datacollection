#include <bits/stdc++.h>

using namespace std;
int cnt[26];
int main()
{
   freopen("lol.in","r",stdin);
   freopen("lol.out","w",stdout);
    int t;
    cin >> t ;
    for(int tt = 1 ; tt <= t ; tt++){
        memset(cnt,0,sizeof cnt);
        string s;
        cin >> s ;
        for(int i = 0 ;i < s.size() ; i++)
            cnt[s[i] - 'A']++;//
        vector<int> ans ;
        for(int i = 0 ;i < cnt[25] ; i++)
           {
               ans.push_back(0);
               cnt['E'-'A']--;
               cnt['R'-'A']--;
               cnt['O'-'A']--;
           }
        cnt[25] = 0 ;
           for(int i = 0 ;i < cnt[23] ; i++)
           {
               ans.push_back(6);
               cnt['S'-'A']--;
               cnt['I'-'A']--;
           }
        cnt[23] = 0 ;
           for(int i = 0 ;i < cnt['S'-'A'] ; i++)
           {
               ans.push_back(7);//gsdfgdssd
               cnt['E'-'A']--;
               cnt['V'-'A']--;//
               cnt['E'-'A']--;
               cnt['N'-'A']--;
           }
        cnt['S'-'A'] = 0 ;
         for(int i = 0 ;i < cnt['V'-'A'] ; i++)
           {
               ans.push_back(5);
               cnt['F'-'A']--;
               cnt['I'-'A']--;
               cnt['E'-'A']--;
           }
        cnt['V'-'A'] = 0 ;
        for(int i = 0 ;i < cnt['F'-'A'] ; i++)
           {
               ans.push_back(4);
               cnt['O'-'A']--;
               cnt['U'-'A']--;
               cnt['R'-'A']--;//gsdfgsd
           }
        cnt['F'-'A'] = 0 ;
        for(int i = 0 ;i < cnt['W'-'A'] ; i++)
           {
               ans.push_back(2);
               cnt['T'-'A']--;//gxdfgds
               cnt['O'-'A']--;
           }
        cnt['W'-'A'] = 0 ;
             for(int i = 0 ;i < cnt['R'-'A'] ; i++)
           {
               ans.push_back(3);
               cnt['T'-'A']--;
               cnt['H'-'A']--;
               cnt['E'-'A']--;
               cnt['E'-'A']--;//
           }
        cnt['R'-'A'] = 0 ;
             for(int i = 0 ;i < cnt['H'-'A'] ; i++)
           {
               ans.push_back(8);
               cnt['E'-'A']--;
               cnt['I'-'A']--;
               cnt['G'-'A']--;
               cnt['T'-'A']--;
           }
        cnt['H'-'A'] = 0 ;
          for(int i = 0 ;i < cnt['O'-'A'] ; i++)
           {
               ans.push_back(1);
               cnt['N'-'A']--;
               cnt['E'-'A']--;
           }//
        cnt['O'-'A'] = 0 ;
          for(int i = 0 ;i < cnt['I'-'A'] ; i++)
            ans.push_back(9);
//

      sort(ans.begin(),ans.end());
      cout << "Case #" << tt << ": " ;
      for(int i = 0 ; i < ans.size(); i++)//
        cout << ans[i];

      cout << endl ;



    }
    return 0;
}
