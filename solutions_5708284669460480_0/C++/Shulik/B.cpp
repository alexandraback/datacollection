#include <cstdio>

#define REP(i, n)for (int i = 0; i < n; i++)

using namespace std;

int k, l, s;
char alphabet[7];
char needle[7];

int pow(int a, int b){
	int ret = 1;
	REP(i, b)ret*=a;
	return ret;
}

void to_word(int n, char * ret){
	REP(i, s){
		ret[i] = alphabet[(n%k)];
		n/=k;
	}
}

int occurences(char * a, char * b, int al, int bl){
	int ret = 0;
	REP(i, al-bl+1){
		int j = 0;
		for(; j < bl && a[i+j] == b[j]; j++);
		if(j==bl)ret++;
	}
	return ret;
}

int maxo(){
	int i = 1;
	for(; i < l; i++){
		int j = 0;
		for(; i+j < l && needle[i+j] == needle[j]; j++);
		if(i+j == l)break;
	}
	return (s-l)/i + 1;
}

bool in_alphabet(char c){
	REP(i, k)if(alphabet[i] == c)return true;
	return false;
}

int main(){
	int t;


	scanf("%d", &t);
	REP(testcase, t){
		scanf("%d %d %d", &k, &l, &s);
		char c;
		REP(i, k){
			while((c=getchar()) < 'A' || c > 'Z');
			alphabet[i] = c;
		}
		bool valid = true;
		REP(i, l){
			while((c=getchar()) < 'A' || c > 'Z');
			needle[i] = c;
			if(!in_alphabet(c))valid = false;
		}

		double ret = 0;

		if(valid){
			int total = pow(k, s);
			int found = 0;
			char test[7];
			REP(i, total){
				to_word(i, test);
				found+=occurences(test, needle, s, l);
			}
			double ex = double(found)/double(total);
			ret = double(maxo()) - ex;
		}

		printf("Case #%d: %lf\n", testcase+1, ret);
	}

	return 0;
}