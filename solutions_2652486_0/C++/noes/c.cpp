#include <cstdio>

int times, picks, ran, muls;
int mul[10];

int picked[5];

bool process(int n) {

	if(n>=picks) {
		for(int j=0; j<muls; ++j) {
			int target=mul[j];
			for(int i=0; i<picks; ++i) 
				if(target%picked[i]==0) target/=picked[i];

			if(target>1) return false;
		}
		for(int i=0; i<picks;++i) printf("%d", picked[i]);
		printf("\n");
		
		return true;
	}

	for(int i=2; i<=ran; ++i) {

		picked[n]=i;
		if(process(n+1)) return true;

	}

	return false;

}

int main() {

	int casen;

	scanf("%d", &casen);
	for(int t=0; t<casen; ++t) {

		scanf("%d %d %d %d", &times, &picks, &ran, &muls);
		
		printf("Case #%d:\n", t+1);
		for(int i=0; i<times;++i) {
			for(int j=0; j<muls;++j)
				scanf("%d", &mul[j]);
			process(0);

		}

	}

	return 0;

}