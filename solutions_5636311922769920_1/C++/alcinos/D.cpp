//problem name
//url

#include  <bits/stdc++.h>//include all stl
#define LL unsigned long long
#define ULL unsigned LL
#define FOR(i,n) for(int i=0;i<n;i++)
#define ALL(v) begin(v),end(v)
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define PRINT(v,sep) {copy(begin(v), end(v)-1, ostream_iterator<int>(cout, sep)); cout << v.back()<<endl;}
#define MAX(v) accumulate(ALL(v),0,[](int a,int b){return max(a,b);});
#define MIN(v) accumulate(ALL(v),0,[](int a,int b){return min(a,b);});
using namespace std;
template<typename T>
inline T SUM(const vector<T>& v){
    return accumulate(ALL(v),T(0),[](T a,T b){return a+b;});
}

typedef vector<int>   VI;       typedef vector<bool> VB;
typedef vector<VI>   VVI;       typedef vector<double> VD;
typedef vector<VVI> VVVI;       typedef vector<VD> VDD;

typedef pair<int,int> PI;       typedef pair<double,double> PD;
typedef pair<PI,int> PII;

int main(){
    ios::sync_with_stdio(false);
    /* 
    const LL s = 41;
    for(LL i = 0;i<(1LL<<41);i++){
        bitset<s> bit(i);
        if(bit.none()) continue;
        if(i%10000000) cout<<i<<endl;
        // cout<<bit<<endl;
        VB pat;
        FOR(j,s)pat.push_back(bit[j]);
        FOR(j,3){
            VB nouv;
            FOR(k,pat.size()){
                if(pat[k])
                    FOR(l,s) nouv.push_back(true);
                else
                    FOR(l,s) nouv.push_back(bit[l]);
            }
            pat = nouv;
        }
        // cout<<(pat[586]||pat[38])<<endl;
        // cout<<(pat[506]||pat[38])<<endl;
        bool ok = pat[43]||pat[5212]||pat[10381]||pat[15550]||pat[20719]||pat[25888]||pat[31057]||pat[36226]||pat[41395]||pat[46564]||pat[51733]||pat[56902]||pat[62071]||pat[65517];
        assert(ok);
        //PRINT(pat,"");
    }
    cout<<"ok"<<endl;*/
    int T;
    cin>>T;
    FOR(t,T){
        int K,C,S;
        cin>>K>>C>>S;
        cout<<"Case #"<<t+1<<":";
        int origC = C;
        if(C*S<K){
            cout<<" IMPOSSIBLE"<<endl;
        }else{
            C = min(C,K);
            if(C==1){
                VI res(S);
                iota(ALL(res),1);
                PRINT(res," ");
                continue;
            }
            LL dec = 0;
            int bound = int(ceil(double(K)/double(C)));
            assert(bound<=S);
            FOR(i,bound){
                if(dec+C>K){
                    assert(i==bound-1);
                    dec = K-C;
                }
                LL u = dec;
                for(LL j=1;j<C;j++){
                    u = (K*u) + j +dec;
                }
                cout<<" "<<u+1;
                assert(u<pow(K,origC));

                dec+=C;
            }
            cout<<endl;
        }
    }
    

    return 0;
}
