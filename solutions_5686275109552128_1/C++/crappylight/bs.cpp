#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
using namespace std;
fstream infile("B-large.in");
fstream outfile("output.txt");
int n,m,cases,i,j,k,l,ans,mm;
int ccs[1010];
int main() {
    infile >> cases;
    for (int cur = 1; cur <= cases; cur++ ) {
        infile >> n;
        for (int i=0;i<1010;i++) ccs[i] = 0;
        l = 0;
        for (int i=0;i<n;i++) {
            infile >> k;
            ccs[k]++;
        }
    ans = 1000;
    for (int mm = 1; mm <= 1000; mm++)
        {
            int cc = mm;
            for (int i = mm+1; i<1010; i++)
                cc += ((i-1)/mm)*ccs[i];
            ans = min(ans,cc);
        }

        outfile << "Case #" << cur << ": " << ans << endl;
    }
    infile.close();
    outfile.close();
}
