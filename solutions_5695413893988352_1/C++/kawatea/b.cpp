#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char s1[20];
char s2[20];
pair<long long, pair<long long, long long> > inf = make_pair(1e18, make_pair(0, 0));

pair<long long, pair<long long, long long> > get(int x, int y) {
    int i;
    long long p = 0, q = 0;
    
    for (i = 0; i < x; i++) {
        p *= 10;
        q *= 10;
        
        if (s1[i] == s2[i]) {
            if (s1[i] != '?') {
                p += s1[i] - '0';
                q += s1[i] - '0';
            }
        } else {
            if (s1[i] == '?') {
                p += s2[i] - '0';
                q += s2[i] - '0';
            } else {
                p += s1[i] - '0';
                q += s1[i] - '0';
            }
        }
    }
    
    if (x < n) {
        p *= 10;
        q *= 10;
        
        if (s1[i] == s2[i]) {
            if (s1[i] != '?') return inf;
            
            if (y == 0) {
                p += 1;
            } else {
                q += 1;
            }
        } else {
            if (s1[i] == '?') {
                if (y == 0) {
                    if (s2[i] == '9') return inf;
                    
                    p += s2[i] - '0' + 1;
                    q += s2[i] - '0';
                } else {
                    if (s2[i] == '0') return inf;
                    
                    p += s2[i] - '0' - 1;
                    q += s2[i] - '0';
                }
            } else if (s2[i] == '?') {
                if (y == 0) {
                    if (s1[i] == '0') return inf;
                    
                    p += s1[i] - '0';
                    q += s1[i] - '0' - 1;
                } else {
                    if (s1[i] == '9') return inf;
                    
                    p += s1[i] - '0';
                    q += s1[i] - '0' + 1;
                }
            } else {
                if (y == 0 && s1[i] < s2[i]) return inf;
                if (y == 1 && s1[i] > s2[i]) return inf;
                
                p += s1[i] - '0';
                q += s2[i] - '0';
            }
        }
    }
    
    for (i++; i < n; i++) {
        p *= 10;
        q *= 10;
        
        if (s1[i] == s2[i]) {
            if (s1[i] == '?') {
                if (y == 0) {
                    q += 9;
                } else {
                    p += 9;
                }
            } else {
                p += s1[i] - '0';
                q += s2[i] - '0';
            }
        } else {
            if (s1[i] == '?') {
                if (y == 0) {
                    q += s2[i] - '0';
                } else {
                    p += 9;
                    q += s2[i] - '0';
                }
            } else if (s2[i] == '?') {
                if (y == 0) {
                    p += s1[i] - '0';
                    q += 9;
                } else {
                    p += s1[i] - '0';
                }
            } else {
                p += s1[i] - '0';
                q += s2[i] - '0';
            }
        }
    }
    
    return make_pair(abs(p - q), make_pair(p, q));
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int j;
        pair <long long, pair<long long, long long> > p = inf;
        
        scanf("%s %s", s1, s2);
        
        n = strlen(s1);
        
        for (j = 0; j < n; j++) {
            if (s1[j] != s2[j] && s1[j] != '?' && s2[j] != '?') break;
        }
        
        for (; j >= 0; j--) {
            p = min(p, get(j, 0));
            p = min(p, get(j, 1));
        }
        
        for (j = n - 1; j >= 0; j--) {
            s1[j] = p.second.first % 10 + '0';
            p.second.first /= 10;
        }
        
        for (j = n - 1; j >= 0; j--) {
            s2[j] = p.second.second % 10 + '0';
            p.second.second /= 10;
        }
        
        printf("Case #%d: %s %s\n", i + 1, s1, s2);
    }
    
    return 0;
}
