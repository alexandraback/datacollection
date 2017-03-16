#include<iostream>
using namespace std;
int T;
char str[105];

char match[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
    freopen("ina.txt","r",stdin);
    freopen("outa.txt","w",stdout);
    cin>>T;
    getchar();
    for(int i=1;i<=T;i++)
    {
            
            gets(str);
            for(int j=0;j<strlen(str);j++)
            if(str[j]>='a'&&str[j]<='z')
                str[j]=match[str[j]-'a'];
            
            cout<<"Case #"<<i<<": "<<str<<endl;
    }
    
    
    
    return 1;
    
}
