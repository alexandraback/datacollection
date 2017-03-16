//Eldar Gaynetdinov
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    for(int t = 1; t <= T; t++)
    {
        int N; cin >> N;

        vector< pair<string, string> > v(N);

        for(int i = 0; i < N; i++)
        {
            cin >> v[i].first >> v[i].second;
        }

        int ans = 0;

        int K = 1 << N;

        for(int k = 0; k < K; k++)
        {
            int fl = 1;

            int cnt = 0;

            for(int i = 0; i < N; i++)
                if(k & (1 << i))
                {
                    int l = 0, r = 0;

                    cnt++;

                    for(int j = 0; j < N; j++)
                        if( !(k & (1 << j)) )
                        {
                            if(v[i].first == v[j].first)    l = 1;
                            if(v[i].second == v[j].second)  r = 1;
                        }

                    fl &= l && r;
                }

            if(fl) ans = max(ans, cnt);
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
