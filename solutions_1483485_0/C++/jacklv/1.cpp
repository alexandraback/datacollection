#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<char,char>a;
string st;
int main()
{
    a['a']='y'; a['b']='h'; a['c']='e';
    a['d']='s'; a['e']='o'; a['f']='c';
    a['g']='v'; a['h']='x'; a['i']='d';
    a['j']='u'; a['k']='i'; a['l']='g';
    a['m']='l'; a['n']='b'; a['o']='k';
    a['p']='r'; a['q']='z'; a['r']='t';
    a['s']='n'; a['t']='w'; a['u']='j';
    a['v']='p'; a['w']='f'; a['x']='m';
    a['y']='a'; a['z']='q';
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T; cin>>T; getline(cin,st);
    for (int tt=1; tt<=T; tt++)
    {
        getline(cin,st);
        for (int i=0 ; i<st.length(); i++)
        if (st[i]>='a'&&st[i]<='z')
        st[i]=a[st[i]];
        cout<<"Case #"<<tt<<": "<<st<<endl;
    }
}
