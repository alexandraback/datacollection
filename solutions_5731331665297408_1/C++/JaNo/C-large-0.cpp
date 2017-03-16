//Fruit of Light
//FoL CC
//Apple Strawberry

#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<cstring>
#include<cassert>

using namespace std;

#define For(i, n) for(int i = 0; i<(n); ++i)
#define ForEach(it, i) for(typeof i.begin() it = i.begin(); it!=i.end(); ++it)
#define INF 1023456789
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,m;
int zip[100];
int M[100][100];
int was[100], flod[100];
int otec[100];
vi sus[100];
vi dalsi;
string code;

bool mycomp(int i, int j){
    return zip[i] < zip[j];
}

void flood(int x){
    flod[x] = 1;
    For(i, n) if ((!was[i]) && (!flod[i]) && M[x][i]) flood(i);
}

bool zijem(int x){
    For(i, n) flod[i] = 0;
    while(x>=0) {
        flood(x);
        x = otec[x];
    }
    For(i, n) if (flod[i] + was[i] == 0) return false;
    return true;
}

int extra(){
    scanf("%d %d",&n, &m);
    int zac = 0;
    For(i, n){
        scanf("%d", zip+i);
        if (zip[i]<zip[zac]) zac = i;
        was[i] = 0;
        For(j, n) M[i][j] = 0;
    }
    For(i, m){
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        M[a][b] = M[b][a] = 1;
    }
    code = "";
    dalsi = vi(1,zac);
    int last = -1;
    For(q, n){
        sort(dalsi.begin(), dalsi.end(), mycomp);
        assert(dalsi.size());
        int x = dalsi[0];
        dalsi.clear();
        while(last>=0 && (!M[last][x])) last = otec[last];
        otec[x] = last;
        last = x;
        was[x] = 1;
        code+=to_string(zip[x]);
        while(x>=0 && zijem(x)){
            For(j, n) if ((!was[j]) && M[x][j]) dalsi.push_back(j);
            x = otec[x];
        }
    }
    printf("%s\n", code.c_str());
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: ",i+1);
        extra();
    }
}
