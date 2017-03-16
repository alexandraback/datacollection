#include <iostream>
#include <list>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int row, col;
int map[500][500];

bool check_row(int row, int value)
{
    for(int c = 0; c < col; ++c)
        if(map[row][c] > value)
            return false;

    return true;
}

bool check_col(int col, int value)
{
    for(int r = 0; r < row; ++r)
        if(map[r][col] > value)
            return false;

    return true;
}

bool calc()
{
    
    for(int r = 0; r < row; ++r)
        for(int c = 0; c < col; ++c)
            if(!check_row(r, map[r][c]) && !check_col(c, map[r][c]))
                return false;

    return true;
}

int main()
{
    int test_case;
    cin>>test_case;

    for(int i = 0; i  < test_case ; ++i)
    {
        
        cin>>row>>col;
        for(int r = 0; r < row; ++r)
            for(int c= 0; c< col; ++c)
                cin>>map[r][c];
    
        bool result = calc();
        if(result)
            cout<<"Case #"<<i+1<<": YES"<<endl;
        else
            cout<<"Case #"<<i+1<<": NO"<<endl;
    }

    return 0;
}



