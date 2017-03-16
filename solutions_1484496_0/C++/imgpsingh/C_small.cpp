#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;
int ar[2000010];
main(){
    int t,Kases=0;
    scanf("%d",&t);
    while(t--){
        cout<<"Case #"<<++Kases<<":\n";
        int n;
        bool flag=1;
        scanf("%d",&n);
        map<int,int> mp;
        for(int i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(int j=0;j<=1048575;j++){
            int k=j,len=0,s=0;
            while(k){
                if(k&1)
                    s+=ar[len];
                k>>=1;
                ++len;
            }
//            cout<<j<<" "<<s<<"\n";
            if(mp[s]==0)
                mp[s]=j;
            else{
                k=j;
                len=0;
                while(k){
                    if(k&1)
                        cout<<ar[len]<<" ";
                    k>>=1;
                    ++len;
                }
                cout<<"\n";
                k=mp[s];
                len=0;
                while(k){
                    if(k&1)
                        cout<<ar[len]<<" ";
                    k>>=1;
                    ++len;
                }
                cout<<"\n";
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"Impossible\n";
    }
    //system("pause");
    return 0;
}

