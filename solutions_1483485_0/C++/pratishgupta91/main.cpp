#include <cstdlib>
#include<iostream>
using namespace std;

int main()
{
    int arr[26]={121,104,101,
               115,111,99,
               118,120,100,
               117,105,103,
               108,98,107,
               114,122,116, 
               110,119,106, 
               112,102,109, 
               97,113};
    char str[]={'a','b','c',
                'd','e','f',
                'g' ,'h','i',
                'j','k','l',
                'm','n','o',
                'p','q','r',
                's','t','u','v',
                'w','x','y','z'};
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    char ch[101];
    
    int T;
    cin>>T;
    int a=T;
    gets(ch);
    while(T--)
    {
        gets(ch);
        cout<<"Case #"<<a-T<<": ";
        for(int i=0;i<strlen(ch)-1;i++)
        {
            if(ch[i]!=' ')
            {
                int j=ch[i]-97;
                int temp=arr[j];
                temp-=97;
                cout<<str[temp];
            }
            else cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

