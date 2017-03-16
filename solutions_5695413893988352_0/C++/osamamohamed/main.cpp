#include <iostream>
#include <cmath>
#include <cstdio>
#include <assert.h>
#include <algorithm>

using namespace std;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    freopen("B-small-attempt1.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , cc = 0;
    cin >> T;
    while(T--)
    {
        ++cc;
        string C , J;
        cin >> C >> J;

        int s = -1 , isJ = -1;
        for(int i = 0;i < (int)C.size();++i)
        {
            if(isdigit(C[i]) and isdigit(J[i]))
            {
                if(C[i] > J[i])
                {
                    isJ = 0;
                    s = i;
                    break;
                }
                else if(C[i] < J[i])
                {
                    isJ = 1;
                    s = i;
                    break;
                }
            }
        }

        if(s != -1)
        {
            for(int i = s - 1;i > -1;--i)
            {
                if(isJ)
                {
                    if(C[i] == '?')
                    {
                        if(J[i] == '?')
                        {
                            C[i] = '1';
                            J[i] = '0';
                            break;
                        }
                        else if(J[i] < '9')
                        {
                            C[i] = J[i] + 1;
                            break;
                        }
                        else
                            C[i] = J[i];
                    }
                }
                else
                {
                    if(J[i] == '?')
                    {
                        if(C[i] == '?')
                        {
                            J[i] = '1';
                            C[i] = '0';
                            break;
                        }
                        else if(C[i] < '9')
                        {
                            J[i] = C[i] + 1;
                            break;
                        }
                        else
                            J[i] = C[i];
                    }
                }
            }
        }

        cerr << C << "  " << J << "\n";
        int state = 0;
        for(int i = 0;i < (int)C.size();++i)
        {
            if(C[i] == '?' and J[i] == '?')
            {
                if(!state)      C[i] = J[i] = '0';
                else if(state == 1)
                {
                    C[i] = '0';
                    J[i] = '9';
                }
                else
                {
                    J[i] = '0';
                    C[i] = '9';
                }
            }
            else if(C[i] == '?' and isdigit(J[i]))
            {
                if(!state)      C[i] = J[i];
                else if(state == 1)
                    C[i] = '0';

                else
                    C[i] = '9';
            }
            else if(isdigit(C[i]) and J[i] == '?')
            {
                if(!state)      J[i] = C[i];
                else if(state == 1)
                    J[i] = '9';

                else
                    J[i] = '0';
            }
            else if(isdigit(C[i]) and isdigit(J[i]) and !state)
            {
                if(C[i] > J[i])     state = 1;
                else if(C[i] < J[i])    state = 2;
            }
        }

        cout << "Case #" << cc << ": " << C << " " << J << "\n";
//        cerr << "done  ->  " << cc << " " << C << " " << J << "\n";
    }
    return 0;
}
