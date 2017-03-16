#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

char c[27]="yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("out.out","w",stdout);

    int t;
    cin>>t;
    string a;
    getline(cin,a);
    int n=0;
    while(t--)
    {
        n++;
        getline(cin,a);
        cout<<"Case #"<<n<<": ";
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==' ')
                cout<<" ";
            else
            {
                cout<<c[a[i]-'a'];
            }
        }
        cout<<endl;
    }
    return 0;
}
