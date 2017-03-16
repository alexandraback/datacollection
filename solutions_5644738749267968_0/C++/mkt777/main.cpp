#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin;
    cin.open("data.txt");
    ofstream cout;
    cout.open("output.txt");
    int cases, n, w, dw, cont, tmp;
    bool mayor;
    cin >> cases;
    for(int i=1;i<=cases;i++){
        w=dw=0;
        cin >> n;
        double ken[n], naomi[n];
        for(int j=0;j<n;j++){
            cin >> naomi[j];
        }
        for(int j=0;j<n;j++){
            cin >> ken[j];
        }
        sort(naomi,naomi+n);
        sort(ken,ken+n);
        cont=0;
        for(int j=0;j<n;j++){
            if(cont==n)
                break;
            if(naomi[j]>ken[cont]){
                dw++;
                cont++;
            }
        }
        cont=0;
        for(int j=0;j<n;j++){
            mayor=true;
            for(int k=cont;k<n;k++){
                if(ken[k]>naomi[j]){
                    mayor=false;
                    tmp=ken[k];
                    ken[k]=ken[cont];
                    ken[cont]=tmp;
                    break;
                }
            }
            if(mayor){
                w++;
                cont++;
            }
            else
                cont++;
        }
        cout << "Case #" << i << ": " << dw << " " << w << endl;
    }
    cin.close();
    cout.close();
    return 0;
}
