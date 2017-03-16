//#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

using namespace std;

int n = 60, m = 40;

int v[60][60];
int t[60][60];

int us(int x, int y) {
    if (x < 0) {
        x += n;
    }
    
    if (x >= n) {
        x -= n;
    }
    
    if (y < 0) {
        y += m;
    }
    
    if (y >= m) {
        y -= m;
    }
    
    if (v[x][y] == 1) {
        return 1;
    }
    return 0;
}

int cnt(int x, int y) {
    return us(x - 1, y) + us(x + 1, y) + us(x, y + 1) + us(x, y - 1) + us(x + 1, y + 1) + us(x - 1, y + 1) + us(x + 1, y - 1) + us(x - 1, y - 1);
}

int die(int x, int y) {
    int f = cnt(x, y);
    
    if (f == 3) {
        return 1;
    }
    
    if (f != 2 && f != 3) {
        return 0;
    }
    
    return 2;
}

int mask = 0;

void* f1(void* arg) {
    for ( ; ;) {
        if ((mask & 1) == 0) {
            //pthread_mutex_t a = PTHREAD_MUTEX_INITIALIZER;
            //pthread_mutex_lock(&a);
            for (int i = 0; i < n / 4; i++) {
                for (int j = 0; j < m; j++) {
                    t[i][j] = v[i][j];
                    int x = die(i, j);
                    
                    if (x == 1) {
                        t[i][j] = 1;
                    }
                    
                    if (x == 0) {
                        t[i][j] = 0;
                    }
                }
            }
            
            mask ^= 1;
            //pthread_mutex_unlock(&a);
        }
    }
    
    return NULL;
}

void* f2(void* arg) {
    for ( ; ;) {
        if (((mask >> 1) & 1) == 0) {
            //pthread_mutex_t a = PTHREAD_MUTEX_INITIALIZER;
            //pthread_mutex_lock(&a);
            
            for (int i = n / 4; i < n / 2; i++) {
                for (int j = 0; j < m; j++) {
                    t[i][j] = v[i][j];
                    int x = die(i, j);
                    
                    if (x == 1) {
                        t[i][j] = 1;
                    }
                    
                    if (x == 0) {
                        t[i][j] = 0;
                    }
                }
            }
            
            mask ^= 2;
            //pthread_mutex_unlock(&a);
        }
    }
    
    return NULL;
}

void* f3(void* arg) {
    for ( ; ;) {
        if (((mask >> 2) & 1) == 0) {
            //pthread_mutex_t a = PTHREAD_MUTEX_INITIALIZER;
            //pthread_mutex_lock(&a);
            
            for (int i = n / 2; i < 3 * n / 4; i++) {
                for (int j = 0; j < m; j++) {
                    t[i][j] = v[i][j];
                    int x = die(i, j);
                    
                    if (x == 1) {
                        t[i][j] = 1;
                    }
                    
                    if (x == 0) {
                        t[i][j] = 0;
                    }
                }
            }
            
            mask ^= 4;
            //pthread_mutex_unlock(&a);
        }
    }
    
    return NULL;
}

void* f4(void* arg) {
    for ( ; ;) {
        if (((mask >> 3) & 1) == 0) {
            //pthread_mutex_t a = PTHREAD_MUTEX_INITIALIZER;
            //pthread_mutex_lock(&a);
            
            for (int i = 3 * n / 4; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    t[i][j] = v[i][j];
                    int x = die(i, j);
                    
                    if (x == 1) {
                        t[i][j] = 1;
                    }
                    
                    if (x == 0) {
                        t[i][j] = 0;
                    }
                }
            }
            
            mask ^= 8;
            //pthread_mutex_unlock(&a);
        }
    }
    
    return NULL;
}

int cont = 0;

void* f5(void* arg) {
    for ( ; ; ) {
        if (mask == 15) {
            cont++;
            //pthread_mutex_t a = PTHREAD_MUTEX_INITIALIZER;
            //pthread_mutex_lock(&a);
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    v[i][j] = t[i][j];
                }
            }
            
            mask = 0;
            //pthread_mutex_unlock(&a);
        }
    }
}

int main() {
    int id1, id2, id3, id4, id5;
    pthread_t t1, t2, t3, t4, t5;
    
    v[5][1] = v[5][2] = v[6][1] = v[6][2] = 1;
    v[5][12] = v[6][12] = v[7][12] = v[8][13] = v[9][14] = v[8][15] = v[7][16] = v[7][17] = v[6][16] = v[6][17] = v[5][16] = v[5][17] = 1;
    v[4][15] = v[3][14] = v[4][13] = 1;
    v[3][22] = v[4][22] = v[5][22] = 1;
    v[2][23] = v[3][23] = v[5][23] = v[6][23] = 1;
    v[2][24] = v[3][24] = v[5][24] = v[6][24] = 1;
    v[2][25] = v[3][25] = v[4][25] = v[5][25] = v[6][25] = 1;
    v[1][26] = v[2][26] = v[6][26] = v[7][26] = 1;
    v[5][31] = v[6][31] = 1;
    v[3][35] = v[4][35] = v[3][36] = v[4][36] = 1;
    
    if (pthread_create(&t1, NULL, f1, &id1) == 0) {
        
    }
    
    if (pthread_create(&t2, NULL, f2, &id2) == 0) {
        
    }
    
    if (pthread_create(&t3, NULL, f3, &id3) == 0) {
        
    }
    
    if (pthread_create(&t4, NULL, f4, &id4) == 0) {
        
    }
    
    if (pthread_create(&t5, NULL, f5, &id5) == 0) {
        
    }
    
    double now = clock();
    
    while (true) {
        while (clock() - now <= 0.5 * CLOCKS_PER_SEC) {
            continue;
        }
        
        now = clock();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << v[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    
    return 0;
}