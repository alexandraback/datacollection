#include <bits/stdc++.h>
#define gcd         __gcd
#define bitcount    __builtin_popcountll
#define rep(i,j,n)  for(i=j;i<n;i++)
#define tr(it,c)    for(auto it=(c).begin();it!=(c).end();it++)
#define pb          push_back
#define mp          make_pair
#define hell        1000000007
#define uset        unordered_set
#define umap        unordered_map
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;

template <class T> T& get(T &n) {
    cin>>n;
    return n;
}

int sum(vector<int> &v,int mask){
    int s=0;
    while(mask){
        s+=v[int(log2(mask&(-mask)))];
        mask&=mask-1;
    }
    return s;
}

bool notall(vector<bool> v){
    tr(it,v)
        if(!*it)
            return true;
    return false;
}

int main() {
    static int T,N,i,j,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    get(T);
    rep(k,1,T+1){
        int C,D,V;
        cin>>C>>D>>V;
        //C=1 for small
        vector<bool> possible(V+1,0);
        possible[0]=1;
        
        vector<int> coins(D);
        rep(i,0,D)
            get(coins[i]);
        sort(coins.begin(), coins.end());
        
        rep(j,1,(1<<D)){
            int t=sum(coins,j);
            if(t<=V)
                possible[t]=1;
        }
        
        int ans=0;
        while(notall(possible)){
            int next=-1,extra=-1;
            rep(i,1,30){
                if(binary_search(coins.begin(), coins.end(), i))
                    continue;
                int cur=0;
                rep(j,0,V+1-i){
                    if(possible[j] && !possible[j+i])
                        cur++;
                }
                if(cur>extra){
                    extra=cur;
                    next=i;
                }
            }
//            cerr<<"ERR:"<<next<<endl;
            rep(j,0,V+1-next){
                possible[j+next]=1;
            }
            ans++;
        }
        
        static char ans_string[100];
        sprintf(ans_string,"Case #%d: %d",k,ans);
        cout<<ans_string<<'\n';
    }
    return 0;
}

