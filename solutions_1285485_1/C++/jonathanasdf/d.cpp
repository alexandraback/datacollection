#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int T; cin >> T;
    for (int z=0; z<T; z++) {
        int H, W, D; cin >> H >> W >> D;
        char grid[H][W];
        int startr, startc;
        for (int i=0; i < H; i++) for (int j=0; j < W; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'X') startr = i, startc = j;
        }
        
        D *= 2;
        int m[H*2+1][W*2+1];
        memset(m, 0, sizeof m);
        //flags start clockwise at top left
        int dd[8][3] = {{0,0,1<<2},{0,1,(1<<2)|(1<<3)},{0,2,1<<3},{1,0,(1<<1)|(1<<2)},{1,2,(1<<0)|(1<<3)},{2,0,1<<1},{2,1,(1<<0)|(1<<1)},{2,2,1<<0}};
        for (int i=0; i < H; i++) for (int j=0; j < W; j++) {
            if (grid[i][j] == '#') {
                for (int k=0; k < 8; k++)
                    m[i*2+dd[k][0]][j*2+dd[k][1]] |= dd[k][2];
            }
        }
        startr = startr*2+1; startc = startc*2+1;
        
        int count = 0;
        for (int i=1; i <= D/2; i++) {
            if (startr+i < H*2+1 && (m[startr+i][startc] & 12) == 12) {
                count++;
                break;
            }
        }
        for (int i=1; i <= D/2; i++) {
            if (startr-i >= 0 && (m[startr-i][startc] & 3) == 3) {
                count++;
                break;
            }
        }
        for (int i=1; i <= D/2; i++) {
            if (startc+i < W*2+1 && (m[startr][startc+i] & 6) == 6) {
                count++;
                break;
            }
        }
        for (int i=1; i <= D/2; i++) {
            if (startc-i >= 0 && (m[startr][startc-i] & 9) == 9) {
                count++;
                break;
            }
        }
        
        set<pair<int, int> > seen;
        for (int i=-D; i <= D; i++) for (int j=-D; j <= D; j++) {
//        for (int i=2; i==2; i++) for (int j=2; j == 2; j++) {
            if (i*i+j*j>D*D || i==0 || j==0) continue;
            // send ray towards i, j
            int ii=abs(i), jj = abs(j), gg = gcd(ii,jj);
            if (seen.count(make_pair(i/gg, j/gg))) continue;
            int dir[2] = {i/ii,j/jj};
            int dr, dc, drf, dcf, dabs;
            dr=dc=drf=dcf=dabs=0;
            while(dabs<ii*jj) {
                //cout << i << " " << j << " " << dabs << " " << dr << " " << dc << " " << drf << " " << dcf << " " << dir[0] << " " << dir[1] << endl;
                int distr, distc;
                if (dir[0] == 1) {
                    distr = jj-drf;
                } else {
                    distr = (drf==0?jj:drf);
                }
                if (dir[1] == 1) {
                    distc = ii-dcf;
                } else {
                    distc = (dcf==0?ii:dcf);
                }
                if (distr <= distc) {
                    dabs += distr;
                    if (dir[0] == 1) {
                        dcf += dir[1]*distr; 
                        if(dcf>=ii) dcf-=ii, dc++;
                        if(dcf<0) dcf+=ii, dc--;
                        drf = 0; dr++; 
                    } else {
                        dcf += dir[1]*distr; 
                        if(dcf>=ii) dcf-=ii, dc++;
                        if(dcf<0) dcf+=ii, dc--;
                        if (drf==0) dr--;
                        drf = 0; 
                    }
                } else {
                    dabs += distc;
                    if (dir[1] == 1) {
                        drf += dir[0]*distc; 
                        if(drf>=jj) drf-=jj, dr++;
                        if(drf<0) drf+=jj, dr--;
                        dcf = 0; dc++;
                    } else {
                        drf += dir[0]*distc; 
                        if(drf>=jj) drf-=jj, dr++;
                        if(drf<0) drf+=jj, dr--;
                        if (dcf==0) dc--;
                        dcf = 0; 
                    }
                }
                if (drf == 0 && dcf == 0) {
                    // on grid
                    int mm = m[startr+dr][startc+dc];
                    if (dir[0] == 1 && dir[1] == 1) {
                        if((mm & 4)==0) ;// do nothing
                        else if((mm & 14)==14) dir[0]*=-1, dir[1]*=-1;
                        else if ((mm & 12)==12) dir[0]*=-1;
                        else if ((mm & 6)==6) dir[1]*=-1;
                        else break;
                    } else if (dir[0] == -1 && dir[1] == 1) {
                        if((mm & 2)==0) ;// do nothing
                        else if((mm & 7)==7) dir[0]*=-1, dir[1]*=-1;
                        else if ((mm & 3)==3) dir[0]*=-1;
                        else if ((mm & 6)==6) dir[1]*=-1;
                        else break;
                    } else if (dir[0] == 1 && dir[1] == -1) {
                        if((mm & 8)==0) ;// do nothing
                        else if((mm & 13)==13) dir[0]*=-1, dir[1]*=-1;
                        else if ((mm & 12)==12) dir[0]*=-1;
                        else if ((mm & 9)==9) dir[1]*=-1;
                        else break;
                    } else if (dir[0] == -1 && dir[1] == -1) {
                        if((mm & 1)==0) ;// do nothing
                        else if((mm & 11)==11) dir[0]*=-1, dir[1]*=-1;
                        else if ((mm & 3)==3) dir[0]*=-1;
                        else if ((mm & 9)==9) dir[1]*=-1;
                        else break;
                    }
                } else if (drf == 0) {
                    int mm = m[startr+dr][startc+dc];
                    if (dir[0] == 1 && (mm & 4) == 4) dir[0] = -1;
                    else if (dir[0] == -1 && (mm & 2) == 2) dir[0] = 1;
                } else {
                    int mm = m[startr+dr][startc+dc];
                    if (dir[1] == 1 && (mm & 4) == 4) dir[1] = -1;
                    else if (dir[1] == -1 && (mm & 8) == 8) dir[1] = 1;
                }
            }
            if (dabs == ii*jj && dr == 0 && dc == 0) {
                seen.insert(make_pair(i/gg, j/gg));
                count++;
            }
        }
        printf("Case #%d: %d\n", z+1, count);
    }
    return 0;
}