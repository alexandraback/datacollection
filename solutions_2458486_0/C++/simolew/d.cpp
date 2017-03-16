#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

bool tested[3000000];
vector<vector<int> > inside;
vector<int> types;
vector<int> start;
vector<int> solution;
int N,K;
string dbg(int state) {
stringstream ss;
for(int i=0;i<N;i++) ss << ((state & (1<<i)) > 0) ? 1 : 0;
return ss.str();
}
bool d(int state) {
    if(tested[state]) return false;
    tested[state]=true;
    if(state == (1<<N)-1) return true;
    vector<int> keys(200);
    for(int i=0;i<200;i++) keys[i]=start[i];
    for(int i=0;i<N;i++) {
        if(state & (1<<i)) {
            keys[types[i]]--;
            for(int j=0;j<inside[i].size();j++) keys[inside[i][j]]++;
        }
    }
    for(int i=0;i<N;i++) {
        if((state & (1<<i)) == 0 && keys[types[i]]>0) {
            if(d(state | (1<<i))) {
                solution.push_back(i);
                return true;
            }
        }
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    for(int T=0;T<t;T++) {
        solution.clear();
        for(int a=0;a<3000000;a++) tested[a]=false;
        cin>>K>>N;
        start.resize(200);
        for(int u=0;u<200;u++) start[u]=0;
        inside.clear();
        inside.resize(N);
        types.resize(N);

        for(int i=0;i<K;i++) {
            int typ=0;
            cin>>typ;
            start[typ]++;
        }
        for(int i=0;i<N;i++) {
            cin>>types[i];
            int sz;
            cin>>sz;
            inside[i].resize(sz);
            for(int j=0;j<sz;j++) cin>>inside[i][j];
        }
        cout<<"Case #"<<T+1<<": ";
        if(d(0)) {
            for(int i=solution.size()-1;i>=0;i--) {
                cout<<solution[i]+1;
                if(i!=0) cout<<" ";
            }
        } else cout<<"IMPOSSIBLE";
        cout<<endl;
    }
}
