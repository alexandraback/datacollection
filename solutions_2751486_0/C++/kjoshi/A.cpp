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
    int i,j,k,l;
    int T,t;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("output-A.txt","w",stdout);

    cin>>T;
    char s1[1123456];
    int N;
    for(t=1;t<=T;++t)
    {
        cin>>s1>>N;
        int len=strlen(s1),countx=0;
        int x=len-N;
        int y=x+1;
        //cout<<x<<y<<len<<endl;
        for(i=0;i<y;++i)
        {
            //cout<<"here 2";
            for(j=i;j<y;++j)
            {
                int chck=0;
                //cout<<"here 1";
                for(k=j;k<(N+j);++k)
                {
                    if(s1[k]!='a'&&s1[k]!='e'&&s1[k]!='i'&&s1[k]!='o'&&s1[k]!='u')
                    chck++;
                }
                if(chck==N)
                {
                    //cout<<"here"<<k<<" "<<j;
                    break;
                }
            }
            if(j!=y)
                countx+=((y-j));
        }
       // N=t/N;
        //cout<<a<<endl;
        cout<<"Case #"<<t<<": "<<countx<<endl;
        //printf("Case #%d: %d\n",t,a);
    }


    return 0;
}
