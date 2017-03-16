#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    cerr << "T:" << T;
    int contador[256];
    char S[10000];
    int resultado[10];
    for (int t=1; t<=T; t++)
    {
        for (int i=0;i<256;i++) {
            contador[i]=0;
        }
        cin >> S;
        int i=0;
        while (S[i])
        {
            contador[S[i]]++;
            i++;
        }
        resultado[0]=0;
        while (contador['Z'])
        {
            resultado[0]++;
            contador['Z']--;
            contador['E']--;
            contador['R']--;
            contador['O']--;
        }
        resultado[2]=0;
        while (contador['W'])
        {
            resultado[2]++;
            contador['T']--;
            contador['W']--;
            contador['O']--;
        }
        resultado[6]=0;
        while (contador['X'])
        {
            resultado[6]++;
            contador['S']--;
            contador['I']--;
            contador['X']--;
        }
        resultado[8]=0;
        while (contador['G'])
        {
            resultado[8]++;
            contador['E']--;
            contador['I']--;
            contador['G']--;
            contador['H']--;
            contador['T']--;
        }
        resultado[3]=0;
        while (contador['H'])
        {
            resultado[3]++;
            contador['T']--;
            contador['H']--;
            contador['R']--;
            contador['E']--;
            contador['E']--;
        }
        resultado[4]=0;
        while (contador['R'])
        {
            resultado[4]++;
            contador['F']--;
            contador['O']--;
            contador['U']--;
            contador['R']--;
        }
        resultado[1]=0;
        while (contador['O'])
        {
            resultado[1]++;
            contador['O']--;
            contador['N']--;
            contador['E']--;
        }
        resultado[5]=0;
        while (contador['F'])
        {
            resultado[5]++;
            contador['F']--;
            contador['I']--;
            contador['V']--;
            contador['E']--;
        }
        resultado[7]=0;
        while (contador['S'])
        {
            resultado[7]++;
            contador['S']--;
            contador['E']--;
            contador['V']--;
            contador['E']--;
            contador['N']--;
        }
        resultado[9]=0;
        while (contador['I'])
        {
            resultado[9]++;
            contador['N']--;
            contador['I']--;
            contador['N']--;
            contador['E']--;
        }
        cout << "Case #" << t << ": ";
        for (int i=0;i<10;i++) {
            for (int j=0;j<resultado[i];j++)
                cout << i;
        }
        cout << "\n";
    }
    return 0;
}
