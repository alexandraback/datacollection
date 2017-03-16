#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out", "w", stdout);
    int t;
    map<char, char> dic;
    string str; 
    dic['a'] ='y'; dic['b'] = 'h'; dic ['c'] = 'e'; dic['d'] = 's';
    dic['e'] ='o'; dic['f'] = 'c'; dic ['g'] = 'v'; dic['h'] = 'x';
    dic['i'] ='d'; dic['j'] = 'u'; dic ['k'] = 'i'; dic['l'] = 'g';
    dic['m'] ='l'; dic['n'] = 'b'; dic ['o'] = 'k'; dic['p'] = 'r';
    dic['q'] ='z'; dic['r'] = 't'; dic ['s'] = 'n'; dic['t'] = 'w';
    dic['u'] ='j'; dic['v'] = 'p'; dic ['w'] = 'f'; dic['x'] = 'm';
    dic['y'] ='a'; dic['z'] = 'q'; dic [' '] = ' '; 
    cin >> t;
    getline(cin,str,'\n');
    for (int test = 1; test <= t; ++test)
    {
        getline(cin,str,'\n');
        cout <<"Case #"<<test<<": ";
        for (int i = 0 ; i < str.length(); ++i)
        cout << dic[str[i]];
        cout << endl;
    }
    
    return 0;
}
