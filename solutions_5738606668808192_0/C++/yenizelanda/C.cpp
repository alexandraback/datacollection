#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int arr[33];
int n,j;


main() {
    int i,k;

    FILE *out=fopen("C_small.out","w");

    n=16;
    j=50;

    fprintf(out,"Case #1:\n");

    vector<int> v1,v2;
    v1.clear();
    for (i=0;i<n/4;i++)
        v1.push_back(0);
    for (;i<n/2-1;i++)
        v1.push_back(1);

    while (next_permutation(v1.begin(),v1.end())) {
        v2.clear();
        for (i=0;i<n/4;i++)
            v2.push_back(0);
        for (;i<n/2-1;i++)
            v2.push_back(1);
        while (next_permutation(v2.begin(),v2.end())) {
            fprintf(out,"1");
            for (i=0;i<v1.size();i++)
                fprintf(out,"%d%d",v1[i],v2[i]);
            fprintf(out,"1 3 4 5 6 7 8 9 10 11\n");
            j--;
            if (!j)
                return 0;
        }
    }
}
