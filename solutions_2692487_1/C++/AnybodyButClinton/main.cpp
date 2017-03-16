#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("codejam.in");
ofstream out("codejam.out");
int t,n,a,c,fa;
vector<int>m;

bool which()
{
    int d=a;
    int e=c;
    int f=0;
    bool ans=0;
    if(d==1)goto end2;
    while(e!=n)
    {
        d+=d-1;
        while(d>m[e]&&e!=n)
        {
            d+=m[e];
            e++;
        }
        f++;
    }
    if(n-c<f){end2:;ans=1;}
    return ans;
}

void add()
{
    a+=a-1;
    while(a>m[c]&&c!=n)
    {
        a+=m[c];
        c++;
    }
}

int main()
{
    in>>t;
    //cout<<t<<endl;
    for(int i=0;i<t;i++)
    {
        fa=0;
        in>>a>>n;
        //cout<<a<<" "<<n<<endl;
        c=0;
        m.resize(n);
        for(int j=0;j<n;j++) in>>m[j];
        sort(m.begin(),m.end());
        //for(int j=0;j<n;j++) cout<<m[j]<<endl;
        //
        //cout<<c<<"-"<<n<<endl;
        while(c!=n)
        {
            while(a>m[c]&&c!=n)
            {
                a+=m[c];
                c++;
            }
            //cout<<c<<endl;
            if(c!=n)
            {
            if(which()==0)
            {
                add();
            }
            else
            {
                fa+=(n-c);
                goto end;
            }
            }
            else goto end;
            fa++;
        }
        end:;
        out<<"Case #"<<i+1<<": "<<fa<<endl;
    }
    return 0;
}
