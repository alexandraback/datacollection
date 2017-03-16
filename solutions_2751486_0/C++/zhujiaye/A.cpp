#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn (1000005)
using namespace std;

char s[maxn];
int N,M,cnt,test,opt[maxn],len[maxn];

bool isVowel(char c){
	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
		return false;
}
int main(){
	freopen("i.txt","r",stdin);
	
	cnt=1;
	for (scanf("%d",&test);test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%s %d",s,&M);
		memset(opt,-1,sizeof(opt));
		memset(len,-1,sizeof(len));
		N=strlen(s);
		len[N]=0;
		for (int i=N-1;i>=0;i--){
			if (isVowel(s[i]))
				len[i]=-1;
			else{
				if (len[i+1]!=-1) len[i]=len[i+1]+1;
					else len[i]=1;
			}
			if (len[i]>=M) 
				opt[i]=i;
			else
				opt[i]=opt[i+1];
		}
		long long res=0;
		for (int i=0;i<N;i++){
			if (opt[i]!=-1)
				res+=N-(opt[i]+M-1);
		}
		cout<<res<<endl;
	}
	return 0;
}
