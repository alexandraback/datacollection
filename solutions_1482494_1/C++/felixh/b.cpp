#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

#define A first
#define B second

int T,N;

int main(){
	scanf("%d",&T);
	for (int tc=1; T--; tc++){
		fprintf(stderr,"Case #%d: \n",tc);
		printf("Case #%d: ",tc);
		scanf("%d",&N);
		vector<pair<int,int> > arr(N);
		REP(i,N) scanf("%d %d",&arr[i].A,&arr[i].B);
		sort(arr.begin(), arr.end());

		int attempt = 0, stars = 0;
		while (arr.size()){
			int minB = 0;
			REP(i,arr.size())
				if (arr[i].B < arr[minB].B)
					minB = i;

			if (stars >= arr[minB].B){
				if (arr[minB].A == -1){
					stars++;
				} else {
					stars += 2;
				}
//				printf("B = %d, %d\n",minB,stars);
				arr.erase(arr.begin() + minB);
			} else {
				int minA = -1;
				REP(i,arr.size())
					if (arr[i].A != -1 && arr[i].A <= stars)
						if (minA == -1 || arr[i].B > arr[minA].B)
							minA = i;

				if (minA == -1){
					puts("Too Bad");
					goto finish;
				}

				stars++;
				arr[minA].A = -1;
//				printf("A = %d, %d\n",minA,stars);
			}
			attempt++;
		}
		printf("%d\n",attempt);
		finish:;
	}
}
