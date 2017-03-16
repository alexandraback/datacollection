#include<cstdio>
using namespace std;

int reverse(int num){
    int rev = 0;
    while(num > 0){
	rev = rev*10 + num%10;
	num /= 10;
    }
    return rev;
}

int COUNT[1000001];

int main(){
    for(int i=1; i<1000001; ++i){
	if(COUNT[i] == 0){
	    COUNT[i] = COUNT[i-1] + 1;
	    int rev = reverse(i);
	    if(rev > i)	COUNT[rev] = COUNT[i] + 1;
	}else{
	    if(COUNT[i-1] + 1 < COUNT[i])   COUNT[i] = COUNT[i-1] + 1;
	}
    }
    int T, N;
    scanf(" %d ", &T);
    for(int t=1; t<=T; ++t){
	scanf(" %d ", &N);
	printf("Case #%d: %d\n", t, COUNT[N]);
    }
    return 0;
}

