#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int tabla[1000000];

unsigned long long int pos=0;

int esPalindromo(char *cad){
    int tam=strlen(cad); // Saca el tamaño de la cadena
    int inicio=0, final =tam-1; // Establecemos inicio y final
    
    while(inicio<final){
        if(cad[inicio]!=cad[final]){ // Caso no palindromo
            return 0;
        }
        inicio++;// Inicio hacia adelante
        final--;// Final hacia atras
    }
    return 1;// Todos iguales, es palindromo
}


unsigned long long int contar(unsigned long long int A, unsigned long long int B)
{
    unsigned long long int res=0;
    
    unsigned long long int i,j,k;
    
    for(i=0;i<pos;i++)
    {
        if(tabla[i]>=A && tabla[i]<=B){
            res++;
            //cout << i << " " << tabla[i] << endl;
        }
    }
    
    
    return res;
}

int main()
{
    unsigned long long int i,j,k;
    tabla[pos]=1;
    pos++;
    for(i=2;i<=10000001;i++){
    char numero1[1000];
    char numero2[1000];
    sprintf(numero1,"%llu",(i));
    sprintf(numero2,"%llu",(i*i));
        if(esPalindromo(numero1)){
            if(esPalindromo(numero2)){
                //cout << pos << " " << i*i<<endl;
                tabla[pos]=(i*i);
                pos++;
            }
        }
    }
    unsigned long long int T,A,B;    
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin >> A >> B;
        if(A>B)
        {
            unsigned long long int tmp;
            tmp=A;
            A=B;
            B=tmp;
        }
        cout << "Case #"<<i<<": "<<contar(A,B)<< endl;
    }
    
    
    return 0;
}
