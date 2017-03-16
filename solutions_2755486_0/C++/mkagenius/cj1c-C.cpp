#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

struct tri {
    int L;
    int R;
    int S;
};

map<int, vector<tri> > mm;


int main(){
    freopen("CC.in", "r",stdin);
    freopen("CC.out", "w", stdout);
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        int N; cin >> N;
        mm.clear();
        int success = 0;
        for(int i = 0; i < N; i++){
            int d, n, l, r, s, del_d, del_move, del_s;
            cin >> d >> n >> l >> r >> s >> del_d >> del_move >> del_s;

            for(int j = 0; j < n; j++){
                tri tmp;
                tmp.L = l;
                tmp.R = r;
                tmp.S = s;
                mm[d].push_back(tmp);
                l += del_move;
                r += del_move;
                s += del_s;
                d += del_d;
            }
        }
        int cur = 0;
        int wall[1010];
        memset(wall, 0, sizeof wall);
        for(map<int, vector<tri> >::iterator it = mm.begin(); it != mm.end(); it++){
            vector<tri> tmp = it->second;
            int d = it->first;
           // cout << "Day :: " << d << endl;
            int attack[1010];
            memset(attack, 0, sizeof attack);
            for(int i = 0; i < tmp.size(); i++){
                tri z = tmp[i];
                bool fl = 0;
               // cout << "Attacking " << z.L << " to " << z.R << " with power " << z.S << endl;
                for(int j = z.L + 500; j < z.R + 500; j++){
                    attack[j] = max(attack[j], z.S);
                    if(z.S > wall[j]){
                        fl = 1;
                    }
                }
                if(fl)
                success ++;
            }
            for(int i = 0; i < 700; i++){
                wall[i] = max(wall[i], attack[i]);
            }

        }
        cout << "Case #"<< t << ": " << success << endl;
    }
}
