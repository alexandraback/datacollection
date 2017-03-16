#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int ncase; cin>>ncase;
    for(int ca=1; ca<=ncase; ca++){
        int a,b,k;
        cin>>a>>b>>k;
        int res=0;
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                if((i&j) <k) res++;
        cout<<"Case #"<<ca<<": "<<res<<endl;
    }
    return 0;
}

