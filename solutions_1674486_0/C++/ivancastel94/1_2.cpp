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

int i,t,n,m,l,j,cases;
bool b[1001][1001];

int paths(int ini, int fin){
    int sum=0;
    if(ini==fin)return 1;
    for(int k=0;k<n;k++){
        if(b[ini][k]==1)sum+=paths(k,fin);
        }
    return sum;
    }
    
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>t;
    cases=1;
    while(t>0){
        for(i=0;i<n;i++)for(j=0;j<n;j++)b[i][j]=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>m;
            for(j=0;j<m;j++){
                cin>>l;
                b[i][l-1]=1;
                }
            }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(paths(i,j)>1)break;
                }
            if(j!=n)break;
            }
        cout<<"Case #"<<cases<<": ";
        if(j!=n)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        cases++;
        t--;
        }
    }
