#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>

#define FR(i,a) for(int i=0;i<a;i++)

using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r+",stdin);
    freopen("output1.txt","w+",stdout);
    int T,it=1;
    cin>>T;
    while(it<=T)
    {
        int A,B;
        cin>>A>>B;
        double temp=0,num=1,ans=B+2,prob;
        FR(i,A)
        {
            cin>>prob;
            num*=prob;
            temp=num*(A+B-(2*i)-1);
            temp+=(1-num)*(A+(2*B)-(2*i));
            if (temp<ans)
            {
                ans=temp;
            }
        }
        //cout<<"Case #"<<it++<<": "<<setprecision(.6)<<ans<<endl;
        printf("Case #%d: %.6lf\n",it++,ans);
    }
}

