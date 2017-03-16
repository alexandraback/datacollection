#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main()
{
    ifstream input;
    input.open("A-large.in");
    ofstream output;
    output.open("outputlarge.txt");
    int cse=1;
    int t;
    input>>t;

    while(cse<=t)
    {
        int ans,smax,sum;
        ans=0;
        sum=0;
        string val;
        input>>smax>>val;
        for(int i=0;i<smax+1;i++){ans=max(ans,i-sum);sum+=val[i]-'0';}
        output<<"Case #"<<cse<<": "<<ans<<endl;
        cout<<"Case #"<<cse<<": "<<ans<<endl;
        cse++;
    }

    return 0;
}
