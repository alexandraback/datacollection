#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool M[4][4];
set<int> hash_set;

int my_hash() {
    int h = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (M[i][j]) {
                h |= (1 << (4 * i + j));
            }
        }
    }
    return h;
}

struct Polymino {
    bool mat[4][4];
    
    Polymino() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mat[i][j] = M[i][j];
            }
        }
    }
};

vector<Polymino> possib[4], filtered[4];

void generate(int sz) {
    if (sz > 0) possib[sz - 1].push_back(Polymino());
    if (sz == 4) return;
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) if (M[i][j] == 0) {
            for (int k = 0; k < 4; ++k) {
                int tx = i + dx[k];
                int ty = j + dy[k];
                if (sz == 0 || (tx >= 0 && tx < 4 && ty >= 0 && ty < 4 && M[tx][ty] == 1)) {
                    M[i][j] = 1;
                    int h = my_hash();
                    if (hash_set.count(h) == 0) {
                        hash_set.insert(h);
                        generate(sz + 1);
                    }
                    M[i][j] = 0;
                }
            }
        }
    }   
}

int last_r(Polymino p) {
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (p.mat[i][j]) res = max(res, i);
        }
    }
    return res;
}

int last_c(Polymino p) {
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (p.mat[i][j]) res = max(res, j);
        }
    }
    return res;
}

void dbg() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotate(Polymino p) {
    int last_row = last_r(p);
    
    memset(M, 0, sizeof M);
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) if (p.mat[i][j] == 1) {
            M[j][last_row - i] = 1;
        }
    }
}

void mirror_v(Polymino p) {
    int last_row = last_r(p);

    memset(M, 0, sizeof M);
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) if (p.mat[i][j] == 1) {
            M[last_row - i][j] = 1;
        }
    }
}

void mirror_h(Polymino p) {
    int last_col = last_c(p);
 
    memset(M, 0, sizeof M); 
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) if (p.mat[i][j] == 1) {
            M[i][last_col - j] = 1;
        }
    }
}

int X, R, C;

bool finish() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (M[i][j] == 0) return false;
        }
    }
    return true;
}

bool can_place(Polymino p) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (p.mat[i][j] == 1 && p.mat[i][j] == M[i][j]) return false;
            if (p.mat[i][j] == 1 && (i >= R || j >= C)) return false;
        }
    }
    return true;
}

void add(Polymino p) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            M[i][j] |= p.mat[i][j];
        }
    }
}

void remove(Polymino p) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (p.mat[i][j] == 1) M[i][j] = 0;
        }
    }
}

bool done;

bool bt() {
    if (done) return false;
    int h = my_hash();
    if (hash_set.count(h)) return false;
    if (finish()) {
        done = true;
        return true;
    }
    for (int i = 0; i < int(possib[X - 1].size()); ++i) {
        if (can_place(possib[X-1][i])) {
            add(possib[X-1][i]);
            if (bt()) return true;
            remove(possib[X-1][i]);
        }
    }
    return false;
}

bool go(Polymino ini) {    
    Polymino p;
    
    for (int i = 0; i < 4; ++i) {
        
        auto check = [&] () {      
            for (int si = 0; si < R; ++si) {
                for (int sj = 0; sj < C; ++sj) {
                    memset(M, 0, sizeof M);
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            if (p.mat[i][j] == 1) {
                                if ((si + i >= R) || (sj + j >= C)) {
                                    goto bad;
                                }
                                M[si + i][sj + j] = 1; 
                            }
                        }
                    }
                    if (bt()) return true;
                    bad:;
                }
            }         
            return false;
        };
        
        rotate(ini);
        ini = p = Polymino();
        
        if (check()) return true;
        
        mirror_h(ini);
        p = Polymino();
        if (check()) return true;
        
        mirror_v(ini);
        p = Polymino();
        if (check()) return true;
    }
    
    return false;
}

int main() {
    generate(0);
    hash_set.clear();
    for (int sz = 0; sz < 4; ++sz) {
        for (int j = 0; j < possib[sz].size(); ++j) {
            Polymino p = possib[sz][j];
            if (p.mat[0][0] == 0) continue;
            bool ok = 1;
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    M[i][j] = p.mat[i][j];
                }
            }
            
            for (int i = 0; i < 4; ++i) {
                
                auto check = [&] () {
                    int h = my_hash();
                    if (hash_set.count(h) != 0) {
                        ok = 0;
                        return false;
                    }
                    return true;
                };
                
                rotate(p);
                
                if (check() == 0) break;
                p = Polymino();
                
                mirror_h(p);
                if (check() == 0) break;
                
                mirror_v(p);
                if (check() == 0) break;
            }
            
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    M[i][j] = p.mat[i][j];
                }
            }
            
            if (ok) {
                int h = my_hash();
                hash_set.insert(h);
                filtered[sz].push_back(p);
                // for (int i = 0; i < 4; ++i) {
                //     for (int j = 0; j < 4; ++j) {
                //         printf("%d", p.mat[i][j]);
                //     }
                //     printf("\n");
                // }
                // printf("\n");
            }
        }
    }
    
    int T;
    scanf("%d", &T);
    
    for (int caso = 1; caso <= T; ++caso) {
        scanf("%d %d %d", &X, &R, &C);
        int richard = false;
        hash_set.clear();
        
        for (int i = 0; i < filtered[X - 1].size(); ++i) {
            done = false;
            if (go(filtered[X-1][i]) == 0) {
                richard = true;
                break;
            }
        }
        printf("Case #%d: %s\n", caso, richard ? "RICHARD" : "GABRIEL");
    }
    
    return 0;
}
