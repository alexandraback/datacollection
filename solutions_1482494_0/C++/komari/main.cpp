/*
PROG: B
LANG: C++
*/
#include <iostream>
#include <fstream>
//#include <algorithm>

using namespace std;

#define SUBMIT
#define _DSP(X)
#   define DV(Var) #Var<<"="<<Var<<' '
#ifdef SUBMIT
    ofstream fout ("B.out");ifstream fin ("B.in");
#   define cin fin
#   define cout fout
#endif

const int MAXN=1000;
int a[MAXN],b[MAXN];

int main()
{
    int T;
    cin>>T;cin.ignore();
    for(int t=1;t<=T;++t)
    {int i;
        int n;
        cin>>n;
        for(i=0;i<n;++i)
            cin>>a[i]>>b[i];

        const int IMP=0xffffff;
        int ans=0,rem=n,star=0;
        for(;(ans!=IMP)&&rem;)
        {
            int maxi=-1;bool fb=false;
            for(i=0;i<n;++i)
            {
                if(b[i]<=star)
                {
                    fb=true;
                    b[i]=IMP;
                    ++ans;--rem;++star;
                    if(a[i]!=IMP)
                    {
                        a[i]=IMP;
                        ++star;
                    }
                }
                else if((a[i]<=star)
                        &&((maxi<0)||(b[maxi]<b[i])))
                        maxi=i;
            }
            if(fb)continue;
            if(maxi<0){ans=IMP;break;}
            a[maxi]=IMP;
            ++ans;++star;
        }

        cout<<"Case #"<<t<<": ";
        if(ans==IMP)cout<<"Too Bad";
        else cout<<ans;
        cout<<endl;
    }

    return 0;
}
