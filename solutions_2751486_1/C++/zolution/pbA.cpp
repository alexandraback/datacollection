#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

char test[1000010];

int main()
{
    ifstream in("pbA.txt");
    ofstream out("pbA_a.txt");
    int po=0;
    in>>po;
    for(int co=0;co<po;co++)
    {
        out<<"Case #"<<co+1<<": ";
        int need=0;
        in>>test>>need;
        long long int ans=0;
        int len=strlen(test);
        int temp=0;
        int left=0;
        for(int i=0;i<len;i++)
        {
            if(!(test[i]=='a' || test[i]=='e' || test[i]=='i' || test[i]=='o' || test[i]=='u'))
            {
                temp++;
                if(temp>=need)
                {
                    ans=ans+((len-i)*(i-need+2-left));
                    left=i-need+2;
                }
            }
            else
            {
                temp=0;
            }
        }
        out<<ans<<endl;
    }
    return 0;
}
            
