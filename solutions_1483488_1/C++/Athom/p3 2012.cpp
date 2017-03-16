#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#define LIM 2000005
using namespace std;

int tabla[LIM];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("p3.out","w",stdout);
    
    int T;
    cin >> T;
    
    for ( int caso = 1; caso <= T; caso++ )
    {
        int a, b;
        cin >> a >> b;
        int respuesta = 0;
        
        for ( int i = a; i <= b; i++ )
            tabla[i] = 0;
            
        int can = 1, lon = 1, aux = a;
        while ( aux > 9 ) // medir numero
        {
              aux /= 10;
              lon *= 10;
              ++can;
        }

        int derecha, nuevo;        
        for ( int i = a; i <= b; i++ )
        {
            int k = i;
            tabla[i] = i; // marco q ya fue hecho con el mismo i
            
             for ( int j = 1; j < can; j++ ) // mientras tenga algo :: una vuelta
             {
               derecha = (k%10);
               k /= 10;
               nuevo = lon*derecha + k;
               k = nuevo;
               
               if ( k > i && k <= b && tabla[k] != i ) // si no lo he obtenido con i, entonces lo cuento
               {
                  ++respuesta;
                  tabla[k] = i;    // marco 
               }
             }
        }//f numero
        
        cout << "Case #" << caso << ": " << respuesta;
        if ( caso < T )
           cout << endl;
    }//f caso
 
 return 0;   
}
