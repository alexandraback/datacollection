#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    cout << fixed << setprecision(7) << showpoint;
    
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
        cout << "Case #" << k+1 << ": ";
        
        if(!datei.good())
            throw 2;
        datei >> C;
        if(C <= 0)
            throw 3;
                
        if(!datei.good())
            throw 2;
        datei >> F;
        if(F <= 0)
            throw 3;
        
        if(!datei.good())
            throw 2;
        datei >> X;
        if(X <= 0)
            throw 3;
        
        int number = (int) (X / C - 2.0 / F);
        double rate = 2.0;
        double time = 0;
        for(int i = 0; i < number; i++)
        {
            time += C / rate;
            rate += F;
        }
        time += X / rate;
        cout << time << endl;
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
