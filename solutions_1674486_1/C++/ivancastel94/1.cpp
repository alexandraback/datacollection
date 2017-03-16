#include<iostream>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int i,t,n,m,l,j,cases;
    vector<int> num[1001];
    queue<int> q;
    set<int> s;
    cin>>t;
    cases=1;
    while(t>0){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>m;
            for(j=0;j<m;j++){
                cin>>l;
                num[i].push_back(l-1);
                }
            }
        for(i=0;i<n;i++){
        s.clear();
            for(j=0;j<num[i].size();j++){
                q.push(num[i][j]);
                s.insert(num[i][j]);
                }
            while(q.size()!=0){
                m=q.front();
                q.pop();
                for(j=0;j<num[m].size();j++){
                    q.push(num[m][j]);
                    if(s.count(num[m][j]))break;
                    s.insert(num[m][j]);
                    }
                if(j!=num[m].size())break;
                }
                if(q.size()!=0)break;
            }
        cout<<"Case #"<<cases<<": ";
        if(i!=n)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        for(i=0;i<n;i++)num[i].clear();
        while(q.size()!=0)q.pop();
        s.clear();
        cases++;
        t--;
        }
    }
