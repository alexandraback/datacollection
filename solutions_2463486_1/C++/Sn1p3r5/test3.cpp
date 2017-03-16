#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> psq;
char buffer[33];
bool status;
int len;

bool check(long long temp){
	lltoa(temp, buffer, 10);
	len=strlen(buffer);
	status=true;
	for (int a=0; a<=len/2; a++){
		if (buffer[a]!=buffer[len-a-1]){
			status=false;
			break;
		}
	}
	if (status) return true;
	else return false;
}

int main(){
	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);
	long long temp, begin, end;
	int ctr=0, ans, tc, num;
	for (long long a=1; a<=10000000; a++){
		if (check(a)){
			temp=a*a;
			if (check(temp)){
				psq.push_back(temp);
			}
		}
	}
	scanf("%d", &tc);
	for (int a=1; a<=tc; a++){
		ans=0;
		scanf("%lld%lld", &begin, &end);
		for (int b=0; b<psq.size(); b++){
			if (psq[b]>=begin && psq[b]<=end) ans++;
		}
		printf("Case #%d: %d\n", a, ans);
	}
}
