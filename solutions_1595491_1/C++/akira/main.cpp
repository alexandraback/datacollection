#include <stdio.h>
int main (int argc, const char * argv[])
{
    FILE *fi = fopen("/Users/jh/t/in.txt", "r"), *fo = fopen("/Users/jh/t/out.txt", "w");
    int T;
    fscanf(fi, "%d\n", &T);
    int N, S, p, t, r;
    for(int i = 0; i != T; ++i)
    {
        r = 0;
        fscanf(fi, "%d %d %d ", &N, &S, &p);
        for(int j = 0; j != N; ++j)
        {
            fscanf(fi, "%d ", &t);
            if(t < p)
                continue;
            if(p * 3 - t <= 2)
                ++r;
            else if(p * 3 - t <= 4)
            {
                if(S > 0)
                {
                    ++r;
                    --S;
                }
            }
        }
        fprintf(fo, "Case #%d: %d\n", i + 1, r);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
