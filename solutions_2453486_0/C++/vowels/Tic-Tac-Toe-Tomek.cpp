#include <iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for( int i=1; i <=t;i++) 
    {
        string arr[4];
        bool DrawNotPossible=false;
        for(int j=0; j<4;j++) 
        {
            cin>>arr[j];
            for(int k=0; k <4;k++)
            {
                if(arr[j][k]=='.')
                {
                    DrawNotPossible = true;
                }
            }
        }
        bool O_Won = false;
        bool X_Won = false;

        for( int j=0; j <4 ;j++)
        {
            if(O_Won || X_Won)
            {
                break;
            }

            int T_count=0;
            int X_count=0;
            int O_count=0;
            for( int k=0; k <4; k++)
            {
                if(arr[j][k]=='.')
                {
                    break;
                }
                else if(arr[j][k]=='T')
                {
                    T_count++;
                }
                else if(arr[j][k]=='O')
                {
                    O_count++;
                }
                else if(arr[j][k]=='X')
                {
                    X_count++;
                }
            }
            if ( X_count ==4 || (X_count==3 && T_count==1))
            {
                X_Won=true;
                        cout<<"Case #"<<i<<": X won"<<endl;
                        break;
            }
            else if (O_count ==4 || (O_count==3 && T_count==1))
            {
                O_Won=true;

                        cout<<"Case #"<<i<<": O won"<<endl;
                        break;
            }
            if(O_Won || X_Won)
            {
                break;
            }
            T_count=0;
            X_count=0;
            O_count=0;
            for( int k=0; k <4; k++)
            {
                if(arr[k][j]=='.')
                {
                    break;
                }
                else if(arr[k][j]=='T')
                {
                    T_count++;
                }
                else if(arr[k][j]=='O')
                {
                    O_count++;
                }
                else if(arr[k][j]=='X')
                {
                    X_count++;
                }
            }
            if ( X_count ==4 || (X_count==3 && T_count==1))
            {
                X_Won=true;
                cout<<"Case #"<<i<<": X won"<<endl;
                break;
            }
            else if (O_count ==4 || (O_count==3 && T_count==1))
            {
                O_Won=true;
                cout<<"Case #"<<i<<": O won"<<endl;
                break;
            }
        }

        if(O_Won || X_Won)
        {
            continue;
        }
        int T_count=0;
        int X_count=0;
        int O_count=0;
        for( int j=0; j<4;j++)
        {
            int k=j;
            if(arr[k][j]=='.')
            {
                break;
            }
            else if(arr[k][j]=='T')
            {
                T_count++;
            }
            else if(arr[k][j]=='O')
            {
                O_count++;
            }
            else if(arr[k][j]=='X')
            {
                X_count++;
            }
        }
        if ( X_count ==4 || (X_count==3 && T_count==1))
        {
            X_Won=true;
            cout<<"Case #"<<i<<": X won"<<endl;
            continue;
        }
        else if (O_count ==4 || (O_count==3 && T_count==1))
        {
            O_Won=true;
            cout<<"Case #"<<i<<": O won"<<endl;
            continue;
        }

        if(O_Won || X_Won)
        {
            continue;
        }
        T_count=0;
        X_count=0;
        O_count=0;

        for( int j=0; j<4;j++)
        {
            int k=3-j;
            if(arr[k][j]=='.')
            {
                break;
            }
            else if(arr[k][j]=='T')
            {
                T_count++;
            }
            else if(arr[k][j]=='O')
            {
                O_count++;
            }
            else if(arr[k][j]=='X')
            {
                X_count++;
            }
        }
        if ( X_count ==4 || (X_count==3 && T_count==1))
        {
            X_Won=true;
            cout<<"Case #"<<i<<": X won"<<endl;
            continue;
        }
        else if (O_count ==4 || (O_count==3 && T_count==1))
        {
            O_Won=true;
            cout<<"Case #"<<i<<": O won"<<endl;
            continue;
        }

        if(O_Won || X_Won)
        {
            continue;
        }
        if(DrawNotPossible)
        {
            cout<<"Case #"<<i<<": Game has not completed"<<endl;
        }
        else
        {
            cout<<"Case #"<<i<<": Draw"<<endl;
        }

    }
    return 0;
}
