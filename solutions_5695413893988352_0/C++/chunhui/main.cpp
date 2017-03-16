#include <iostream>

#include <string>
using namespace std;

int string2Int(const string& a)
{
    int ans = 0;
    for(int i=0; i<a.size(); i++)
    {
        ans *= 10;
        ans += a[i]-'0';
    }
    return ans;
}
void check(string C, string J, int i, int j, string& c, string& jj, int& minV)
{
    if(i == C.size() && j==C.size())
    {
        int a = string2Int(C);
        int b = string2Int(J);
        if(abs(a - b) < minV)
       {
           c = C;
           jj = J;
           minV = abs(a - b);
       }
       else if(abs(a - b) == minV)
       {
           if(a < string2Int(c))
           {
               c = C;
               jj = J;
           }
           else if(a == string2Int(c) && b < string2Int(jj))
           {
               jj = J;
           }
       }
    }
    else if(i < C.size())
    {
        while(i < C.size() && C[i] != '?') ++i;
        if(i < C.size())
        {
            for(int a=0; a<=9; a++)
            {
                C[i] = '0'+ a;
                check(C, J, i+1, j, c, jj, minV);
            }
        }
        else
        {
            check(C, J, C.size(), j, c, jj, minV);
        }
    }
    else
    {
        while(j < C.size() && J[j] != '?') ++j;
        if(j < C.size())
        {
            for(int a=0; a<=9; a++)
            {
                J[j] = '0' + a;
                check(C, J, i, j+1, c, jj, minV);
            }
        }
        else
            check(C, J, i, C.size(), c, jj, minV);
    }
}
int main()
{
    int T;
    cin >> T;
    for(int i=1; i<=T; i++)
    {
        string C, J;
        cin >> C >> J;
        int minV = 2000;
        string c, j;
        check(C, J, 0, 0, c, j, minV);
        cout << "Case #" << i << ": " << c << " " << j << endl;
    }


    return 0;
}


