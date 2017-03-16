#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
typedef struct a
{
        char fir[1005], sec[1005];
}lol;
lol one[105];
lol two[105];
int compare(const void* a, const void* b)
{
        if(strcmp((*(lol*)a).fir, (*(lol*)b).fir)==0)
                return (strcmp((*(lol*)a).sec, (*(lol*)b).sec));
        else
                return (strcmp((*(lol*)a).fir, (*(lol*)b).fir));
}
int compare1(const void* a, const void* b)
{
        if(strcmp((*(lol*)a).sec, (*(lol*)b).sec)==0)
                return (strcmp((*(lol*)a).fir, (*(lol*)b).fir));
        else
                return (strcmp((*(lol*)a).sec, (*(lol*)b).sec));
}
int binse(int l, int r, int x)
{
        if (r >= l)
        {
                int mid = l + (r - l)/2;

                // If the element is present at the middle itself
                if (strcmp(two[mid].sec, one[x].sec)==0) return mid;

                // If element is smaller than mid, then it can only be present
                // in left subarray
                if (strcmp(two[mid].sec, one[x].sec)>0) return binse(l, mid-1, x);

                // Else the element can only be present in right subarray
                return binse(mid+1, r, x);
        }

        // We reach here when element is not present in array
        return -1;
}
int main()
{
        int t, cn;
        scanf("%d", &t);
        for(cn=1; cn<=t; cn++)
        {
                int n, i, ans=0;
                scanf("%d", &n);
                for(i=0; i<n; i++)
                {
                        scanf("%s", one[i].fir);
                        strcpy(two[i].fir, one[i].fir);
                        scanf("%s", one[i].sec);
                        strcpy(two[i].sec, one[i].sec);
                }
                qsort(one, n, sizeof(lol), compare);
                qsort(two, n, sizeof(lol), compare1);
                for(i=0; i<n-1; i++)
                {
                        if(strcmp(one[i].fir, one[i+1].fir)==0)
                        {
                                int j = binse(0, n, i);
                                if(j==-1)
                                        continue;
                                else
                                {
                                        if(strcmp(two[j].sec, two[j+1].sec)==0 || strcmp(two[j].sec, two[j-1].sec)==0)
                                                ans++;
                                }
                                continue;
                        }
                        ans--;
                }
                if(strcmp(one[i].fir, one[i-1].fir)==0)
                {
                        int j = binse(0, n, i);
                        if(j==-1)
                                continue;
                        else
                        {
                                if(strcmp(two[j].sec, two[j+1].sec)==0 || strcmp(two[j].sec, two[j-1].sec)==0)
                                        ans++;
                        }
                }
                printf("Case #%d: %d\n", cn, ans);
        }
        return 0;
}
