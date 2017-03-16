#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
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
    int N = 0;
    double* naomi;
    double* ken;
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
        cout << "Case #" << k+1 << ": ";
        
        if(!datei.good())
            throw 2;
        datei >> N;
        if(N <= 0)
            throw 3;
        
        naomi = new double[N];
        ken = new double[N];
        for(int i = 0; i < N; i++)
        {
            if(!datei.good())
                throw 2;
            datei >> naomi[i];
            if(naomi[i] < 0)
                throw 3;
        }
        for(int i = 0; i < N; i++)
        {
            if(!datei.good())
                throw 2;
            datei >> ken[i];
            if(ken[i] < 0)
                throw 3;
        }
        
        sort(naomi, naomi + N);
        sort(ken, ken + N);
        
        int y = 0;
        int score = 0;
        for(int x = 0; x < N; x++)
        {
            if(naomi[x] > ken[y])
            {
                score++;
                y++;
            }
        }
        
        cout << score << " ";
        
        y = N-1;
        score = 0;
        for(int x = N-1; x >= 0; x--)
        {
            if(naomi[x] > ken[y])
            {
                score++;
            }
            else
                y--;
        }
        
        cout << score << endl;
        
        delete[] naomi;
        delete[] ken;
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
