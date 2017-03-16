#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MaxN= 1111;
int T, N, a[MaxN], b[MaxN], hsh[2][MaxN], flag, case_cnt, ans, star;
bool able_to_play(){
	int pos= -1, flag= 0;
	for(int i= 1;i<= N && !flag;++ i)
		if(!hsh[1][i])
			flag= 1;
	if(flag){
		for(int i= 1;i<= N;++ i) if(!hsh[1][i])
			if(star >= b[i] && (pos==-1 || b[pos] < b[i])){
				pos= i;
//				return 1;
			}
		if(pos != -1){
			hsh[1][pos]= 1;
			if(hsh[0][pos])
				++ star;
			else
				star+= 2;
			return 1;
		}
		for(int i= 1;i<= N;++ i) if(!hsh[0][i] && !hsh[1][i])
			if(star >= a[i] && (pos==-1 || b[pos] < b[i])){
					pos= i;
//				hsh[0][i]= 1;
//				++ star;
//				return 1;
			}
		if(pos != -1){
			hsh[0][pos]= 1;
			++ star;
			return 1;
		}
		return 0;
	}else
		return 0;
}
int main(){
//	freopen("gcj.in", "r", stdin);
	scanf("%d", &T);
	while(T --){
		flag= 1, ans= 0, star= 0;
		memset(hsh, 0, sizeof hsh);		
		scanf("%d", &N);
		for(int i= 1;i<= N;++ i)
			scanf("%d%d", a+i, b+i);
		int cur= 0;
		while(able_to_play())
			++ ans;
		for(int i= 1;i<= N;++ i)
			if(!hsh[1][i])
				flag= 0;
		printf("Case #%d: ", ++ case_cnt);
		if(flag)
			printf("%d\n", ans);
		else
			printf("Too Bad\n");
	}
//	system("pause");
}
/*
1
1
1 1
*/
