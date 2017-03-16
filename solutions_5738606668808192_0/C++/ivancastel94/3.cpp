#include<bits/stdc++.h>
using namespace std;
vector<unsigned long long> primos;
bool criba[1000001];

unsigned long long escoin(unsigned long long a1, unsigned long long a2, int base){
    unsigned long long b1,b2,mod,p,d16=1;
    int i;
    for(i=0;i<16;i++)d16*=base;
    p=1;
    b1=0;
    for(i=0;i<16;i++){
        b1+=(a1%10)*p;
        a1=a1/10;
        p=p*base;
    }
    p=1;
    b2=0;
    for(i=0;i<16;i++){
        b2+=(a2%10)*p;
        a2=a2/10;
        p=p*base;
    }
    for(int i=0;i<primos.size()&&b2>primos[i];i++){
        mod=((b1%primos[i])*(d16%primos[i])+(b2%primos[i]))%primos[i];
        if(mod==0)return primos[i];
    }
    return 0;
}

int main(){
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    unsigned long long aux,num,a1,a2,b1,b2;
    int i,j,t,n,can;
    for(i=2;i<100000;i++){
        if(criba[i]==0){
            primos.push_back(i);
            if(i<1000){
                for(j=i*i;j<100000;j+=i){
                    criba[j]=1;
                }
            }
        }
    }
    cin>>t>>n>>j;
    cout<<"Case #"<<t<<":"<<endl;
    can=0;
    num=(1ll<<(n-1))|1;
    while(can<j){
        b1=b2=0;
        aux=num;
        for(i=0;i<16;i++){
            b1=b1*10+(aux%2);
            aux/=2;
        }
        for(i=16;i<32;i++){
            b2=b2*10+(aux%2);
            aux/=2;
        }
        a1=a2=0;
        aux=b2;
        for(i=0;i<16;i++){
            a1=a1*10+(aux%10);
            aux/=10;
        }
        aux=b1;
        for(i=16;i<32;i++){
            a2=a2*10+(aux%10);
            aux/=10;
        }
        vector<unsigned long long> v;
        for(i=10;i>=2;i--){
            //cout<<" "<<i;
            v.push_back(escoin(a1, a2, i));
            if(v.back()==0){
                v.pop_back();
                break;
            }
        }
        //cout<<endl;
        if(v.size()==9){
            if(a1>0){
                for(i=0;i<16;i++){
                    cout<<(b2%10);
                    b2/=10;
                }
            }
            for(i=0;i<16;i++){
                cout<<(b1%10);
                b1/=10;
            }
            for(i=0;i<9;i++)
                cout<<" "<<v[8-i];
            cout<<endl;
            can++;
        }
        num+=2;
    }
}
