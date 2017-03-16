#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



int main()
{  
  int i,n,a,b,x,j,k;

  vector<int> vec;
  int have[2600];
  ofstream output;
  output.open("output4.txt");
  
  ifstream input;
  input.open("B-large.in");
  input>>n;
  
  for(i=1;i<=n;i++)
   {  input>>a;
      //cout<<s.size()<<endl;
      for(j=1;j<=2500;j++) have[j]=0;
      b=2*a-1;
      vec.clear();
      for(j=0;j<b;j++)
       {  
         for(k=0;k<a;k++)
          { input>>x;
            have[x]++;
          }
       }
       
       for(j=1;j<=2500;j++)
        { 
		  if(have[j]%2==1 && have[j]>0) 
		   {
		     vec.push_back(j);
		    
           }
        }
        
      sort(vec.begin(),vec.end());
      
      output<<"Case #"<<i<<": ";
      for(j=0;j<a;j++)
       output<<vec[j]<<" ";
       output<<endl;
   }
   
 input.close();
 output.close();
   return 0;
}
