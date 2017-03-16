#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int X,R,C;

int main() {
    FILE* fin = fopen("D-small-attempt0.in","r");
    FILE* fout = fopen("D-small-attempt0.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for (int t=1;t<=T;t++) {
        fscanf(fin,"%d%d%d",&X,&R,&C);
        if (R<C) swap(R,C);
        int rich = 0;
        if ((R*C)%X!=0) rich = 1;
        if (X>R && X>C) rich = 1;
        if (X>6) rich = 1;
        if (min(X/2+1,X-X/2)>min(R,C)) rich = 1;
        if (X==4 && R==4 && C==2) rich = 1;
        if (X==5 && R==5 && C==3) rich = 1;
        if (X==6 && R==6 && C==3) rich = 1;
        fprintf(fout,"Case #%d: ",t);
        if (rich) fprintf(fout,"RICHARD\n");
        else fprintf(fout,"GABRIEL\n");
    }

    return 0;
}
