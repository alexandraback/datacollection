#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

vector <int> s1(10,0),s2(10,0),a(10,0),b(10,0);
int n,m,x,y,mn,w,i,ts;
string s,t;

void back2(int k)
{
    if (k==n)
    {
        if (labs(x-y)<mn)
        {
            mn=labs(x-y);
            s1=a;
            s2=b;
        }
        return;
    }
    if (t[k]!='?')
    {
        b[k]=t[k]-'0';
        y=y*10+b[k];
        back2(k+1);
        y/=10;
    }
    else
    {
        int i;
        for (i=0;i<=9;i++)
        {
            b[k]=i;
            y=y*10+b[k];
            back2(k+1);
            y/=10;
        }
    }
}

void back1(int k)
{
    if (k==n)
    {
        back2(0);
        return;
    }
    if (s[k]!='?')
    {
        a[k]=s[k]-'0';
        x=x*10+a[k];
        back1(k+1);
        x/=10;
    }
    else
    {
        int i;
        for (i=0;i<=9;i++)
        {
            a[k]=i;
            x=x*10+a[k];
            back1(k+1);
            x/=10;
        }
    }
}


    int main()
{
    ifstream f("in.txt");
    ofstream g("out.txt");
    f >> ts;
    for (w=1;w<=ts;w++)
    {
        g << "Case #" << w << ": ";
        f >> s >> t;
        n=s.size();
        x=0;y=0;
        mn=1 << 30;
        back1(0);
        for (i=0;i<n;i++)
            g << s1[i];
        g << ' ';
        for (i=0;i<n;i++)
            g << s2[i];
        g << "\n";
    }
    return 0;
}
