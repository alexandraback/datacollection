#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100][100], res[100][100];
int r, c;

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		scanf("%d %d", &r, &c);
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) { scanf("%d", arr[i] + j); res[i][j] = 100; }
		for(int i=0;i<r;i++)
		{
			int v = arr[i][0];
			for(int j=1;j<c;j++) v = max(v, arr[i][j]);
			for(int j=0;j<c;j++) res[i][j] = min(res[i][j], v);
		}
		for(int i=0;i<c;i++)
		{
			int v = arr[0][i];
			for(int j=1;j<r;j++) v = max(v, arr[j][i]);
			for(int j=0;j<r;j++) res[j][i] = min(v, res[j][i]);
		}

		bool isSame = true;
		for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(arr[i][j] != res[i][j]) isSame = false;
		if(isSame) printf("Case #%d: YES\n", caseN);
		else printf("Case #%d: NO\n", caseN);
	}

	return 0;
}

