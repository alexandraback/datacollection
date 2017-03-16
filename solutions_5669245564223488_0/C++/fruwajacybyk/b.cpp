#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;

int mod = 1e9+7;

int n;
int stan[30][12];

char s[1000];

bool dobry(){
	int u = strlen(s);
	set<int> uzyte;
	char akt = s[0];
	FOR(i,1,n){
		if(s[i]!=akt){
			uzyte.insert(akt-'a');
			if(uzyte.find(s[i]-'a')!=uzyte.end()) return false;
			akt = s[i];
		}
	}
	return true;
}

int t[20];

bool check(int j){
	bool mozepocz = true;
	bool mozekon = true;
	bool mozesrod = true;
	int juzbylo = 0;
	FOR(i,0,n){
		if(stan[j][t[i]]==-1 && juzbylo==1){
			mozepocz=false;
			mozekon = false;
			mozesrod = false;
		}
		if(stan[j][t[i]]==0) { 
			if(mozesrod==false) return false;
			mozekon = false; juzbylo = 1;
		}
		if(stan[j][t[i]]==1) { 
			if(mozepocz==false) return false;
			mozekon = false; mozepocz = false; mozesrod = false; juzbylo = 1;
		}
		if(stan[j][t[i]]==2) { 
			if(mozekon==false) return false;
			mozekon = false; juzbylo = 1;
		}
	}
	return true;
	
}

int main(){
	int z; scanf("%d",&z);
	int casenr=0;
	while(z--){
		casenr++;
		printf("Case #%d: ",casenr);
		scanf("%d",&n);
		bool flaga = true;

		FOR(i,0,n) FOR(j,0,26) stan[j][i] = -1;

		FOR(i,0,n){
			scanf("%s ",s);
			if(!dobry()) flaga = false; 
			int u = strlen(s);
			int start = s[0]-'a';
			int meta = s[u-1]-'a';
			int ilezakaz = 0;
			FOR(j,0,u){
				if((s[j]-'a')!=start && (s[j]-'a')!=meta){
					stan[s[j]-'a'][i]=3;
					ilezakaz++;
				}
			}

			if(start==meta && ilezakaz>0) flaga = false;
			if(start==meta){
				stan[start][i] = 0;
			}
			else{
				stan[start][i] = 1;
				stan[meta][i] = 2;
			}	
		}
		
		FOR(j,0,26){
			FOR(u,0,n) FOR(v,u+1,n){
				if(stan[j][u]==3 && stan[j][v]!=-1) flaga = false;
				if(stan[j][v]==3 && stan[j][u]!=-1) flaga = false;
			}
		}

		if(!flaga){ printf("0\n"); continue;}
		
		int res =0;
		FOR(i,0,n) t[i] = i;
		do{
			bool dasie = true;
			FOR(j,0,26){
				if(!check(j)){ dasie = false; break;}
			}
			if(dasie) res++;
			res = res%mod;
		}while(next_permutation(t,t+n));
	
		printf("%d\n",res);

	}
	return 0;
}
  

