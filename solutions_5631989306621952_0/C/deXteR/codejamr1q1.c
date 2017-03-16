#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int t;
    string s,s1="";
    int x=0,c=0,i,j;
    cin>>t;
    while(t--)
    {
        s1="";
        x++;
        cin>>s;
        int l=s.length();
        s1=s1+s[0];
        char f;
        for(i=1;i<l;i++)
        {
            f=s1[0];
            if(s[i]>=f)
                s1=s[i]+s1;
            else
                s1=s1+s[i];
        }

        cout<<"Case #"<<x<<": "<<s1<<endl;
    }
    return 0;
}
