#include<iostream>
#include<math.h>

using namespace std;

int pow10(int y){
    int a=1;
    while(y>0){
        a*=10;
        y--;
    }
    return a;
}
int move1digit(int x,int firstdigit){
    int y;
    while(x%10==0){
        x/=10;
    }
    return x/10+(x%10)*pow10(firstdigit-1);
}
int firstdigit(int x){
    int y=0;
    while(x){
        x/=10;
        y++;
    }
    return y;
}

void run(){
    int A,B;
    int i,j;
    
    cin>>A>>B;
    
    int x,f;
    int k=0;
    for(int i=A;i<=B;i++){
        x=i;
        f=firstdigit(x);
        for(j=0;j<f;j++){
            x=move1digit(x,f);
            if(x==i) break;
            if(x>i && x<=B){
                k++;
                //cout<<x<<' '<<i<<endl;
            }
        };
    }
    cout<<k;
}

int main(){
    int i,n;
    //cout<<move1digit(600,3);
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"Case #"<<i<<": ";
        run();
        cout<<endl;
    }
    
    return 0;
}
