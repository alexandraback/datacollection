#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    //int temp = 0;
    
    //Eingabe des Dateinamens über Konsole oder Übergabe als Eingabeparameter
    char* filename;
    if(argc > 1)
    {
        filename = argv[1];
    }
    else
    {
        char buffer[256];
        cout << "Input file name (up to 255 Characters): " << endl;
        cin >> buffer;
        filename = buffer;
    }
    
    int T = 0;
    double C;
    double F;
    double X;
    int answer = -1;
    try
    {
        ifstream datei(filename);
        if(!datei.is_open())
            throw 1;
        
        if(!datei.good())
            throw 2;
        datei >> T;
        if(T <= 0)
            throw 3;
        
        for(int k = 0; k < T; k++)
    {
        cout << "Case #" << k+1 << ":" << endl;
        
        int R = 0;
        int C = 0;
        
        if(!datei.good())
            throw 2;
        datei >> R;
        if(R <= 0)
            throw 3;
                
        if(!datei.good())
            throw 2;
        datei >> C;
        if(C <= 0)
            throw 3;
        
        int M = -1;
        
        if(!datei.good())
            throw 2;
        datei >> M;
        if(M < 0)
            throw 3;
        
        int A[R][C];
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                A[i][j] = 0;
        
        //Case 1: R = 1 or C = 1.
        if(R == 1)
        {
            for(int i = 0; i < C; i++)
            {
                if(i < C-M)
                    A[0][i] = 0;
                else
                    A[0][i] = 1;
            }
            goto output;
        }
        if(C == 1)
        {
            for(int i = 0; i < R; i++)
            {
                if(i < R-M)
                    A[i][0] = 0;
                else
                    A[i][0] = 1;
            }
            goto output;
        }
        
        //Case 2: R,C > 1; M <= (R-2)(C-2)
        if(M <= (R-2)*(C-2))
        {
            int counter = 0;
            if(M == 0)
                goto output;
            for(int j = C-1; j >= 2; j--)
            {
                for(int i = R-1; i >= 2; i--)
                {
                    A[i][j] = 1;
                    counter++;
                    if(counter >= M)
                        goto output;
                }
            }
            goto output;
        }
        
        //Case 3: R,C > 1; M has same parity as R*C.
        if((R*C-M)%2 == 0)
        {
            int free = R*C-M;
            if(free == 2)
            {
                cout << "Impossible" << endl;
                goto outputImp;
            }
            
            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++)
                    A[i][j] = 1;
            
            for(int i = 0; i < C; i++)
            {
                A[0][i] = 0;
                A[1][i] = 0;
                free -= 2;
                if(free <= 0)  
                    goto output;
            }
            for(int i = 2; i < R; i++)
            {
                A[i][0] = 0;
                A[i][1] = 0;
                free -= 2;
                if(free <= 0)  
                    goto output;
            }
            goto output;
        }
        
        //Case 4: R,C > 1; M does not have the same parity as R*C.
        if((R*C-M)%2 == 1)
        {
            int free = R*C - M;
            
            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++)
                    A[i][j] = 1;
            
            if(free == 1)
            {
                A[0][0] = 0;
                goto output;
            }
            if(free < 9 || R == 2 || C == 2)
            {
                cout << "Impossible" << endl;
                goto outputImp;
            }
            
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    A[i][j] = 0;
            
            free -= 9;
            if(free == 0)
                goto output;
            for(int i = 3; i < C; i++)
            {
                A[0][i] = 0;
                A[1][i] = 0;
                free -= 2;
                if(free <= 0)  
                    goto output;
            }
            for(int i = 3; i < R; i++)
            {
                A[i][0] = 0;
                A[i][1] = 0;
                free -= 2;
                if(free <= 0)  
                    goto output;
            }
            goto output;
        }
        
        //Output
        output:
            //temp = 0;
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                if(i == 0 && j == 0)
                    cout << "c";
                else
                {
                    if(A[i][j] == 0)
                        cout << ".";
                    else
                    {
                        cout << "*";
                        //temp++;
                    }
                    
                    //if(j < C-1)
                      //  cout << " ";
                }
            }
            cout << endl;
        }
        //if(temp!=M) cout << "FALSCH";
        
        outputImp:
            ;
    }
    }
    catch(int e)
    {
        cout << "Fehler (Nr. " << e << ") beim Einlesen der Datei.";
        int a;
    cin >> a;
        return 1;
    }
    
    //int a;
    //cin >> a;
    return 0;    
}
