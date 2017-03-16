#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <limits>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;

int main (){
    ifstream fin("B-small-attempt2.in");
    ofstream fout("B.out");
    int cpt; fin>>cpt;
    for (int k=1;k<=cpt;++k){
        int n; fin>>n;
        string s;
        vector<vector<char> > V(n);
        for (int i=0;i<n;++i) {
            fin>>s;
            char prv='0';
            for (int j=0;j<s.size();++j){
                if (s[j]!=prv) {
                    V[i].push_back(s[j]);
                    prv=s[j];
                }
            }
        }
        /*for (int i=0;i<n;++i){
            for (int j=0;j<V[i].size();++j){
                fout<<V[i][j];
            }
            fout<<endl;
        }*/
        sort(V.begin(),V.end());
        long long ans=0;
        char prev='0';
        long long coef=1;
        vector<bool> vis(n);
        fill(vis.begin(),vis.end(),0);
        for (int i=0;i<n;++i){
            long long k=1;
            for (int j=i+1;j<n;++j){
                if (V[i]==V[j] && !(vis[i] && vis[j])) {
                    k++;
                    vis[i]=true;
                    vis[j]=true;
                }
            }
            coef*=k;
        }
        do{
            set<char> S;
            bool stop=false;
            for (int i=0;i<n;++i){
                //fout<<V[i]<<"  ";
                for (int j=0;j<V[i].size();++j){
                    if (V[i][j]!=prev){
                        int sz=S.size();
                        S.insert(V[i][j]);
                        if (S.size()==sz) stop=true;
                        prev=V[i][j];
                    }
                }
            }
            if (!stop) ++ans;
            //if (!stop) {for (int i=0;i<n;++i) fout<<V[i]<<"  "; fout<<endl;}
            //fout<<endl;
        } while (next_permutation(V.begin(),V.end()));
        fout<<"Case #"<<k<<": "<<ans*coef<<endl;
    }
    return 0;
}
