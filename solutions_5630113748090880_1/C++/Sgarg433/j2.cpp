#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("j2.txt","r",stdin);
freopen("j2outl.txt","w",stdout);
int t;
cin>>t;
for(int z=0;z<t;z++){
int n;
cin>>n;
int arr[2501];
for(int i=0;i<2501;i++){
arr[i]=0;
}
for(int i=0;i<(2*n-1);i++){
    for(int j=0;j<n;j++){
        int k;
        cin>>k;
        arr[k]++;
    }
}
cout<<"Case #"<<z+1<<": ";
for(int i=0;i<2501;i++){
if(arr[i]%2==1){
cout<<i<<" ";
}
}
cout<<endl;
}
}
