#include <cstdio>
#include <iostream>

using namespace std;
int t, n, gx, gy, anso, ansn;
bool mapm[40][40];
int rec(int x, int y, int num){
    //cout << x << " " << y << " " << num << endl;
    if(num == n){
        ++anso;
        if(mapm[gx + 20][gy]){
            ++ansn;

        }
        return 0;
    }
    while(y - 2 >= 0 && not mapm[x][y - 2] && not mapm[x - 1][y - 1] && not mapm[x + 1][y - 1]){
        y -= 2;
    }
    bool truly = false;
    if(y - 1 >= 0 && not mapm[x - 1][y - 1]){
        truly = true;
        rec(x - 1, y - 1, num);
    }
    if(y - 1 >= 0 && not mapm[x + 1][y - 1]){
        truly = true;
        rec(x + 1, y - 1, num);
    }
    if(not truly){
        mapm[x][y] = true;
        rec(20, 38, num + 1);
        mapm[x][y] = false;
    }
    return 0;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int k = 0; k < t; ++k){
        cin >> n >> gx >> gy;
        if(gx <= -20 || gx >= 20 || gy > 38){
            printf("Case #%d: 0.0\n", k + 1);

        }
        else
        {
        anso = 0;
        ansn = 0;
        rec(20, 38, 0);
        printf("Case #%d: %.6lf\n", k + 1, ansn / (anso * 1.0));
        }
        //cout << c << endl;
    }
    return 0;
}