#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define LL long long
#define Maxn 15
char key[Maxn],tar[Maxn];
queue<string> que;
int k,l,s;
int main(){
	int cases;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		int k,l,s;
		scanf("%d%d%d",&k,&l,&s);
		scanf("%s",key);
		scanf("%s",tar);
		que.push("");
		double Max=0;
		int ans=0;
		while (!que.empty()){
			string sta=que.front();que.pop();
			int len=sta.length();
			if (len==s){
				int tmp=0;
				for (int i=0;i<=len-1;i++){
					bool flag=true;
					for (int j=0;j<l;j++){
						if (sta[i+j]!=tar[j]){
							flag=false;
							break;
						}
					}
					if (flag) tmp++;
				}
				Max=max((double)tmp,Max);
				ans+=tmp;
			}
			if (len<s){
				for (int i=0;i<k;i++){
					que.push(sta+key[i]);
				}
			}
		}
		double an=1;
		for (int i=0;i<s;i++) an*=k;
		ans=Max-1.0*ans/an;
		printf("Case #%d: %.7f\n",cas,ans);
	}
	return 0;
}