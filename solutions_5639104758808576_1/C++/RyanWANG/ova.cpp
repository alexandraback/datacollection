#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("ova.in");
ofstream fout("ova.out");
int T;

int main()
{
    fin>>T;
    for(int curcase=0;curcase<T;curcase++)
    {
        int maxShy;
        int totalAud = 0;
        int result = 0;
        std::string sshy;
        fin>>maxShy;
        fin>>sshy;
        
        for(int shyLevel=0;shyLevel<=maxShy;shyLevel++)
        {
            char audc;
            int aud;
            audc = sshy[shyLevel];
            cout<<audc<<' ';
            aud = audc-'0';
            if(totalAud<shyLevel)
            {
                result += (shyLevel-totalAud);
                totalAud+=(shyLevel-totalAud);
            }
            totalAud+=aud;
        }
        cout<<'\n';
        fout<<"Case #"<<curcase+1<<": "<<result<<'\n';
    }
}
