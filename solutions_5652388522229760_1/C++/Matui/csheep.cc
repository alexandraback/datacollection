#include<iostream>
using namespace std;
unsigned long T;
void solve(unsigned long,unsigned long);
int main(){
    cin>>T;
    for(unsigned long i=1;i<=T;++i){
        unsigned long a;
        cin>>a;
        solve(i,a);
    }
    return 0;
}

void solve(unsigned long i,unsigned long a){
    if(a==0){ 
        cout<<"Case #"<<i<<": INSOMNIA"<<endl;
        return;
    }
    bool check[10];
    for (unsigned long j=0;j<10;++j)
        check[j]=false;
    unsigned long n = 0;
    while(true){
        n += a;
        unsigned long x = n;
        while(x > 0){
            check[x%10] = true;
            x /= 10;
        }
        bool res = true;
        for(unsigned long j=0;j<10;++j){
            if(check[j])
                continue;
            res = false;
            break;
        }
        if(res){
            cout<<"Case #"<<i<<": "<<n<<endl;
            return;
        }
    }
}
