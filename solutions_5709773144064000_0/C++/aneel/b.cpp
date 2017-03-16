#include <iostream>
using namespace std;

int main()
{
    double T,C,F,X;
    double tt,t1,t2,c,r;
    cin>>T;
    for(int i = 1; i <= T; ++i)
    {
        cout<<"Case #"<<i<<": ";
        
        cin>>C>>F>>X;
        //cout<<C<<" "<<F<<" "<<X<<endl;
        //system("pause");
        r=2;
        c=0;
        tt=0;
        for(;;) {
            t1 = X/r;
            t2 = (C/r) + X/(r+F);
            
            //cout<<t1<<" "<<t2<<endl;
            if(t1 < t2) {
                tt = tt+t1;
                break;
            }
            else {
                tt = tt+C/r;
                r = r+F;
            }
        }
        printf("%.7lf\n",tt);
        //cout<<tt<<endl;
    }
    return 0;
}
