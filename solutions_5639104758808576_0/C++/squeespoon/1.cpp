#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

char str[1010];

int main(){
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		int MAX;
		cin>>MAX;
		scanf("%s",str);
		int len=strlen(str);
		
		int cnt=0;
		int ans=0;
		for(int i=0;i<len;i++){
			str[i]-='0';
			cnt+=str[i];
			if(cnt<i+1){
				int add = i+1-cnt;
				cnt+=add;
				ans+=add;
			}
		}
		
		printf("Case #%d: %d\n",cas,ans);
		//cout<<ans<<endl;
		
	}
	
	return 0;
}



