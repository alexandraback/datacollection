#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXREP = 12;
const int MAXL = 10000;

// 0,  1, 2,  3, 4,  5, 6,  7
// 1, -1, i, -i, j, -j, k, -k
int valtable[4][4] = {{0, 1, 2, 3},
                      {1, 0, 3, 2},
                      {2, 3, 0, 1},
                      {3, 2, 1, 0}};
                      
int signtable[4][4] = {{0, 0, 0, 0},
                       {0, 1, 0, 1},
                       {0, 1, 1, 0},
                       {0, 0, 1, 1}};                  
                      
bool resp[MAXREP*MAXL+1][8][4];

int mul(int a, int b)
{
    int av = a/2;
    int bv = b/2;
    int sign = (a + b + signtable[av][bv]) % 2;
    int val = valtable[av][bv];
    return 2*val + sign;
}

int convert(char c)
{
    if(c == 'i')
    {
        return 2;
    }
    
    if(c == 'j')
    {
        return 4;
    }
    
    if (c == 'k')
    {
        return 6;
    }
    
    return 0;
}

bool cando(const string& num)
{
    static const int req[] = {convert('i'), convert('j'), convert('k')};
    int n = num.size();
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<8;++j)
        {
            for(int k=0;k<4;++k)
            {
                resp[i][j][k] = false;
            }
        }
    }
    
    resp[0][0][0] = true;
    for(int i=0;i<n;++i)
    {
        int v = convert(num[i]);
        for(int j=0;j<8;++j)
        {
            for(int k=0;k<3;++k)
            {
                if(resp[i][j][k])
                {
                    int prod = mul(j, v);
                    resp[i+1][prod][k] = true;
                    if(prod == req[k])
                    {
                        resp[i+1][0][k+1] = true;
                    }
                }
            }
        }
    }
    
    return resp[n][0][3];
}

int main()
{
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        int l;
        long long x;
        string s;
        cin >> l >> x >> s;
        int rep = (x > MAXREP) ? static_cast<int>(MAXREP + (x % 4) - 4) : static_cast<int>(x);
        
        string num;
        for(int i=0;i<rep;++i)
        {
            num += s;
        }
        
        cout << "Case #" << lp << ": " << (cando(num) ? "YES" : "NO") << "\n";  
    }
    return 0;
}