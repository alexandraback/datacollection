#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <set>
#define mapa make_pair
#define ff first
#define ss second

using namespace std;
const int MAXN = 55;

int t, r, c, m;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
bool used[MAXN][MAXN], iszero[MAXN][MAXN];

set <pair <int, pair <int, int> > > s;

int numbomb(int x, int y) {
    int ret = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0 <= ny && ny < c && !used[nx][ny]) {
            ++ret;
        }
    }
    return ret;
}

int num_n;
int relax(int x, int y) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = x + i;
            int ny = y + j;
            if (0 <= nx && nx < r && 0 <= ny && ny < c && !used[nx][ny]) {
                used[x + i][y + j] = true;
                ++num_n;
            }
        }
    }
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {            
            int nx = x + i;
            int ny = y + j;
            if (0 <= nx && nx < r && 0 <= ny && ny < c && !iszero[nx][ny] && used[nx][ny]) {
                //cout << "insert " << numbomb(x + i, y + j) << " " << x + i << " " << y + j << endl;
                s.insert(mapa(numbomb(x + i, y + j), mapa(x + i, y + j)));
            }
        }
    }
    return 0;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> r >> c >> m;        
        //cout << i << endl;
        bool flag = false;
        for (int j = 0; j < r; ++j) {
            for (int k = 0; k < c; ++k) {   
                memset(used, 0, sizeof used);
                memset(iszero, 0, sizeof iszero);
                used[j][k] = true;
                num_n = 1;
                s.clear();
                s.insert(mapa(numbomb(j, k), mapa(j, k)));
                //cout << j << " : " << k << endl;
                //cout << numbomb(j, k) << endl;
                while (num_n < r * c - m && (int) s.size() > 0) {
                    set <pair <int, pair <int, int> > >::iterator it;
                    while (true) {
                        //it = s.lower_bound(mapa(0, mapa(0, 0))); 
                        it = s.lower_bound(mapa(r * c - m - num_n + 1, mapa(0, 0)));
                        
                        if (it == s.begin()) {
                            break;
                        }
                        
                        --it;
                        if (iszero[(*it).ss.ff][(*it).ss.ss] || numbomb((*it).ss.ff, (*it).ss.ss) != (*it).ff) {                            
                            s.erase(*it);
                        } else {
                            break;
                        }
                    }
                    //cout << "num_n " << num_n << endl;
                    //cout << (*it).ff << " " << (*it).ss.ff << " " << (*it).ss.ss << endl;
                    if ((*it).ff > r * c - m - num_n) {
                        break;
                    }
                    iszero[(*it).ss.ff][(*it).ss.ss] = true;
                    relax((*it).ss.ff, (*it).ss.ss);
                }
                if (num_n == r * c - m) {
                    cout << "Case #" << i + 1 << ":\n"; 
                    for (int x = 0; x < r; ++x) {
                        for (int y = 0; y < c; ++y) {
                            if (j == x && k == y) {
                                cout << "c";
                            } else if (used[x][y]) {
                                cout << ".";
                            } else {
                                cout << "*";
                            }
                        }
                        cout << endl;
                    }
                    flag = true;
                    break;
                }
                
            }
            if (flag) {
                break;
            }
        }
        if (!flag) {
            
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {   
                    memset(used, 0, sizeof used);
                    memset(iszero, 0, sizeof iszero);
                    used[j][k] = true;
                    num_n = 1;
                    s.clear();
                    s.insert(mapa(numbomb(j, k), mapa(j, k)));
                    //cout << j << " : " << k << endl;
                    //cout << numbomb(j, k) << endl;
                    while (num_n < r * c - m && (int) s.size() > 0) {
                        set <pair <int, pair <int, int> > >::iterator it;
                        while (true) {
                            it = s.lower_bound(mapa(0, mapa(0, 0))); 
                            //it = s.lower_bound(mapa(r * c - m - num_n + 1, mapa(0, 0)));
                            /*
                            if (it == s.begin()) {
                                break;
                            }*/
                            
                            //--it;
                            if (iszero[(*it).ss.ff][(*it).ss.ss] || numbomb((*it).ss.ff, (*it).ss.ss) != (*it).ff) {                            
                                s.erase(*it);
                            } else {
                                break;
                            }
                        }
                        //cout << "num_n " << num_n << endl;
                        //cout << (*it).ff << " " << (*it).ss.ff << " " << (*it).ss.ss << endl;
                        if ((*it).ff > r * c - m - num_n) {
                            break;
                        }
                        iszero[(*it).ss.ff][(*it).ss.ss] = true;
                        relax((*it).ss.ff, (*it).ss.ss);
                    }
                    if (num_n == r * c - m) {
                        cout << "Case #" << i + 1 << ":\n"; 
                        for (int x = 0; x < r; ++x) {
                            for (int y = 0; y < c; ++y) {
                                if (j == x && k == y) {
                                    cout << "c";
                                } else if (used[x][y]) {
                                    cout << ".";
                                } else {
                                    cout << "*";
                                }
                            }
                            cout << endl;
                        }
                        flag = true;
                        break;
                    }
                    
                }
                if (flag) {
                    break;
                }
            }
            if (!flag) {
                cout << "Case #" << i + 1 << ":\nImpossible\n";
            }
            //int numb;            
        }
    }
    return 0;
}
