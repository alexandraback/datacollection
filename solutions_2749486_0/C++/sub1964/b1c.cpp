#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
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
    int t,i,j,z;
    cin>>t;
    string s;
    int len;
    bool flag;
    int x,y;
    int p,q,n;
    for(int k=1;k<=t;k++)
    {
        s="";
        n=1;
        cin>>x>>y;
        p=0;q=0;
        if(x>0)
        {
            while(p+n<=x)
            {
                p+=n;
                s.append(1,'E');
                n++;
            }
        }
        else
        {
            while(p-n>=x)
            {
                p-=n;
                s.append(1,'W');
                n++;
            }
        }

        if(y>0)
        {
            while(q+n<=y)
            {
                q+=n;
                s.append(1,'N');
                n++;
            }
        }
        else
        {
            while(q-n>=y)
            {
                q-=n;
                s.append(1,'S');
                n++;
            }
        }

        if(x>0)
        {
            z=-1;
            while(p<x)
            {
                p+=(n*z);
                if(z==1)
                {
                    s.append(1,'E');
                }
                else
                {
                    s.append(1,'W');
                }
                z=0-z;
                n++;
            }
        }
        else
        {
            z=1;
            while(p>x)
            {
                p+=(n*z);
                if(z==1)
                {
                    s.append(1,'E');
                }
                else
                {
                    s.append(1,'W');
                }
                z=0-z;
                n++;
            }
        }

        if(y>0)
        {
            z=-1;
            while(q<y)
            {
                q+=(n*z);
                if(z==1)
                {
                    s.append(1,'N');
                }
                else
                {
                    s.append(1,'S');
                }
                z=0-z;
                n++;
            }
        }
        else
        {
            z=1;
            while(q>y)
            {
                q+=(n*z);
                if(z==1)
                {
                    s.append(1,'N');
                }
                else
                {
                    s.append(1,'S');
                }
                z=0-z;
                n++;
            }
        }
        cout<<"Case #"<<k<<": "<<s<<endl;
    }
    return 0;
}



