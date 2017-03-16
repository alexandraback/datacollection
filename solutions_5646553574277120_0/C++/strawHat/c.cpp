#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long int LL;
typedef vector<int> VI;

#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define LD long double

#define D 11234

LL a[D];

int main(){
    freopen("inp.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	int t;
	sd(t);
	for(int kas = 1; kas <= t; kas++){
	    cout<<"Case #"<<kas<<": ";
        LL c, d, v;
        LL ans, cs;
        cin>>c>>d>>v;
        for(int i = 0; i < d; i++){
            cin>>a[i];
        }
        sort(a, a + d);
        cs = 0;
        ans = 0;
        for(int i = 0; i < d; i++){
            while(a[i] > cs + 1){
                cs = (cs + 1) * c + cs;
                ans++;
            }
            cs = a[i] * c + cs;
            if(cs >= v){
                break;
            }
        }
        while(cs < v){
            cs = (cs + 1) * c + cs;
            ans++;
        }
        /*int ans2 = 5;
        for(int i, mask = 0; mask < 32; mask++){
            vector<int> vec;
            for(i = 0; i < d; i++){
                vec.PB(a[i]);
            }
            for(i = 0; i < 5; i++){
                if(mask & (1<<i)){
                    vec.PB((1<<i));
                }
            }
            bool can[v + 1];
            memset(can, false, sizeof can);
            int s = vec.size();
            for(int mask2 = 0; mask2 < (1<<s); mask2++){
                int sum = 0;
                for(i = 0; i < s; i++){
                    if(mask2 & (1<<i)){
                        sum += vec[i];
                    }
                }
                if(sum <= v){
                    can[sum] = true;
                }
            }
            for(i = 1; i <= v; i++){
                if(can[i] == false){
                    break;
                }
            }
            if(i > v){
                ans2 = min(ans2, s - (int)d);
            }
        }
        if(ans2 != ans){
            cout<<"ERROR!!!"<<" "<<ans2<<" ";
        }*/
        cout<<ans<<'\n';
	}
	return 0;
}
