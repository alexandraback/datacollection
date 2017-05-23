#include "iostream"
#include "cstdio"
#include "string"
#include "cstring"

using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("p1.out","w",stdout);
    
    int T;
    char cad[105];

    cin >> T;
    gets(cad); // Traga enter
    for ( int i = 0 ; i < T; i++ ) 
    {
        gets(cad);
        int lon = strlen(cad);
        
        cout << "Case #" << (i+1) <<": ";
        for ( int ii = 0; ii < lon; ii++ )
            switch( cad[ii] )
            {
                 case 'a': cout << "y"; break;
                 case 'b': cout << "h"; break;
                 case 'c': cout << "e"; break;
                 case 'd': cout << "s"; break;
                 case 'e': cout << "o"; break;
                 case 'f': cout << "c"; break;
                 case 'g': cout << "v"; break;
                 case 'h': cout << "x"; break;
                 case 'i': cout << "d"; break;
                 case 'j': cout << "u"; break;
                 case 'k': cout << "i"; break;
                 case 'l': cout << "g"; break;
                 case 'm': cout << "l"; break;
                 case 'n': cout << "b"; break;
                 case 'o': cout << "k"; break;
                 case 'p': cout << "r"; break;
                 case 'q': cout << "z"; break;
                 case 'r': cout << "t"; break;
                 case 's': cout << "n"; break;
                 case 't': cout << "w"; break;
                 case 'u': cout << "j"; break;
                 case 'v': cout << "p"; break;
                 case 'w': cout << "f"; break;
                 case 'x': cout << "m"; break;
                 case 'y': cout << "a"; break;
                 case 'z': cout << "q"; break;
                 default : cout << " "; break;
            }
            
        if ( i < T-1 )
           cout << endl;
    }
    
 return 0;
}

