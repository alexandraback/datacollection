#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#define PROB "B"

//string inPath = PROB "-large.in";
//string outPath = PROB "-large.out";

string inPath = PROB "-small-attempt1.in";
string outPath = PROB "-small-attempt1.out";

//string inPath = "input.txt";
//string outPath = "output.txt";

#define M 1000000007

long long fc(long long n) {
    long long ans = 1;
    
    for(long long i = 2; i <= n; ++i)
        ans = (ans * i) % M;
    
    return ans;
}

int main(int argc, char** argv) {
    FILE * fin = fopen(inPath.c_str(), "r");
    FILE * fout = fopen(outPath.c_str(), "w");
    
    int tcases;
    fscanf(fin, "%d", &tcases);
    
    for(int tcase = 0; tcase < tcases; ++tcase) {
        printf("test %d...\n", tcase + 1);
        
        int n;
        char s[200][200] = {0};
        
        fscanf(fin, "%d", &n);
        
        for(int i = 0; i < n; ++i)
            fscanf(fin, "%s", s[i]);
        
        int mid[30] = {0}, lft[30] = {0}, rght[30] = {0}, full[30] = {0};
        int bl_n[30];
        int bl_l[200], bl_r[200];
        for(int i = 0; i < 30; ++i)
            bl_n[i] = -1;
        
        for(int i = 0; i < n; ++i) {
            int l = 0;
            for(int j = 1; ; ++j) {
                if(!s[i][j]) {
                    bl_r[i] = s[i][l] - 'a';
                    if(l == 0)
                        full[s[i][l] - 'a']++, bl_l[i] = s[i][l] - 'a';
                    else
                        rght[s[i][l] - 'a']++;
                    break;
                }
                
                if(s[i][j] != s[i][l]) {
                    if(l == 0)
                        lft[s[i][l] - 'a']++, bl_l[i] = s[i][l] - 'a', bl_n[s[i][l] - 'a'] = i;
                    else
                        mid[s[i][l] - 'a']++;
                    l = j;
                }
            }
        }
        
        long long ans = 1;
        int cnt = 0;
        
        for(int i = 0; i < 26; ++i) {
            if(mid[i] + lft[i] > 1 || mid[i] + rght[i] > 1 || (mid[i] && full[i])) {
                ans = 0;
                break;
            }
            
            ans = (ans * fc(full[i])) % M;
            
            if(full[i])
                cnt += 2 - rght[i] - lft[i];
            else if(rght[i] + lft[i] == 1)
                cnt++;
        }
        
        int u[30] = {0};
        for(int i = 0; i < 26; ++i) {
            if(!u[i]) {
                
                int cur = i, flag = 0;
                while(1) {
                    if(u[cur] == i+1) {
                        flag = 1;
                        break;
                    }
                    
                    u[cur] = i+1;
                    
                    if(bl_n[cur] == -1)
                        break;
                    
                    cur = bl_r[ bl_n[cur] ];
                }
                
                if(flag) {
                    ans = 0;
                    break;
                }
            }
        }
        
        printf("1ans: %lld\n", ans);
        printf("cnt: %d\n", cnt);
        
        cnt /= 2;
        ans = (ans * fc(cnt)) % M;
        
        
        fprintf(fout, "Case #%d: %lld\n", tcase+1, ans);
        

        printf("OK\n");
    }
    
    return 0;
}

