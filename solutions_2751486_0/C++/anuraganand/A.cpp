#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

bool check(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
         return false;
    return true;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	char S[1000010];
	scanf("%d%*c",&T);
	for(int tt=1;tt<=T;tt++){
		int n;
		scanf("%s %d%*c",&S,&n);
		int l = strlen(S);
		long long ans=0;
		int p=-1;
		for(int i=0;i<=l-n;i++){
			int count=0;
			int j=i;
			while(check(S[j]) && j<l){
				count++;
				//printf("i = %d count = %d\n",i,count);
				if(count == n)
					break;
				j++;
			}
			if(count >= n){
				ans += (long long)((long long)i - (long long)p)*((long long)l - (long long)j);
				p = i;
			}

		}
		printf("Case #%d: %lld\n",tt,ans);
	}
	return 0;
}
