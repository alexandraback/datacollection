//problem name
//url

#include  <bits/stdc++.h>//include all stl
#define LL long long
#define ULL unsigned LL
#define FOR(i,n) for(int i=0;i<n;i++)
#define ALL(v) begin(v),end(v)
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define PRINT(v,sep) {copy(begin(v), end(v)-1, ostream_iterator<int>(cout, sep)); cout << *(end(v)-1)<<endl;}
#define MAX(v) accumulate(ALL(v),INT_MIN,[](int a,int b){return max(a,b);})
#define MIN(v) accumulate(ALL(v),INT_MAX,[](int a,int b){return min(a,b);})
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

VI nbrA,nbrB;
int L;
int best_dif;
PI best_co;
void brute(int pos,int C,int J){
    if(pos>=L){
        if(abs(J-C)<best_dif){
            best_dif = abs(J-C);
            best_co = PI({C,J});
        }
        if(abs(J-C)==best_dif){
            if(C<best_co.first){
                best_co = PI({C,J});
            }else if(J<best_co.second)
                best_co = PI({C,J});
        }
        return;
    }
    if(nbrA[pos]==-1){
        if(nbrB[pos]==-1){
            FOR(a,10){
                FOR(b,10){
                    brute(pos+1,C*10+a,J*10+b);
                }
            }
        }else{
            FOR(a,10){
                brute(pos+1,C*10+a,J*10+nbrB[pos]);
            }
        }
    }else{
        if(nbrB[pos]==-1){
            FOR(b,10){
                brute(pos+1,C*10+nbrA[pos],J*10+b);
            }
        }else{
            brute(pos+1,C*10+nbrA[pos],J*10+nbrB[pos]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    FOR(t,T){
        string strA,strB;
        cin>>strA>>strB;
        L = strA.size();
        nbrA.assign(L,-1);
        nbrB.assign(L,-1);
        FOR(i,L){
            if(strA[i]!='?'){
                nbrA[i] = strA[i]-'0';
            }
            if(strB[i]!='?'){
                nbrB[i] = strB[i]-'0';
            }
        }
        best_dif = INT_MAX;
        brute(0,0,0);
        cout<<"Case #"<<t+1<<": ";
        cout.width(L);
        cout<<best_co.first;
        cout.fill('0');
        cout<<" ";
        cout.width(L);
        cout<<best_co.second;
        cout.fill('0');
        cout<<endl;
    }
    

    return 0;
}
