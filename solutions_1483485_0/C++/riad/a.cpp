#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string str,str1;

int main()
{
    freopen("a.txt","r",stdin);
    freopen("a.out","w",stdout);
    int cas,len,i,test;
    str="yhesocvxduiglbkrztnwjpfmaq";
    scanf("%d",&test);
    getline(cin,str1);
    for (cas=1;cas<=test;cas++)
    {
        getline(cin,str1);
        len=str1.length();
        for (i=0;i<len;i++)
        {
            if (str1[i]>='a'&&str1[i]<='z') str1[i]=str[str1[i]-'a'];
        }
        printf("Case #%d: ",cas);
        cout<<str1<<endl;
    }
    return 0;
}
