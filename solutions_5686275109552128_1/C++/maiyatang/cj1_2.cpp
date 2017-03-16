#include<fstream>
using namespace std;
ifstream cin ("temp.in");
ofstream cout ("temp.out");
int save[1000];
int main ()
{
    int t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        int d;
        cin>>d;
        for (int j=0;j<d;j++)
            cin>>save[j];
        int best=1000;
        for (int j=1000;j>=1;j--)
        {
            int time=0;
            for (int x=0;x<d;x++)
                if (save[x]%j==0) time+=save[x]/j-1;
                else time+=save[x]/j;
            if (time+j<best) {best=time+j;}
        }
        cout<<"Case #"<<i<<": "<<best<<endl;
    }
}
