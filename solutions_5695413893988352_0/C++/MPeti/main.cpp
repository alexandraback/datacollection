#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

typedef long long ll;

ll P10[19];
ll minC[20];
ll minJ[20];
ll maxC[20];
ll maxJ[20];
string C, J;

int main()
{
    //istream& in = cin;
    //ostream& out = cout;
    ifstream in("in.txt");
    ofstream out("out.txt");
    ios::sync_with_stdio(false);
    P10[0] = 1;
    for (int i = 1; i <= 18; i++)
    {
        P10[i] = 10*P10[i-1];
    }
    minC[0] = minJ[0] = maxC[0] = maxJ[0] = 0;
    int T;
    in >> T;
    for (int t = 1; t <= T; t++)
    {
        in >> C >> J;
        int bc = -1;
        int bj = -1;
        for (int c = 0; c < P10[C.size()]; c++)
        {
            for (int j = 0; j < P10[C.size()]; j++)
            {
                bool ok = true;
                for (int cc = 0; cc < C.size(); cc++)
                {
                    int b = C.size()-cc-1;
                    if (C[cc] != '?' && (C[cc]-'0') != (c/P10[b])%10)
                        ok = false;
                }
                for (int cc = 0; cc < C.size(); cc++)
                {
                    int b = C.size()-cc-1;
                    if (J[cc] != '?' && (J[cc]-'0') != (j/P10[b])%10)
                        ok = false;
                }
                if (ok)
                {
                    if (bc == -1 || (abs(c-j) < abs(bc-bj) || abs(c-j) == abs(bc-bj) && (c < bc || c == bc && j < bj)))
                    {
                        bc = c;
                        bj = j;
                    }
                }
            }
        }
        for (int cc = 0; cc < C.size(); cc++)
        {
            int b = C.size()-cc-1;
            C[cc] = (bc/P10[b])%10+'0';
        }
        for (int cc = 0; cc < C.size(); cc++)
        {
            int b = C.size()-cc-1;
            J[cc] = (bj/P10[b])%10+'0';
        }
        out << "Case #" << t <<": ";
        for (char c : C)
            out << c;
        out << " ";
        for (char c : J)
            out << c;
        out << endl;
    }
}

