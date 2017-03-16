#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>

using namespace std;
int n,m;
string old = "abcdefghijklmnopqrstuvwxyz";
string map = "yhesocvxduiglbkrztnwjpfmaq";
string str;
void calc()
{
    for(int i=0;i<str.size();i++) {
        char c = str[i];
        if(c>='a' && c<='z')
            str[i]=map[c-'a'];
    }
}
void input()
{
    getline(cin, str);
}
void output(int ncase)
{
    cout<<"Case #"<<ncase<<":"<<" "<<str<<endl;
}
int main(void)
{
    cin>>n;
    getline(cin, str);
    for(int i=0;i<n;i++)
    {
        input();
        calc();
        output(i+1);
    }
    return 0;
}
