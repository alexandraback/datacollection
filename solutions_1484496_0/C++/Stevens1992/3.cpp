#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <memory.h>
using namespace std;

int input[25];
map<int,int> mymap;
bool flag1[25], flag2[25];
pair<map<int,int>::iterator,bool> p;

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t, n, num, sum, i, j, tmp, cas=1;
	bool success;
    scanf("%d", &t);
    while(t--)
    {
		printf("Case #%d:\n", cas++);
        scanf("%d",&n);
        for(i = 0; i < n; i++)
			scanf("%d", &input[i]);
        mymap.clear();
        num = 1 << n;
        for(i = 0, success = false; i < num; i++)
        {
            sum=0;
            for(j = 0; j < n; j++)
                if((1 << j) & i)
                    sum += input[j];
            p=mymap.insert(make_pair(sum, i));
            if(!p.second)
            {
                tmp = mymap[sum];
                memset(flag1, 0, sizeof(flag1));
                memset(flag2, 0, sizeof(flag2));
                for(j = 0; j < n; j++)
                    if((1 << j) & i)
                        flag1[j]=1;
                for(j = 0; j < n; j++)
                    if((1 << j) & tmp)
                        flag2[j]=1;
                for(j = 0; j < n; j++)
				{
                    if(flag1[j] && !flag2[j])
                    {
                        printf("%d", input[j]);
						success = true;
                        break;
                    }
				}
                j++;
                for(; j < n; j++)
				{
                    if(flag1[j] && !flag2[j])
                        printf(" %d", input[j]);
				}
                printf("\n");
                for(j = 0; j < n; j++)
				{
                    if(flag2[j] && !flag1[j])
                    {
                        printf("%d", input[j]);
						success = true;
                        break;
                    }
				}
                j++;
                for(; j < n; j++)
                    if(flag2[j] && !flag1[j])
                        printf(" %d", input[j]);
                printf("\n");
				success = true;
                break;
            }
        }
		if(!success)
			printf("Impossible\n");
    }
	return 0;
}

