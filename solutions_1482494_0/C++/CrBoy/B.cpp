#include <cstdio>
#include <algorithm>
#include <limits.h>

using namespace std;

class Stage
{
public:
	Stage(int a, int b):a(a), b(b), star(2){}

//private:
	int a, b;
	int star;
};

bool cmp_a(Stage *A, Stage *B) { return A->a < B->a; }
bool cmp_b(Stage *A, Stage *B) { return A->b < B->b; }

int main(int argc, const char *argv[])
{
	int T, N, a, b;
	int casen=0;
	Stage *stages[1024];
	int play, stars;
	bool flag;

//	freopen("B.in", "r", stdin);
	scanf("%d", &T);
	while(casen<T){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d%d", &a, &b);
			stages[i] = new Stage(a,b);
		}
		sort(stages, stages+N, cmp_b);

		play = stars = 0;
		flag = true;
		for(int i=0; i<N && flag; i++){
			if(stages[i]->b <= stars){ // earn 2 stars
				stars += stages[i]->star;
				++play;
			}else{ // find 1 star to earn
				flag = false;
				for(int j=N-1; j>=i; j--){
					if(stages[j]->a <= stars){
						stages[j]->a = INT_MAX;
						--stages[j]->star;
						++stars;
						++play;
						flag = true;
						break;
					}
				}
				--i;
			}
		}


		if(flag)
			printf("Case #%d: %d\n", ++casen, play);
		else
			printf("Case #%d: Too Bad\n", ++casen);
	}
	return 0;
}
