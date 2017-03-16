#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 20
using namespace std;

class BigInt{
	public:
		int num[N+1];
		int len;
		BigInt(){
			memset(num, 0, sizeof(num));
		}
		BigInt(const char str[]){
			memset(num, 0, sizeof(num));
			len=strlen(str);
			for(int i=0; i<len; i++)
				num[i]=str[len-i-1]-'0';
		}
		void find_len(){
			for(len=N; len>1&&!num[len-1]; len--);
		}
		void print(){
			for(int i=len-1; i>=0; i--)
				printf("%d", num[i]);
			puts("");
		}
		bool is_palin(){
			int i, j;
			for(i=0, j=len-1; i<j&&num[i]==num[j]; i++, j--);
			return i>=j;
		}
		int bigger(BigInt b){
			if(len>b.len) return 1;
			else if(len<b.len) return -1;
			for(int i=len-1; i>=0; i--)
				if(num[i]>b.num[i]) return 1;
				else if(num[i]<b.num[i]) return -1;
			return 0;
		}
		void add_one(){
			num[0]++;
			make();
		}
		void make(){
			for(int i=0; i<N; i++){
				num[i+1]+=num[i]/10;
				num[i]%=10;
			}
			find_len();
		}
		BigInt sq(){
			BigInt c;
			for(int i=0; i<len; i++)
				for(int j=0; j<len; j++)
					c.num[i+j] += num[i]*num[j];
			c.make();
			return c;
		}
} list[1000];

int main(){
	int T, time=0, top=0;
	char str[100];
	BigInt limit("100000000000000");
	for(BigInt i("1");  ; i.add_one()){
		BigInt sq=i.sq();
		if(sq.bigger(limit) == 1) break;
		if(i.is_palin() && sq.is_palin()) list[top++]=sq;
	}

	scanf("%d", &T);
	while(T--){
		scanf(" %s", str);
		BigInt l(str);
		scanf(" %s", str);
		BigInt r(str);
		printf("Case #%d: ", ++time);
		int i, j;
		for(i=0; l.bigger(list[i]) == 1; i++);
		for(j=i; r.bigger(list[j]) >= 0; j++);
		printf("%d\n", j-i);
	}
	return 0;
}
