#include <iostream>
#include <stdio.h>
using namespace std;
bool as[11];
void func(int foc){
    int n = foc;
    while(n){
        as[n%10]=true;
        n/=10;
    }
}
bool func1(){
    for(int i=0;i<10;i++){
        if(!as[i]) return false;
    }
    return true;
}
int main(){
    freopen("A.in", "r", stdin);
    freopen("ProbA.txt","w",stdout);
    int n;
    int k=0;
    cin >> n;
    int t;
    int we;
    while(k!=n){
        k++;
        printf("Case #%d: ",k);
        for(int i=0;i<10;i++){
            as[i]=false;
        }
        cin>>t;
        we=0;
        if(!t){
            cout<<"INSOMNIA" <<endl;
            continue;
        }
        while(!func1()){
            we+=t;
            func(we);
        }
        cout<<we<<endl;
    }
}
