#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        //CHECK if with or without endline!!!
        printf("Case #%d: ", kras);
        int n;
        scanf("%d", &n);
        vector<string> first_words(n);
        vector<string> second_words(n);
        for(int i=0; i<n; i++)
        {
            cin >> first_words[i] >> second_words[i];
        }

        int ans=0;
        for(int bitmask=0; bitmask<(1LL<<n); bitmask++)
        {
            set<string> eerste_set;
            set<string> tweede_set;
            set< pair<string, string> > total;
            int vervalst=0;
            for(int i=0; i<n; i++)
            {
                if((1LL<<i)&bitmask)
                {
                    vervalst++;
                }
                else
                {
                    eerste_set.insert(first_words[i]);
                    tweede_set.insert(second_words[i]);
                    total.insert(make_pair(first_words[i], second_words[i]));
                }
            }

            bool can=true;
            for(int i=0; i<n; i++)
            {
                if((1LL<<i)&bitmask)
                {
                    if(!(eerste_set.find(first_words[i]) != eerste_set.end() && tweede_set.find(second_words[i]) != tweede_set.end() && total.find(make_pair(first_words[i], second_words[i])) == total.end()))
                    {
                        can = false;
                        break;
                    }
                }
            }
            if(can)
            {
                ans = max(ans, vervalst);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
