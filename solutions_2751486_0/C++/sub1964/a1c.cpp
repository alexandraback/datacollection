#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
//#include<malloc.h>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
/*char * getstring()
{
    char *s;
    char z;
    int i=0;
    while((z=getchar())!='\n' && z!=' ' && z!='\0')
    {
        if(i==0)
        {
            if(z!='\b')
            {
                s = (char *)malloc(sizeof(char));
                *s = z;
                i++;
            }
        }
        else
        {
            if(z!='\b')
            {
                s = (char *)realloc(s,sizeof(char)*(i+1));
                s[i]=z;
                i++;
            }
            else
            {
                if(i>1)
                {
                    s = (char *)realloc(s,sizeof(char)*(i-1));
                    i--;
                }
                else
                {
                    delete(s);
                    i=0;
                }
            }
        }
    }
    s[i]='\0';
    return s;
}*/

int main()
{
    int t,i,j;
    cin>>t;
    string s;
    int len;
    int n,val;
    long nval;
    for(int k=1;k<=t;k++)
    {
        nval=0;
        cin>>s>>n;
        len=s.length();
        for(i=0;i<=len-n;i++)
        {
            val=0;
            for(j=i;j<len;j++)
            {

                if(s.at(j)!='a' && s.at(j)!='e' && s.at(j)!='i' && s.at(j)!='o' && s.at(j)!='u')
                {
                    val++;
                }
                else
                {
                    val=0;
                }
                if(val>=n)
                {
                    nval+=(len-j);
                    break;
                }
            }
        }
        cout<<"Case #"<<k<<": "<<nval<<endl;
    }
    return 0;
}


