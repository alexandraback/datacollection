#include<stdio.h>
#include<set>
#include<vector>
#include<map>
using namespace std;
char ch[10001];
int L,X,id;
map<pair<int,int>,pair<int,int> >mp;
int mul(int a,int b){
	if(a<0)return -mul(-a,b);
	if(b<0)return -mul(a,-b);
	if(a==1)return b;
	if(b==1)return a;
	if(a==b)return -1;
	if(a=='i'&&b=='j')return 'k';
	if(a=='i'&&b=='k')return -'j';
	if(a=='j'&&b=='i')return -'k';
	if(a=='j'&&b=='k')return 'i';
	if(a=='k'&&b=='i')return 'j';
	if(a=='k'&&b=='j')return -'i';
}
void get(int&cc,int c){
	int fr=cc;
	if(mp.find(make_pair(cc,c))!=mp.end()){
		id=mp[make_pair(cc,c)].first;
		cc=mp[make_pair(cc,c)].second;
		return;
	}
	while(id<L&&cc!=c){
		cc=mul(cc,ch[id++]);
	}
	mp[make_pair(fr,c)]=make_pair(id,cc);
}
set<int>st;
bool find(int c){
	int cc=1;
	while(id<L){
		cc=mul(cc,ch[id++]);
		if(cc==c)return true;
	}
	st.clear();
	while(X>1){
		id=0;
		X--;
		if(st.find(cc)!=st.end())return false;
		st.insert(cc);
		get(cc,c);
		if(cc==c)return true;
	}
	return false;
}
int pow(int a,int b){
	if(b==1)return a;
	int tmp=pow(a,b/2);
	tmp=mul(tmp,tmp);
	if(b&1)tmp=mul(tmp,a);
	return tmp;
}
int sum(){
	int tmp=1;
	for(int i=0;i<L;i++)
		tmp=mul(tmp,ch[i]);
	return tmp;
}
int re(){
	int tmp=1;
	while(id<L)tmp=mul(tmp,ch[id++]);
	if(X==1)return tmp;
	return mul(tmp,pow(sum(),X-1));
}
int main(){
	int ca;
	scanf("%d",&ca);
	for(int cas=1;cas<=ca;cas++){
		scanf("%d%d%s",&L,&X,ch);
		id=0;
		printf("Case #%d: ",cas);
		mp.clear();
		if(!find('i')){
			printf("NO\n");
			continue;
		}
		if(!find('j')){
			printf("NO\n");
			continue;
		}
		if(!find('k')){
			printf("NO\n");
			continue;
		}
		if(re()==1)printf("YES\n");
		else printf("NO\n");
	}
}
