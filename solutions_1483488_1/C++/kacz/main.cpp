#include <QtCore/QCoreApplication>
#include <cmath>
#include <iostream>
#include "malloc.h"

#define ABS(x) ((x<0) ? (-(x)) : (x))
using namespace std;

int main(int argc, char *argv[])
{
    int cases;
    cin >> cases;
    for(int i = 0; i<cases;++i)
    {
        long a,b;
        long result=0;

        cin >> a >> b;

        for(long i = a; i<=b; ++i) {
            long dig = log10(i);
            long* ls = (long*)malloc(dig*sizeof(long));
            long l = i;
            for(long j = 0; j < dig; ++j) {
                bool rossz = false;
                ls[j]=l;
                l = l/10 + l%10 * pow(10,dig);
                long digl = log10(l);
                //cout << "i:" <<i << " l:" << l << " log10i:" << dig << " log10l:" << log10(l) << endl;
                for(long x = 0; x < j+1; ++x) {
                    if(ls[x] == l) rossz = true;
                }
                if(rossz) continue;
                if(digl == dig && l > i && l>=a && l <=b){
                    //cout << i << ' ' << l << endl;
                    result++;
                }
            }
            free(ls);
        }

        cout << "Case #" << i+1 << ": ";
        cout << result << endl;
    }
    return 0;
}
