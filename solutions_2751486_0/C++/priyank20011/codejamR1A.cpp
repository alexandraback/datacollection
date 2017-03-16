#include<iostream>
#include<ostream>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<map>
#include<math.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long int ans=0,n;
class SubstringGen
{
public:
	void GetAllSubstrings(string input, int startIndex)
	{
		int innerStartIndex = startIndex;
		string s(1, input[innerStartIndex]);
		long int i,l,x=0,f=0;
      // cout<<s<<" ";
        l=s.size();
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
            //cout<<x<<"\n";
        if(f==1)
            ans++;}
		while (innerStartIndex < input.length())
		{
			innerStartIndex++;
			if (innerStartIndex == input.length())
				break;
			s += input[innerStartIndex];
           
			long int i,l,x=0,f=0;
            l=s.size();
           // cout<<s<<" ";
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
			GetAllSubstrings(input, startIndex);
	};
};
int main()
{
	freopen("D:\\input1.txt","r",stdin);
    freopen("D:\\output2.txt","w",stdout);
    long int t,l,no=1;
    string a;
    cin>>t;
    while(t--)
    { ans=0;
        cin>>a>>n;
    SubstringGen substringGen;
    substringGen.GetAllSubstrings(a,0);
        cout<<"Case #"<<no<<": "<<ans<<"\n";
        no++;
    }
    return 0;
}

