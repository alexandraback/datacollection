#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
char s[MAXN], str[MAXN];
int Left[MAXN], Right[MAXN];
char v[4][4]={
    '1','i','j','k',
    'i','0','k','J',
    'j','K','0','i',
    'k','j','I','0'
};
int val(char c){
    if(c=='1') return 1;
    if(c=='i') return 2;
    if(c=='j') return 3;
    if(c=='k') return 4;
    if(c=='0') return -1;
    if(c=='I') return -2;
    if(c=='J') return -3;
    if(c=='K') return -4;
}
map<int, map<int,int> > mp, decodeL, decodeR;
void init(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            int x=val(v[i-1][j-1]);
            mp[i][j]=x;
            decodeL[j][x]=i;
            decodeR[i][x]=j;
            mp[-i][j]=-x;
            decodeL[j][-x]=-i;
            decodeR[-i][x]=j;
            mp[i][-j]=-x;
            decodeL[-j][-x]=i;
            decodeR[i][-x]=-j;
            mp[-i][-j]=-x;
            decodeL[-j][-x]=-i;
            decodeR[-i][-x]=-j;
        }
    }
}
vector<int> vL, vR;
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    init();
    int t; cin>>t;
    for(int cs=1; cs<=t; cs++){
        int X, L; cin>>L>>X;
        scanf("%s",s);
        strcpy(str,s);
        for(int i=1; i<X; i++){
            strcat(str,s);
        }
        vL.clear(); vR.clear();
        Left[0]=val(str[0]);
        if(Left[0]==2){
            vL.push_back(0);
        }
        for(int i=1; i<X*L; i++){
            Left[i]=mp[Left[i-1]][val(str[i])];
            if(Left[i]==2){
                vL.push_back(i);
            }
        }
        Right[X*L-1]=val(str[X*L-1]);
        if(Right[X*L-1]==4){
            vR.push_back(X*L-1);
        }
        for(int i=X*L-2; i>=0; i--){
            Right[i]=mp[val(str[i])][Right[i+1]];
            if(Right[i]==4){
                vR.push_back(i);
            }
        }
        printf("Case #%d: ",cs);
        for(auto p1: vL){
            for(auto p2: vR){
                if(p1+1<p2){
                    if(decodeR[Left[p1]][Left[p2-1]]==3){
                        goto ok;
                    }
                }
                else break;
            }
        }
        puts("NO");
        continue;
        ok:; puts("YES");
    }
    return 0;
}
