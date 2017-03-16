#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<set>
#include<vector>
using namespace std;


int k,l,s;
string s1,s2;
int m;
double x[26];
int Tx[26];
double expected=0;
vector<char> element;
int calc(string str1, string str2)
{
    int ans=0;
    if(str1.size()<str2.size()) return 0;
    for(int i=0;i<str1.size();i++)
    {
        if(str1[i]==str2[0])
        {
            int j;
            for(j=0;j<str2.size();j++)
            {
                if(str1[j+i] !=str2[j]) break;
            }
            if(j==str2.size()) ans++;
        }
    }
    return ans;

}
void dfs(int d, string &str)
{
    if(d==s)
    {
        double p=1;
        for(int i=0;i<s;i++)
        {
            p*=x[str[i]-'A'];
        }
        int t=calc(str, s2);
        if(t> m)
            m=t;
        expected+=p*t;
        return;
    }
    for(int i=0;i<element.size();i++)
    {
        string temp=str;
        str+=element[i];
        dfs(d+1,str);
        str=temp;
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);


    for(int cas=0;cas<T;cas++)
    {
       // cin>>s1>>s2;
       // cout<<calc(s1,s2)<<endl;
       // continue;

        cin>>k>>l>>s;
        cin>>s1>>s2;
        //if(s2.size())
        memset(x,0,sizeof(x));
        memset(Tx,0,sizeof(Tx));
        element.clear();
        for(int i=0;i<k;i++)
        {
            Tx[s1[i]-'A']++;
            if(Tx[s1[i]-'A']==1)
            {
               element.push_back(s1[i]);
            }
        }
        for(int i=0;i<26;i++)
            x[i]= Tx[i]*1.0/k;

        string str="";
        expected=0;
        m=0;
        dfs(0,str);


        printf("Case #%d: %.8lf\n",cas+1,m-expected);

    }
    return 0;
}
