#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("C-small-attempt0.in");
ofstream out("output.out");

int t,r,c,m;
char g[5][5];

void scan()
{
    in>>r>>c>>m;
}

bool check()
{
    bool b=1;
    while(b)
    {
        b=0;
        for(int i=0;i<r;i++)for(int j=0;j<c;j++)
        {
            if(g[i][j]=='c')
            {
                b=1;
                bool z=1;
                if(i-1>=0&&j>=0&&i-1<r&&j<c)if(g[i-1][j]=='*')z=0;
                if(i-1>=0&&j+1>=0&&i-1<r&&j+1<c)if(g[i-1][j+1]=='*')z=0;
                if(i>=0&&j+1>=0&&i<r&&j+1<c)if(g[i][j+1]=='*')z=0;
                if(i+1>=0&&j+1>=0&&i+1<r&&j+1<c)if(g[i+1][j+1]=='*')z=0;
                if(i+1>=0&&j>=0&&i+1<r&&j<c)if(g[i+1][j]=='*')z=0;
                if(i+1>=0&&j-1>=0&&i+1<r&&j-1<c)if(g[i+1][j-1]=='*')z=0;
                if(i>=0&&j-1>=0&&i<r&&j-1<c)if(g[i][j-1]=='*')z=0;
                if(i-1>=0&&j-1>=0&&i-1<r&&j-1<c)if(g[i-1][j-1]=='*')z=0;
                if(z)
                {
                    if(i-1>=0&&j>=0&&i-1<r&&j<c)if(g[i-1][j]=='.')g[i-1][j]='c';
                    if(i-1>=0&&j+1>=0&&i-1<r&&j+1<c)if(g[i-1][j+1]=='.')g[i-1][j+1]='c';
                    if(i>=0&&j+1>=0&&i<r&&j+1<c)if(g[i][j+1]=='.')g[i][j+1]='c';
                    if(i+1>=0&&j+1>=0&&i+1<r&&j+1<c)if(g[i+1][j+1]=='.')g[i+1][j+1]='c';
                    if(i+1>=0&&j>=0&&i+1<r&&j<c)if(g[i+1][j]=='.')g[i+1][j]='c';
                    if(i+1>=0&&j-1>=0&&i+1<r&&j-1<c)if(g[i+1][j-1]=='.')g[i+1][j-1]='c';
                    if(i>=0&&j-1>=0&&i<r&&j-1<c)if(g[i][j-1]=='.')g[i][j-1]='c';
                    if(i-1>=0&&j-1>=0&&i-1<r&&j-1<c)if(g[i-1][j-1]=='.')g[i-1][j-1]='c';
                    g[i][j]='#';
                }
                else g[i][j]='#';
            }
        }
        /*cout<<":::"<<endl;
        for(int k=0;k<r;k++)
        {
            for(int l=0;l<c;l++)cout<<g[k][l];
            cout<<endl;
        }
        cout<<":::"<<endl;*/
    }
    int count=0;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)if(g[i][j]=='#')count++;
    if(count==r*c-m)return 1;
    else return 0;
}

void form(string s)//*.c r=3 c=1
{
    //if(s=="*.c")cout<<s<<" "<<r<<"-"<<c<<endl;
    for(int i=0;i<r*c;i++){/*if(s=="*.c")cout<<i/c<<endl;*/g[i/c][i%c]=s[i];}
}

void print(int t)
{
    out<<"Case #"<<t<<":"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)out<<g[i][j];
        out<<endl;
    }
}

void solve(int t)
{
    string s;
    for(int i=0;i<m;i++)s+="*";
    for(int i=0;i<r*c-m-1;i++)s+=".";
    s+="c";
    form(s);
    /*cout<<"m"<<m<<s<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)cout<<g[i][j];
        cout<<endl;
    }
    cout<<endl;*/
    if(check()){form(s);print(t);goto end;}
    while(next_permutation(s.begin(),s.end()))
    {
        form(s);
        if(check()){form(s);print(t);goto end;}
    }
    out<<"Case #"<<t<<":"<<endl<<"Impossible"<<endl;
    end:;
}

int main()
{
    in>>t;
    for(int i=0;i<t;i++)
    {
        scan();
        solve(i+1);
    }
    return 0;
}
