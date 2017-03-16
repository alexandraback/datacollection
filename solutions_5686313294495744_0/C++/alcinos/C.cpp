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

VVI adj_left; //adjency list of the left nodes
int V;        //total number of vertices

VB visited; VI match;
int augment(int l){
    if(visited[l]) return 0;
    visited[l] = true;
    for(auto r : adj_left[l])
        if(match[r] == -1 || augment(match[r])){
            match[r] = l;
            return 1;
        }
    return 0;
}
int BipartiteMatching(){ //returns the size of the matching
    int tot = 0;
    match = VI(V,-1);
    FOR(i,adj_left.size()){
        visited.assign(adj_left.size(),false);
        tot+=augment(i);
    }
    FOR(i,V)if(match[i]!=-1) match[match[i]]=i;
    return tot;
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    FOR(t,T){
        int N;
        cin>>N;
        map<string,int> idA,idB;
        int curA=0,curB = 0;
        vector<PI> edges;
        // VVI graph(2*N);
        FOR(i,N){
            string strA,strB;
            cin>>strA>>strB;
            if(idA.count(strA)==0){
                idA[strA]=curA++;
            }
            if(idB.count(strB)==0){
                idB[strB]=curB++;
            }
            edges.push_back({idA[strA],idB[strB]});
            // graph[idA[strA]].push_back(idB[strB]);
            // graph[idB[strB]].push_back(idA[strA]);
        }
        V = curA+curB;
        adj_left = VVI(curA);
        VVI adj_right = VVI(curB);
        FOR(i,edges.size()){
            edges[i].second+=curA;
        }
        for(const auto& e:edges){
            adj_left[e.first].push_back(e.second);
            adj_right[e.second-curA].push_back(e.first);
        }
        int m = BipartiteMatching();
        FOR(i,curA){
            if(match[i]==-1 && adj_left[i].size()>1){
                match[i] = adj_left[i][0];
            }
        }
        FOR(i,curB){
            if(match[i+curA]==-1 && adj_right[i].size()>1){
                match[i+curA] = adj_right[i][0];
            }
        }
        // FOR(i,N){
        //     cout<<graph[i].size()<<endl;
        //     if(graph[i].size()>0){
        //         cout<<i<<" ";
        //         PRINT(graph[i]," ");
        //     }
        // }
        // cout<<m<<endl;
        LL count = 0;
        for(const auto& e:edges){
            // cout<<e.first<<" "<<e.second<<" "<<match[e.first]<<" "<<match[e.second]<<endl;
            if(match[e.second]!=e.first && match[e.first]!=e.second&& match[e.second]!=-1 && match[e.first]!=-1){
                // cout<<"y"<<endl;
                count++;
            }
        }
        cout<<"Case #"<<t+1<<": "<<count<<endl;;
    }
    

    return 0;
}
