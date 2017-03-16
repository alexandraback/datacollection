#include <cstdio>

using namespace std;

double time(int num,double c, double f, double x) {
    double result = 0, income = 2;
    for(int i=0;i<num;i++) {
        result += c/income;
        income += f;
    }
    result += x/income;
    return result;
}

int main()
{
    FILE* in = fopen("input.txt","r");
    FILE* out = fopen("output.txt","w");
    int t;
    fscanf(in,"%d",&t);
    for(int i=1;i<=t;i++) {
        double c,f,x;
        fscanf(in,"%lf%lf%lf",&c,&f,&x);
        int p = 0;
        int q = (int)(x/c+2);
        while(p<q-1) {
            int r = (p+q)/2;
            if(time(r-1,c,f,x) < time(r,c,f,x)) {
                q = r;
            }
            else {
                p = r;
            }
        }
        fprintf(out,"Case #%d: %.7lf\n",i,time(p,c,f,x));
    }
    fclose(in);
    fclose(out);
    return 0;
}
//hamarabb megtermelõdik a cél, mint egy új visszahozná az árát
