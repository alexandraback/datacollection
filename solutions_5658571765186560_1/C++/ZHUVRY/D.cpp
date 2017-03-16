#include <bits/stdc++.h>
using namespace std;
long long int T;
int X,R,C;
bool isRichard(){
    int valor = X/2 + X%2;
    int valor2 = 1+(X-valor);
    if(X>=7){
        return true;
    }

    if(R*C%X !=0){
        return true;
    }
    if(X>R and X>C){
        return true;
    }
    if(X>max(R,C)){
        return true;
    }

    if(min(valor,valor2)>min(R,C)){
        return true;
    }
    if(min(valor,valor2)>=min(R,C) and X>=4){
        return true;
    }

    return false;
}
int main()
{
    ofstream cout("prueba.txt");
    ifstream cin;cin.open ("D-large.in");
    while (cin>>T){
        for(int i=0;i<T;i++){
            cin>>X>>R>>C;
            int minimo = min(R,C);
            int maximo = max(R,C);
            R = minimo;
            C = maximo;

            string ans = "GABRIEL";
            if(isRichard()){
                ans = "RICHARD";
            }
            cout<<"Case #"<<i+1<<": "<<ans<<endl;

        }
    }
    cin.close();
    cout.close();
}
