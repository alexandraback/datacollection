#include<iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;

    char c;

    for(int cas=1;cas<=T;cas++)
    {
        char rowX[4]={};
        char colX[4]={};
        char rowO[4]={};
        char colO[4]={};
        char diag1X=0;
        char diag2X=0;
        char diag1O=0;
        char diag2O=0;
        char emp=0;
        char win='\0';

        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            cin>>c;

            if(win != '\0')
                continue;

            if(c=='X')
            {
                rowX[i]++;
                colX[j]++;

                if(i == j)
                {
                    diag1X++;
                    if(diag1X == 4)
                        win='X';
                }
                else if((i+j)==3)
                {
                    diag2X++;
                    if(diag2X == 4)
                        win='X';
                }

                if((rowX[i]==4)||(colX[j]==4))
                    win='X';
            }
            else if(c=='O')
            {
                rowO[i]++;
                colO[j]++;

                if(i == j)
                {
                    diag1O++;
                    if(diag1O == 4)
                        win='O';
                }
                else if((i+j)==3)
                {
                    diag2O++;
                    if(diag2O == 4)
                        win='O';
                }

                if((rowO[i]==4)||(colO[j]==4))
                    win='O';
            }
            else if(c=='T')
            {
                rowX[i]++;
                colX[j]++;
                rowO[i]++;
                colO[j]++;

                if((rowX[i]==4)||(colX[j]==4))
                    win='X';

                if((rowO[i]==4)||(colO[j]==4))
                    win='O';

                if(i == j)
                {
                    diag1X++;
                    diag1O++;

                    if(diag1X == 4)
                        win='X';
                    if(diag1O == 4)
                        win='O';
                }
                else if((i+j)==3)
                {
                    diag2X++;
                    diag2O++;
                    if(diag2X == 4)
                        win='X';
                    if(diag2O == 4)
                        win='O';
                }
            }
            else
                emp++;
        }

        if(win == '\0')
        {
            if(emp == 0)
                cout<<"Case #"<<cas<<": Draw"<<endl;
            else
                cout<<"Case #"<<cas<<": Game has not completed"<<endl;
        }
        else
                cout<<"Case #"<<cas<<": "<<win<<" won"<<endl;
    }
    return 0;
}
