#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<bitset>
#define pii pair<int,int>
#define A first
#define B second
using namespace std;
int n,a[27],c[10],M,pos,br;
long long A[7];
char s[7][20001];
void Do(){
    scanf("%s %s",s[0],s[1]);
    M = -1; pos = 0; n = 0;
    for(int i=0;s[0][i]!='\0';i++){
        if(s[0][i] != '?' && s[1][i] != '?' && s[0][i] != s[1][i]){
            M = (s[0][i] > s[1][i] ? 0 : 1);
            pos = i; break;
        }
    }
    for(int i=0;s[0][i] != '\0';i++){
        n++;
        if(s[0][i] == '?' && s[1][i] == '?') s[2][i] = s[3][i] = '0' ;
        else if(s[0][i] == '?') s[2][i] = s[3][i] = s[1][i];
        else if(s[1][i] == '?') s[2][i] = s[3][i] = s[0][i];
        else s[2][i] = s[0][i], s[3][i] = s[1][i];
    }
    s[2][n] = s[3][n] = s[4][n] = s[5][n] = '\0';
    for(int i=0;i<4;i++) A[i] = 0ll;

    for(int i=0;s[0][i] != '\0';i++) s[4][i] = s[2][i], s[5][i] = s[3][i];

    br = 0;
    for(int i=pos-1;i>=0 && br == 0 && M != -1;i--){
        if(s[M][i] == '?' && s[(1^M)][i] == '?') s[M+2][i] = '0', s[(1^M)+2][i] = '1', br = 1;
        else if(s[M][i] == '?'){
            if(s[(1^M)+2][i] != '0') s[M+2][i] = s[(1^M)+2][i]-1, br = 1;
            else s[M+2][i] = '9';
        }
        else if(s[(1^M)][i] == '?'){
            if(s[M+2][i] != '9') s[(1^M)+2][i] = s[M+2][i]+1, br = 1;
            else s[(1^M)+2][i] = '0';
        }
    }

    for(int i=pos+1;s[0][i] != '\0' && M != -1; i++){
        if(s[M][i] == '?' && s[(1^M)][i] == '?') s[M+2][i] = '9', s[(1^M)+2][i] = s[(1^M)+4][i] = '0';
        else if(s[M][i] == '?')
            s[M+2][i] = '9';
        else if(s[(1^M)][i] == '?'){
            s[(1^M)+2][i] = '0';
        }
    }

    for(int i=pos+1;s[0][i] != '\0' && M != -1; i++){
        if(s[M][i] == '?' && s[(1^M)][i] == '?') s[M+4][i] = '0', s[(1^M)+4][i] = '9';
        else if(s[M][i] == '?')
            s[M+4][i] = '0';
        else if(s[(1^M)][i] == '?'){
            s[(1^M)+4][i] = '9';
        }
    }
    //printf("%s\n",s[2]);
    for(int i=0;i<4;i++)
        for(int j=0;s[0][j] != '\0';j++)
            A[i] *= 10ll, A[i] += s[i+2][j]-'0';
    if(abs(A[0]-A[1]) < abs(A[2]-A[3])) printf("%s %s",s[2],s[3]);
    else if(abs(A[0]-A[1]) > abs(A[2]-A[3])) printf("%s %s",s[4],s[5]);
    else if(A[0] > A[2]) printf("%s %s",s[4],s[5]);
    else if(A[0] < A[2]) printf("%s %s",s[2],s[3]);
    else if(A[1] < A[3]) printf("%s %s",s[2],s[3]);
    else printf("%s %s",s[4],s[5]);

}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int rr=1;rr<=T;rr++){
        printf("Case #%d: ",rr);
        Do();
        printf("\n");
    }
    return 0;
}
