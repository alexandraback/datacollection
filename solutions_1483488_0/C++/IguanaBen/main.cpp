#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int X=2000001;
const int Y=8;
int tab[X][Y];

int length(int x)
{
    if(x<10)
        return 1;
    if(x<100)
        return 2;
    if(x<1000)
        return 3;
    if(x<10000)
        return 4;
    if(x<100000)
        return 5;
    if(x<1000000)
        return 6;
    return 7;
}
int init(int tab[X][Y])
{
    for(int a=0;a<X;a++)
        tab[a][7]=-1;
}
int tenPow(int a)
{
    int res=1;
    for(int i=0;i<a;i++)
        res=res*10;
    return res;
}
int fill(int tab[X][Y])
{
    init(tab);
    for(int a=1;a<X;a++)
    {
        if(tab[a][7]==-1)
        {
            int n=length(a);
            int iterator=0;
            for(int b=1;b<n;b++)
            {
                int pow=tenPow(b);
                int rest=a%pow;
                int val=a-rest;
                val/=pow;
                val+=rest*tenPow(n-b);
                bool unique = (a!=val)&&(a<val)&&(val<2000001);
                for(int i=0;i<iterator && unique;i++)
                {
                    unique=(tab[a][i]!=val);
                }
                if(unique)
                {
                    tab[a][7]=42;
                    tab[a][iterator]=val;
                    iterator++;
                }
            }
            sort(tab[a],tab[a]+iterator);
            for(int i=0;i<iterator;i++)
            {
                for(int j=0;j<iterator-i-1;j++)
                {
                    tab[(tab[a][i])][7]=42;
                    tab[(tab[a][i])][j]=tab[a][j+i+1];
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    fill(tab);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int pairs=0;
        int min,max;
        cin>>min>>max;
        for(int j=min;j<=max;j++)
        {
            int iter=0;
            while(tab[j][iter]!=0&&tab[j][iter]<=max)
            {
                iter++;
                pairs++;
            }
        }
        cout<<"Case #"<<i+1<<": "<<pairs<<endl;
    }
    return 0;
}
