#include<fstream>
#include<iostream>

using namespace std;


string solve(string s)
 {  string res;
    if(s.size()==0) return res;
    else res+=s[0];
    
 	int i;
 	char first=res[0];
 	for(i=1;i<s.size();i++)
 	 { 
 	    if(s[i]>=first)  res.insert(0,1,s[i]);
 	    else res+=s[i];
 	    first=res[0];
 	 }
 	 
 	 return res;
 }
int main()
{  
  int i,n;
  string s;
 
  ofstream output;
  output.open("output1.txt");
  
  ifstream input;
  input.open("A-small-attempt0.in");
  input>>n;
  
  for(i=1;i<=n;i++)
   {  input>>s;
      output<<"Case #"<<i<<": "<<solve(s)<<endl; 
   }
 input.close();
 output.close();
   return 0;
}
