#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define x first
#define y second
#define pushb(a) push_back(a)
#define pushf(a) push_front(a)
#define popb()   pop_back()
#define popf()   pop_front()
#define setmem(a,val) memset(a,val,sizeof(a))
#define LEN 1000

using namespace std;
typedef long long int large;
typedef pair<int,int> ii;

char line[LEN], p[LEN],t[LEN],keyb[LEN];
int plen,tlen,K,mb,vlen;
large v[LEN];
int b[LEN];

void kmpPreprocess() {
	int j=-1, i=0;
	for(i=0;i<=plen;i++){
		if(j>=0 && p[i]==p[j]) b[i]=b[j];
		else b[i]=j;
		while(j>=0 && p[i]!=p[j]) j=b[j];
		j++;
	}
}

int kmpSearch() {
	int i = 0, j = 0,ans=0;
	while (i < tlen) {
		while (j >= 0 && t[i] != p[j]) j = b[j];
		i++; j++;
		if (j == plen) {
			//printf("%s = %s\n",p,t+i-j);
			++ans;
			j = b[j];
		}
	}
	return ans;
}

void brute(int lo){
	int i;
	if(lo==tlen){
		kmpPreprocess();
		i = kmpSearch();
		//if(i>0) printf("Test %s in %s\n",p,t);
		vlen = max(i+1,vlen);
		//if(i>0)printf("%d\n",i);
		++v[i];
	}
	else{ loop(i,0,K) t[lo]=keyb[i], brute(lo+1); }
}

double solve(){
	int i; double num=0,den=0; t[tlen]=0;
	setmem(v,0), vlen=0, brute(0);
	loop(i,0,vlen) num += i*v[i], den+=v[i];
	//loop(i,0,vlen) printf("Prob of %d times: %d\n",i,v[i]);
	//printf("%lf vs %lf\n",vlen-1,(num==0? 0 : num/den));
	return (vlen-1) - (num==0? 0 : num/den);
}

int main(){
	int ntc,test=1;
	//freopen("monkey.txt","r",stdin);
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	gets(line);
	sscanf(line,"%d",&ntc);
	while(ntc--){
		gets(line);
		sscanf(line,"%d %d %d",&K,&plen,&tlen);
		gets(keyb);
		gets(p);
		printf("Case #%d: %lf\n",test++,solve());
	}
	return 0;
}

