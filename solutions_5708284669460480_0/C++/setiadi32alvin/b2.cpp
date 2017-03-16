#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

#define LL long long
#define ii pair<int,int>
using namespace std;
int t,l,k,s;
char in[1000];
string K,L;
double ans;
double mx;

double cek(string S){
	double r = 0;
	for(int i=0;i<=S.size() - L.size();i++){
		if(S.substr(i,L.size()) == L)
			r+=1.0;
	}
	mx = max(mx,r);
	return r;
}
void coba(string S){
	if(S.size() == s)	ans+=cek(S);
	else{
		for(int i=0;i<K.size();i++)
			coba(S+K[i]+"");
	}
}

int main(){
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		printf("Case #%d: ",z);
		scanf("%d%d%d",&k,&l,&s);
		scanf("%s",in);	K = in;
		scanf("%s",in);	L = in;
		ans = 0.0;
		mx = 0.0;
		coba("");
		for(int i=0;i<s;i++)	ans/=(double)(K.size());
		//cout<<mx<<" "<<ans<<endl;
		printf("%.6lf\n",mx - ans);			
	}
	return 0;
}
