# include<iostream>
# include<cstdio>
# include<cstring>
# include<fstream>
# include<sstream>
using namespace std;
int main()
{
    unsigned long int t,j,n,beg,bego,c,ct,l,f=0,e;
    string a;
    freopen("A-large.in","r",stdin);
    cin>>t;
    cin.ignore();
    ofstream m;
    m.open("otp1.txt");
    while(t--)
    {
              cin>>a;
              cin.ignore();
              cin>>n;
              cin.ignore();
              //m<<a<<" "<<n;
              l=a.length();
              c=0;
              ct=0;
              beg=0;
              for(j=0;j<l;++j)
              {
                              if(a[j]!='a' && a[j]!='e' && a[j]!='i' && a[j]!='o' && a[j]!='u')
                              ++ct;
                              else
                              ct=0;
                              if(ct==n)
                              {
                                       bego=beg+1;
                                       e=j+1;
                                       beg=e-n+1;
                                       c+=((l-e+1)*(beg-bego+1));
                                       //ut<<c<<endl;
                              }
                              if(ct>n)
                              {
                                      e=j+1;
                                      beg=e-n+1;
                                      c+=(l-e+1);
                              }
              }
              m<<"Case #"<<++f<<": "<<c<<endl;
    }
    m.close();
    return 0;
}
                   
