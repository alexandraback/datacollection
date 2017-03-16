#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[200];
int ss[200];
int mid[26];
int c2[26][26];
int c1[26];
int di[26];
int dj[26];
int con[26][26];
int u[26];
int out[26];
long long fac[100000];

const long long MOD = 1000000007;

int main(){
    int tt,TT,n,flag,d;
    fac[0] = 1;
    for( int i=1; i<100000; i++ ){
        fac[i] = (fac[i-1]*i)%MOD;
    }
    scanf("%d",&TT);
    for( tt=0; tt<TT; tt++ ){
        scanf("%d",&n);
        flag = 1;
        memset(mid,0,sizeof(mid));
        memset(c2,0,sizeof(c2));
        memset(c1,0,sizeof(c1));
        memset(di,0,sizeof(di));
        memset(dj,0,sizeof(dj));
        memset(u,0,sizeof(u));
        memset(con,0,sizeof(con));
        memset(out,-1,sizeof(out));
        for( int i=0; i<n; i++ ){
            scanf("%s",str);
            d = 1;
            ss[0] = str[0]-'a';
            for( int j=1; str[j]; j++ ){
                if(str[j]!=str[j-1]){
                    ss[d++] = str[j]-'a';
                }
            }
            for( int j=1; j<d-1; j++ ){
                if(mid[ss[j]]){
                    flag = 0;
                }
                mid[ss[j]] = 1;
            }
            if(d>1){
                if(ss[0]==ss[d-1]){
                    flag = 0;
                }
            }
            c2[ss[0]][ss[d-1]]++;
        }
        for( int i=0; i<26; i++ ){
            for( int j=0; j<26; j++ ){
                con[i][j] = 0;
                if(i!=j){
                    if(c2[i][j]){
                        if(c2[j][i]){
                            flag = 0;
                        }
                        if(c2[i][j]>1 || di[i] || dj[j]){
                            flag = 0;
                        }
                        out[i] = j;
                        di[i]++;
                        dj[j]++;
                        con[i][j] = 1;
                    }
                }else{
                    c1[i] = c2[i][i];
                }
                if(c2[i][j] && (mid[i] || mid[j])){
                    flag = 0;
                }
            }
        }
        for( int k=0; k<26; k++ ){
            for( int i=0; i<26; i++ ){
                for( int j=0; j<26; j++ ){
                    con[i][j] |= (con[i][k]&con[k][j]);
                }
            }
        }
        for( int i=0; i<26; i++ ){
            if(con[i][i]){
                flag = 0;
            }
        }
        printf("Case #%d: ",tt+1);
        if(!flag){
            puts("0");
            continue;
        }
        long long s = 1;
        d = 0;
        for( int i=0; i<26; i++ ){
            s = (s*fac[c1[i]])%MOD;
            if(u[i]) continue;
            if(dj[i]==0 && di[i]!=0){
                d++;
                for( int j=i; j!=-1; j=out[j] ){
                    u[j] = 1;
                }
            }else if(di[i]==0 && dj[i]==0 && c1[i]!=0){
                d++;
            }
        }
        s = (s*fac[d])%MOD;
        printf("%lld\n",s);
    }
    return 0;
}
