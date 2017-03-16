#include<iostream>
#include<ostream>
#include<fstream>
#include<iomanip>
#include<map>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>

#include<vector>
using namespace std;
long int ans=0,n;
class Subs
{
public:
	void Get(string input, int startIndex)
	{
		int xxx = startIndex;
		string s(1, input[xxx]);
		long int i,l=s.size(),x=0,f=0;
     
        
        if(l>=n){
        for(i=0;i<l;i++)
        {
            if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
            {
                x++;
                if(x==n)
                {
                    f=1;break;
                }
                
            }
            else
                x=0;
        }
           
        if(f==1)
            ans++;}
		while (xxx < input.length())
		{
			xxx++;
			if (xxx == input.length())
				break;
			s += input[xxx];
           
			long int i,l=s.size(),x=0,f=0;
                     
            if(l>=n){
            for(i=0;i<l;i++)
            {
              if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
              {  x++;
                if(x==n)
                {
                    f=1;break;
                }
                
            }
                else
                    x=0;
            }
               // cout<<x<<"\n";
            if(f==1)
                ans++;
		}
        }
		startIndex++;
		if (startIndex < input.length())
			Get(input, startIndex);
	};
};
int main()
{

 freopen("input.txt","r",stdin);
  freopen("output.in","w",stdout);
    long int test,l,no=1;
    string a;
    cin>>test;
    while(test--)
    { ans=0;
        cin>>a>>n;
    Subs A;
  A.Get(a,0);
        cout<<"Case #"<<no<<": "<<ans<<"\n";
        no++;
    }
    return 0;
}