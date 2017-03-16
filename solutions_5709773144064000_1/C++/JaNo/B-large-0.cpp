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

double c, f, x;

int extra(){
    scanf("%lf %lf %lf",&c, &f, &x);
    double time = 0.0;
    double generate = 2.0;
    double best = x/generate;
    For(i, 100047){
        best = min(best, time + x/generate);
        time += c/generate;
        generate += f;
    }
    printf("%.9lf\n", best);
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: ",i+1);
        extra();
    }
}
