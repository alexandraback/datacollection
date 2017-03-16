#include <bits/stdc++.h>
using namespace std;
long long int T;
int D;
bool mayor(int a,int b){
    return a>=b;
}
int divRed(int a){
    if(a%2==0)
        return a/2;
    else
        return (a/2)+1;
}

int main()
{
    ofstream cout("respuestasFuerte.txt");
    ifstream cin;cin.open ("B-small-attempt3.in");

    while (cin>>T){
        for(int i=0;i<T;i++){
            cin>>D;
            vector<int> platos(1);
            for(int i=0;i<D;i++){
                int temp;
                cin>>temp;
                platos.push_back(temp);
            }
            int turnos = 0;
            sort(platos.begin(),platos.end(),mayor);
            int minimo = platos[0];
            while(true){


                sort(platos.begin(),platos.end(),mayor);
                minimo = min(platos[0]+turnos,minimo);
                if(platos[0]>1){
                    turnos++;
                    if(platos[0]%2==0){
                        int a = platos[0]/2;
                        int b = divRed(platos[0]);
                        platos.push_back(a);
                        platos[0] = b;
                    }
                    else{
                        for(int i=0;i<platos.size();i++){
                            platos[i]--;
                        }
                    }
                }
                else{
                    break;
                }

            }
            cout<<"Case #"<<i+1<<": "<<minimo<<endl;
        }
    }
    cin.close();
    cout.close();
}
