#include<iostream>
using namespace std;

string map[4];
bool x , o , hasdot;
int xcnt, ocnt, tcnt;

void check(char a)
{
     if(a == 'X')
         xcnt++;
     if(a == 'O')
         ocnt++;
     if(a == 'T')
         tcnt++;
     if(a == '.')
         hasdot = true;
}

bool checkwin(int index)
{
     if(xcnt + tcnt == 4)
     {
         cout<<"X won"<<endl;
         return true;
     }
     if(ocnt + tcnt == 4)
     {
         cout<<"O won"<<endl;
         return true;   
     }
     return false;
}

int main()
{
    freopen("c:\\1.in","r",stdin);
    freopen("c:\\1-out.txt","w",stdout);
    int T;
    cin>>T;
    for(int caseIndex = 1; caseIndex <= T; ++caseIndex)
    {
        cout<<"Case #"<<caseIndex<<": ";
        for(int i = 0; i < 4; ++i)
            cin>>map[i];
        
        x = false;
        o = false;
        hasdot = false;
        
        //check row
        for(int i = 0; i < 4; ++i)
        {
            xcnt = ocnt = tcnt = 0;
            for(int j = 0; j < 4 ;++j)
            {
                check(map[i][j]);
            }
            
            if(checkwin(caseIndex))
                goto nextcase;
        }
        
        //check col
         for(int i = 0; i < 4; ++i)
        {
            xcnt = ocnt = tcnt = 0;
            for(int j = 0; j < 4 ;++j)
            {
                check(map[j][i]);
            }
            
            if(checkwin(caseIndex))
                goto nextcase;
        }
        
        //\/
        xcnt = ocnt = tcnt = 0;
        for(int i = 0; i < 4; ++i)
            check(map[i][i]);
        if(checkwin(caseIndex))
            goto nextcase;
        
        xcnt = ocnt = tcnt = 0;
        for(int i = 0; i < 4; ++i)
            check(map[i][3-i]);
        if(checkwin(caseIndex))
            goto nextcase;
            
        if(hasdot)
            cout<<"Game has not completed"<<endl;
        else
            cout<<"Draw"<<endl;
nextcase:
        continue;
    }
}
