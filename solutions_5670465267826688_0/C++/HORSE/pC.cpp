#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N_MAX = 40050;
char str[N_MAX];
int mat[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

int id(char c){
	if(c == '1')
		return 1;
	if(c == 'i')
		return 2;
	if(c == 'j')
		return 3;
	if(c == 'k')
		return 4;
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("pC_small.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cnt = 1; cnt <= t; cnt++){
		printf("Case #%d: ", cnt);
		int len;
		ll mul;
		scanf("%d%lld", &len, &mul);
		scanf("%s", str);
		for(int i = 0; i < 3 * len; i++)
			str[i + len] = str[i];
		int lb = 0, rb = 4 * len - 1;
		int sta = 1;
		bool neg = false;
		while(lb < 4 * len){
			sta = mat[sta][id(str[lb])];
			if(sta < 0){
				sta = -sta;
				neg ^= 1;
			}
			if(sta == 2 && !neg)
				break;
			lb ++;
		}
		sta = 1;
		neg = false;
		while(rb >= 0){
			sta = mat[id(str[rb])][sta];
			if(sta < 0){
				sta = -sta;
				neg ^= 1;
			}
			if(sta == 4 && !neg)
				break;
			rb --;
		}
		//printf("%d %d\n", lb, rb);
		if(lb == 4 * len || rb == -1 || (ll)len * mul <= (lb + 1) + (4 * len - rb)){
			puts("NO");
			continue;
		}
        mul %= 4;
        sta = 1;
        neg = false;
        for(int i = 0; i < mul * len; i++){
			sta = mat[sta][id(str[i])];
			if(sta < 0){
				sta = -sta;
				neg ^= 1;
			}/*
			if(neg)
				putchar('-');
			printf("%d ", sta);*/
        }
        //putchar('\n');
        (sta == 1 && neg) ? puts("YES") : puts("NO");
	}
	return 0;
}
