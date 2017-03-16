#include<stdio.h>

int main()
{
    FILE *in;
    FILE *out;
    int t, n, s, p, i, j, k, c=0, ts;
    int scores[100];
    
    in = fopen("B-small.in", "r");
    out = fopen("B-small.out", "w");
    
    fscanf(in, "%d\n", &t);
    
    while(t--)
    {
        c++;
        fscanf(in, "%d %d %d", &n, &s, &p);
        
        for(i=0; i<n; i++) fscanf(in, "%d", &scores[i]);
        
        for(i=0, j=0, k=0, ts=0; i<n; i++)
        {
            k = scores[i]/3;
            if(k >= p) ts++;
            else if(scores[i])
            {
                if(p-k==1)
                {
                    if(scores[i]%3 == 0){ if(j<s) j++, ts++;}
                    else ts++;
                }
                else if(p-k==2)
                {
                    if(j<s && scores[i]%3 == 2) j++, ts++;
                }
            }
            //printf("%d %d\n", j, ts);
        }
        fprintf(out, "Case #%d: %d\n", c, ts);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
