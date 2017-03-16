#include <iostream>
#include <fstream>
using namespace std;

int ttt;
long long a, b, k;

int main()
{
    ifstream be("B-small-attempt0.in");
    FILE *out = fopen("b.out", "w");
    be >> ttt;
    for (int t=1;t<=ttt;t++) {
        be >> a>>b>>k;
        long long sum=0;
        for (int i=0;i<a;i++) {
            for (int j=0;j<b;j++) {
                if ((i&j)<k) sum++;
            }
        }
        fprintf(out, "Case #%d: %ld\n", t, sum);
    }
    fclose(out);
    return 0;
}
