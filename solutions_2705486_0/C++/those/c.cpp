#include<stdio.h>
#include<map>
#include<queue>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

char w[530000][11];
char s[5000];
int f[5000][10];
int len[530000];

int n = 521196;
int main(){
    FILE* fin = fopen("garbled_email_dictionary.txt", "r");
    FOR(i,0,n){
        fscanf(fin,"%s",w[i]);
        len[i] = strlen(w[i]);
    }
    fclose(fin);

    int ca; scanf("%d",&ca);
    FOE(tt,1,ca){
        fprintf(stderr, "running for case %d\n", tt);
        scanf("%s",s);
        int m = strlen(s);
        FOE(i,0,m) FOE(k,0,6) f[i][k]=1<<29;
        f[0][5] = 0;
        FOR(i,0,m){
            FOE(t,1,5){
                FOR(j,0,n){
                    if (i+len[j]>m) continue;
                    int d = 0;
                    int last=i-t;
                    bool ok=true;
                    FOR(k,0,len[j]){
                        if (w[j][k]==s[i+k]) continue;
                        if (i+k-last>=5){
                            last=i+k;
                            d+=1;
                        }else{
                            ok=false;
                            break;
                        }
                    }
                    if (ok){
                        int x = min(5, i+len[j]-last);
                        f[i+len[j]][x] = min(f[i+len[j]][x], f[i][t]+d);
                    }
                }
            }
        }
        int ans=1<<29;
        FOR(i,0,6) ans = min(ans, f[m][i]);
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
