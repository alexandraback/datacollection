#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > plate;

int main(){
    FILE *file = fopen("input.txt", "r");
    FILE *f = fopen("output.txt", "w");
    int test;
    fscanf(file, "%d", &test);
    for(int z=0;z<test;z++){
        int r, c, w;
        fscanf(file, "%d %d %d", &r, &c, &w);
        fprintf(f, "Case #%d: %d\n", z+1, (c/w) * (r-1) + (c-1)/w + w);
    }
    return 0;
}
