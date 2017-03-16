#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string o[3];
string s[3];
string str;
bool used[27];
int map[26]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    getchar();
    int cas=1;
    while(t--)
    {
        getline(cin,str);
        //cout<<str<<endl;
        cout<<"Case #"<<cas++<<": ";

        int l = str.size();
        for(int i=0;i<l;i++)
        {
            if(str[i]==' ')
                continue;
            str[i]=char('a'+map[str[i]-'a']);
        }
        cout<<str<<endl;
    }
    return 0;
}
