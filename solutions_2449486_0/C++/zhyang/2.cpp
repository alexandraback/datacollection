#include<iostream>
using namespace std;

int map[105][105];
int row, col;

int main()
{
    freopen("c:\\2.txt","r",stdin);
    freopen("c:\\2-out.txt","w",stdout);
    
    int T;
    cin>>T;
    for(int caseIndex = 1; caseIndex <= T; ++caseIndex)
    {
        cin>>row>>col;
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                cin>>map[i][j];
                
        bool ok = true;
        for(int i = 0; i < row && ok; ++i)
            for(int j = 0; j < col && ok; ++j)
            {
                //check row
                bool rowok = true, colok = true;
                for(int k = 0; k < row; ++k)
                    if(map[i][j] < map[k][j])
                    {
                        rowok = false;
                        break;
                    }
                for(int k = 0; k < col; ++k)
                    if(map[i][j] < map[i][k])
                    {
                        colok = false;
                        break;
                    }
                if(!rowok && !colok)
                    ok = false;
            }
        
        if(ok)
            cout<<"Case #"<<caseIndex<<": YES"<<endl;
        else
            cout<<"Case #"<<caseIndex<<": NO"<<endl;
    }
    return 0;
}
