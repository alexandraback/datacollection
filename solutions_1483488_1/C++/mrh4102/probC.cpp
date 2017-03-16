#include<stdio.h>
#include <map>

using namespace std;

map<int, int> mem;

int rdr(int n, int d)
{
    return d==1? 0: ((n%10)*d)+(n/10);
}

int main()
{
    FILE *in;
    FILE *out;
    int t, c=0, a, b, d, nd, i, j, k, ts;
    
    in = fopen("C-small.in", "r");
    out = fopen("C-small.out", "w");
    
    fscanf(in, "%d\n", &t);
    
    while(t--)
    {
        c++;
        fscanf(in, "%d %d", &a, &b);
        for(i=a, ts=0; i<=b; i++)
        {
            if(i>=0) d=1, nd=1;
            if(i>=10) d=10, nd=2;
            if(i>=100) d=100, nd=3;
            if(i>=1000) d=1000, nd=4;
            if(i>=10000) d=10000, nd=5;
            if(i>=100000) d=100000, nd=6;
            if(i>=1000000) d=1000000, nd=7;
            mem.clear();
            for(j=0, k=i; j<nd; j++)
            {
                k = rdr(k, d);
                if(mem.count(k) == 0)
                {
                    mem[k] = 1;
                    if(i<k && k<=b) ts++;
                }
            }
        }
        
        fprintf(out, "Case #%d: %d\n", c, ts);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
