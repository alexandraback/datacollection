#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>

using namespace std;

char str[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char st[105];
int senr(0);
ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

void solve()
{


    int len;
    fout<<"Case #"<<++senr<<": ";
    fin.getline(st,104);
    len = strlen(st);
    for(int j=0; j<len; ++j)
    {
        if(st[j]!=' ')
            fout<<str[st[j]-'a'];
        else fout<<st[j];

    }
    fout<<endl;

}


int main()
{
    int test(0);
    fin>>test;
    fin.getline(st,104);
    while(test--)
    {
        solve();
    }
    return 0;
}
