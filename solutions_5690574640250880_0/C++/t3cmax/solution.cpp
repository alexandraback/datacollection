#include<fstream>
#include<cmath>
#include<string.h>
#include<stdio.h>
using namespace std;

ofstream fout("ans.out");
ifstream fin("C-small-attempt3.in");

char map[51][51];
int t,r,c,m;

int main()
{
    int i,j,k,times;
    int temp_r,temp_c;
    int temp;
    bool flag;
    bool sol;
    fin>>t;
    for(times=1;times<=t;times++)
    {
        fin>>r>>c>>m;
        //fout<<r<<' '<<c<<' '<<m<<endl;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                map[i][j]='*';
            }
        }
        
        
        fout<<"Case #"<<times<<":"<<endl;
        
        temp_r=r;
        temp_c=c;
        flag=0;
        sol=1;
        while(1)
        {
             if(temp_r<=2 && temp_c<=2)
             {
                 break;
             }
             
             if(temp_r<=temp_c)
             {
                  if(temp_r<=m)
                  {
                      temp_c--;
                      m-=temp_r;
                  }
                  else
                  {
                      break;
                  }
             }
             else
             {
                  if(temp_c<=m)
                  {
                      temp_r--;
                      m-=temp_c;
                  }
                  else
                  {
                      break;
                  }
             }
        }
        
        if(temp_r==1 && temp_c<=3)
        {
             if(temp_c==2)
             {
                  if(m==0)
                  {
                       map[1][2]='.';
                  }
             }
             else
             {
                  if(m==0)
                  {
                      map[1][2]=map[1][3]='.';
                  }
                  else if(m==1)
                  {
                      map[1][2]='.';
                  }
             }
        }
        else if(temp_c==1 && temp_r<=3)
        {
             if(temp_r==2)
             {
                  if(m==0)
                  {
                       map[2][1]='.';
                  }
             }
             else
             {
                  if(m==0)
                  {
                      map[2][1]=map[3][1]='.';
                  }
                  else if(m==1)
                  {
                      map[2][1]='.';
                  }
             }
        }
        else if(temp_r>2 || temp_c>2)
        {
            if(temp_r<=temp_c)
            {
                 if((temp_c==3 && temp_r==3 && m==2) || (temp_r==2 && m==1))
                 {
                    sol=0;
                 }
                 else
                 {
                     for(i=1;i<=temp_r;i++)
                     {
                         for(j=1;j<=temp_c;j++)
                         {
                             map[i][j]='.';
                         }
                     }
                     
                     for(i=temp_r;m!=0;i--)
                     {
                         map[i][temp_c]='*';
                         m--;
                     }
                     
                     if(temp_r!=1)
                     {
                     if(map[2][temp_c]=='*')
                     {
                         map[2][temp_c]='.';
                         map[temp_r][temp_c-1]='*';
                     }
                     }
                 }
            }
            else
            {
                 if((temp_r==3 && temp_c==3 && m==2) || (temp_c==2 && m==1))
                 {
                    sol=0;
                 }
                 else
                 {
                     for(i=1;i<=temp_r;i++)
                     {
                         for(j=1;j<=temp_c;j++)
                         {
                             map[i][j]='.';
                         }
                     }
                     
                     for(i=temp_c;m!=0;i--)
                     {
                         map[temp_r][i]='*';
                         m--;
                     }
                     
                     if(temp_c!=1)
                     {
                     if(map[temp_r][2]=='*')
                     {
                         map[temp_r][2]='.';
                         map[temp_r-1][temp_c]='*';
                     }
                     }
                 }
            }
        }
        else
        {
            if(temp_r==2 && temp_c==2)
            {
                if(m==0)
                {
                    map[1][1]=map[1][2]=map[2][1]=map[2][2]='.';
                }
                else if(m==3)
                {
                    
                }
                else
                {
                    sol=0;
                }
            }
            else
            {
                if(temp_r==2)
                {
                     map[2][1]=map[1][1]='.';
                }
                else
                {
                    map[1][2]=map[1][1]='.';
                }
            }
        }
        
        
        map[1][1]='c';
        
        if(sol==1)
        {
            for(i=1;i<=r;i++)
            {
                for(j=1;j<=c;j++)
                {
                    fout<<map[i][j];
                }
                fout<<endl;
            }
        }
        else
        {
            fout<<"Impossible"<<endl;
        }
        
    }
    
    
    
    system("pause");
}
