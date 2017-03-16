#include <bits/stdc++.h>

using namespace std;


int policz (int przedzial)
{
    int result=0;
    if (przedzial>0)
    {
        ++ result;
        przedzial/=2;
    }
    return result;
}


int main()
{
    int tes;
    cin >> tes;
    for (int i=0; i<tes; ++i)
    {
        int kolumny, wiersze, dlugosc;
        cin >> wiersze >> kolumny >> dlugosc;
        int result=0;
        int pozostale;
        pozostale=kolumny%dlugosc;
        result+=kolumny/dlugosc;
        result+=policz(pozostale);
        result+=dlugosc-1;
        result+=(wiersze-1)*(kolumny/dlugosc);
        cout << "Case #" << i+1 << ": " << result << endl;
    }
}
