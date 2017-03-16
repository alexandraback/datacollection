#include<fstream>
using namespace std;
ifstream fin ("temp.in");
ofstream fout ("temp.out");
int main ()
{
    int t;
    fin>>t;
    for (int i=1;i<=t;i++)
    {
        int c,d,v;
        fin>>c>>d>>v;
        int now=0;
        int add=0;
        int money;
        fin>>money;
        int j=1;
        while (now<v)
        {
            if (money<=now+1&&j<=d)
            {
                now+=c*money;
                if (j<d) {fin>>money;}
                j++;
            }
            else {add++;now+=c*(now+1);}
        }
        for (;j<d;j++)
            fin>>money;
        fout<<"Case #"<<i<<": "<<add<<endl;
    }
}
