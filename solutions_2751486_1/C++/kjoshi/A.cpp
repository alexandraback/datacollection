#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <stack>

using namespace std;

int main()
{
    long long i,j,k,l;
    long long T,t;

    freopen("A-large.in","r",stdin);
    freopen("output-A.txt","w",stdout);

    cin>>T;
    char s1[1123456];
    long long N;
    for(t=1;t<=T;++t)
    {
        cin>>s1>>N;
        long long len=strlen(s1),countx=0;
        long long x=len-N;
        long long y=x+1;
        //cout<<x<<y<<len<<endl;
       /* for(i=0;i<y;++i)
        {*/
            //cout<<"here 2";
            int chck=0;
            i=0;l=0;
            for(j=0;j<len;++j)
            {

                //cout<<"here 1";
                /*for(k=j;k<(N+j);++k)
                {*/
                k=j;
                if(s1[k]!='a'&&s1[k]!='e'&&s1[k]!='i'&&s1[k]!='o'&&s1[k]!='u')
                {
                    chck++;

                }
                else
                {
                    chck=0;
                    if(l==1)
                        i=(j-N+1);
                    l=0;
                }

                //}
               // cout<<endl<<chck<<endl;
                if(chck==N)
                {

                    chck--;
                   // cout<<j<<endl;
                    //cout<<"here"<<k<<" "<<j;
                    //if(j!=y)
                if(l==0)
                    countx+=((j-(N-1)-i+1)*(len-j));
                else
                    countx+=((len-j));
                //cout<<j<<" : "<<countx<<" : "<<i<<endl;
                    //break;
                l=1;
                }
            }

        //}
       // N=t/N;
        //cout<<a<<endl;
        cout<<"Case #"<<t<<": "<<countx<<endl;
        //printf("Case #%d: %d\n",t,a);
    }


    return 0;
}
