//problem name
//url

#include  <bits/stdc++.h>//include all stl
#define LL long long
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
    int T;
    cin>>T;
    FOR(t,T){
        cout<<"Case #"<<t+1<<": ";
        int N;
        cin>>N;
        if(N==0) {
            cout<<"INSOMNIA"<<endl;
            continue;
        }
        unordered_set<char> seen;
        LL K = 0;
        do{
            K+=N;
            string str = to_string(K);
            for(auto c: str) seen.insert(c);
        }while(seen.size()<10);
        cout<<K<<endl;
    }
    

    return 0;
}
