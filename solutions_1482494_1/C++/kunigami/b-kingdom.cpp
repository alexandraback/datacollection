#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1234
typedef pair<int, int> pii;

int v[MAXN];

struct triple {
    int a, b, c;
};
bool operator< (const triple &t1, const triple &t2){
    if(t1.a != t2.a) return t1.a < t2.a;
    if(t1.b != t2.b) return t1.b < t2.b;
    return t1.c < t2.c;
}
vector<triple> p2, p1;

int main (){

    int T, n;
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> n;
        
        memset(v,0,sizeof(v));
        p1.resize(n);
        for(int i=0; i<n; i++){
            cin >> p1[i].b >> p1[i].a;
            p1[i].c = i;
        }
        sort(p1.begin(), p1.end());
        
        int stars = 0, i2 = 0, cnt = 0;
        bool error = false;
        while(stars < 2*n){
            
            //cout << "estrelas " << stars << endl;
            
            if(p1[i2].a <= stars){
                if(v[i2] == 0) stars += 2;
                else stars += 1;
                v[i2] = 1;
                //cout << "escolhendo 2: " << p1[i2].a << " " << i2 << endl;
                i2++;
                cnt++;
            }
            else {

                int bestFit = -1;
                int bestValue = -1;
                int i1;
                for(i1 = 0; i1 < n; i1++){
                    if(p1[i1].b <= stars && v[i1] == 0 && bestValue < p1[i1].a){
                        bestValue = p1[i1].a;
                        bestFit = i1;
                    }                        
                }
                if(bestFit == -1){
                    error = true;
                    break;
                }
                v[bestFit] = 1;
                stars++;
                cnt++;
                //cout << "escolhendo 1: " << p1[bestFit].b << " " << bestFit << endl;
            }
        }
        printf("Case #%d: ", t+1);
        if(error)
            printf("Too Bad\n");
        else
            printf("%d\n", cnt);
    }

    return 0;
}
