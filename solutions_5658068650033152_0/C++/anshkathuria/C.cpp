#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main()
{
    ifstream fin ("C-small-attempt0.in",ios::in);
    fstream fout;
    fout.open ("C-small2.txt",ios::out);
    int t,i;
    fin>>t;
    int initial=0,count=0;

    int n,m,k;
    int sqr;
    int ans=0;
    while(t--)
    {
        initial++;
        ans=0;
        fin>>n;
        fin>>m;
        fin>>k;
        sqr=sqrt(k);
        //fout<<"sqr "<<sqr;
        if((sqr*sqr>k/2) && (sqr<=n)&& (sqr<=m))
        {
            ans=k-(sqr*sqr-(sqr*2+2*(sqr-2)));
        //fout<<endl;
        //fout<<ans<<endl;

        ans=ans-(k-(sqr*sqr));
        //fout<<ans<<endl;
        }
        else
        {
int l,b;

        l=sqr;
        b=sqr;
        bool con=true;
        do
        {
            if(con)
            {l++;
            con=false;
            }
            else{
            b++;
            con=true;
            }

        }while(l*b<=k);
        if(con)
        b--;
        else
        l--;
        ans=k-(l*b-(b*2+2*(l-2)));
        //fout<<endl;
        //fout<<ans<<endl;

        ans=ans-(k-(l*b));
        //fout<<ans<<endl;
        }
        fout<<"Case #"<<initial<<": "<<ans<<endl;


    }


}
