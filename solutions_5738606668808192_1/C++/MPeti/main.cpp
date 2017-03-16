#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int P[40][40];
int PR[100]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
int pow(int a, int e, int m)
{
    int r = 1;
    for (int i = 0; i < e; i++)
    {
        r *= a;
        r %= m;
    }
    return r;
}

int d(bool* T, int s, int b)
{
   // cout << "Trying ";
   // for (int i = s-1; i >= 0; i--)
     //   cout << T[i];
    //cout << "

    for (int p : PR)
    {
     //   cout << "Div by " << p << endl;
        int r = 0;
        for (int i = 0; i < s; i++)
        {
            if (T[i])
                r += pow(b, i, p);
        //    cout << r << endl;
        }
        if (r % p == 0)
            {
                //cin.get();
                return p;
            }
    }

    return -1;
}

int main()
{
    int N, C;
    cin >> N >> C;
    bool T[N];
    int c = 0;
    vector<string> V1;
    vector<vector<int>> V2;
    T[0] = T[N-1] = true;
    for (int i = 0; i < (1 << N-2) && c < C; i++)
    {
        for (int j = 0; j < N-2; j++)
        {
            T[j+1] = (bool)(i & (1 << j));
        }
        vector<int> divs;
        for (int b = 2; b <= 10; b++)
        {
            int x = d(T, N, b);
            if (x == -1)
            {
                divs.clear();
                break;
            }
            else
            {
                divs.push_back(x);
            }
        }
        if (!divs.empty())
        {
            c++;
            V2.push_back(divs);
            string s;
            for(int i = N-1; i >= 0; i--)
            {
                s.push_back(char(T[i] + '0'));
            }
            V1.push_back(s);
        }
    }
    ofstream out("out.txt");
    out << "Case #1: " << endl;
    for (int i = 0; i < C; i++)
    {
        out << V1[i] << " ";
        for (int x : V2[i])
            out << x << " ";
        out << endl;
    }
}
