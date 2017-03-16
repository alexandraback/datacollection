#include <bits/stdc++.h>

using namespace std;

#define FILE_IO
#define fs first
#define sc second

typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;

const int b1 = 29;
const int b2 = 31;
const int mod1 = 1e9 + 9;
const int mod2 = 1e9 + 7;

vector <ppi> v;
vector <int> prm;
map <pii, int> fst, sec;
char s[25];

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    srand(time(0));

    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);

        int N;
        scanf("%d\n", &N);
        v.clear();
        fst.clear();
        sec.clear();
        for(int i = 1; i <= N; i++)
        {
            ppi tpc;

            scanf("%s", s + 1);
            int M = strlen(s + 1);
            pii hsh = {0, 0};
            for(int i = 1; i <= M; i++)
            {
                hsh.fs = ((1LL * hsh.fs * b1) % mod1 + s[i] - 'A' + 1) % mod1;
                hsh.sc = ((1LL * hsh.sc * b2) % mod2 + s[i] - 'A' + 1) % mod2;
            }
            fst[hsh]++;
            tpc.fs = hsh;

            scanf("%s", s + 1);
            M = strlen(s + 1);
            hsh = {0, 0};
            for(int i = 1; i <= M; i++)
            {
                hsh.fs = ((1LL * hsh.fs * b1) % mod1 + s[i] - 'A' + 1) % mod1;
                hsh.sc = ((1LL * hsh.sc * b2) % mod2 + s[i] - 'A' + 1) % mod2;
            }
            sec[hsh]++;
            tpc.sc = hsh;
            v.push_back(tpc);
        }

        int ans = 0;

        for(int i = 0; i < v.size(); i++)
        {
            if(fst[ v[i].fs ] == 1 || sec[ v[i].sc ] == 1)
            {
                fst[ v[i].fs ] = -1;
                sec[ v[i].sc ] = -1;
                v.erase(v.begin() + i);
                i--;
            }
        }

        for(int i = 0; i < v.size(); i++)
        {
            if(fst[ v[i].fs ] == -1 && sec[ v[i].sc ] == -1)
            {
                ans++;
                v.erase(v.begin() + i);
                i--;
            }
        }

        sort(v.begin(), v.end());

        /*while(v.size() > 0)
        {
            int ok = 0;
            for(int i = 0; i < v.size(); i++)
            {
                if(fst[ v[i].fs ] != -1 && sec[ v[i].sc ] != -1)
                {
                    fst[ v[i].fs ] = -1;
                    sec[ v[i].sc ] = -1;
                    v.erase(v.begin() + i);
                    i--;
                    ok = 1;
                    break;
                }
            }

            if(!ok)
            {
                fst[ v[0].fs ] = -1;
                sec[ v[0].sc ] = -1;
                v.erase(v.begin());
                ok = 1;
            }

            for(int i = 0; i < v.size(); i++)
            {
                if(fst[ v[i].fs ] == -1 && sec[ v[i].sc ] == -1)
                {
                    ans++;
                    v.erase(v.begin() + i);
                    i--;
                }
            }
        }*/

        int mx = 0;
        if(v.size() > 0)
        {
            prm.clear();
            for(int i = 0; i < v.size(); i++)
                prm.push_back(i);
            int K = v.size();
            for(int p = 1; p <= 500000; p++)
            {
                for(int i = 1; i <= 30; i++)
                {
                    int x = rand() % K;
                    int y = rand() % K;
                    swap(v[x], v[y]);
                }

                //fst.clear();
                //sec.clear();

                int fake = 0;
                for(int i = 0; i < K; i++)
                {
                    int pos = prm[i];
                    if(fst[ v[pos].fs ] > -1)
                        fst[ v[pos].fs ] = 0;
                    if(sec[ v[pos].sc ] > -1)
                        sec[ v[pos].sc ] = 0;

                    //if(fst[ v[pos].fs ] > 1 && sec[ v[pos].sc ] > 1)
                    //    fake++;
                }

                for(int i = 0; i < K; i++)
                {
                    int pos = prm[i];
                    if(fst[ v[pos].fs ] != -1)
                        fst[ v[pos].fs ]++;
                    if(sec[ v[pos].sc ] != -1)
                        sec[ v[pos].sc ]++;

                    if( (fst[ v[pos].fs ] > 1 || fst[ v[pos].fs ] == -1) && (sec[ v[pos].sc ] > 1 || sec[ v[pos].sc ] == -1) )
                        fake++;
                }

                if(fake > mx)
                    mx = fake;
            }
        }

        /*int mx = 0;
        do
        {
            fst.clear();
            sec.clear();

            int fake = 0;
            for(int i = 0; i < v.size(); i++)
            {
                fst[ v[i].fs ]++;
                sec[ v[i].sc ]++;

                if(fst[ v[i].fs ] > 1 && sec[ v[i].sc ] > 1)
                    fake++;
            }

            if(fake > mx)
                mx = fake;
        }while( next_permutation(v.begin(), v.end()) );*/

        ans += mx;
        printf("%d\n", ans);
    }

    return 0;
}
