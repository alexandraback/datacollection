#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int T,n;
string name;

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A.out");
    fin >> T;
    int k;
    for (int i=1;i<=T;i++)
    {
        fin >> name;
        int k=name.size();
        fin >> n;
        int ats=0;
        int p=0;
        for (int j=0;j<=k-n;j++)
        {
            bool fragmentas=true;
            for (int m=j;m<j+n;m++) if (name[m]=='a' || name[m]=='e' || name[m]=='i' || name[m]=='o' || name[m]=='u'){
                fragmentas=false;
                break;
            }
            if (fragmentas) {
                ats+=(j-p+1)*(k-j-n+1);
                p=j+1;
            }
        }
        fout << "Case #" << i << ": " << ats << endl;
    }
    return 0;
}
