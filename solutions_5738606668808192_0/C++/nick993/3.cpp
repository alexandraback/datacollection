#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#define ll unsigned long long

using namespace std;

bool isPrime[43046721+10];
int factor[43046721+10];
vector<ll> primes;
map<vector<ll>, int > mymap;

void init() {
    memset(isPrime,true,sizeof isPrime);
    memset(factor,0,sizeof factor);
    isPrime[0]=isPrime[1]=false;
    for(int i=2*2;i<=43046721;i+=2) {
        isPrime[i]=false;
        factor[i]=2;
    }
    for(int i=3;i<=(6562);i+=2) {
        if(isPrime[i]==true){
            for(int j=2*i;j<=43046721;j+=i) {
                isPrime[j]=false;
                factor[j]=i;
            }
        }
    }
}

void calculate_prime_list() {
    for(ll i=2;i<43046721;i++) {
        if(isPrime[i])
            primes.push_back(i);
    }

}


ll returnPow(ll a,ll b) {
    if(b==0)
        return 1L;
    ll val=returnPow(a,b/2);
    if(b%2){
        return val*val*a;
    }
    return val*val;
}


ll  getBase(ll n,ll base) {
    ll num=0;
    ll cnt=0;
    while(n>0) {
        num+=returnPow(base,cnt)*(n%10);
        n/=10;
        cnt++;
    }
    return num;
}

ll convertToDec(ll n) {
    ll val=0;
    ll cnt=0;
    while(n>0) {
        val+=returnPow(10,cnt++)*(n%2);
        n/=2;
    }
    return val;
}

ll calculate_divisor(ll num) {
    for(int i=0;i<primes.size();i++) {
        ll val=primes[i];
        if(val*val<=num) {
            if(num%val==0)
                return val;
        }
        else{
            return 0;
        }
    }
}


int main() {
    int t;
    cin>>t;
     int n,c;
    cin>>n>>c;
   freopen("prime_bin.txt","r",stdin);
    freopen("prime_bin2.txt","w",stdout);
    init();
    calculate_prime_list();

   int cnt=0;
   vector<ll> v1,v2;
   cout<<"Case #1: "<<endl;
    while(1) {
            bool cont=false;
        if(cnt==50)
            break;
        v1.clear();
        v2.clear();
        ll tmp;
        for(int i=0;i<9;i++){
            cin>>tmp;
            v1.push_back(tmp);
        }
        if(v1[0]==0)
            break;
        for(int i=0;i<9;i++) {
            v2.push_back(calculate_divisor(v1[i]));
            if(v2[i]==0){
                cont=true;
                break;
            }
        }
        if(cont)
            continue;


       // if(mymap[v2]!=0) {
        cnt++;
        mymap[v2]=1;
        cout<<v1[8]<<' ';
        for(int i=0;i<9;i++)
            cout<<v2[i]<<' ';
        cout<<endl;

      //  }
    }




}
