#include<iostream>
#include<cstdio>
#include<numeric>
#include<cstring>

using namespace std;
int main(){
    freopen("ain.txt","r",stdin);
    freopen("aout.txt","w",stdout);
    int T;
    cin>>T;
    for (int i=1;i<=T;i++){
        int n;
        cin>> n;
        if (n==0){
            cout<<"Case #"<<i<<": "<<"INSOMNIA"<<endl;
        }else{
            int check[10];
            memset(check,0,sizeof check);
            long long curr=n;
            while (accumulate(check,check+10,0)!=10) {
                long long x=curr;
                while (x>0){
                    check[x%10]=1;
                    x/=10;
                }
                curr+=n;
            }
            curr-=n;
            cout<<"Case #"<<i<<": "<<curr<<endl;
        }
    }
}
