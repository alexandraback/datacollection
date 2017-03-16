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

int a,b,k;

int extra(){
    scanf("%d%d%d",&a, &b, &k);
    if(a>b) swap(a,b);
    
    int pos = (1<<30);

    ll pocet = 0;
    For(i, a) For(j, b) {
        if ((i & j) < k) pocet++;
    }
    printf("%lld\n", pocet);
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
