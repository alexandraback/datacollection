#include<bits/stdc++.h>
using namespace std;
int a[10] ;
int ans = 0 ;
int n ;
vector<int>arr;
bool vis[10] ;
void solve(int x){
    //if(x == n){
        int z = 0 ;
        bool flag = false;
        int hamada = arr.size();
        for(int i = 0 ; i < hamada ; i++){
            int j = (i-1+arr.size())%arr.size() ;
            if(a[arr[i]] == arr[j]){
                z++ ;
                continue;
            }
            j = (i+1)%arr.size() ;
            if(a[arr[i]] == arr[j]){
                z++ ;
                continue;
            }
            else {
                flag = true;
                break;
            }
        }
        if(z == arr.size())ans = max(ans,z) ;
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            arr.push_back(i);
            vis[i] = true;
            solve(x+1);
            vis[i] = false;
            arr.pop_back();
        }
    }
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin) ;
    freopen("hash.in","w",stdout) ;
    int t ;
    cin >> t ;
    for(int I = 1 ; I <= t ; I ++){
        cin >> n ;
        for(int i = 0 ; i < n ; i++)cin >> a[i] ,a[i]-- ;
        ans = 0 ;
        memset(vis,false,sizeof vis) ;
        arr.clear();
        solve(0) ;
        printf("Case #%d: %d\n",I,ans) ;
    }
    return 0;
}
