#include<iostream>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;

vector<long long>v;

int main(){

    freopen("gcj_round1A_input_prbB.txt","r",stdin);
    freopen("gcj_round1A_output_prbB.txt","w",stdout);

    int t,r;
    cin>>t;
    for(r=1;r<=t;r++){
            v.clear();
            long long n,i,a[2505],j,x;
            memset(a,0,sizeof(a));
            cin>>n;
            for(i=1;i<=2*n-1;i++){
                for(j=1;j<=n;j++){
                    cin>>x;
                    a[x]++;
                }
            }
            for(i=1;i<=2500;i++){
                if(a[i]>0){
                    if(a[i]%2!=0)v.push_back(i);
                }
            }


        cout<<"Case #"<<r<<": ";
        for(i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;





}

