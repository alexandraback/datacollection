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

map<char,int> letters;
vector<map<char,int> > let= {{{'Z',1},{'E',1},{'R',1},{'O',1}},
                             {{'O',1},{'N',1},{'E',1}},
                             {{'T',1},{'W',1},{'O',1}},
                             {{'T',1},{'H',1},{'R',1},{'E',2}},
                             {{'F',1},{'O',1},{'R',1},{'U',1}},
                             {{'F',1},{'I',1},{'V',1},{'E',1}},
                             {{'S',1},{'I',1},{'X',1}},
                             {{'S',1},{'E',2},{'V',1},{'N',1}},
                             {{'E',1},{'I',1},{'G',1},{'H',1},{'T',1}},
                             {{'N',2},{'I',1},{'E',1}},
                             {{'N',1},{'T',1},{'E',1}},
};
int remaining = 0;
VI seq;
VI res;
bool ok;
void brute(int cur){
    if(remaining==0){
        ok = true;
        res = seq;
        return;
    }
    if(cur>=10) return;
    brute(cur+1);
    if(ok) return;
    bool possible = true;
    for(const auto& l : let[cur]){
        if(letters[l.first]<l.second){
            possible = false;
            break;
        }
    }
    if(!possible) return;
    for(const auto& l : let[cur]){
        letters[l.first]-=l.second;
        remaining-=l.second;
    }
    seq.push_back(cur);
    brute(cur);
    if(ok) return;
    seq.pop_back();
    for(const auto& l : let[cur]){
        letters[l.first]+=l.second;
        remaining+=l.second;
    }
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    FOR(t,T){
        string str;
        cin>>str;
        letters.clear();
        remaining = str.size();
        seq.clear();
        ok = false;
        for(char c: str){
            letters[c]++;
        }
        brute(0);
        cout<<"Case #"<<t+1<<": ";
        PRINT(res,"");

    }
    

    return 0;
}
