#include <bits/stdc++.h>
using namespace std;

#define fin cin
#define fout cout
#define double long double
/*
ifstream fin("input.in");
ofstream fout("output.out");
*/
int hash[29];

    string s1,s2;
int k,l,s;
char ch[26];int x=0;

int countstring(string a,string b)
{
    int c=0;
    for(int i=0;i<a.length()-b.length()+1;i++)
    {
        string z=a.substr(i,b.length());
        if(z==b)c++;
    }
    return c;
}

double prob(string s)
{
    double kans=1;
    for(int i=0;i<s.length();i++)
    {
        int num=s[i]-'A';
        kans=kans*(double)hash[num]/s1.length();
    }
    return kans;
}

double zans=0;
int maxans=0;

void recur(string temp)
{
    if(temp.length()==s)
    {

        zans+=prob(temp)*countstring(temp,s2);
        //cout<<zans<<" ";
        maxans=max(maxans,countstring(temp,s2));
        //cout<<countstring(temp,s2)<<" ";
        return;
    }
    for(int i=0;i<x;i++)
    {
        recur(temp+ch[i]);
    }
}

int main()
{
    int t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(hash,0,sizeof(hash));
            x=0,zans=0,maxans=0;
            fin>>k>>l>>s;
            fin>>s1>>s2;
            for(int i=0;i<s1.length();i++)
            {
                int num=s1[i]-'A';
                hash[num]++;
            }
            for(int i=0;i<26;i++)
            {
                if(hash[i]!=0)
                {
                    ch[x++]=i+'A';
                }
            }
            /*
            for(int i=0;i<x;i++)fout<<ch[i];
            fout<<endl;
            */
                    cout<<"Case #"<<i<<": ";
        //fout<<ans;

            string temp;
            recur(temp);
            //cout<<zans<<endl;
            double u=maxans;
            printf("%.7Lf\n",u-zans);
    }
}
