#include <bits/stdc++.h>
using namespace std;
long long int T;
long long int L,X;
int matriz[4][4] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
int operacion(int a,int b){
    bool negativo = false;
    if(a<0 and b>0 or a>0 and b<0){
        negativo = true;
    }
    if(negativo){
        return -1*matriz[abs(a)-1][abs(b)-1];
    }
    return matriz[abs(a)-1][abs(b)-1];
}
int convertir(char a){
    if(a=='1'){
        return 1;
    }
    if(a=='i'){
        return 2;
    }
    if(a=='j'){
        return 3;
    }
    if(a=='k'){
        return 4;
    }
}
bool analizar(string palabra){
    int a,b,c;
    a = convertir(palabra[0]);
    for(int i=0;i<palabra.size();i++){
        if(i!=0)
            a = operacion(a,convertir(palabra[i]));
        b = 0;
        c = 0;
        if(a==2 and i+1<palabra.size()){
            b = convertir(palabra[i+1]);
            for(int j=i+1;j<palabra.size();j++){
                if(j!=i+1)
                    b = operacion(b,convertir(palabra[j]));
                    if(b==3){
                        return true;
                    }
                c = 0;
            }
            return false;
        }
    }
    return false;
}
int solucionarString(string a){
    int b;
    for(int i=0;i<a.size();i++){
        if(i==0)
            b=convertir(a[0]);
        else{
            b = operacion(b,convertir(a[i]));
        }
    }
    return b;
}

int main()
{

    //ofstream cout("respuesta.txt");
    //ifstream cin;cin.open ("C-large.in");
    while (cin>>T){
        for(int i=0;i<T;i++){
            cin>>L>>X;
            string temp,palabra;
            cin>>temp;
            for(int i=0;i<X and i<10;i++){
                palabra+=temp;
            }
            string ans = "NO";
            int primera = solucionarString(temp);
            bool rep = false;
            if(primera!=1){
                if(primera == -1 and X%2==1){
                    rep = true;
                }
                if(primera != -1 and X%4 == 2){
                    rep = true;
                }
            }
            if(rep and analizar(palabra)){
                ans = "YES";
            }
            cout<<"Case #"<<i+1<<": "<<ans<<endl;

        }
    }
    //cin.close();
    //cout.close();
}
