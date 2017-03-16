#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long int LL;
typedef vector<int> VI;

#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define F first
#define INF 2000000000
#define MOD 1000000007
#define LD long double

#define L 112
#define S 112

int pi[L];
double dp[S][L];

int main(){
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);
	int t;
	sd(t);
	for(int kas = 1; kas <= t; kas++){
	    cout<<"Case #"<<kas<<": ";
        int k, l, s, i, j, p, j2;
        string alp, str;
        sd(k); sd(l); sd(s);
        cin>>alp;
        cin>>str;
        str = " " + str;
        for(i = 1; i <= l; i++){
            for(j = 0; j < k; j++){
                if(str[i] == alp[j]){
                    break;
                }
            }
            if(j == k){
                break;
            }
        }
        if(i <= l){
            printf("0.0\n");
            continue;
        }
        pi[1] = 0;
        j = 0;
        for(i = 2; i <= l; i++){
            while(j > 0){
                if(str[j + 1] == str[i]){
                    break;
                }
                j = pi[j];
            }
            if(str[j + 1] == str[i]){
                j++;
            }
            pi[i] = j;
        }
        double ans = 1 + int((s - l) / (l - pi[l]));
        for(i = 0; i <= s; i++){
            for(j = 0; j <= l; j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(i = 0; i < s; i++){
            //cout<<i<<endl;
            for(j2 = 0; j2 <= l; j2++){
                for(p = 0; p < k; p++){
                    j = (j2 == l ? pi[l] : j2);
                    while(j > 0){
                        if(str[j + 1] == alp[p]){
                            break;
                        }
                        j = pi[j];
                    }
                    if(str[j + 1] == alp[p]){
                        j++;
                    }
                    dp[i + 1][j] += dp[i][j2] / k;
                }
            }
            ans -= dp[i + 1][l];
        }
        printf("%0.9f\n", ans);
	}
	return 0;
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
