#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#define MAXN 2000010

using namespace std;

inline int scan (int *p)
{
	char c, s;
	while ((c = getchar_unlocked ()) && (c < 48 || c > 57));
	for (*p = (c - 48); (c = getchar_unlocked ()) >= 48 && c <= 57; *p = (*p * 10) + (c - 48));
	return *p;
}

int main()
{
    /*freopen("C-large.in", "r", stdin);
    freopen("C-large-output-any.out", "w", stdout);*/
    int t,tz = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int a,b;
        //scanf("%d %d", &a, &b);
        scan(&a);
        scan(&b);
        if(a <= 9)
            a = 12;
        int resp = 0;
        for(int i = a; i < b; i++)
        {
            char numb[10];
            int aux = i;
            int ct = 0;
            while( aux )
            {
                numb[ct++] = (aux%10)+'0';
                aux /= 10;
            }
            reverse(numb,numb+ct);
            numb[ct] = 0;
            ct = strlen(numb);
            set < int > N;
            for(int qt = 1; qt < ct; qt++)
            {
                char auxi[10];
                int k = 0;
                for(int j = (ct-qt); j < ct; j++)
                    auxi[k++] = numb[j];
                for(int j = 0; j < (ct-qt); j++)
                    auxi[k++] = numb[j];
               // printf("\n");
                auxi[k] = 0;
                int tf = atoi(auxi);
                //printf("Tf: %d\n", tf);
                if(tf > i && tf <= b && strlen(auxi) == ct && (N.find(tf) == N.end()))
                {
                    N.insert(tf);
                    resp++;
                }
            }
        }
        printf("Case #%d: %d\n",tz++, resp);
    }
    return 0;
}
