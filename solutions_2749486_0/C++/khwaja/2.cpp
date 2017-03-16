#include<iostream>
#include<fstream.h>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
    int i,j,cnt=0,l,k,m,n,x,y,xc,yc,cnt1=0,cnt2=0,flag;
    ifstream f1;
    ofstream f2;
    int t,r,b,c;
    f1.open("a.txt");
    f2.open("1boutput.txt");
    f1>>t;
    m=1;
    while(m<=t)
    {
     f1>>x>>y;
     l=1,flag=0;
     xc=0,yc=0,cnt1=0,cnt2=0;
     string st;
     while(xc!=x)
     {
        xc+=l;
        if(cnt1%2==0)
        {
         l=(-1)*(cnt1+2);
        st+="E";
        cout<<"E";
        }
        else
        {
        st+="W";
        cout<<"W";
        l=cnt1+2;
        }
        cnt1++;
        }
         if(yc>0)
         {
           st+="S";
           cout<<"S";
           yc-=abs(l);
           cnt1++;
           flag=1;
           }
           else
           {
           st+="N";
           cout<<"N";
           yc+=abs(l);
           cnt1++;
           }
             cnt2=abs(l);
             cout<<yc<<cnt2<<endl;
             if(flag==1)
             {
             cnt1=0;
         while(yc!=y)
       {
        if(cnt1%2==0)
        {
         yc+=(cnt2+1);
         cnt2++;
        st+="N";cout<<"N";
        }
        else
        {
         yc-=(cnt2+1);
         cnt2++;
        st+="S";
        cout<<"S";
        }
        cnt1++;
        }
        }
        else if(flag==0)
             {
                   cnt1=0;
         while(yc!=-64)
       {
        if(cnt1%2==0)
        {
         yc-=(cnt2+1);
         cnt2++;
        st+="S";
        cout<<"S";
        }
        else
        {
         yc+=(cnt2+1);
         cnt2++;
        st+="N";
        cout<<"N";
        }
        cout<<yc<<endl;
        cnt1++;
        }
        }
        f2<<"Case #"<<m<<": "<<st<<endl;
         m++;
         }
          f1.close();
    f2.close();
    system("pause");
    return 0;
}
