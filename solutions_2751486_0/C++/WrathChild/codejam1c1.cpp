#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int chk(string x,int n)
{
    int i=0,j=0,l=x.length(),count=0;
    for(i=0;i<l;i++)
    {
        if(x[i]!='a'&&x[i]!='o'&&x[i]!='i'&&x[i]!='e'&&x[i]!='u')
            count++;
        else
            count=0;
        if(count==n)return 1;
    }
    return 0;
}
int main()
{
//    freopen("C:\\Users\\wrathchild\\Desktop\\input.txt","r",stdin);
//    freopen("C:\\Users\\wrathchild\\Desktop\\output.txt","w",stdout);
    int test=0,temp=0;
    scanf("%d",&test);
    for(temp=1;temp<=test;temp++)
    {
        string s;int n;
        cin>>s>>n;
        int i=0,j=0,l=0,ans=0;
        l=s.length();
        for(i=0;i<s.length();i++)
        {
            for(j=i;j<s.length();j++)
            {
                string x=s.substr(i,j-i+1);
                if(x.length()>=n)
                ans+=chk(x,n);
            }
        }
        printf("Case #%d: %d\n",temp,ans);
    }
    return 0;
}

