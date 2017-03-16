#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int shift(char * arr) {
	int len = strlen(arr);
	int last = arr[0];
	for (int i=1;i<len;i++)
		arr[i-1] = arr[i];
	arr[len-1] = last;
}

bool between(int x,int l,int r) {
	return (l <= x && x<= r);
}

int main()
{
	int nCase;
	scanf("%d",&nCase);

	for (int nc = 0 ; nc < nCase ; nc ++ ) {
		cerr << "Done @ " << nc+1 << endl;
		int ans = 0;
		int A , B;
		scanf("%d%d",&A,&B);
		for (int i=A;i<=B;i++)
		{
//			cerr << "Doing .... " << i << endl;
			char tmp[10];
			sprintf(tmp,"%d",i);
			int x;

			do {
				shift(tmp);
				sscanf(tmp,"%d",&x);
//				cerr << x << endl;
				if (between(x,i+1,B))
					ans++;
			}while (x != i);
		}
		printf("Case #%d: %d\n",nc+1,ans);
	}
	return	0;
}
