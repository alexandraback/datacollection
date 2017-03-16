#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <cassert>
#include <set>
using namespace std;

typedef set<string> tSS;
typedef pair<string,string> tPSS;
typedef set<tPSS> tSP;

char s[20];
char *ptr[20];

int main()
{
    int T;
    cin >> T;
    for (int cases=1; cases<=T; cases++)
    {
        int A, B;
        cin >> A >> B;

        int tmp = A;

        stringstream ssB;
        ssB << B;

        string sB = ssB.str();
        int d = sB.length();

        int cnt = 0;
        // tSP all;
        for (int n=A; n<B; n++)
        {
            tmp = n;
            for (int k=1; k<=d; k++)
            {
                s[d-k] = '0' + (tmp % 10);
                s[2*d-k] = s[d-k];
                tmp /= 10;
            }
            s[2*d] = '\0';

            //tSS known; 
            int c = 0;
            for (int k=1; k<d; k++) 
            {
                if (strncmp(s+0, s+k, d)<0 && strncmp(s+k, sB.c_str(), d)<=0) 
                {
                    bool good = true;
                    for (int j=0; j<c; j++)
                        if (strncmp(ptr[j], s+k, d) == 0)
                        {
                            good = false;
                            break;
                        }

                    if (good)
                    {
                        ptr[c] = s+k;
                        ++c;
                    }
                           

/*
                    string str = s+k;
                    known.insert(str.substr(0,d));
                   // ++cnt;
                    cout << cnt << " " << n << " " << str.substr(0,d) << endl;

                    tPSS p = tPSS(str.substr(0,d), string(s).substr(0,d));

                    if (all.find(p) != all.end())
                        cout << "ALARM!" << endl;
                    all.insert(p);
*/
                }
            }
            cnt += c;
            //cnt += known.size();

        }
        cout << "Case #" << cases << ": " << cnt << endl;
    }
    


}
