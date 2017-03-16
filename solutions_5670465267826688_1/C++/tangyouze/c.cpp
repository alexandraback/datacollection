


#include <iostream>
#include <vector>
using namespace std;
int g[100][100];
int mul(int a, int b){
    return g[abs(a)][abs(b)] * a / abs(a) * b / abs(b);
}
void solve(int icase){
    g[1][1] = 1;
    g[1][2] = 2;
    g[1][3] = 3;
    g[1][4] = 4;


    g[2][1] = 2;
    g[2][2] = -1;
    g[2][3] = 4;
    g[2][4] = -3;


    g[3][1] = 3;
    g[3][2] = -4;
    g[3][3] = -1;
    g[3][4] = 2;


    g[4][1] = 4;
    g[4][2] = 3;
    g[4][3] = -2;
    g[4][4] = -1;


    int L, X;
    cin >> L >> X;
    string s;
    cin >> s;
    int tot = 1;
    if (X>50){
        X = X%4  + 40;
    }
    string ori = s;
    for(int i=1; i<X; i++){
        s += ori;
    }
    int firsti = -1;
    int lastk = -1;
    for(int i=0; i<(int)s.size(); i++){
        int q = s[i] - 'i' + 2;
        tot = mul(tot, q);
        if(tot == 2){
            if (firsti < 0)
                firsti = i;
        }
        if(tot == 4){
            lastk = i;
        }
    }
    //cout << firsti << " " << lastk << endl;
    if (  tot == -1 && firsti >=0 && lastk >=0 && firsti < lastk)
    {
        printf("Case #%d: YES\n", icase );
        return ;
    }
    printf("Case #%d: NO\n", icase );
    return ;

}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve(i+1);

    }

}
