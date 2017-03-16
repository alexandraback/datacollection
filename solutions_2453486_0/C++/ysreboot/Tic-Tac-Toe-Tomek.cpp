#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>

#define ulli unsigned long long int
#define MOD 1000000007

using namespace std;

int main()
{
    /* uncomment the following two lines to fectch input from input.txt and write to output.txt (after you have completed rest of your code) */
    
    freopen("A-small-attempt0.in","r",stdin);
    freopen("Aoutput.txt","w",stdout);
    
    int T;
    scanf("%d",&T);
    int t=1;
    
    while(T--)
    {
             
             int out=0;  //0=draw 1=Incomplete     2=X wins   3=O wins
             int tab[4][4]={0};
             
             for(int i=0;i<4;i++)
             {
                 char in[5];
                 scanf("%s",&in);
                 for(int j=0;j<4;j++)
                 {
                         switch(in[j])
                         {
                                   case 'X':
                                        tab[i][j]=10;
                                        break;
                                   case 'O':
                                        tab[i][j]=30;
                                        break;
                                   case 'T':
                                        tab[i][j]=5;
                                        break;
                                   case '.':
                                        tab[i][j]=100;
                                        out=1;
                                        break;
                         }
                 }
                 
             }
             
             for(int i=0;i<4;i++)
             {
                     int sum=0;
                 for(int j=0;j<4;j++)
                 {
                         if(tab[i][j]==100)
                         {
                                  sum=0;
                                  break;
                         }
                         sum+=tab[i][j];
                 }
                 if(sum==40 || sum==35)
                 {
                            out=2;
                            break;
                 }
                 else if(sum==120 || sum==95)
                 {
                            out=3;
                            break;
                 }
             }
             
             
             for(int i=0;i<4;i++)
             {
                     int sum=0;
                 for(int j=0;j<4;j++)
                 {
                         if(tab[j][i]==100)
                         {
                                  sum=0;
                                  break;
                         }
                         sum+=tab[j][i];
                 }
                 if(sum==40 || sum==35)
                 {
                            out=2;
                            break;
                 }
                 else if(sum==120 || sum==95)
                 {
                            out=3;
                            break;
                 }
             }
             
             int sum=0;
             for(int jj=0;jj<4;jj++)
             {
                     if(tab[jj][jj]==100)
                     {
                              sum=0;
                              break;
                     }
                     sum+=tab[jj][jj];
             }
             if(sum==40 || sum==35)
             {
                        out=2;
             }
             else if(sum==120 || sum==95)
             {
                        out=3;
             }
         
             int sum2=0;
             for(int jk=0;jk<4;jk++)
             {
                     if(tab[jk][3-jk]==100)
                     {
                              sum2=0;
                              break;
                     }
                     sum2+=tab[jk][3-jk];
             }
             if(sum2==40 || sum2==35)
             {
                        out=2;
             }
             else if(sum2==120 || sum2==95)
             {
                        out=3;
             }
             
              printf("Case #%d: ",t++);
              switch(out)
              {
                         case 0: printf("Draw");
                              break;
                         case 1: printf("Game has not completed");
                              break;
                         case 2: printf("X won");
                              break;
                         case 3: printf("O won");
                              break;
              }
              printf("\n");
              
    }
    
    return 0;
}
