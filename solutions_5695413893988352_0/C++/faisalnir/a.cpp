#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<string>p;
vector<string>q;
void make(char s[],int i,string num,int X)
{
    string pp;
    if(i==strlen(s))
    {
        //printf("%d\n",num);
        //cout<<num<<endl;
        if(X==0)
       p.pb(num);
       else q.pb(num);
        return ;
    }
    if(s[i]!='?')
    {
        //num=num*10+s[i]-'0';
         pp=num+=s[i];
        make(s,i+1,pp,X);
    }
    else
    {
        for(int j=0;j<=9;j++)
        {
            pp=num+(char)(j+'0');
            make(s,i+1,pp,X);
        }
    }
}
int nn(string x)
{
    int p=0;
    for(int i=0;i<x.size();i++)p=p*10+(x[i]-'0');
    return p;
}

struct node
{
    int c,j;
    string cc,jj;
    node(string x,string y)
    {
        cc=x;
        jj=y;
        c=nn(cc),j=nn(jj);
    }
    bool operator<(const node t)const
    {
        return (abs(c-j)<abs(t.c-t.j))||(abs(c-j)==abs(t.c-t.j) && c <t.c) ||(abs(c-j)==abs(t.c-t.j) && c ==t.c && j<t.j);
    }
};
vector<node>ans;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        char s[20],ss[20];

        p.clear();q.clear();ans.clear();
        scanf("%s",s);scanf("%s",ss);
        make(s,0,"",0);

        make(ss,0,"",1);
        for(int i=0;i<p.size();i++)for(int j=0;j<q.size();j++)ans.pb(node(p[i],q[j]));
        sort(ans.begin(),ans.end());
        //printf("febfui");
       cout<<"Case #"<<c<<": "+ans[0].cc+" "+ans[0].jj<<endl;



    }

}
