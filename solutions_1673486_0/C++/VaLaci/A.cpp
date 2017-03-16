#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    cout.precision(10);
    ifstream be("jamA.be");
    ofstream ki("jamA.ki");
    int t;
    be>>t;
    for(int testcase=1;testcase<=t;testcase++)
    {
        int a,b;
        be>>a>>b;
        long double p[a];
        long double exp[a+2];
        for(int i=0;i<a;++i)
           be>>p[i];
        //keep typing
        long double prod=1;
        for(int i=0;i<a;++i)
            prod=prod*p[i];
        exp[0]=prod*(b-a+1)+(1-prod)*(2*b-a+2);
        //backspace c-szer
        for(int c=1;c<=a;c++)
        {
            long double prodE=1;
            for(int i=0;i<a-c;++i)
                        prodE=prodE*p[i];
            exp[c]=c+prodE*(b-(a-c)+1)+(1-prodE)*(b-(a-c)+1+b+1);
        }
        //press enter
        exp[a+1]=2+b;
        long double max=exp[0];
        //cout<<exp[0]<<endl;
        for(int i=1;i<=a+1;i++)
        {
            //cout<<exp[i]<<endl;
            if(max>exp[i]) max=exp[i];
        }
//
        ki<<"Case #"<<testcase<<": "<<max<<endl;
        cout<<"Case #"<<testcase<<": "<<max<<endl;

    }
    be.close();
    ki.close();
    return 0;
}
