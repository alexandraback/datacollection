#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

char a[30]={'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    int n;
    cin>>n;
    char s1[110];
    cin.ignore(10, '\n');
    for(int i=1; i<=n; i++)
    {
        cout<<"Case #" << i<<": ";
        cin.getline(s1, 110);
        int nt=strlen(s1);
        for(int i=0; i<nt; i++)
        {
            cout<<a[s1[i]-'a'];
        }
        cout<<endl;
    }
}
