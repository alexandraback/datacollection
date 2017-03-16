#include <iostream>

using namespace std;

int main()
{
    int n,t;
    double c,f,x;
    double s,s1,s2;
    double p,p1,p2;
    cin>>n;
    t=1;
    while(t<=n)
    {
        s=0.0;
        p1=2;
        cin>>c>>f>>x;
        while(x>0.0000000001)
        {
            s1=x/p1;
            s2=c/p1+x/(p1+f);
            if(s2>s1) {
                s+=s1;
                break;
            } else {
                s+=c/p1;
                p1+=f;
            }
        }
        cout.setf(ios::fixed);
        cout.precision(7);
        cout<<"Case #"<<t<<": "<<s<<endl;;
        t++;
    }
    return 0;
}
