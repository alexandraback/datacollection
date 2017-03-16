#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>

using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("C-small-attempt0.out");
int len,ans;
int senr(0);
int tt[10]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000};
int num[10];
void getlen(int x,int &cnt)
{
    cnt = 0;
    while(x)
    {
        x /= 10;
        ++cnt;
    }
}

void solve()
{
    int i(0),j(0),a(0),b(0),k(0),km(0),tmp(0);
    fout<<"Case #"<<++senr<<": ";
    fin>>a>>b;

    ans = 0;
    getlen(a,len);
    for(i=a; i<=b; ++i)
    {
        tmp = i;
        k =0;
        for(j=1; j<len; ++j)
        {
            tmp = 10*(tmp%tt[len])+(tmp/tt[len]);
            if(tmp>i && tmp<=b)
            {
                for(km=0; km<k; ++km)
                {
                    if(num[km]==tmp) break;
                }
                if(km>=k)
                {
                    ++ans;
                    num[k++] = tmp;
                }

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


