#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
char s[1001];
char o[1001];
int n=0;
char lower(char c)
{
    if((c<='Z')&&(c>='A'))
    {
      c-='a'-'A';
    }
    return c;
}
void insertend()
{
    o[n]=s[n];
    n++;
}
void insertbeg()
{
    int i;
    for(i=n;i>0;i--)
    {
        o[i]=o[i-1];
    }
    o[0]=s[n];
    n++;
}
int main()
{
    int t,i,j;
    int len;
    cin>>t;
    for(j=0;j<t;j++)
    {
        n=0;
        cout<<"Case #"<<j+1<<": ";
        cin>>s;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(lower(s[i])>=lower(o[0]))
            {
                insertbeg();
            }
            else
            {
                insertend();
            }
        }
        for(i=0;i<len;i++)
        {
            cout<<o[i];
        }
        cout<<"\n";
    }
    return 0;
}
