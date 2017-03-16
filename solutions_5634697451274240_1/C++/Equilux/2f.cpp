#include<iostream>
#include<string.h>
using namespace std;
char s[100][101];
int ind=0;
int solve(int x,int c)
{
    int i=0;
    if(x==0)
    {

        if(c==1)
        {
            if(s[ind][0]=='+')
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            if(s[ind][0]=='-')
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    if(c==1)
    {
        if(s[ind][x]=='+')
        {
            i+=solve(x-1,1);
        }
        else
        {
            i+=solve(x-1,0);
            i++;
        }

    }
    else
    {
        if(s[ind][x]=='+')
        {
            i+=solve(x-1,1);
            i++;
        }
        else
        {
            i+=solve(x-1,0);
        }

    }

    return i;
}
int main()
{
    int t,i,n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s[i];
    }
    for(ind=0;ind<t;ind++)
    {
        n=strlen(s[ind])-1;
        cout<<"Case #";
	cout<<ind+1;
	cout<<": ";
	cout<<solve(n,1);
	cout<<"\n";
    }
    return 0;
}
