#include <iostream>
#include <string>

using namespace std;

bool isvalid(string s,int n)
{
    int i,j;
    if(s.length()<n)
      return false;
           //cout<<"--"<<s<<endl;
    for(i=0;i<=s.length()-n;i++)
    {
        bool is = true;
        for(j=i;j<i+n;j++)
        {
            if(s[j]=='a' || s[j] == 'e' || s[j] == 'o' || s[j] =='u' || s[j] == 'i')
            {
              is = false;
              break;
            }
          
        }
        if(is)
        {
           return true;

        }
    
    }
    return false;

}

int main()
{
    int T;
    cin>>T;
    
    int cot = 1;
    while(T--)
    {
        string s;
        cin>>s;

        int n;
        cin>>n;
        
        int i,j;
        int count = 0;


        for(i=0;i<s.length();i++)
        {
          for(j=0;j<=s.length()-i;j++)
          {
                if(isvalid(s.substr(i,j) , n))
                {
                    count++;
                
                }
          
          }
        }
        cout<<"Case #"<<cot<<": "<<count<<endl;
        cot++;
    
    }



}
