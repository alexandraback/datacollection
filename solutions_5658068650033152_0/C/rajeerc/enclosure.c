#include <stdio.h>

int calculate (int p, int q, int k)
{
    int min, max;
    if (p>q)
    {
        max = p;
        min = q;
    }
    else
    {
        max = q;
        min = p;
    }

    switch (min)
    {
    case 1:
        return k;
    case 2:
        return k;
    case 3:
    {
        switch (max)
        {
        case 3:
        {
            switch (k)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                return k;
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                return k-1;
            }
        }
        case 4:
        {
            switch (k)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                return k;
            case 5:
            case 6:
            case 7:
                return k-1;
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                return k-2;
            }
        }
        case 5:
        {
            switch (k)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                return k;
            case 5:
            case 6:
            case 7:
                return k-1;
            case 8:
            case 9:
            case 10:
                return k-2;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                return k-3;
            }
        }

        case 6:
        {
            switch (k)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                return k;
            case 5:
            case 6:
            case 7:
                return k-1;
            case 8:
            case 9:
            case 10:
                return k-2;
            case 11:
            case 12:
            case 13:
                return k-3;
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
                return k-4;
            }
        }

        }
    }

    case 4:
    {
        switch (max)
        {
        case 4:
        {
            switch (k)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                return k;
            case 5:
            case 6:
            case 7:
                return k-1;
            case 8:
            case 9:
            return k-2;
            case 10:

            case 11:
                return k-3;
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
                return k-4;
            }
        }

        case 5:
        {
            switch (k)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                return k;
            case 5:
            case 6:
            case 7:
                return k-1;
            case 8:
            case 9:
            case 10:
                return k-2;
            case 11:
                return k-3;
            case 12:
            case 13:
                return k-4;
            case 14:
            case 15:
                return k-5;
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
                return k-6;
            }
        }
        }
    }
    }
}

int main ()
{
    FILE *fp1, *fp2;
    fp1 = fopen ("C-small-attempt2.in", "r");
    fp2 = fopen ("output.txt", "w");

    int count;
    int t;
    int ans;
    int p, q, k;

    if (fp1 && fp2)
    {
        fscanf(fp1, "%d", &t);
        count = 0;

        while (count<t)
        {
            count++;
            fscanf(fp1, "%d %d %d", &p, &q, &k);
            ans = calculate(p, q, k);
            fprintf(fp2, "Case #%d: %d\n", count, ans);
        }
    }
}
