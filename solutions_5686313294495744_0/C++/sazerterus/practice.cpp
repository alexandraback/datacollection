#include <bits/stdc++.h>

using namespace std;


int main(){//ios::sync_with_stdio(0);
    freopen("input1.txt","r",stdin);
 freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    int index=1;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int> > V;

        map<pair<int,int>,int > M;
        map<string,int> G;
        int tim=1;
        for(int i=1;i<=n;++i){
            string a,b;
            cin >> a >> b;

            if(G[a]==0){
                G[a]=++tim;
            }
            if(G[b]==0){
                G[b]=++tim;
            }
            V.push_back(make_pair(G[a],G[b]));
            M[make_pair(G[a],G[b])]=1;


        }
        set<int> S;
        set<int> T;
        int ans=0;

        for(int i=0;i<(1<<n);++i){
            int temp=0;
            vector<int> forw;
            vector<int> rev;
            map<pair<int,int>,int > as;
            for(int j=0;j<n;++j){
                if(i & (1<<j)){
                    forw.push_back(V[j].first);
                    rev.push_back(V[j].second);
                    ++as[V[j]];
                }
            }

            for(int j=0;j<forw.size();++j){
                for(int k=0;k<rev.size();++k){

                    if(M[make_pair(forw[j],rev[k])]>as[make_pair(forw[j],rev[k])]){
                        ++temp;
                       ++as[make_pair(forw[j],rev[k])];
                        }
                }
            }
            ans=max(ans,temp);
        }

        cout << "Case #" << index++ <<  ": "  <<  ans << endl;
    }



    return 0;
}
