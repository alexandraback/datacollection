#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream IF;
    IF.open("input.txt");
    ofstream OF;
    OF.open("output.txt");
    int t,i;

    IF >> t;
    string s;
    
    vector<int> vc;
    
   
    for(int tc=1;tc<=t;tc++)
    {
      OF <<"Case #"<<tc<<": ";
      vc.clear();
      IF>>s;
      
      int n=s.length();
      
      int buck[30]={0};
      
      for(i=0;i<n;i++)
        buck[s[i]-'A']++;
        
        int cnt=buck['Z'-'A']; //Z
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['Z'-'A']--;
          buck['E'-'A']--;
           buck['R'-'A']--;
            buck['O'-'A']--;
            vc.push_back(0);
       }
       
       cnt=buck['X'-'A']; //X
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['S'-'A']--;
          buck['I'-'A']--;
           buck['X'-'A']--;
           vc.push_back(6);
      
       }
       
       
       
        cnt=buck['W'-'A']; //W
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['T'-'A']--;
          buck['W'-'A']--;
            buck['O'-'A']--;
            vc.push_back(2);
       }
       
       
        cnt=buck['G'-'A']; //G
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['E'-'A']--;
          buck['I'-'A']--;
           buck['G'-'A']--;
            buck['H'-'A']--;
            buck['T'-'A']--;
            vc.push_back(8);
       }
       
       
         cnt=buck['H'-'A']; //H
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['T'-'A']--;
          buck['H'-'A']--;
           buck['R'-'A']--;
            buck['E'-'A']--;
            buck['E'-'A']--;
            vc.push_back(3);
       }
       
       
        cnt=buck['U'-'A']; //U
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['F'-'A']--;
          buck['O'-'A']--;
           buck['U'-'A']--;
            buck['R'-'A']--;
            vc.push_back(4);
       }
       
         cnt=buck['F'-'A']; //F
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['F'-'A']--;
          buck['I'-'A']--;
           buck['V'-'A']--;
            buck['E'-'A']--;
            vc.push_back(5);
       }
       
         cnt=buck['V'-'A']; //V
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['S'-'A']--;
          buck['E'-'A']--;
           buck['V'-'A']--;
            buck['E'-'A']--;
            buck['N'-'A']--;
            vc.push_back(7);
       }
       
        cnt=buck['O'-'A']; //O
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['O'-'A']--;
          buck['N'-'A']--;
           buck['E'-'A']--;
           vc.push_back(1);
         
       }
       
         cnt=buck['E'-'A']; //E
        
       
       for(i=1;i<=cnt;i++)
       {
         buck['N'-'A']--;
          buck['I'-'A']--;
           buck['N'-'A']--;
            buck['E'-'A']--;
            vc.push_back(9);
       }
       
       
       sort(vc.begin(),vc.end());
       
       
       for(i=0;i<vc.size();i++)
         OF<<vc[i];
         
         OF<<endl;
       
         
         
        
        
       
      
      
      
      
      

    



    }

    OF.close();
    IF.close();
}
