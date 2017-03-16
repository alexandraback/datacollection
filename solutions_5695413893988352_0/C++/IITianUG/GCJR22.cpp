#include<bits/stdc++.h>
using namespace std;

vector< pair<int, pair<string,string> > > vc;
string s1,s2;


void gn(int i,string t1,string t2,int n)
{
    if(i==n)
    {
    
  
      int ff = stoi(t1);
      int gg = stoi(t2);
      
    
      
      vc.push_back(make_pair(abs(gg-ff),make_pair(t1,t2)));
      return;
       
    }
  
     if(s2[i]=='?')
     {
        for(int j=0;j<=9;j++){    
       char xx = j+48; 
        gn(i+1,t1,t2+xx,n);
        }
     } 
     else
      {
        gn(i+1,t1,t2+s2[i],n);
      }

}




void fn(int i,string t1,string t2,int n)
{
    if(i==n)
    {
    
       gn(0,t1,t2,n);
       return;
    }
  
     if(s1[i]=='?')
     {
        for(int j=0;j<=9;j++){    
        char xx = j+48; 
        fn(i+1,t1+xx,t2,n);
        }
     } 
     else
     fn(i+1,t1+s1[i],t2,n);
     

}

int main()
{
    ifstream IF;
    IF.open("input.txt");
    ofstream OF;
    OF.open("output.txt");
    int t,i;

    IF >> t;
   
    
   
    for(int tc=1;tc<=t;tc++)
    {
      OF <<"Case #"<<tc<<": ";
      vc.clear();
      
   
      IF>>s1>>s2;
      
      int n=s1.length();
      
      string k1="";
      string k2="";
      
      fn(0,k1,k2,n);
      
      sort(vc.begin(),vc.end());
      
      
      OF<<vc[0].second.first<<" "<<vc[0].second.second<<endl;
      
      
      
      
      
     

    }

    OF.close();
    IF.close();
}
