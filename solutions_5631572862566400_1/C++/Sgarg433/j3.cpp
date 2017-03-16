#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("j3.txt","r",stdin);
freopen("j3outl.txt","w",stdout);
int t;
cin>>t;
for(int z=0;z<t;z++){
    int n;
    cin>>n;
    int arr[n];
    bool a[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
        a[i]=false;
    }
    int ans=0;
    for(int i=0;i<n;i++){
            int k=1;
            int j=arr[i];
            k++;
            while(arr[j]!=i && k<=n){
                j=arr[j];
                k++;
            }
            if(arr[j]==i){
                ans=max(ans,k);
            }
    }
    for(int i=0;i<n;i++){
        if(i==arr[arr[i]]){
            a[i]=true;
            a[arr[i]]=true;
        }
    }
    int arr1[n];
    for(int i=0;i<n;i++){
        arr1[i]=0;
    }
    for(int i=0;i<n;i++){
        if(a[i]==false){
            int j=arr[i];
            int k=1;
            while(a[j]==false && k<=n){
                j=arr[j];
                k++;
            }
            if(a[j]==true){
                arr1[j]=max(arr1[j],k);
            }
        }
    }
    int ans1=0;
    for(int i=0;i<n;i++){
        if(a[i]==true){
            a[i]=false;
            a[arr[i]]=false;

            ans1+=(2+arr1[i]+arr1[arr[i]]);
        }
    }
    //cout<<ans<<" "<<ans1<<endl;
    cout<<"Case #"<<z+1<<": "<<max(ans,ans1)<<endl;
}
}
