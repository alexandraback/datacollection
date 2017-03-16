#include <stdio.h>
#include <vector>
using namespace std;

vector<int> getjamcoin(int N, int x)
{
	vector<int> result;
	result.resize(N);

	// init
	result[0]=1;
	result[N-1]=1;
	for (int i=1;i<N-1;i++) result[i]=0;

	for (int p=N-3; p>0; p-=2) {
		if (x>=p) {
			x-=p;
			for (int i=1;i<=N-p-1;i++) {
				result[i]=1;
			}
		} else {
			result[N-p-2+x]=1;
			result[N-p-2+x+1]=1;
			break;
		}
	}

	return result;
}

int jamcoin(int N, int J, int skip)
{
	int i=0;
	for (i=0;i<J;) {
		//printf("i=%d ", i);
		vector<int> temp=getjamcoin(N-2*skip, i);
		vector<int> result;
		result.resize(N);

		result[0]=1;
		result[N-1]=1;
		result[skip]=1;
		result[N-1-skip]=1;
		copy(temp.begin(), temp.end(), result.begin()+skip);
		
		int cnt=0;
		for (int j=skip;j<N-skip;j++) {
			if (result[j]==1) cnt++;
		}
		if (cnt==N-skip*2) {
			break;
		}
		for (int j=0;j<N;j++) {
			printf("%d", result[j]);
		}
		for (int j=2;j<=10;j++) {
			printf(" %d", j+1);
		}
		printf("\n");

		i++;
	}
	return i;
}

int main()
{
	int T=1;
	scanf("%d", &T);
	for (int i=0;i<T;i++) {
		int N,J;
		scanf("%d %d", &N, &J);

		printf("Case #%d:\n", i+1);
		int skip=0;
		while (J>0) {
			J-=jamcoin(N,J, skip);
			skip++;
		}
	}

	return 0;
}
