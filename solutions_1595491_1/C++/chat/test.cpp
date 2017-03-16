#include<iostream>
#include<math.h>

using namespace std;

void run(){
    int N,S,p;
        
    int i;
    double a;
    int x;
    
    cin>>N>>S>>p;
    
    x=0;
    for(i=0;i<N;i++){
        cin>>a;
        if(ceil(a/3.0)>=p) x++;
        else if(ceil((a+2.0)/3.0)>=p && S>0 && a>=2.0 && a<=28.0){
            x++;
            S--;
        }
    }
    cout<<x;
}

int main(){
    int i,n;
    
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"Case #"<<i<<": ";
        run();
        cout<<endl;
    }
    
    return 0;
}
