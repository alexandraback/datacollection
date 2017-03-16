#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
#include<vector>
#include<stdio.h>
using namespace std;
typedef long long LL;



bool IsPalindrom(int i, int j, string s)
{
    if(i>j)
        return true;
    if(s[i]!=s[j])
        return false;
    return IsPalindrom(i+1, j-1, s);

}



int main()
{
    freopen("C-large-1.in", "r", stdin);
    freopen("C-large-1.out", "w", stdout);
    long long i, d, t;
    vector<LL> a, b;
    stringstream ss;
    string s;
    for(i=1;i<=10000000;i++)
    {
        ss.clear();
        s="";
        ss<<i;
        ss>>s;
        if(IsPalindrom(0, s.size()-1, s)==false) continue;
        t=i*i;
        ss.clear();
        s="";
        ss<<t;
        ss>>s;
        if(IsPalindrom(0, s.size()-1, s)==false) continue;

        a.push_back(i);
        b.push_back(t);

    }
    LL T, A, B;
    cin>>T;
    int kase=0;
    while(T--)
    {
        cin>>A>>B;
        int kount=0;
        for(int i=0;i<a.size();i++)
        {
            if(b[i]>=A&&b[i]<=B)
                kount++;
        }

        cout<<"Case #"<<++kase<<": "<<kount<<endl;


    }

}
