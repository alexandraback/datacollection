#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int cantTestCase;
    cin >> cantTestCase;
    for(int i =1; i<=cantTestCase; i++) {
        double acum = 0;
        double n;
        cin >> n;
        double suma = 0;
        double res;
        list<int> numeros;
        for(int k = 0; k < n; k++) {
            int tmp;
            cin >> tmp;
            numeros.push_back(tmp);
            suma += tmp;
        }
        double arriba, abajo;
        //cout << "suma " << suma << endl;
        //cout << "abajo " <<abajo << endl;
        cout << "Case #" << i << ":";
        double nuevaSuma = suma;
        double viejaSuma =  0;
        list<int> copia;
        copia = numeros;
        int m = n;
        while (viejaSuma != nuevaSuma) {
            viejaSuma = nuevaSuma;
            for(list<int>::iterator it = copia.begin(); it!=copia.end(); it++) {
                if ((*it)*m > suma + viejaSuma) {
                    nuevaSuma -= (*it);
                    //cout << nuevaSuma << endl;
                    (*it) = -1;
                    m--;
                }
            }
        }
        //abajo = n*nuevaSuma;
        abajo = m*suma;
        for(list<int>::iterator it = numeros.begin(); it!=numeros.end(); it++) {
            //cout << endl << (*it) << "*" << n << " contra " << suma << endl;
            if ((*it)*m >= suma + nuevaSuma) {
                res = 0;
            } else {
                //cout <<"el IT " << *it << endl;
                arriba = 100 * (nuevaSuma + suma - (*it)*m);
                //if (n == m) arriba *= 2;
                //cout <<endl << arriba << " / " << abajo << " = ";
                res = arriba / abajo;
                //cout << "arriba vale" << arriba << endl;
            }
            printf(" %4.6f", res);
            acum += res;
        }
        cout << endl;
        //printf(" %4.6f", acum);
        //cout << endl;
    }
    return 0;
}
