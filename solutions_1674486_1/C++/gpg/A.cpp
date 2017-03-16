#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;




int num[1010];
int marked[1010];
int hasFather[1010];
int nos[1010][1010];
int N;
int mark(int no){
	if(marked[no])
		return 1;
	marked[no] = 1;
	for(int i = 0;i<num[no];i++){
		if(mark(nos[no][i]))
			return 1;
	}
	return 0;
}

int main(){

	int _C,_c;

	scanf("%d",&_C);
	for(_c = 1;_c<=_C;_c++){
		scanf("%d",&N);
		for(int i = 1;i<=N;i++)
			hasFather[i] = 0;
		for(int i = 1;i<=N;i++){
			marked[i] = 0;
			scanf("%d",num+i);
			for(int j = 0;j<num[i];j++){
				scanf("%d",nos[i]+j);
				hasFather[nos[i][j]] = 1;
			}
		}
		int result = 0;
		for(int i = 1;i<=N;i++){
			if(hasFather[i])
				continue;
			for(int j = 1;j<=N;j++){
				marked[j] = 0;
			}

			result|=mark(i);
		}
		printf("Case #%d: ",_c);
		printf("%s\n",(result)?"Yes":"No");
	}

	return 0;
}
