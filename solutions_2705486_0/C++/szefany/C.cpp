#include "iostream"
#include "cstring"
#include "cstdio"
#include "vector"
#include "fstream"
#include "string"
#include "algorithm"
#include "map"
#define PB push_back
#define MP make_pair
using namespace std;
map<pair<int,int> ,int>mp;
const int N = 521196;
char dic[N+10][20];
char s[70];
int n;
int ans;
bool check(int l,int r,int &sum,int &last,int i)
{
	for(int j=0;j<strlen(dic[i]);j++){
		if(dic[i][j]!=s[r+j]){
			if(r+j-last<5) return 0;
			last=r+j;
			sum++;
		}
	}
	// printf("%d %d %s\n",l,r,dic[i]);
	return 1;
}
void gao(int l,int r,int val)
{
	// printf("%d %d %d %d\n",l,r,val,n);
	if(mp.find(MP(l,r))!=mp.end()){
		if(mp[MP(l,r)]<=val) return ; 
	}
	mp[MP(l,r)]=val;
	if(r==n){
		ans=min(ans,val);
	}
	for(int i=0;i<N;i++){
		if(strlen(dic[i])+r<=n){
			int sum=0,last=l;
			if(check(l,r,sum,last,i)){
				gao(last,r+strlen(dic[i]),val+sum);
			}
		}
	}
}
int main(void)
{
	ifstream fin("dict.txt");	
	for(int i=0;i<N;i++){
		fin>>dic[i];
	}
	freopen("C-small-attempt1.in","r",stdin);
	int T,g=0;
	scanf("%d",&T);
	while(T--){
		mp.clear();
		scanf("%s",s);
		n=strlen(s);
		ans=10000000;
		gao(-100,0,0);
		printf("Case #%d: %d\n",++g,ans);
	}
	return 0;
}