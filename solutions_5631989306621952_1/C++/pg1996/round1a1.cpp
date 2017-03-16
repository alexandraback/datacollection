#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("1a1large.txt","w",stdout);
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        string s;
        cin>>s;

        int n=s.length();
        int pos[n];
        char ans[n+1];
        pos[0]=0;int start=0;int end=0;char sc=s[0];
        for(int i=1;i<n;i++)
        {
            if(s[i]>=sc)
            {
                pos[i]=start-1;
                start--;
                sc=s[i];
            }
            else
            {
                end++;
                pos[i]=end;

            }
        }
        int min=1000;
        for(int j=0;j<n;j++)
        {
            if(pos[j]<min)
                min=pos[j];
        }
        int x=-1*min;
        for(int y=0;y<n;y++)
        {
            pos[y]+=x;
            ans[pos[y]]=s[y];
        }
        ans[n]='\0';
        cout<<"Case #"<<q+1<<": "<<ans<<"\n";
    }
    return 0;
}
