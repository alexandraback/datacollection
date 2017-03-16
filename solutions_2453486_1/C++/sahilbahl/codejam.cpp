#include<iostream>
using namespace std;
int main()
{
   freopen("A-large.in","r",stdin);
    freopen("output.in","w",stdout);
    int cases;
    int arr[4][4];
    char a;
    int breaker=0;
    int row[4];
    int col[4];
    int diag[4];
    int check = 0;
    cin>>cases;
    
    int count=0;
    cin.ignore();
    while(cases--)
    {
      count++;
      breaker=0;
      check=0;
      for(int k=0;k<4;k++)
      {
         row[k]=0;
         col[k]=0;
         diag[k]=0;
      }
       for(int i=0;i<4;i++)
       {
               for(int j=0;j<4;j++)
               {
                       cin>>a;
                       
                       if(a=='X')
                      {
                           arr[i][j]=1;                
                      }
                      else if(a=='O')
                      {
                              arr[i][j] = -1;
                      }
                      else if(a=='T')
                      {
                           arr[i][j]= 0;
                      }
                      else
                      {
                          arr[i][j] = 2;
                           check=1;      
                      }
               }
       }
      /* for(int g=0;g<4;g++)
       {
               for(int r=0;r<4;r++)
               {
                       cout<<arr[g][r]<<" ";
               }
               cout<<endl;
       }*/
       for(int l=0;l<4;l++)
       {
               for(int m=0;m<4;m++)
               {
                       if(arr[l][m]==2)
                       {
                           //break;
                           if(l==m)
                        {
        //                 cout<<"first";
                           diag[0] = diag[0] + 10;
                           row[l] = row[l]  + 10;
                       col[m] = col[m] + 10;
                       }
                       else  if((l + m)==3)
                       {
                             diag[1] = diag[1] + 10;
                             row[l] = row[l]  + 10;
                       col[m] = col[m] + 10;
                       }
                       else
                       {
                            row[l] = row[l]  + 10;
                       col[m] = col[m] + 10;
                       }
                           
                       }
                       else if(l==m)
                       {
        //                 cout<<"first";
                           diag[0] = diag[0] + arr[l][m];
                           row[l] = row[l]  + arr[l][m];
                       col[m] = col[m] + arr[l][m];
                       }
                       else  if((l + m)==3)
                       {
                             diag[1] = diag[1] + arr[l][m];
                             row[l] = row[l]  + arr[l][m];
                       col[m] = col[m] + arr[l][m];
                       }
                       else
                       {
                            row[l] = row[l]  + arr[l][m];
                       col[m] = col[m] + arr[l][m];
                       }
               }
       }
     //  cout<<col[0]<<"row"<<diag[0]<<"sec"<<diag[1];
       for(int o=0;o<4;o++)
       {
               if(row[o]==3||row[o]==4)
               {
                  //cout<<"a";
                    cout<<"Case #"<<count<<": X won"<<endl;
                    breaker=1;
                    break;
               }
               else if(row[o]==-3||row[o]==-4)
               {
                    //cout<<"b";
                    cout<<"Case #"<<count<<": O won"<<endl;
                    breaker=1;
                    break;
               }
               
               else if(col[o]==3||col[o]==4)
               {
                    //cout<<"c"<<o;
                    cout<<"Case #"<<count<<": X won"<<endl;
                    breaker=1;
                    break;
               }
               else if(col[o]==-3||col[o]==-4)
               {
                    //cout<<"d"<<o;
                    cout<<"Case #"<<count<<": O won"<<endl;
                    breaker=1;
                    break;
               }
               else if(diag[0]==3||diag[0]==4)
               {
                    //cout<<"e";
                    cout<<"Case #"<<count<<": X won"<<endl;
                    breaker=1;
                    break;
               }
               else if(diag[0]==-3||diag[0]==-4)
               {
                   //cout<<"f";
                    cout<<"Case #"<<count<<": O won"<<endl;
                    breaker=1;
                    break;
               }
               else  if(diag[1]==3||diag[1]==4)
               {
                     //cout<<"g";
                    cout<<"Case #"<<count<<": X won"<<endl;
                    breaker=1;
                    break;
               }        
               else   if(diag[1]==-3||diag[1]==-4)
               {
                     // cout<<"h";
                    cout<<"Case #"<<count<<": O won"<<endl;
                    breaker=1;
                    break;
               }        
       }
      //cout<<diag[0]<<"SDAdf"<<diag[1];  
       if((breaker==0)&&(check==0))
       {
            cout<<"Case #"<<count<<": Draw"<<endl;
       }
       else if((breaker==0)&&(check==1))
       {
           cout<<"Case #"<<count<<": Game has not completed"<<endl;
       }
    }
   // system("pause");
    return 0;
}
