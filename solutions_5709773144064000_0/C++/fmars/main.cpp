#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    FILE*fin=fopen("in.txt","r");
    FILE*fout=fopen("out.txt","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++){
        double v=2,c,f,x;
        fscanf(fin,"%lf%lf%lf",&c,&f,&x);
        double r=0;
        while((x/v)>(c/v+x/(v+f))){
            r+=c/v;
            v+=f;
        }
        r+=x/v;
        fprintf(fout,"Case #%d: %.7f\n",i,r);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
