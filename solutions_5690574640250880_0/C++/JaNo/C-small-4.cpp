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

using namespace std;

#define For(i, n) for(int i = 0; i<(n); ++i)
#define ForEach(it, i) for(typeof i.begin() it = i.begin(); it!=i.end(); ++it)
#define INF 1023456789
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int r, s, m;
int A[100][100];

int extra(){
    scanf("%d %d %d",&r, &s, &m);
    For(i, max(r,s)) For(j, max(r,s)) A[i][j] = '*';
    bool otoc = 0;
    if (r>s){
        swap(r,s);
        otoc = 1;
    }
    int free = r*s-m;
    if (free==1) goto ano;
    if (min(r,s) == 1){
        For(i, free) A[0][i] = '.';
        goto ano;
    }
    if (min(r,s) == 2){
        if (free%2) goto nie;
        if (free==2) goto nie;
        For(i, free/2){
            A[0][i] = '.';
            A[1][i] = '.';
        }
        goto ano;
    }
    if (free >= 4 && free != 5 && free != 7) {
        if (free > 2*s){
            int poc = free;
            int i = 0, j = 0;
            while (poc--){
                A[i][j] = '.';
                j++;
                i+=j/s;
                j%=s;
            }
            if (free % s == 1){
                A[i][j] = '.';
                A[i-1][s-1] = '*';
                if (i<=2) {
                    A[i][j+1] = '.';
                    A[i-2][s-1] = '*';
                }
            }
            goto ano;
        }
        if (free%2 == 0) 
            For(i, free/2){
                A[0][i] = '.';
                A[1][i] = '.';
            }
        else{
            For(i, (free-3)/2){
                A[0][i] = '.';
                A[1][i] = '.';
            }
            A[2][0] = '.';
            A[2][1] = '.';
            A[2][2] = '.';
        }            
        goto ano;
    }
    goto nie;
    ano:;
    A[0][0] = 'c';
    if (otoc)
        For(i, s) {For(j, r) printf("%c",A[j][i]); printf("\n"); }
    else
        For(i, r) {For(j, s) printf("%c",A[i][j]); printf("\n"); }
    

    return 0;
    nie:;
    printf("Impossible\n");
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: \n",i+1);
        extra();
    }
}
