#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main ()
{
  freopen("B-small-attempt3.in","r",stdin);   
  freopen("Bs.txt","w",stdout);
    
  int T, b, b_remain;  
  double M;
  /*
  M = 1000000000;
  M = M*M;
  cout<<M<<"\n";
  cin>>T;
  */  
  cin>>T;
  
  
 // cout<<T<<"\n";
  double powers_of_two[50];
  double cur = 1;
  bool slides [51][51];
  

  
 // cout<<T<<"\n";
  for (int i=1;i<21;++i)
  {
      cur = cur * i;  
      powers_of_two[i] = cur;     
      //cout<<cur<<"\n";
  }
  
  //cout<<T<<"\n";

  for (int t=1;t<=T;++t)
  {
      cin>>b>>M;
      b_remain = b-2;
      
        for (int i=0;i<51;++i)
        {
          for (int j=0;j<51;++j)
               slides[i][j] = false;    
           }
      
      //cout<<"T: "<<T<<" b: "<<b<<" M:"<<M<<"\n";
      
      int cur_pos = 2;
      bool possible = true;
      
      M = M-1;
      slides[1][b] = true; //Always have a slide from 1 to B
      
      
      
      while (M>0.5 && possible)
      {
            //cout<<"M: "<<M<<" cur_pos: "<<cur_pos<<" b_remain: "<<b_remain<<"\n";
            //Find x
            int x = 0;
            while (M>(powers_of_two[x+1]-0.5))
                  x++;
            
            if (x>b_remain)
            {
               possible = false;               
            }
            else
            {
                for (int i=cur_pos; i<cur_pos+x;++i)
                {
                    slides[1][i] = true;
                    for (int j=i+1;j<cur_pos+x;++j)
                    {
                        slides[i][j] = true;    
                    }    
                    slides[i][b] = true;
                }
                M = M - powers_of_two[x];
                cur_pos += x;
                b_remain -= (x);
            }
      }
      
      
      
      
      if (possible)
      {
         cout<<"Case #"<<t<<": POSSIBLE\n";
         for (int i=1;i<=b;++i)
         {
             for (int j=1;j<=b;++j)
             {
                 if (slides[i][j])
                    cout<<"1";
                 else
                     cout<<"0";    
             }    
             cout<<"\n";
         }
      }
      else
          cout<<"Case #"<<t<<": IMPOSSIBLE\n";    
  }
  
  return 0;
}
