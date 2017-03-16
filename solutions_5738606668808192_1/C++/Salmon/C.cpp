#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n,j;
struct no
{
    string s;
    int d2,d6,d8;
    no(string ss,int dd2,int dd6,int dd8)
    {
        s=ss;
        d2=dd2;
        d6=dd6;
        d8=dd8;
    }
};
vector<no> as;
vector<int> ps;
long long vl(string s,int b)
{
    long long re=0;
    for(int i=0;i<s.length();i++)
    {
        re=re*b+s[i]-'0';
    }
    return re;
}
bool ts(string s,int b,int m)
{
    int ms=0;
    for(int i=0;i<s.length();i++)
        ms=(ms*b+s[i]-'0')%m;
    return ms==0;
}
void gn(string s,int c1)
{
    if(j==0)
        return;
    if(c1==7)
        return;
    if(s.length()==n)
    {
        if(s[s.length()-1]!='1')
            return;
        if(c1!=6)
            return;
        int d2=0;
        for(int i=0;i<ps.size();i++)
        {
            if(ts(s,2,ps[i]))
            {
                d2=ps[i];
                break;
            }
        }
        if(d2==0)
            return;
        int d6=0;
        for(int i=0;i<ps.size();i++)
        {
            if(ts(s,6,ps[i]))
            {
                d6=ps[i];
                break;
            }
        }
        if(d6==0)
            return;
        int d8=0;
        for(int i=0;i<ps.size();i++)
        {
            if(ts(s,8,ps[i]))
            {
                d8=ps[i];
                break;
            }
        }
        if(d8==0)
            return;
        as.push_back(no(s,d2,d6,d8));
        j--;
        return;
    }
    gn(s+"0",c1);
    gn(s+"1",c1+1);
}
int main()
{
    //freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    ps.push_back(3);
    ps.push_back(2);
    ps.push_back(5);
    ps.push_back(7);
    ps.push_back(11);
    ps.push_back(13);
    ps.push_back(17);
    ps.push_back(19);
    ps.push_back(23);
    ps.push_back(29);
    ps.push_back(31);
    n=32;
    j=500;
    printf("Case #1:\n");
    gn("1",1);
    for(int i=0;i<as.size();i++)
    {
        cout<<as[i].s<<" "<<as[i].d2<<" 2 3 2 "<<as[i].d6<<" 6 "<<as[i].d8<<" 2 3"<<endl;
    }
}
