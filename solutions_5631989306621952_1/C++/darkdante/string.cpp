#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
        
         fstream fin("A-large.in",ios::in);
         fstream fout("stringlarge.txt",ios::out) ; 
        ios_base::sync_with_stdio(0);
        int t,count=0;
        fin>>t;
        while(t--)
        {
                count++;
                
                string s ;
                fin>>s;
                for(int i=1;i<s.length();i++)
                {
                        if(s[i]>=s[0])
                        {
                           char fin=s[i];
                           for(int j=i-1;j>=0;j--)
                           s[j+1]=s[j];
                           s[0]=fin;     
                        }   
                  }
                  fout<<"Case #"<<count<<": "<<s<<"\n";         
                
        }
}
