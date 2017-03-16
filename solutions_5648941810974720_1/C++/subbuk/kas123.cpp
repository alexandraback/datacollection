#include<bits/stdc++.h>
using namespace std;
 
int main(){
 freopen ("input1.txt","r",stdin);
	freopen ("output1.txt","w",stdout);
    int t;
    cin>>t;
    int z=1;
    while(t--){
        string s;
        cin>>s;
        long long int arr[27]={0}, l=s.size(), ans[2000];
        for(int i=0; i<l; i++){
            int k=s[i]-64;
            arr[k]++;
        }
 
        //for(int i=0; i<=26; i++) cout<<arr[i]<<" ";
 
        int j=0;
        while(arr[26]--){
            ans[j]=0;
            arr[5]--; arr[18]--; arr[15]--;
            j++;
        }
        while(arr[24]--){
            ans[j]=6;
            arr[19]--; arr[9]--;
            j++;
        }
        while(arr[23]--){
            ans[j]=2;
            arr[20]--; arr[15]--;
            j++;
        }
        while(arr[7]--){
            ans[j]=8;
            arr[5]--; arr[9]--; arr[8]--; arr[20]--;
            j++;
        }
        while(arr[21]--){
            ans[j]=4;
            arr[6]--; arr[15]--; arr[18]--;
            j++;
        }
        while(arr[15] && arr[21]<1){
            ans[j]=1;
            arr[15]--; arr[14]--; arr[5]--;
            j++;
        }
        while(arr[6] && arr[21]<1){
            ans[j]=5;
            arr[6]--; arr[9]--; arr[22]--; arr[5]--;
            j++;
        }
        while(arr[18] && arr[21]<1){
            ans[j]=3;
            arr[20]--; arr[8]--; arr[18]--; arr[5]--; arr[5]--;
            j++;
        }
        while(arr[19] && arr[24]<1){
            ans[j]=7;
            arr[19]--; arr[5]--; arr[22]--; arr[5]--; arr[14]--;
            j++;
        }
        while(arr[9] && arr[7]<1 && arr[24]<1){
            ans[j]=9;
            arr[14]--; arr[9]--; arr[14]--; arr[5]--;
            j++;
        }
        sort(ans, ans+j);
        cout<<"Case #"<<z<<": ";
        for(int i=0; i<j; i++){
            cout<<ans[i];
        }
        cout<<"\n";
		z++;
    }
}
