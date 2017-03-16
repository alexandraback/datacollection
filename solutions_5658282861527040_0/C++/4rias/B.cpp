#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define Mod 1000000

template<class T>
int toInt(T t){stringstream ss;ss<<t;int r;ss>>r;return r;}
template<class T>
string toStr(T t){stringstream ss;ss<<t;string r;ss>>r;return r;}


int main(){
    int n,A,B,K,nc=0;cin>>n;
    while(n--){
        cin>>A>>B>>K;
        int sol=0;
        for(int i= 0;i<A;i++){
            for(int j=0;j<B;j++){
                if( (i&j) < K)sol++;
            }
        }
        cout<<"Case #"<<++nc<<": "<<sol<<endl;
    }
}
