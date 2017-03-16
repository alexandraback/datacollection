#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char str1[20];
bool visit[3000000];

int my_atoi(char *str, int n){
	int ans=0, i;
	for(i=0; i<n; i++)
		ans = ans*10+str[i]-'0';
	return ans;
}
int my_itoa(int num, char *str){
	int i, len, t;
	for(i=0; num; num/=10, i++)
		str[i] = num%10+'0';
	str[i] = 0;
	len = strlen(str);
	for(i=0; i<len/2; i++){
		t = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = t;
	}
	for(i=0; i<len; i++)
		str[len+i] = str[i];
	str[len+len]=0;
	return len;
}

int main(){
	int a, b, i, x, y, t, time=0, len, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		ans=0;
		for(x=a; x<=b; x++){
			len = my_itoa(x, str1);
			//printf("%s\n", str1);
			memset(visit, 0, sizeof(bool)*(b+3));
			for(i=1; i<len; i++){
				y = my_atoi(str1+i, len);
				if(x<y && y<=b && !visit[y]){
					ans++;
					visit[y]=1;
				}
				//printf("%d\n", y);
			}
		}
		printf("Case #%d: %d\n", ++time, ans);
	}
	return 0;
}
