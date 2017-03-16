#include <iostream>
using namespace std;

const double INF=1e-9;
const double s=2;
double c,f,x;

int main(int argc, const char * argv[])
{
    int nCase; cin>>nCase;
    for(int ca=1; ca<=nCase; ca++){
        cout<<"Case #"<<ca<<": ";
        cin>>c>>f>>x;
        int k= max(0,int(x/c-s/f-INF));
        double res=0;
        for(int i=0; i<k; i++)
            res += c/(s+i*f);
        res += x/(s+k*f);
        printf("%.7lf\n",res);
        //cout<<res<<endl;
    }
    return 0;
}

