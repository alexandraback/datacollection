#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <limits>
#include <map>
#include <math.h> 

using namespace std;

#define ONE 1
#define I 2
#define J 3
#define K 4

bool solve();
int getval(int a, int b);

int main(){
	int cases;
	bool ans;
	scanf("%d", &cases);

	for(int i=0; i<cases; i++){
		printf("Case #%d: ", i+1);
		ans = solve();
		if(!ans)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

bool solve(){
	int L, X;
	char buffer[10010];
	
	scanf("%d %d", &L, &X);
	scanf("%s", buffer);

	if(L*X<3)
		return false;

	for(int i=1; i<X; i++){
		memcpy(buffer+L*i, buffer, sizeof(char)*L);
	}
	buffer[L*X] = '\0';

	vector<int> is;
	vector<int> ks;

	int curr = ONE, tmp; //1==1, i==2, j==3, k==4
	for(int i=0; i<L*X-2; i++){
		tmp = buffer[i]-'g';
		curr = getval(curr, tmp);
		if(curr==I){
			is.push_back(i);
			//printf("I: %d!\n", i);
		}
	}

	curr = ONE;
	for(int i=L*X-1; i>=2; i--){
		tmp = buffer[i]-'g';
		curr = getval(tmp, curr);
		if(curr==K){
			ks.push_back(i);
			//printf("K: %d\n", i);

		}
	}

	int old;
	for(unsigned int i=0; i<is.size(); i++){
		curr = ONE;
		old = is[i]+1;
		for(unsigned int j=0; j<ks.size(); j++){
			if(ks[j]-is[i] < 2)
				continue;
			for(int k=old; k<ks[j]; k++){ //k = is[i]+1
				tmp = buffer[k]-'g';
				curr = getval(curr, tmp);
			}
			if(curr==J){
				return true;
			}
			old = ks[j];
		}
	}

	return false;
}

int getval(int a, int b){
	int neg = 1;
	if(a<0){
		neg*=-1;
		a = -a;
	}
	if(b<0){
		neg*=-1;
		b = -b;
	}

	int matrix[4][4] = {ONE, I, J, K,         I, -ONE, K, -J,      J,-K, -ONE, I,           K, J, -I, -ONE};

	int tmp = matrix[a-1][b-1];
	tmp*=neg;
	return tmp;
}