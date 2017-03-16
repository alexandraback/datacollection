#include <iostream>
#include <fstream>

using namespace std;

int n, k, llaves[200], total, cofres[200], keys[200][41], opened, orden[200];
bool abierto[200];

bool abrirCofre()
{
    if(opened == n)
        return true;
    if(total == 0)
        return false;
    for(int i = 0; i < n; i++){
        if(abierto[i] == false && llaves[cofres[i]] > 0){
            abierto[i] = true;
            llaves[cofres[i]]--;
            total--;
            orden[opened++] = i;
            total += keys[i][0];
            for(int j = 1; j <= keys[i][0]; j++)
                llaves[keys[i][j]]++;
            if(abrirCofre())
                return true;
            abierto[i] = false;
            llaves[cofres[i]]++;
            total++;
            opened--;
            total -= keys[i][0];
            for(int j = 1; j <= keys[i][0]; j++)
                llaves[keys[i][j]]--;
        }
    }
    return false;
}

int main()
{
    ifstream arc;
    ofstream sal;
    arc.open("input.txt");
    sal.open("output.txt");

    int casos, llave;
    arc >> casos;
    for(int c = 1; c < casos+1; c++){
        arc >> k >> n;
        opened = 0;
        total = k;
        for(int i = 0; i < k; i++){
            arc >> llave;
            llaves[llave]++;
        }
        for(int i = 0; i < n; i++){
            abierto[i] = false;
            arc >> cofres[i] >> keys[i][0];
            for(int j = 1; j <= keys[i][0]; j++)
                arc >> keys[i][j];
        }
        sal << "Case #" << c << ": ";
        if(abrirCofre()){
            bool first = true;
            for(int i = 0; i < n; i++){
                if(!first)
                    sal << " ";
                sal << orden[i]+1;
                first = false;
            }
            sal << endl;
        }
        else
            sal << "IMPOSSIBLE" << endl;
    }

    arc.close();
    sal.close();
    return 0;
}
