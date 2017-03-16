#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ii pair<int, int>
#define iii pair<ii, int>
int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        map<iii, int> mapa1;
        map<ii, int> jp;
        map<ii, int> js;
        map<ii, int> ps;
        printf("Case #%d: ", t);
        int j, p, s, k;
        scanf("%d %d %d %d", &j, &p, &s, &k);
        vector<iii> vetor;
        for(int i = 1; i <= j; i++)
            for(int l = 1; l <= p; l++)
                for(int m = 1; m <= s; m++){
                    iii a = make_pair(make_pair(i, l), m);
                    ii b = make_pair(i, l);
                    ii c = make_pair(i, m);
                    ii d = make_pair(l, m);
                    if(mapa1[a] == 0 && jp[b] < k&& js[c] < k && ps[d] < k)
                    {
                        vetor.push_back(a);
                        mapa1[a]++;
                        jp[b]++;
                        js[c]++;
                        ps[d]++;
                    }
                }
        printf("%d\n", vetor.size());
        for(int i = 0; i < vetor.size(); i++)
        {
            printf("%d %d %d\n", vetor[i].first.first, vetor[i].first.second, vetor[i].second);
        }
    }
}
