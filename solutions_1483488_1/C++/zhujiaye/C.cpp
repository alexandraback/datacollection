#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int A,B,test,tmp[10];
vector<int>res;

int calc(int x){
	int len=0,S=x,T=B;
	res.clear();
	for (;x;x/=10) tmp[len++]=x%10;
	for (int i=len-2;i>=0;i--) if (tmp[i]!=0){
		int w=0;
		for (int j=i,l=0;l<len;l++,j=(j-1+len)%len){
			w=w*10+tmp[j];
			if (w>B) break;
		}
		if (w>S && w<=B){
			res.push_back(w);
			//printf("%d %d\n",S,w);
		}
	}
	sort(res.begin(),res.end());
	len=res.size();
	int cnt=0;
	for (int i=0;i<len;i++) if (i==0 || res[i]!=res[i-1]) cnt++;
	return cnt;
}
int main(){
	freopen("i.txt","r",stdin);
	int cnt=1;
	scanf("%d",&test);
	for (;test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d%d",&A,&B);
		int res=0;
		for (int i=A;i<=B;i++){
			res+=calc(i);
		}
		printf("%d\n",res);
	}
	return 0;
}
