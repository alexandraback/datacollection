#include <bits/stdc++.h>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define BE(a) a.begin(), a.end()

using namespace std;
const int mod = 1000000007;
#define MUL(a, b) ((a*1LL*b)%mod)
#define ADD(a, b) ((a+b)%mod)

int main(){
    int t, z;
    cin>>t;
    for(z = 1;z<=t;z++){
        int n;
        cin>>n;
        vector<string> topics[2];
        for(int i = 0;i<n;i++){
            string s1, s2;
            cin>>s1>>s2;
            topics[0].push_back(s1);
            topics[1].push_back(s2);
        }
        int res = 0;
        for(int i = 0;i<(1<<n);i++){
            bool possible=true;
            int ans = 0;
            for(int j = 0;j<n;j++){
                if(i&(1<<j)){
                    ans++;
                    bool fake1 = false, fake2 = false;
                    for(int k = 0;k<n;k++){
                        if(!(i&(1<<k))){
                            if(topics[0][k] == topics[0][j])
                                fake1 = true;
                            if(topics[1][k] == topics[1][j])
                                fake2 = true;
                        }
                        if(fake1 && fake2)break;
                    }
                    if(!(fake1 && fake2)){
                        possible = false;
                        break;
                    }
                }
            }
            if(possible)
                res = max(res, ans);
        }
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
}
