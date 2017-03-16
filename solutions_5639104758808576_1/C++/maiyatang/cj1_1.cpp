#include<fstream>
using namespace std;
ifstream cin ("temp.in");
ofstream cout ("temp.out");
int main ()
{
    int t;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        int smax;
        cin>>smax;
        int now=0;
        int add=0;
        for (int j=0;j<=smax;j++)
        {
            char number;
            cin>>number;
            if (now<j) {add++;now++;}
            now+=number-'0';
        }
        cout<<"Case #"<<i<<": "<<add<<endl;
    }
}
