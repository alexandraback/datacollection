#include <bits/stdc++.h>

using namespace std;

int n, nb_wanted;

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        printf("Case #%d:\n", kras);
        scanf("%d %d", &n, &nb_wanted);
        long long now = (1LL<<(n-1))+1;
        vector<string> jamcoins;
        vector< vector<int> > divisors;

        int succesful=0;
        for(long long test=now; succesful != nb_wanted; test += 2)
        {
            string s = "";
            long long cop = test;
            while(cop != 0)
            {
                s += '0'+(cop%2);
                cop /= 2;
            }
            reverse(s.begin(), s.end());

            vector<int> delers;
            for(int base=2; base<=10; base++)
            {
                bool deler_found = false;
                for(int deler=2; deler<=100; deler++)
                {
                    int totale_rest=0;
                    int basis_rest=1;
                    for(int i=s.size()-1; i>=0; i--)
                    {
                        totale_rest = (totale_rest+basis_rest*(s[i]-'0'))%deler;
                        basis_rest = (basis_rest*base)%deler;
                    }
                    if(totale_rest==0)
                    {
                        deler_found = true;
                        delers.push_back(deler);
                        break;
                    }
                }
                if(!deler_found)
                {
                    break;
                }
            }
            if(delers.size() == 9)
            {
                succesful++;
                jamcoins.push_back(s);
                divisors.push_back(delers);
            }
        }
        for(int i=0; i<nb_wanted; i++)
        {
            cout << jamcoins[i];
            for(int j=0; j<9; j++)
            {
                cout << " " << divisors[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
