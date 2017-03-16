#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int i,j,k,m,n,x,t;
cin>>t;
k=0;
while(t--){
int flag=1;
k++;
cin>>n>>m;
vector<int> col(m,0),row(n,0);
int arr[n][m];
//int rmax=0,flag=1;
for(i=0;i<n;i++){
for(j=0;j<m;j++){
cin>>x;
row[i]=max(row[i],x);
col[j]=max(col[j],x);
arr[i][j]=x;
}
}
for(i=0;i<n;i++){
if(flag==1){
for(j=0;j<m;j++){
if(arr[i][j]>=col[j] || arr[i][j]>=row[i]){}
else {flag=0;break;}
}
}
else break;
}
if(flag==1) cout<<"Case #"<<k<<": YES\n";
else cout<<"Case #"<<k<<": NO\n";
}
}