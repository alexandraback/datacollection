#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int i,j,k,l,m,n, cur , test,s,t, mx, a[1005],d, ii,x,r,c;
string str;
int next[1000001];
int ans[1000001];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w", stdout);
    cin>>t;
    for (i=1;i<=1000000;i++){
        int numb = i;
        vector <int> digits;
        while (numb>0){
            digits.push_back(numb%10);
            numb/=10;
        }
        int cur = 0;
        for (j=0;j<digits.size();j++){
            cur=cur*10+digits[j];    
        }
        next[i] = cur;
    }
    
    for (i=0;i<=1000000;i++) ans[i] = 1000000000;
    ans[1] = 1;
    vector <int> bfs;
    bfs.push_back(1);
    for (k=0;k<bfs.size();k++){
        int cur = bfs[k];
        if (ans[cur+1]>ans[cur]+1){
            ans[cur+1] = ans[cur]+1;
            bfs.push_back(cur+1);
        }
        if (ans[next[cur]]>ans[cur]+1){
            ans[next[cur]] = ans[cur]+1;
            bfs.push_back(next[cur]);
        }
    }   
    while(t--){
        cin>>n;
        test++;
        cout<<"Case #"<<test<<": "<<ans[n]<<"\n";
    } 
    return 0;
}
