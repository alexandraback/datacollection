#include<iostream>
using namespace std;
int T;
void solve(int,int);
int main(){
    cin>>T;
    for(int i=1;i<=T;++i){
        int a;
        cin>>a;
        solve(i,a);
    }
    return 0;
}

void solve(int i,int a){
    if(a==0){ 
        cout<<"Case #"<<i<<": INSOMNIA"<<endl;
        return;
    }
    bool check[10];
    for (int j=0;j<10;++j)
        check[j]=false;
    int n = 0;
    while(true){
        n += a;
        int x = n;
        while(x > 0){
            check[x%10] = true;
            x /= 10;
        }
        bool res = true;
        for(int j=0;j<10;++j){
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
