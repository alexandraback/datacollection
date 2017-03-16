/*

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
map<char, char> h;
bool init()
{
    string a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
    if (a.length() != b.length()) return false;
    for (int i=0;i<(int)a.length();i++)
        h[a[i]]=b[i];
    h['z'] = 'q';
    h['q'] = 'z';
    return true;
}
void display()
{
    string a;
    int n;
    h.clear();
    if (!init()) return;
    cin>>n;
    getchar();
    for (int i=1;i<=n;i++) {
        cout<<"Case #"<<i<<": ";
        getline(cin, a);
        for (int j=0;j<(int)a.length();j++)
            a[j]=h[a[j]];
        cout<<a<<endl;
    } 
}
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt.out","w",stdout);
    display();
    return 0;
}

