# include<iostream>
# include<cstdio>
# include<cstring>
# include<fstream>
# include<sstream>
using namespace std;
int main()
{
    int t,j,n,beg,bego,c,ct,l,e;
    string a;
    cin>>t;



    for(q=1;q<=t;q++)
    {
          //  mf>>a;
          //  mf>>n;
              cin>>a;
              cin.ignore();
              cin>>n;
             cin.ignore();
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
                              }
                              if(ct>n)
                              {
                                      e=j+1;
                                      beg=e-n+1;
                                      c+=(l-e+1);
                              }
              }
              myfile<<"Case #"<<q<<": "<<c<<endl;
    }
 //   mf.close();
  //  myfile.close();

    return 0;
}
