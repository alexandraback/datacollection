#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
#define X first
#define Y second
#define RED 0
#define GREEN 1
#define BLUE 2
typedef long long LL;
//typedef __int128_t VL;
typedef long double LD;

bool square_is_OK[10123000];
int prefix_sum[10123000];

long long decimal[20];
bool isPalindrome(long long a){
	int length = 0;
	while(a>0){
		decimal[length++] = a%10;
		a /= 10;
	}
	for(int i = 0; i < length/2; i++)
		if(decimal[i] != decimal[length-i-1])
			return false;
	return true;
}

int main(){
	for(long long i = 0; i < 10123000; i++){
		square_is_OK[i] = (isPalindrome(i) && isPalindrome(i*i));
	}
	prefix_sum[0] = square_is_OK[0];
	for(int i = 1; i < 10123000; i++)
		prefix_sum[i] = square_is_OK[i]+prefix_sum[i-1];

	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		long long A, B;
		scanf("%lld %lld", &A, &B);
		long long a, b;
		a = sqrt(A);
		b = sqrt(B);
		if(a*a < A)
			a++;
		if(b*b > B)
			b--;

		printf("Case #%d: ", t);
		printf("%d\n", prefix_sum[b] - prefix_sum[a-1]);
	}
	return 0;
}
