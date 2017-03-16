#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
char s[101];
int tc,tcn,n,d[30][5];
long long re;
vector <string> v[26];
typedef vector<string> vs;
typedef pair<vs,long long> vsl;
vector <vsl> p;
void input(){
	int len,tmp_len;
	string tmp;
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++){
		scanf("%s",s);
		len=strlen(s);
		tmp=s[0];
		tmp_len=1;
		for(int j =1 ; j< len ;j++){
			if(s[j]!=tmp[tmp_len-1]){
				tmp+=s[j];
				tmp_len++;
			}
		}
		
		v[tmp[0]-'a'].push_back(tmp);
	}
	for(int i = 0 ; i < 26; i++)
		sort(v[i].begin(),v[i].end());
}
int check(){
	int len;
	for(int j = 0 ; j< 26; j++){
		int m=v[j].size();
		for(int i = 0  ; i < m ; i++){
			len=v[j][i].length();
			if(v[j][i].size()==1){
				d[ v[j][i][0]-'a' ][0]++;
			}
			else{
				d[ v[j][i][0]-'a' ][1]++;
				d[ v[j][i][len-1]-'a' ][2]++;
				for(int k=1 ; k <len-1; k++)
					d[v[j][i][k]-'a'][3]++;
			}
		}
	}
	for(int i = 0 ; i< 26; i++){
		if( d[i][3]>1)
			return 1;
		if( (d[i][0] || d[i][1] || d[i][2] ) && d[i][3] )
			return 1;
	//	if( d[i][0] && d[i][1] && d[i][2])
	//		return 1;
		if( (d[i][1] && d[i][2]) && (d[i][1]>1 || d[i][2]>1))
			return 1;
	}

	return 0;
}

long long get(){
	
	int psize,pi_size,push,fb;
	long long cnt=0;
	long long ans;
	bool ch[26];
	memset(ch,0,sizeof(ch));
	int cur=-1;
	int all_visit=0;
	while(1){
		if(cur == -1){
			for(int i = 0 ; i < 26 ; i++){
				if( !ch[i]){
					ch[i]=1;
					cur=i;
					break;
				}
				else if( i== 25)
					all_visit=1;
			}
		}
		if(all_visit)
			break;
		int m=v[cur].size();
		for(int i = 0 ; i <  m ; i++){
			//if(v[cur][i].size()==1)
			//	continue;
			psize=p.size();
			push=0;
			cnt=1;
			if(v[cur][i].size() == 1)
				fb=1;
			else fb=0;
			for(int j = 0 ; j < psize; j++){
				pi_size=p[j].first.size();
				for(int k =0 ; k< pi_size; k++){
					if(fb && p[j].first[k][0]==v[cur][i][0] && p[j].first[k].size()==1){
						cnt++;
						push=1;
					}
					else if(p[j].first[k][0]==v[cur][i].back())
						push=1;
					else if(p[j].first[k].back()==v[cur][i][0])
						push=1;
				}
				if( push ){
					p[j].second*=cnt;
					p[j].second%=mod;
					p[j].first.push_back(v[cur][i]);
					break;
				}
			}
			if( !push ){
				vsl tmp;
				tmp.first.push_back(v[cur][i]);
				tmp.second=1;
				p.push_back(tmp);
			}
		}
		if( v[cur].size() ){
			int nxt=v[cur].back()[v[cur].back().length()-1];
			nxt-='a';
			if(!ch[ nxt]){
				cur=nxt;
				ch[nxt]=1;
			}
			else 
				cur=-1;
		}
		else 
			cur=-1;
	}
	/*
	for(int i = 0 ; i <  n ; i++){
		if(v[i].size()!=1)
			continue;
		psize=p.size();
		push=0;
		cnt=1;
		if(v[i].size() == 1)
			fb=1;
		else fb=0;
		for(int j = 0 ; j < psize; j++){
			pi_size=p[j].first.size();
			for(int k =0 ; k< pi_size; k++){
				if(fb && p[j].first[k][0]==v[i][0] && p[j].first[k].size()==1){
					cnt++;
					push=1;
				}
				else if(p[j].first[k][0]==v[i].back())
					push=1;
				else if(p[j].first[k].back()==v[i][0])
					push=1;
			}
			if( push ){
				p[j].second*=cnt;
				p[j].second%=mod;
				p[j].first.push_back(v[i]);
				break;
			}
		}
		if( !push ){
			tmp.first.clear();
			tmp.first.push_back(v[i]);
			tmp.second=1;
			p.push_back(tmp);
		}
	}*/
	psize=p.size();
	ans=1;
	for(long long i = 1; i<= psize; i++){
		ans*=i;
		ans%=mod;
		ans*=p[i-1].second;
		ans%=mod;
	}
	return ans;
}
int main(void){
	//freopen("B-small-attempt5.in","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&tc);
	while(tc--){
		for(int i = 0; i< 26; i++)
			v[i].clear();
		p.clear();
		memset(d,0,sizeof(d));
		input();
		if(check()){
			printf("Case #%d: 0\n",++tcn);
			continue;
		}
		re=get();
		printf("Case #%d: %lld\n",++tcn,re);
		
	}
	return 0;
}