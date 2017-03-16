#include <algorithm>
#include <string.h>

using namespace std;

int N;
int v[1010];
double A[1010],B[1010];

int get_lower(double val){
	for(int i=N-1;i>=0;--i){
		if (!v[i]&&B[i]<val) return i;
	}
	return -1;
}

int get_upper(double val){
	for(int i=0;i<N;++i){
		if (!v[i]&&B[i]>val) return i;
	}
	return -1;
}

void solve_case(){
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%lf",A+i);
	}
	for(int i=0;i<N;++i){
		scanf("%lf",B+i);
	}
	sort(A,A+N);
	sort(B,B+N);
	int a=0;
	memset(v,0,sizeof(v));
	for(int i=0;i<N;++i){
		int x=get_lower(A[i]);
		if (x==-1){
			for(int i=N-1;i>=0;--i){
				if (!v[i]){
					v[i]=1;
					break;
				}
			}
		} else {
			++a;
			v[x]=1;
		}
	}
	printf("%d ",a);
	a=0;
	memset(v,0,sizeof(v));
	for(int i=0;i<N;++i){
		int x=get_upper(A[i]);
		if (x==-1){
			for(int i=0;i<N;++i){
				if (!v[i]){
					v[i]=1;
					break;
				}
			}
			++a;
		} else {
			v[x]=1;
		}
	}
	printf("%d\n",a);
}

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d: ",t);
		solve_case();
	}
	return 0;
}

