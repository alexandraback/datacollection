#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
bool isalpha(char a){
        if( a >='0'&&a<='9')
            return true;
        return false;
    }
int sum(string a){
    int sum=0;
    for(int i=0;i<a.length();i++)
        sum+=(a[i]-'0');
    return sum;
}
int main()
{
    freopen("hindu.in","r",stdin);
   freopen("hindu.txt","w",stdout);
     string str;
     int v=1;
    char g;
    while(true){

        cin>>str;
        if(str==".")
            break;
        cout<<v++<<". ";
        int k=0;
        int a,b,c;
        a=b=c=0;
        int n=str.length();
        int f=str.find('=');
        c=sum(str.substr(f+1,n-f-2));
        int d=str.find('+');
        if(d!=string::npos){
            g='+';
        }
        else{
                d=str.find('*');
                g='*';

        }
        a=sum(str.substr(0,d));
        b=sum(str.substr(d+1,f-d-1));
        if(g=='+')
        {
            if((a+b)%9==c%9)
            cout<<"PASS";
        else
            cout<<"NOT!";
        }

    else{
        if((a*b)%9==c%9)
            cout<<"PASS";
        else
            cout<<"NOT!";
    }
        cout<<endl;

    }
}
