#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char,int> convMap;

class Board
{
public:
    bool has_empty;
    int v[4][4];

    void read(istream& is)
    {
        has_empty = false;
        string str;
        for (int i=0; i<4; ++i)
        {
            is >> str;
            //cout << str << endl;
            for (int j=0; j<4; ++j)
            {
                v[i][j]=convMap[str[j]];
                
                if (!has_empty && v[i][j] == 0) has_empty=true;
            }
        }
        //is >> str;
    }
    
    int winner()
    {
        int ret3=3;
        int ret4=3;
        for (int i=0; i<4; ++i)
        {
            ret3 &= v[i][i];
            ret4 &= v[i][3-i];
            int ret1=3;
            int ret2=3;
            for (int j=0; j<4; ++j)
            {
                ret1 &= v[i][j];
                ret2 &= v[j][i];
            }
            if (ret1 != 0) return ret1;
            if (ret2 != 0) return ret2;
        }
        if (ret3 != 0) return ret3;
        if (ret4 != 0) return ret4;
        
        return 0;
    }
    
    void result()
    {
        int win = winner();
        if ( win == 1 )
            cout << "X won";
        else if ( win == 2 )
            cout << "O won";
        else if ( win == 0 )
        {
            if (has_empty)
                cout << "Game has not completed";
            else
                cout << "Draw";
        }
    }
};

void readfile(istream& is)
{
    int num_tests;
    is >> num_tests;
    Board bo;
    for (int i=1; i<=num_tests; ++i)
    {
        bo.read(is);
        cout << "Case #" << i << ": ";
        bo.result();
        cout << endl;
    }
}

int main()
{
    convMap['X']=1;
    convMap['O']=2;
    convMap['T']=3;
    convMap['.']=0;
    readfile(cin);
    return 0;
}
