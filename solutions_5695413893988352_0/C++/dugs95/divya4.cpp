#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    
    int t;
    cin>>t;
    int x=1;
    while(t--)
    {
        string s1,s2;
        int i,j,k;
        cin>>s1>>s2;
        vector<string> ans1,ans2;
        queue<string> q;
        q.push(s1);
        while(!q.empty())
        {
            string str=q.front();
            q.pop();
            
            for(i=0;i<str.length();i++)
            {
                if(str[i]=='?')
                {
                    for(j=0;j<=9;j++)
                    {
                        str[i]=j+'0';
                        q.push(str);
                    }
                    
                    break;
                }
            }
            if(i==str.length())
            {
                ans1.push_back(str);
            }
            
        }
        q.push(s2);
        while(!q.empty())
        {
            string str=q.front();
            q.pop();
            
            for(i=0;i<str.length();i++)
            {
                if(str[i]=='?')
                {
                    for(j=0;j<=9;j++)
                    {
                        str[i]=j+'0';
                        q.push(str);
                    }
                    
                    break;
                }
            }
            if(i==str.length())
            {
                
                ans2.push_back(str);
            }
            
        }
        
        int mini=100000000;
        string a1,a2;
        int a11,a21;
        for(int i=0;i<ans1.size();i++)
        {
            int d1=0,d2=0;
            for(k=ans1[i].size()-1;k>=0;k--)
            {
                d1+=(ans1[i][k]-'0')*pow(10,ans1[i].length()-1-k);
            }
            
            for(int j=0;j<ans2.size();j++)
            {
                d2=0;
                for(k=ans2[j].size()-1;k>=0;k--)
                {
                    d2+=(ans2[j][k]-'0')*pow(10,ans2[j].length()-1-k);
                }
                
                if(abs(d1-d2)<mini)
                {
                    mini=abs(d1-d2);
                    a11=d1;
                    a21=d2;
                    a1=ans1[i];
                    a2=ans2[j];
                }
                else if(abs(d1-d2)==mini)
                {
                    
                    if(d1<a11)
                    {
                        a11=d1;
                        a21=d2;
                        a1=ans1[i];
                        a2=ans2[j];
                    }
                    else if(a11==d1)
                    {
                        if(d2<a21)
                        {
                            a11=d1;
                            a21=d2;
                            a1=ans1[i];
                            a2=ans2[j];
                        }
                        
                    }
                    
                }
            }
        }
        
        cout<<"Case #"<<x<<": "<<a1<<" "<<a2<<endl;
        x++;
    }
    
    
    return 0;
}