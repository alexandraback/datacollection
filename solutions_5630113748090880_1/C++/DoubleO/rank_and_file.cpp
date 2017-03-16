#include<bits/stdc++.h>
using namespace std;
int i, j, k, l, x, y, z, m, n, p, q, t;

map < int, int > cnt, chk;
vector < int > vec[110];

vector < int > ans_vec;

int main()
{

    freopen("B-large.txt", "r", stdin);
    freopen("output_b_large.txt", "w", stdout);

    int cs = 1;

    cin >> t;

    while(t--){

        cin >> n;

        for(i = 0; i <= 105; i++) vec[i].clear();
        chk.clear();
        cnt.clear();
        ans_vec.clear();

        for(i = 0; i < ((2 * n) - 1); i++) for(j = 0; j < n; j++){
            scanf("%d", &x);
            vec[i].push_back(x);

            cnt[x]++;
        }

        for(i = 0; i < ((2 * n) - 1); i++){
            for(j = 0; j < n; j++){
                if(chk[vec[i][j]]) continue;
                chk[vec[i][j]] = 1;

                if(cnt[vec[i][j]] % 2) ans_vec.push_back(vec[i][j]);
            }
        }
        printf("Case #%d: ", cs++);

        sort(ans_vec.begin(), ans_vec.end());

        for(i = 0; i < ans_vec.size(); i++) cout << ans_vec[i] << ' ';

        cout << endl;
    }



    return 0;
}
