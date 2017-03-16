#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        string C, J;
        cin >> C >> J;
        
        int n = C.length();

        string resC, resJ;
        int Cval = 10000, Jval = 10000;
        int ans = 10000;
        
        if(n == 3)
        {
            int a, b, c, d, e, f;
            for(int a = 0; a < 10; a++)
            {
                if(C[0] != a + '0' && C[0] != '?') continue;
                for(int b = 0; b < 10; b++)
                {
                    if(C[1] != b + '0' && C[1] != '?') continue;
                    for(int c = 0; c < 10; c++)
                    {
                        if(C[2] != c + '0' && C[2] != '?') continue;
                        for(int d = 0; d < 10; d++)
                        {
                            if(J[0] != d + '0' && J[0] != '?') continue;
                            for(int e = 0; e < 10; e++)
                            {
                                if(J[1] != e + '0' && J[1] != '?') continue;
                                for(int f = 0; f < 10; f++)
                                {
                                    if(J[2] != f + '0' && J[2] != '?') continue;
                                    int currC = a * 100 + b * 10 + c;
                                    int currJ = d * 100 + e * 10 + f;
                                    int diff = abs(currC - currJ);
                                    if((diff < ans) || (diff == ans && currC < Cval) || (diff == ans && currC == Cval && currJ < Jval))
                                    {
                                        ans = diff; Cval = currC; Jval = currJ;
                                        resC = ""; resJ = "";
                                        resC = resC + to_string(a); resC = resC + to_string(b); resC = resC + to_string(c); 
                                        resJ = resJ + to_string(d); resJ = resJ + to_string(e); resJ = resJ + to_string(f);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(n == 2)
        {
            int a, b, c, d;
            for(int a = 0; a < 10; a++)
            {
                if(C[0] != a + '0' && C[0] != '?') continue;
                for(int b = 0; b < 10; b++)
                {
                    if(C[1] != b + '0' && C[1] != '?') continue;
                    for(int c = 0; c < 10; c++)
                    {
                        if(J[0] != c + '0' && J[0] != '?') continue;
                        for(int d = 0; d < 10; d++)
                        {
                            if(J[1] != d + '0' && J[1] != '?') continue;
                            int currC = a * 10 + b;
                            int currJ = c * 10 + d;
                            int diff = abs(currC - currJ);
                            if((diff < ans) || (diff == ans && currC < Cval) || (diff == ans && currC == Cval && currJ < Jval))
                            {
                                ans = diff; Cval = currC; Jval = currJ;
                                resC = ""; resJ = "";
                                resC = resC + to_string(a); resC = resC + to_string(b); 
                                resJ = resJ + to_string(c); resJ = resJ + to_string(d);
                            }
                        }
                    }
                }
            }
        }
        else if(n == 1)
        {
            int a, b;
            for(int a = 0; a < 10; a++)
            {
                if(C[0] != a + '0' && C[0] != '?') continue;
                for(int b = 0; b < 10; b++)
                {
                    if(J[0] != b + '0' && J[0] != '?') continue;
                    int currC = a;
                    int currJ = b;
                    int diff = abs(currC - currJ);
                    if((diff < ans) || (diff == ans && currC < Cval) || (diff == ans && currC == Cval && currJ < Jval))
                    {
                        ans = diff; Cval = currC; Jval = currJ;
                        resC = ""; resJ = "";
                        resC = resC + to_string(a);
                        resJ = resJ + to_string(b);
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << resC << " " << resJ << endl;
    }

    return 0;
}
