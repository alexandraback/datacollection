#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool dfs(int x, int y, //cord 
        int left, // num of mine left
        const int r,
        const int c,
        const int m, 
        vector<vector<char> >& s) {
    vector<pair<int,int> > neigh;
    for (int i=x-1;i<=x+1;++i) {
        for (int j=y-1;j<=y+1;++j) {
            if(i<0 || i>=r) continue;
            if(j<0 || j>=c) continue;
            if(i==x&&j==y) continue;
            if (s[i][j]=='*') {
                neigh.push_back(make_pair(i,j));
                s[i][j]='.';
            }
        }
    }
    left-=neigh.size();
    if (left==m) {
        return true;
    }
    if (left > m)  {
        for (int i=0;i<neigh.size();++i) {
            if (dfs(neigh[i].first, neigh[i].second, left,r,c,m,s)) {
                return true;
            }
        }
    }
    for (int i=0;i<neigh.size();++i) {
        s[neigh[i].first][neigh[i].second]='*';
    }
    return false;
}
int main(int argc, char* argv[]) {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cout<<"Case #"<<t<<": "<<endl;
        int r,c,m;
        cin>>r>>c>>m;
        vector<vector<char> > s(r,vector<char>(c,'*'));
        bool ans=false;
        if (m>=r*c) {
            ans=false;
        } else if (m==r*c-1) {
            s[0][0]='c';
            ans=true;
        } else {
            for (int i=0;i<(r+1)/2;++i) {
                for (int j=0;j<(c+1)/2;++j) {
                    s[i][j]='c';
                    if (dfs(i,j,r*c-1,r,c,m,s)) {
                        ans=true;
                        break;
                    }
                    s[i][j]='*';
                }
                if (ans) break;
            }
        }
        if (ans) {
            for (int i=0;i<r;++i) {
                for (int j=0;j<c;++j) {
                    cout<<s[i][j];
                }
                cout<<endl;
            }
        } else {
            cout<<"Impossible"<<endl;
        }
    }
    return 0;
}
