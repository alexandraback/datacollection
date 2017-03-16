#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>

using namespace std;

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");
int n,t,s,p,ans;
int senr(0);
void solve()
{
    int i(0),a(0);
    fout<<"Case #"<<++senr<<": ";
    fin>>n>>s>>p;
    ans = 0;
    for(i=0; i<n; ++i)
    {
        fin>>a;
        if((a+2)>=3*p)
        {
            ++ans;
        }
        else if(s)
        {
            if((a+4)>=3*p && a>=2)
            {
                --s;
                ++ans;
            }
        }
    }
    fout<<ans<<endl;

}


int main()
{
    int test(0);
    fin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}

