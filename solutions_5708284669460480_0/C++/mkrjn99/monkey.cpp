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

void z_algorithm(const char *s,int N,vector<int> &z){
    z.resize(N);
    z[0]=N;
    int l,r,k;
    l=1;r=0;
    rep(k,1,N){
        if(k<=r && k+z[k-l]<=r)
            z[k]=z[k-l];
        else{
            l=k;r=max(l-1,r);
            while(r+1<N && s[r+1]==s[r-l+1])
                r++;
            z[k]=r-l+1;
        }
    }
}

int count_occ(string s1,string s2){
    //count of occ of s1 in s2
    string x=s1+"$"+s2;
    int l=s1.size();
    vector<int> z;
    z_algorithm(x.c_str(),x.size(),z);
    int c=0;
    for(int i=l+1;i<z.size();i++){
        if(z[i]==l)
            c++;
    }
    return c;
}

typedef long double ld;

int main() {
    static int T,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    cerr<<"Err:"<<count_occ(string("ABA"),string("ABABA"))<<endl;
    get(T);
    rep(k,1,T+1){
        int K,L,S;
        cin>>K>>L>>S;
        string keys,word;
        cin>>keys>>word;
        queue<string> q;
        q.push(string(""));
        while(q.front().size()<S){
            string t=q.front();q.pop();
            tr(it,keys){
                q.push(t+*it);
            }
        }
        int maxocc=0;
        ld ans=0;
        while(!q.empty()){
//            cerr<<q.front()<<endl;
            string t=q.front();
            int occ = count_occ(word,t);
            maxocc=max(maxocc,occ);
            ans+=occ*pow(keys.size(),-S);
            q.pop();
        }
        ans=maxocc-ans;
        if(ans<0)
            ans=0;
        static char ans_string[100];
        sprintf(ans_string,"Case #%d: %.7Lf",k,ans);
        cout<<ans_string<<'\n';
    }
    return 0;
}

