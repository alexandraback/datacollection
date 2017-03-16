#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


int main(int argc, const char * argv[])
{
    ifstream cin("C-small-attempt3.in.txt");
    ofstream cout("C-small-attempt3.out.txt");
    
    int T;
    cin>>T;
    for(int q = 0; q < T; q++)
    {
        cout << "Case #" << q + 1 << ":\n";
        int r, c, m;
        cin >> r >> c >> m;
        int left = r * c - m;
        vector<vector<char> > result(r, vector<char>(c, '*'));
        int a, b, l;
        //======
        for(a = 2; a <= r && result[0][0] != 'c'; a++)
            for(b = 2; b <= c && result[0][0] != 'c'; b++)
            {
                l = left - a * b;
                for(int l1 = 0; l1 <= min(l, a) && result[0][0] != 'c'; l1++)
                {
                    int l2 = l - l1;
                    if (l1 != 0 && l2 != 0 && a < r && b < c && l1 >= 2 && l2 >= 2 && l1 <= a && l2 <= b)
                    {
                        for(int i = 0; i < a; i++)
                            for(int j = 0; j < b; j++)
                                result[i][j] = '.';
                        for(int i = 0; i < l1; i++)
                            result[i][b] = '.';
                        for(int i = 0; i < l2; i++)
                            result[a][i] = '.';
                        result[0][0] = 'c';
                    }
                    if (l1 == 0 && l2 != 0 && a < r && b <= c  && l2 >= 2 && l2 <= b)
                    {
                        for(int i = 0; i < a; i++)
                            for(int j = 0; j < b; j++)
                                result[i][j] = '.';
                        for(int i = 0; i < l2; i++)
                            result[a][i] = '.';
                        result[0][0] = 'c';
                    }
                    if (l1 != 0 && l2 == 0 && a <= r && b < c && l1 >= 2 && l1 <= a)
                    {
                        for(int i = 0; i < a; i++)
                            for(int j = 0; j < b; j++)
                                result[i][j] = '.';
                        for(int i = 0; i < l1; i++)
                            result[i][b] = '.';
                        result[0][0] = 'c';
                    }
                    if (l1 == 0 && l2 == 0 && a <= r && b <= c)
                    {
                        for(int i = 0; i < a; i++)
                            for(int j = 0; j < b; j++)
                                result[i][j] = '.';
                        result[0][0] = 'c';
                    }
                }
            }
        
        if(r * c - m == 1)
            result[0][0] = 'c';
        
        if(r == 1)
        {
            for(int i = 1; i < left; i++)
                result[0][i] = '.';
            result[0][0] = 'c';
        }
        
        if(c == 1)
        {
            for(int i = 1; i < left; i++)
                result[i][0] = '.';
            result[0][0] = 'c';
        }
        
        if(result[0][0] != 'c')
            cout << "Impossible\n";
        else
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                    cout<<result[i][j];
                cout<<"\n";
            }
    }
    
}

