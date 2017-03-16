#include <iostream>
#include <string>
#include <assert.h>

using namespace std;


long long DPmin[100];
string Cmina[100], Cminb[100];
long long DPmax[100];
string Cmaxa[100], Cmaxb[100];
long long DPabs[100];
string Cabsa[100], Cabsb[100];

int main()
{
    int T;
    cin >> T;
    for(int ct = 1; ct <= T; ++ct)
    {
        // IT IS ALWAYS C-J
        string a, b;
        cin >> a >> b;
        int n = a.length();
        for(int i = 0; i < 100; ++i)
        {
            DPmin[i] = DPmax[i] = DPabs[i] = 0;
            Cmina[i] = Cminb[i] = Cmaxa[i] = Cmaxb[i] = Cabsa[i] = Cabsb[i] = "";
        }
        long long base = 1;
        for(int i = n-1; i >= 0; --i, base*=10)
        {
            DPabs[i] = DPmin[i] = 10 * base;
            DPmax[i] = -10 * base;
            for(int ca = 0; ca < 10; ++ca)
            {
                if(a[i] != '?' && a[i]-'0' != ca)
                    continue;
                for(int cb = 0; cb < 10; ++cb)
                {
                    if(b[i] != '?' && b[i]-'0' != cb)
                        continue;
                    long long newmin = base * (ca-cb) + DPmin[i+1];
                    long long newmax = base * (ca-cb) + DPmax[i+1];
                    if(newmin < DPmin[i])
                    {
                        DPmin[i] = newmin;
                        Cmina[i] = char(ca + '0') + Cmina[i+1];
                        Cminb[i] = char(cb + '0') + Cminb[i+1];

                    }
                    if(newmax > DPmax[i])
                    {
                        DPmax[i] = newmax;
                        Cmaxa[i] = char(ca + '0') + Cmaxa[i+1];
                        Cmaxb[i] = char(cb + '0') + Cmaxb[i+1];
                    }
                    long long newabs = 0;
                    if(ca == cb) newabs = DPabs[i+1];
                    if(ca < cb) newabs = -(base * (ca-cb) + DPmax[i+1]);
                    if(ca > cb) newabs = base*(ca-cb)+DPmin[i+1];
                    assert(newabs >= 0);
                    if(newabs < DPabs[i])
                    {
                        DPabs[i] = newabs;
                        if(ca == cb)
                        {
                            Cabsa[i] = char(ca + '0') + Cabsa[i+1];
                            Cabsb[i] = char(cb + '0') + Cabsb[i+1];
                        }
                        if(ca < cb)
                        {
                            Cabsa[i] = char(ca + '0') + Cmaxa[i+1];
                            Cabsb[i] = char(cb + '0') + Cmaxb[i+1];
                        }
                        if(ca > cb)
                        {
                            Cabsa[i] = char(ca + '0') + Cmina[i+1];
                            Cabsb[i] = char(cb + '0') + Cminb[i+1];
                        }
                    }
                }
            }
            //cout << "$" << i << " " << DPmin[i] << " " << DPmax[i] << " " << DPabs[i] << endl;
        }
        cout << "Case #" << ct << ": " << Cabsa[0] << " " << Cabsb[0] << endl;
    }
}
