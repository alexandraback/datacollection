#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char tab[26]={'y','h','e','s','o',
            'c', 'v' ,'x', 'd' ,'u' ,'i',
            'g', 'l' , 'b', 'k', 'r',
            'z','t', 'n','w', 'j',
            'p', 'f','m','a','q'};

int main()
{
    int n;
    string nn;
    getline(cin,nn);
    stringstream ss(nn);
    ss>>n;

    for(int a=0;a<n;a++)
    {
        cout<<"Case #"<<a+1<<": ";
        string str;
        getline(cin,str);
        for(int b=0;b<str.length();b++)
        {
            if(str[b]!=' ')
                cout<<tab[str[b]-97];
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
