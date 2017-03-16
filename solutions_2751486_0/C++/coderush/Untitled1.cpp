# include<iostream>
# include<cstdio>
# include<cstring>
# include<fstream>
# include<sstream>
using namespace std;
int main()
{
    int t,i,n,j,d,c,ct,l,f=0;
    string a;
    freopen("in.txt","r",stdin);
    freopen("outa.txt","w",stdout);
    cin>>t;
    cin.ignore();
    ofstream m;
    m.open("otp.txt");
    while(t--)
    {
              cin>>a;
              //cin.ignore();
              cin>>n;
              //cin.ignore();
              l=a.length();
              c=0;
              //cout<<a<<" "<<n<<endl;
              for(i=0;i<l;++i)
              {
                              ct=0;
                              d=l;
                              //cout<<"a";
                              for(j=i;j<l;++j)
                              {
                                              if(a[j]!='a' && a[j]!='e' && a[j]!='i' && a[j]!='o' && a[j]!='u')
                                              ++ct;
                                              else
                                              ct=0;
                                              //cout<<ct<<endl;
                                              if(ct==n)
                                              {
                                                       d=j;
                                                       break;
                                              }
                              }
                              c+=(l-d);
                              //cout<<c<<" "<<d<<endl;
              }
              cout<<"Case #"<<++f<<": "<<c<<endl;
    }
    m.close();
    return 0;
}
