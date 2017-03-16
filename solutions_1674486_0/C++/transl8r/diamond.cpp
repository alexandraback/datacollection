#include<cstdio>
#include<queue>

using namespace std;

int in[1010][1010];
int check(int i, int n)
{
    int mark[1010]={0};
    mark[i] = 1;
    queue<int> q;
    q.push(i);
    int flag = 0;
    int j, t;
    while(q.size())
    {
	t = q.front();
	q.pop();
	for(j = 0; j < n; j++)
	{
	    if(in[t][j])
	    {
		if(mark[j])
		{
		    flag = 1;
		    break;
		}
		else
		{
		    mark[j] = 1;
		    q.push(j);
		}
	    }
	}
	if(flag)
	    break;
    }
    return flag;
}

int main()
{
    int t;
    int n, i , j, k, m, cs=0;
    int flag;
    scanf("%d", &t);
    while(t--)
    {

	for( i = 0; i < 1010; i++)
	    for(j = 0; j < 1010; j++)
		in[i][j] = 0;
	cs++;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
	    scanf("%d", &m);
	    for(j = 0; j < m; j++)
	    {
		scanf("%d", &k);
		in[i][k-1] = 1;
	    }
	}

	flag = 0;
	for(i = 0; i < n; i++)
	    if(check(i, n))
	    {
		flag = 1;
		break;
	    }

	if(flag)
	    printf("Case #%d: Yes\n", cs);
	else
	    printf("Case #%d: No\n", cs);
    }
    return 0;
}
