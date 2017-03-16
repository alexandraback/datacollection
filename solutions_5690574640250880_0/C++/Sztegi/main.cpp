#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class MineField
{
public:
    MineField(int rows, int columns, int mines)
        : _rows(rows)
        , _columns(columns)
        , _size(rows*columns)
        , _mines(mines)
        , _free(rows*columns-mines)
        , _fields(rows*columns)
        , _possible(false)
        , _clicked(0)
    {
    }

    void solve()
    {
        if(_mines > _size) return;

        if(_free==1)
        {
            _fields[0] = true;
            _possible = true;
            return;
        }

        if(_rows==1 || _columns==1)
        {
            fillFirstN(_free);
            _possible=true;
            return;
        }


        //if(1 == _free%2 && _free<9) return;

        if(innerSolve())
        {
            _possible=true;
            return;
        }

        transpose();

        if(innerSolve())
        {
            _possible=true;
            transpose();
            return;
        }
    }

    bool innerSolve()
    {          
        for(int i = 2; i <= _free/2 && i<=_columns; i++)
        {
            if( _free > _rows*i) continue;
            if(_free%i==1)
            {
                if(_free/i<3) continue;
                if(i==2) continue;
                fillFirstNWithWidth(_free+1, i);
                _fields[_columns*(_free/i-1) + i -1] = 0;
                return true;
            }

            fillFirstNWithWidth(_free, i);
            return true;
        }
        return false;
    }

    void fillFirstN(int n)
    {
        for(int i = 0; i< n; ++i) _fields[i] = true;
    }

    void fillFirstNWithWidth(int n, int w)
    {
        for(int row = 0; row<=n/w; row++)
            for(int i = 0; i<w && row*w + i < n; ++i) _fields[_columns*row +i] = true;
    }



    void transpose()
    {
        vector<int> v2 = _fields;

        for(int i = 0; i < _columns; ++i)
             for(int j = 0; j < _rows; ++j)
                _fields[j+ _rows*i] = v2[i+_columns*j];


        int tmp = _rows;
        _rows = _columns;
        _columns = tmp;

    }

    string toString()
    {
       if(!_possible) return string("Impossible\n");

       string s;
       s.reserve(_rows*(_columns + 1)+10);

       for(int i = 0; i < _size; ++i)
       {
           char ch = (!_fields[i])? '*' : i==_clicked?'c':'.';
           s+=ch;

           if(i%_columns==_columns-1) s+='\n';
       }

       return s;
    }

private:

    int _rows;
    int _columns;
    int _size;
    int _mines;
    int _free;
    vector<int> _fields;
    bool _possible;
    int _clicked;
};

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");

    out.precision(15);

    int t;
    string line;

    {
        std::getline(in, line);
        istringstream iss(line);
        iss >> t;
    }

    for(int i = 0; i < t; ++i)
    {
        int rows, columns, mines;

        {
            std::getline(in, line);
            istringstream iss(line);
            iss >> rows >> columns >> mines;
        }

        MineField mineField(rows, columns, mines);

        mineField.solve();

        out << "Case #" << i + 1 << ":" << endl;

        out <<  mineField.toString();
    }

    return 0;
}
