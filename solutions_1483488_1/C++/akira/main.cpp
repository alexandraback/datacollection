#include <stdio.h>
#include <set>
using namespace std;
int main (int argc, const char * argv[])
{
    FILE *fi = fopen("/Users/jh/t/in.txt", "r"), *fo = fopen("/Users/jh/t/out.txt", "w");
    int T;
    fscanf(fi, "%d\n", &T);
    int A, B, a, b, r;
    set<int> s;
    for(int i = 0; i != T; ++i)
    {
        r = 0;
        b = 1;
        fscanf(fi, "%d %d\n", &A, &B);
        while(A < B)
        {
            while(b < A)
                b *= 10;
            if(b > A)
                b /= 10;
            a = A;
            s.clear();
            while(1)
            {
                a = a / b + a % b * 10;
                if(a == A)
                    break;
                else if(a > A && a <= B && s.find(a) == s.end())
                {
                    ++r;
                    s.insert(a);
                }
            }
            ++A;
        }
        fprintf(fo, "Case #%d: %d\n", i + 1, r);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
