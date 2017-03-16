#include <iostream>
#include <cstdio>

using namespace std;

char que;
int casos, hasta, suma, res;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>casos;
    for(int v=1; v<=casos; v++){
        cin>>hasta;
        suma=0;
        res=0;
        for(int i=0; i<=hasta; i++){
            cin>>que;
            if(que>'0'){
                if(suma<i){
                    res += i-suma;
                    suma = i;
                }
                suma = suma + que - '0';
            }
        }
        cout<<"Case #"<<v<<": "<<res<<endl;
    }
    return 0;
}
