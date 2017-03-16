#include<cstdio>
#include<iostream>
#include<fstream>

using namespace std;
char grid[10][10];

int main()
{
    freopen("codejam1.in","r",stdin);
    freopen("codejam1out.txt","w",stdout);
    int tc,filled;
    char tmp;
    scanf("%d",&tc);
    //cout << tc << endl;
    for (int i=0; i<tc; i++)
    {
        filled=1;
        //Read in grid
        for (int j=0; j<4; j++)
        {
            for (int k=0; k<4; k++)
            {
                cin >> tmp;
                //cout << tmp << "~";
                grid[j][k]=tmp;
                if (tmp=='.')
                   filled=0;
            }
            //cout << endl;
        }
        int success=0;
        int cor=0; //0 can be both, 1 must be O, 2 must be X
        for (int j=0; j<4; j++)
        {
            cor=0;
            //Check rows
            for (int k=0; k<4; k++)
            {
                if (cor==0)
                {
                   if (grid[j][k]=='O')
                   {
                      cor=1;
                   }
                   else if (grid[j][k]=='X')
                   {
                        cor=2;
                   }
                   else if (grid[j][k]=='.')
                   {
                        break;
                   }
                }
                else if (cor==1) //Must be O
                {
                       if (grid[j][k]=='X')
                       {
                          break;
                       }
                       else if (grid[j][k]=='.')
                       {
                            break;
                       }
                }
                else if (cor==2) //Must be X
                {
                    if (grid[j][k]=='O')
                       {
                        break;
                       }
                       else if (grid[j][k]=='.')
                       {
                            break;
                       }
                }
                if (k==3)
                {
                   success=cor;
                }
            }
            if (success!=0)
            {
               break;
            }
        }
        if (success==0)
        {
            for (int k=0; k<4; k++)
            {
                cor=0;
                //Check columns
                for (int j=0; j<4; j++)
                {
                    if (cor==0)
                    {
                       if (grid[j][k]=='O')
                       {
                          cor=1;
                       }
                       else if (grid[j][k]=='X')
                       {
                            cor=2;
                       }
                       else if (grid[j][k]=='.')
                       {
                            break;
                       }
                    }
                    else if (cor==1) //Must be O
                    {
                           if (grid[j][k]=='X')
                           {
                              break;
                           }
                           else if (grid[j][k]=='.')
                           {
                                break;
                           }
                    }
                    else if (cor==2) //Must be X
                    {
                        if (grid[j][k]=='O')
                           {
                            break;
                           }
                           else if (grid[j][k]=='.')
                           {
                                break;
                           }
                    }
                    if (j==3)
                    {
                       success=cor;
                    }
                }
                if (success!=0)
                {
                   break;
                }
            }
            //Check diagonals
            if (success==0)
            {
                           cor=0;
                for (int j=0; j<4; j++)
                {
                    int k=j;
                    if (cor==0)
                        {
                           if (grid[j][k]=='O')
                           {
                              cor=1;
                           }
                           else if (grid[j][k]=='X')
                           {
                                cor=2;
                           }
                           else if (grid[j][k]=='.')
                           {
                                break;
                           }
                        }
                        else if (cor==1) //Must be O
                        {
                               if (grid[j][k]=='X')
                               {
                                  break;
                               }
                               else if (grid[j][k]=='.')
                               {
                                    break;
                               }
                        }
                        else if (cor==2) //Must be X
                        {
                            if (grid[j][k]=='O')
                               {
                                break;
                               }
                               else if (grid[j][k]=='.')
                               {
                                    break;
                               }
                        }
                        if (k==3)
                        {
                           success=cor;
                        }
                }
                cor=0;
                for (int j=0; j<4; j++)
                {
                    int k=3-j;
                    if (cor==0)
                        {
                           if (grid[j][k]=='O')
                           {
                              cor=1;
                           }
                           else if (grid[j][k]=='X')
                           {
                                cor=2;
                           }
                           else if (grid[j][k]=='.')
                           {
                                break;
                           }
                        }
                        else if (cor==1) //Must be O
                        {
                               if (grid[j][k]=='X')
                               {
                                  break;
                               }
                               else if (grid[j][k]=='.')
                               {
                                    break;
                               }
                        }
                        else if (cor==2) //Must be X
                        {
                            if (grid[j][k]=='O')
                               {
                                break;
                               }
                               else if (grid[j][k]=='.')
                               {
                                    break;
                               }
                        }
                        if (k==0)
                        {
                           success=cor;
                        }
                }
            }
        }
        printf("Case #%d: ",i+1);
        if (success==1)
        {
           printf("O won\n");
        }
        else if (success==2)
        {
             printf("X won\n");
        }
        else if (success==0)
        {
             if (filled==0)
             {
                printf("Game has not completed\n");
             }
             else
             {
                 printf("Draw\n");
             }
        }
    }
}
