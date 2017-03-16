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
        int r,w,c;
        fin>>r>>c>>w;
        int ans;
        if (c%w==0||w==1) ans=c/w*r+w-1;
        else ans=c/w*r+w;
        fout<<"Case #"<<i<<": "<<ans<<endl;
    }
}
