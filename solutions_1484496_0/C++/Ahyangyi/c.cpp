#include <stdio.h>
#include <map>

using namespace std;

int data[500];
map<int, int> M;

int main ()
{
    int t, n;
    int ct = 0;

    for (scanf ("%d", &t); t > 0; t --)
    {
        scanf ("%d", &n);
        for (int i = 0; i < n; i ++)
            scanf ("%d", data + i);

        M.clear ();

        int i1, i2;
        printf ("Case #%d:\n", ++ct);

        for (int i = 1; i < (1<<n); i ++)
        {
            int sum = 0;
            for (int j = 0; j < n; j ++)
                if (i & (1 << j))
                    sum += data[j];
            if (M.find(sum)==M.end())
            {
                M[sum] = i;
            }
            else
            {
                i1 = i;
                i2 = M[sum];
                goto second;
            }
        }

first:
        printf ("Impossible\n");
        goto third;
second:
        {
        bool flag = false;
        for (int i = 0; i < n; i ++)
            if (i1 & (1 << i))
            {
                if (flag)
                    printf (" ");
                printf ("%d", data[i]);
                flag = true;
            }
        printf ("\n");
        
        flag = false;
        for (int i = 0; i < n; i ++)
            if (i2 & (1 << i))
            {
                if (flag)
                    printf (" ");
                printf ("%d", data[i]);
                flag = true;
            }
        printf ("\n");
        }
third:
        ;
    }

    return 0;
}
