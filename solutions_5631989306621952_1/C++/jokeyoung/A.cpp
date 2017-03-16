#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>

using namespace std;

int main()
{     
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out","w",stdout);
    
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        string s;
        cin>>s;
        
        vector<char> v;
        v.clear();
        //
        v.push_back(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]>=v[0])
            {v.insert(v.begin(),s[i]);}
            else
            {v.insert(v.end(),s[i]);}    
        }//
        
        for(int i=0;i<s.size();i++)
            s[i]=v[i];
            
        //printf("Case #%d: %d\n",cas,ans);      
        cout<<"Case #"<<cas<<": "<<s<<endl;
          
    }//
    
  //system("pause");
}
