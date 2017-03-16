#include <iostream>
#include <cstring>
using namespace std;

const int lmax = 10001;
int v[lmax], starts[lmax], t, l, x;
string s;

int comp[5][5] = {
    {0, 0,  0,  0,  0},
    {0, 1,  2,  3,  4},
    {0, 2, -1,  4, -3},
    {0, 3, -4, -1,  2},
    {0, 4,  3, -2, -1}
};

int compose(int x, int y) {
    return comp[x<0? -x:x][y<0? -y:y] * (x<0? -1:1) * (y<0? -1:1);
}

int main() {
    cin>>t;
    for(int test=1; test<=t; test++) {
        cin>>l>>x;
        cin>>s;

        for(int group=0; group<x; group++)
            for(int i=0; i<l; i++) {
                if(s[i] == '1') v[group*l + i] = 1;
                if(s[i] == 'i') v[group*l + i] = 2;
                if(s[i] == 'j') v[group*l + i] = 3;
                if(s[i] == 'k') v[group*l + i] = 4;
            }

        starts[x*l-1] = v[x*l-1];
        for(int i=x*l-2; i>=0; i--)
            starts[i] = compose(v[i], starts[i+1]);

        bool ans = false;
        int L = v[0], M, R;
        for(int i=0; i<x*l-2 && !ans; i++) {
            M = v[i+1];

            for(int j=i+1; j<x*l-1 && !ans; j++) {
                R = starts[j+1];

                ans |= ((L == 2) && (M == 3) && (R == 4));
                M = compose(M, v[j+1]);
            }

            L = compose(L, v[i+1]);
        }

        cout<<"Case #"<<test<<": "<<(ans? "YES\n":"NO\n");
    }

    return 0;
}
