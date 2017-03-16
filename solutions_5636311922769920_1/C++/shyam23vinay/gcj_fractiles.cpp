#include<bits/stdc++.h>
using namespace std;
unsigned long long int pow(unsigned long long int a,unsigned long long int b)
{
    unsigned long long int x=1;
    unsigned long long int y=a;
    while(b>0)
    {
        if(b%2==1)
        {
            x=x*y;
        }
        y=y*y;
        b=b/2;
    }
    return x;
}
int main()
{
    ofstream fout ("D-large.out");
    ifstream fin ("D-large.in");
    int t;
    fin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        fout << "Case #"<<tc<<": ";
        unsigned long long int k,c,s;
        fin >> k >> c >> s;
        if(k==s)
        {
            for(unsigned long long int i=1;i<=s;i++)
                fout << i << " ";
            fout << endl;
        }
        else
        {
            unsigned long long int smin;
            int flag=0;
            if((k/c)*c!=k)
            {
                smin=k/c+1;
                flag=1;
            }
            else
                smin=k/c;
            if(smin>s)
                fout << "IMPOSSIBLE" << endl;
            else
            {
                for(unsigned long long int i=1;i<=smin;i++)
                {
                    unsigned long long int sum=1;
                    int x;
                    if(flag==1 && i==smin)
                        x=k%c;
                    else
                        x=c;
                    for(unsigned long long int j=1;j<=x;j++)
                    {
                        sum=sum+((i-1)*c+j-1)*pow(k,c-j);
                    }
                    fout << sum << " ";
                }
                fout << endl;
            }
        }
    }
    return 0;
}
