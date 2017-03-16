#include <bits/stdc++.h>
using namespace std;
long long int T;
int main()
{
//    ofstream cout("respuestas.txt");
//    ifstream cin;cin.open ("A-large.in");

    while (cin>>T){

        for(int i=0;i<T;i++){
            long long int maximo;
            string palabra;
            cin>>maximo>>palabra;
            int llevo = 0;
            int resp = 0;
            for(int i=0;i<palabra.size();i++){
                if(llevo<i){
                    resp += (i-llevo);
                    llevo+= (i-llevo);
                }
                llevo+= palabra[i]-48;
            }

            cout<<"Case #"<<i+1<<": "<<resp<<endl;
        }
    }
//    cin.close();
//    cout.close();
}
