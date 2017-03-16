#include "iostream"
#include "cstdio"
#include "vector"
#include "algorithm"

using namespace std;

class Total // 0 a 30
{
  public:
         int maxCon;
         int maxSin;
};

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("p2.out","w",stdout);
    
    Total resultados[32];
    
    // precalculo
    for ( int i = 0; i < 31; i++ )
    {
        int max1 = -1; // con
        int max2 = -1; // sin
        
        for ( int a = 0; a <= i; a++ )
            for ( int b = a; (a+b) <= i && (b-a) < 3; b++ )
                for ( int c = b; (a+b+c) <= i && (c-a) < 3; c++ )
                    if ( (a+b+c) == i )
                    {
                       if ( (c-a) == 2 ) // con sorpresa
                          max1 = max( max1, c );
                       else // sin sorpresa
                          max2 = max( max2, c );
                    }
                    
        resultados[i].maxCon = max1;
        resultados[i].maxSin = max2;
        //cout << "i : " << i << " Con : " << max1 << " Sin : " << max2 << endl;
    }
    //

    int T;
    cin >> T;
    for ( int caso = 1; caso <= T; caso++ )
    {
        int N, S, p;
        vector<int> lista;
        int respuesta = 0;
        
        cin >> N >> S >> p;
        
        for ( int i = 0; i < N; i++ )
        {
            int k;
            cin >> k;
            lista.push_back(k); 
        }
        
        sort( lista.begin(), lista.end() );
        // ordenados de mayor a menor.
        
        int cuenta = 0;
        for ( int i = 0; i < lista.size(); i++ )
        {
            //cout << "ver : " << lista[i] << endl;
            //cout << resultados[lista[i]].maxCon << endl;
            //cout << resultados[lista[i]].maxSin << endl << endl;
            if ( cuenta < S && resultados[lista[i]].maxSin < p && resultados[lista[i]].maxCon >= p ) //tomarlo como Con
            {
               ++cuenta;
               ++respuesta;  
            }
            else if ( resultados[lista[i]].maxSin >= p )
               ++respuesta;
        }
        
        cout << "Case #" << caso << ": " << respuesta;
        if ( caso < T )
           cout << endl;

    }//f caso
    
 return 0;
}//fp
