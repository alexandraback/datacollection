#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>

#define LL long long
#define MP make_pair
#define PB push_back
#define ii pair<int,int>
using namespace std;
LL n,t,x,l;
LL idx;
char cek;
char in[10010];
pair<char,int> now;

pair<char,int> kali(pair<char,int> now,pair<char,int> b){
	char k = b.first;
	now.second^=b.second;
	switch(now.first){
		case '1':
			now.first = k;
		break;
		case 'i':
			if(k=='i' || k=='k')	now.second^=1;
			if(k=='i')		now.first = '1';
			else if(k=='j')	now.first = 'k';
			else if(k=='k')	now.first = 'j';
		break;
		case 'j':
			if(k=='i' || k=='j')	now.second^=1;
			if(k=='i')		now.first = 'k';
			else if(k=='j')	now.first = '1';
			else if(k=='k')	now.first = 'i';
		break;
		case 'k':
			if(k=='j' || k=='k')	now.second^=1;
			if(k=='i')		now.first = 'j';
			else if(k=='j')	now.first = 'i';
			else if(k=='k')	now.first = '1';
		break;
	}
	return now;
}

vector<int> V;
pair<char,int> cari(int k,pair<char,int> base){
	if(k==0)	return MP('1',0);
	if(k==1)	return base;
	pair<char,int> ret = base;
	if(base.first=='1'){
		ret = MP(base.first,k&1);
	}
	else
		ret = MP((k&1)?base.first:'1', (k%4>=2)?1:0);
	return ret;
}

int main(){
	scanf("%lld",&t);
	for(int z=1;z<=t;z++){
		printf("Case #%d: ",z);
		scanf("%lld %lld",&n,&x);
		scanf("%s",in);
		idx = 0;
		cek='i';
		now = MP('1',0);
		for(LL i=0;i<min(x*n,1000000ll);i++){
			now = kali(now, MP(in[i%n],0));
			
			if(cek==now.first){
				now.first = '1';
				cek++;
			}
			if(cek>'k'){
				idx = i+1;
			}
		}
		if(cek<='k'){
			printf("%s\n","NO");
			continue;
		}
		if(n*x - idx>0){
			for(int i=idx%n;i<n;i++)
				now = kali(now, MP(in[i%n],0));
			pair<char,int> base = MP('1',0);
			for(int i=0;i<n;i++)	base = kali(base,MP(in[i],0));
			pair<char,int> tmp = cari((n*x-idx)/n, base);
			now = kali(now,tmp);
		}
		printf("%s\n",(now.first=='1' && now.second==0)?"YES":"NO");
	}
	return 0;
}