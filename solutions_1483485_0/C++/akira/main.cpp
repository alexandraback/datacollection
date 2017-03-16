#include <stdio.h>
char GG[26] = {
    'y', 'h', 'e', 's', 'o', 'c', 'v',
    'x', 'd', 'u', 'i', 'g', 'l', 'b',
    'k', 'r', 'z', 't', 'n', 'w',
    'j', 'p', 'f', 'm', 'a', 'q'
};
/*
 */
int main (int argc, const char * argv[])
{
    FILE *fi = fopen("/Users/jh/t/in.txt", "r"), *fo = fopen("/Users/jh/t/out.txt", "w");
    int T;
    fscanf(fi, "%d\n", &T);
    char buf[1024];
    for(int i = 0, j = 0; i != T; ++i)
    {
        fgets(buf, 1024, fi);
        while(buf[j] != '\n')
        {
            if(buf[j] != ' ')
                buf[j] = GG[buf[j] - 'a'];
            ++j;
        }
        j = 0;
        fprintf(fo, "Case #%d: %s", i + 1, buf);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
