#include <iostream>
#include <list>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

char map[4][4];
bool empty;

char check_dlg()
{
    char last = 0;
    bool result = true;

    for(int r = 0; r < 4; ++r)
    {
        if(map[r][r] == '.')
        {
            result = false;
            empty = true;
            break;
        }
        else if(last == 0 && map[r][r] != 'T')
            last = map[r][r];
        else if(map[r][r] == 'T' && last != 0)
            last = last;
        else if(map[r][r] == 'T' && last == 0)
            last = 0;
        else if(map[r][r] != last)
        {   
            result = false;
            break;
        }
    }

    if(result)
    {
        return last;
    }
        
    last = 0;
    result = true;

    for(int r = 0; r < 4; ++r)
        if(map[r][3 -r] == '.')
        {
            result = false;
            empty = true;
            break;
        }
        else if(last == 0 && map[r][r] != 'T')
            last = map[r][3 - r];
        else if(map[r][3 - r] == 'T' && last != 0)
            last = last;
        else if(map[r][3 - r] == 'T' && last == 0)
            last = 0;
        else if(map[r][3 - r] != last)
        {    
                result = false;
                break;
        }

        if(result)
            return last;

        return 0;
}

char calc()
{
    empty = false;

    char r = check_dlg();
    if(r != 0)
    {
        return r;
    }

    for(int r = 0; r < 4; ++r)
    {
        int last = 0;
        bool result = true;

        for(int c = 0; c < 4; ++c)
        {
            if(map[r][c] == '.')
            {   
                empty = true;
                result = false;
                break;
            }

            if(last == 0 && map[r][c] != 'T')
                last = map[r][c];
            else if(map[r][c] == 'T' && last == 0)
                last = 0;
            else if(map[r][c] == 'T' && last != 0)
                last = last;
            else if(map[r][c] != last)
            {
                result = false;
                break;
            }
        }

        if(result)
            return last;
    }
    
    for(int c = 0; c < 4; ++c)
    {
        int last = 0;
        bool result = true;

        for(int r = 0; r < 4; ++r)
        {
            if(map[r][c] == '.')
            {   
                empty = true;
                result = false;
                break;
            }

            if(last == 0 && map[r][c] != 'T')
                last = map[r][c];
            else if(map[r][c] == 'T' && last == 0)
                last = 0;
            else if(map[r][c] == 'T' && last != 0)
                last = last;
            else if(map[r][c] != last)
            {
                result = false;
                break;
            }
        }
        
        if(result)
            return last;
    }

    return 0;
}

int main()
{
    int test_case;
    cin>>test_case;

    for(int i = 0; i < test_case ; ++i)
    {
        for(int r = 0; r < 4; ++r)
            for(int c = 0; c < 4; ++c)
            {  
                cin>>map[r][c];
            }

        char r = calc();
        
        if(r == 0 && empty)
            cout<<"Case #"<<i+1<<": Game has not completed"<<endl;
        else if(r == 0 && !empty)
            cout<<"Case #"<<i+1<<": Draw"<<endl;
        else
        cout<<"Case #"<<i+1<<": "<<r<<" won"<<endl;
    }
    
    return 0;
}
