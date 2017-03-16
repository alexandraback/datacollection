#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int test;
    fin>>test;

    for(int i=1;i<=test;i++)
    {
        char a[1001];
        fin>>a;
        string b;
        int l=strlen(a);
        for(int j=0;j<l;j++)
        {
            if(b.length() >0)
            {
                char c=b.at(0);
                if(c > a[j])
                    b=b+a[j];
                else
                    b=a[j]+b;
            }
            else
                b=a[j];
        }
        fout<<"Case #"<<i<<": "<<b<<endl;
    }

    return 0;
}
