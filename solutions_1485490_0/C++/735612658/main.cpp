#include <iostream>
#include<set>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include<map>
using namespace std;
typedef long long ll;
inline ll min(ll a, ll b){return a < b? a: b;}
const int size = 110;
struct DPNode
{
    ll ans, toyid, toynum, boxid, boxnum;
}dp[size][size];

struct DATA
{
    ll id, num;
}toy[size], box[size];

int tn, bn;

void getans()
{
    if(toy[0].id == box[0].id)
    {
        dp[0][0].ans = min(toy[0].num , box[0].num);
        dp[0][0].toyid = toy[0].id;
        dp[0][0].boxid = box[0].id;
        dp[0][0].toynum = toy[0].num - dp[0][0].ans;
        dp[0][0].boxnum = box[0].num - dp[0][0].ans;
     }
        else
                {
                    dp[0][0].ans = 0;
                    dp[0][0].toyid = toy[0].id;
                    dp[0][0].boxid = box[0].id;
                    dp[0][0].toynum = toy[0].num - dp[0][0].ans;
                    dp[0][0].boxnum = box[0].num - dp[0][0].ans;
                }


    for(int t = 1; t < tn; t++)
    {
        dp[t][0].ans = dp[t-1][0].ans;
        ll tmp = 0;
        if(toy[t].id == dp[t-1][0].boxid)
        {
            tmp = min(toy[t].num, dp[t-1][0].boxnum);
        }

        dp[t][0].ans += tmp;
        dp[t][0].toyid = toy[t].id;
        dp[t][0].toynum = toy[t].num - tmp;
                if(dp[t][0].toyid == dp[t-1][0].toyid)
                    dp[t][0].toynum += dp[t-1][0].toynum;
        dp[t][0].boxid = dp[t-1][0].boxid;
        dp[t][0].boxnum = dp[t-1][0].boxnum - tmp;

    }

    for(int b = 1; b < bn; b++)
    {
        dp[0][b].ans = dp[0][b-1].ans;
        ll tmp = 0;
        if(box[b].id == dp[0][b-1].toyid)
        {
            tmp = min(box[b].num, dp[0][b-1].toynum);
        }

        dp[0][b].ans += tmp;
        dp[0][b].boxid = box[b].id;
        dp[0][b].boxnum = box[b].num - tmp;

                if(dp[0][b].boxid == dp[0][b-1].boxid)
                    dp[0][b].boxnum += dp[0][b-1].boxnum;

        dp[0][b].toyid = dp[0][b-1].toyid;
        dp[0][b].toynum = dp[0][b-1].toynum - tmp;
    }


    for(int t = 1; t < tn; t++)
    {
        for(int b = 1; b < bn; b++)
        {
            dp[t][b].ans = dp[t][b-1].ans;
            ll tmp = 0;
            if(box[b].id == dp[t][b-1].toyid)
            {
                tmp = min(box[b].num, dp[t][b-1].toynum);
            }

            dp[t][b].ans += tmp;
            dp[t][b].boxid = box[b].id;
            dp[t][b].boxnum = box[b].num - tmp;

                if(dp[t][b].boxid == dp[t][b-1].boxid)
                    dp[t][b].boxnum += dp[t][b-1].boxnum;

            dp[t][b].toyid = dp[t][b-1].toyid;
            dp[t][b].toynum = dp[t][b-1].toynum - tmp;
            if(
               (toy[t].id == dp[t-1][b].boxid &&
                 min(toy[t].num , dp[t-1][b].boxnum) + dp[t-1][b].ans > dp[t][b].ans
                ) ||

                 (toy[t].id != box[b].id && dp[t-1][b].ans > dp[t][b].ans   )
               )
               {
                    ll tmp = 0;
                    if(toy[t].id == dp[t-1][b].boxid)
                        tmp = min(toy[t].num , dp[t-1][b].boxnum);


                    dp[t][b].ans = dp[t-1][b].ans + tmp;
                    dp[t][b].boxid = dp[t-1][b].boxid;
                    dp[t][b].boxnum = dp[t-1][b].boxnum - tmp;
                    dp[t][b].toyid = toy[t].id;
                    dp[t][b].toynum = toy[t].num - tmp;

                        if(dp[t][b].toyid == dp[t-1][b].toyid)
                            dp[t][b].toynum += dp[t-1][b].toynum;

               }

            ll Bnum = 0;
            for(int prebox = b; prebox >= 0; prebox --)
            {
                if(  box[prebox].id != toy[t].id )
                    continue;
                if(  min(dp[t-1][prebox].boxnum + Bnum, toy[t].num ) + dp[t-1][prebox].ans > dp[t][b].ans  )
                     {
                        ll tmp = 0;
                        tmp = min(dp[t-1][prebox].boxnum + Bnum, toy[t].num );


                        dp[t][b].ans = dp[t-1][prebox].ans + tmp;
                        dp[t][b].boxid = dp[t-1][prebox].boxid;
                        dp[t][b].boxnum = dp[t-1][prebox].boxnum + Bnum - tmp;
                        dp[t][b].toyid = toy[t].id;
                        dp[t][b].toynum = toy[t].num - tmp;
                            if(dp[t][b].toyid == dp[t-1][prebox].toyid)
                                dp[t][0].toynum += dp[t-1][0].toynum;
                     }
                Bnum += box[prebox].num;
            }


            ll Tnum = 0;
            for(int pretoy = t; pretoy >= 0; pretoy --)
            {
                if(  toy[pretoy].id != box[b].id )
                    continue;
                if(  min(dp[pretoy][b-1].toynum + Tnum, box[b].num ) + dp[pretoy][b-1].ans > dp[t][b].ans  )
                     {
                        ll tmp = 0;
                        tmp = min(dp[pretoy][b-1].toynum + Tnum, box[b].num );


                        dp[t][b].ans = dp[pretoy][b-1].ans + tmp;

                        dp[t][b].boxid = box[b].id; //dp[t-1][prebox].boxid;
                        dp[t][b].boxnum = box[b].num - tmp;  //dp[t-1][prebox].boxnum + Bnum - tmp;

                            if(dp[t][b].boxid == dp[pretoy][b-1].boxid)
                                dp[t][b].boxnum += dp[pretoy][b-1].boxnum;


                        dp[t][b].toyid = dp[pretoy][b-1].toyid;
                        dp[t][b].toynum = dp[pretoy][b-1].toynum + Tnum - tmp;
                     }
                Tnum += toy[pretoy].num;
            }
        }
    }

}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("t.txt", "w", stdout);
    int cas; cin >> cas;
    for(int cc = 1; cc <= cas; cc++)
    {
        cin >> tn >> bn;
        for(int i = 0; i < tn; i++)
            cin >> toy[i].num >> toy[i].id;
        for(int i = 0; i < bn; i++)
            cin >> box[i].num >> box[i].id;

        getans();

        cout << "Case #" << cc << ": " << dp[tn-1][bn-1].ans << endl;
    }

    return 0;
}
