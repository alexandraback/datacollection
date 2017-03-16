#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;


int mat[11][11][11];
int sumx[11][11], sumy[11][11], sumz[11][11];
int j, p, s, k;

bool best(int x, int y, int z, int xb, int yb, int zb) {
    if(xb == -1)
        return true;
    int db[3], d[3];
    db[0] = sumx[yb][zb];
    db[1] = sumy[xb][zb];
    db[2] = sumz[xb][yb];

    d[0] = sumx[y][z];
    d[1] = sumy[x][z];
    d[2] = sumz[x][y];
    sort(d, d + 3);
    sort(db, db + 3);

    if(d[0] != db[0])
        return d[0] > db[0];
    if(d[1] != db[1])
        return d[1] > db[1];
    if(d[2] != db[2])
        return d[2] > db[2];
}

int main()
{
    ios::sync_with_stdio(0);
    int casos;
    cin >> casos;
    for(int cas = 1; cas <= casos; cas++) {
        memset(mat, 0, sizeof mat);
        cin >> j >> p >> s >> k;

        memset(sumx, 0, sizeof sumx);
        memset(sumy, 0, sizeof sumy);
        memset(sumz, 0, sizeof sumz);

        bool could = true;
        int ans = 0;
        while(could) {
            could = false;
            int xbest = -1, ybest = -1, zbest = -1;
            for(int x = 0; x < j; x++)
                for(int y = 0; y < p; y++)
                    for(int z = 0; z < s; z++) {
                        if(mat[x][y][z] == 0 && sumx[y][z] < k && sumz[x][y] < k && sumy[x][z] < k) {
                            if(best(x, y, z, xbest, ybest, zbest)) {
                                xbest = x; ybest = y; zbest = z;
                                could = true;
                            }
                        }
                    }
            if(could) {
                sumx[ybest][zbest]++;
                sumy[xbest][zbest]++;
                sumz[xbest][ybest]++;

                mat[xbest][ybest][zbest] = 1;

                ans++;
            }
        }
        cout << "Case #" << cas << ": " << ans << '\n';
        for(int x = 0; x < j; x++)
            for(int y = 0; y < p; y++)
                for(int z = 0; z < s; z++)
                    if(mat[x][y][z] == 1)
                        cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
    }
}
