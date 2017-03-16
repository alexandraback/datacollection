#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    int t,i,j,k,start,end,cas=1;
    ofstream out;
    out.open("big.out");
    char ch[2010];
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        start=end=1000;
        out<<"Case #"<<cas<<": ";
        cas++;
        ch[1000]=s[0];
        for(i=1;i<s.length();i++)
        {
            if(s[i]>=ch[start])
            {
                start--;
                ch[start]=s[i];
            }
            else
            {
                end++;
                ch[end]=s[i];
            }
        }
        for(i=start;i<=end;i++)
        {
            out<<ch[i];
        }
        out<<endl;
    }
    return 0;
}
