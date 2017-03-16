#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
double naomi[2000];
double ken[2000];

int solve1()
{
    int ret=0;
    for(int i=N-1,j=N-1;j>=0;--j)
    {
        if(naomi[i]>ken[j])
        {
            ++ret;
            --i;
        }
    }
    return ret;
}

int solve2()
{
    int ret=0;
    for(int i=N-1,j=N-1;i>=0;--i)
    {
        if(naomi[i]>ken[j])
        {
            ++ret;
        }
        else
        {
            --j;
        }
    }
    return ret;
}

int main()
{
#ifdef LOCALMACHINE
    freopen("C:\\Users\\zero\\Desktop\\D-large.in","r",stdin);
    freopen("C:\\Users\\zero\\Desktop\\D-large.txt","w",stdout);
#endif
    int T;
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        cin>>N;
        for(int j=0;j<N;++j)
            cin>>naomi[j];
        for(int j=0;j<N;++j)
            cin>>ken[j];
        sort(naomi,naomi+N);
        sort(ken,ken+N);
        cout<<"Case #"<<i<<": "<<solve1()<<" "<<solve2()<<endl;
    }
    return 0;
}
