/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

map<char,char> m;
int main()
{
    unsigned int t,i,j;
    string str;
    cin>>t;;
    m['a']='y';
    m['b']='h';
    m['c']='e';
    m['d']='s';
    m['e']='o';
    m['f']='c';
    m['g']='v';
    m['h']='x';
    m['i']='d';
    m['j']='u';
    m['k']='i';
    m['l']='g';
    m['m']='l';
    m['n']='b';//
    m['o']='k';
    m['p']='r';
    m['q']='z';
    m['r']='t';
    m['s']='n';
    m['t']='w';
    m['u']='j';
    m['v']='p';
    m['w']='f';
    m['x']='m';
    m['y']='a';
    m['z']='q';//
    getline(cin,str);
    for(i=1;i<=t;i++)
    {
                     getline(cin,str);
                     for(j=0;j<str.length();j++)
                     {
                                     if(str[j] == ' ')
                                         continue;
                                     str[j]=m[str[j]];
                     }
        cout<<"Case #"<<i<<": "<<str<<endl;
    }
}
