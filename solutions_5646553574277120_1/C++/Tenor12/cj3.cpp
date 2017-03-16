#include <bits/stdc++.h>


using namespace std;


int main()
{
    long long t;
    cin >> t;
    for (long long i=0; i<t; ++i)
    {
        long long ogr, ilosc, max_value;
        cin >> ogr >> ilosc >> max_value;
        vector <long long> monety (ilosc);
        for (long long i=0; i<ilosc; ++i) cin >> monety[i];
        long long result = 0;
        long long temp = ogr;
        long long obecna=0;
        if (monety[0]!=1) result=1;
        else obecna=1;
        while (temp<max_value)
        {
            if (obecna<ilosc && monety[obecna]-1<=temp)
            {
                temp+=(monety[obecna]*ogr);
                ++obecna;
            }
            else
            {
                ++result;
                temp+=((temp+1)*ogr);
            }
        }
        cout << "Case #" << i+1 << ": " << result << endl;
    }
}
