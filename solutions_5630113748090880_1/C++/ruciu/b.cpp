#include<iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    for(int n=0;n<number;n++) {
        int size;
        cin >> size;
        int tab[2501];
        for(int k=0;k<=2500;k++) tab[k]=0;
        for(int y=0;y<2*size-1;++y) {
            for(int x=0;x<size;++x) {
                 int l;
                cin >> l;
                tab[l]++;
            }
               
        }
        cout << "Case #" << n+1 << ": ";
        for(int k=0;k<=2500;k++) {
            if(tab[k]%2==1) cout << k << " ";
        }
        cout << endl;
    } 
}