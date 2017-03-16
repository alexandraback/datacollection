#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

#define SIZE 1000

static bool visited[SIZE][2];
static bool a[SIZE][SIZE];
static int le[SIZE];
static int ri[SIZE];
static int l_tot, r_tot;

void dfs(int x)
{
	visited[x][0] = true;
	for (int i = 0; i < r_tot; ++i)
		if (!visited[i][1])
		{
			visited[i][1] = true;
			if (ri[i] == -1)
			{
				le[x] = i;
				ri[i] = x;
			}
			else if (!visited[ri[i]][0])
			{
				int tmp = ri[i];
				le[x] = i;
				ri[i] = x;
				dfs(tmp);
			}
		}
}

int main()
{
	//ifstream infile("C-sample");
	ifstream infile("C-small-attempt0.in");
    ofstream outfile("C-output");
    int t;
    infile >> t;
    for (int ca = 1; ca <= t; ++ca)
    {
        outfile << "Case #" << ca << ": ";
        int n;
        infile >> n;
        memset(a, '\0', sizeof(a));
        memset(le, -1, sizeof(le));
        memset(ri, -1, sizeof(ri));
        vector<string> ls(SIZE);
        vector<string> rs(SIZE);
        int idx[n][2];
        l_tot = 0; r_tot = 0;
        for (int i = 0; i < n; ++i)
        {
        	infile >> ls[i] >> rs[i];
        	cerr << ls[i] << " " << rs[i] << endl;
        	idx[i][0] = -1; idx[i][1] = -1;
        	for (int j = 0; j < i; ++j)
        	{
        		if (ls[i].compare(ls[j]) == 0)
        		{
        			idx[i][0] = idx[j][0];
        		}
        		if (rs[i].compare(rs[j]) == 0)
        		{
        			idx[i][1] = idx[j][1];
        		}
        	}
        	if (idx[i][0] == -1) idx[i][0] = (l_tot++);
        	if (idx[i][1] == -1) idx[i][1] = (r_tot++);
        	a[idx[i][0]][idx[i][1]] = true;
        }

	    for (int i = 0; i < l_tot; ++i)
	    {
	    	memset(visited, '\0', sizeof(visited));
	    	dfs(i);
	    }

	    int ans = n;
	    for (int i = 0; i < l_tot; ++i)
	    	if (le[i] != -1) --ans;
	   	outfile << ans << endl;
    }

    infile.close();
    outfile.close();

    return 0;

}