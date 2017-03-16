#include <bits/stdc++.h>
using namespace std;

int t,j,p,s,k;
vector<pair<pair<int,int>,int>> comb;

int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    scanf("%d",&t);
    for(int test = 1; test <= t; test++){
        comb.clear();
        scanf("%d%d%d%d",&j,&p,&s,&k);
        clog << test << " " << j << " " << p << " " << s << " " << k << endl;
        int x = j*p*s;
        vector<int> c1(50),c2(50),c3(50);
        int sol = 0;
        vector<pair<pair<int,int>,int>> out;
        for(int a = 1; a <= j; a++){
            for(int b = 1; b <= p; b++){
                for(int c = 1; c <= s; c++){
                    if(c1[a+b*3]+1 > k || c2[a+c*3]+1 > k || c3[b+c*3]+1 > k) continue;
                    if(++c1[a+b*3] > k) break;
                    if(++c2[a+c*3] > k) break;
                    if(++c3[b+c*3] > k) break;
                    sol++;
                    out.push_back({{a,b},c});
                }
            }
        }
        cout << "Case #" << test << ": " << sol << endl;
        for(auto i : out) cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    }
}