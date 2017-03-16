#include <bits/stdc++.h>

#define MAX 105

using namespace std;

typedef long long int ll;

int T,K,L,S,pref;
//char key[MAX],s[MAX];
string key,s;
int pre[MAX][30];
double dp[MAX][MAX];
int dp2[MAX][MAX];

double doit(int idx,int tam){
	if(idx == S) return 0;
	if(dp[idx][tam]!=-1) return dp[idx][tam];
	//printf("tam:%d\n",tam);
	double resp=0;	
	for(int i=0;i<K;i++){
		int x = pre[tam][key[i]-'A'];
		if(tam == L-1 && s[L-1] == key[i])	resp += 1.0/K * ( doit(idx+1,pref) + 1);
		else resp += 1.0/K * ( doit(idx+1,x));
	}
	return dp[idx][tam]=resp;
}


int doit2(int idx,int tam){
	if(idx == S) return 0;
	if(dp2[idx][tam]!=-1) return dp2[idx][tam];
	int resp=0;	
	for(int i=0;i<K;i++){
		int x = pre[tam][key[i]-'A'];
		if(tam == L-1 && s[L-1] == key[i])	resp = max(resp,   doit2(idx+1,pref) + 1);
		else resp = max( resp,   doit2(idx+1,x) );
	}
	return dp2[idx][tam]=resp;
}

int main(){
	scanf("%d",&T);
	for(int caso=1;caso<=T;caso++){
		scanf("%d %d %d",&K,&L,&S);
		cin >> key >> s;		
		//scanf("%s",key);
		//scanf("%s",s);
		memset(pre,0,sizeof pre);
		for(int i=0;i<=S;i++){
			for(int j=0;j<30;j++){
				dp[i][j]=-1;
				dp2[i][j]=-1;		
			}		
		}
		for(int i=0;i<=L;i++){
			for(int j=0;j<26;j++){
				string a=s.substr(0,i);
				a.push_back(j+'A');
				pre[i][j]=0;		
				for(int k=1;k<=a.size();k++){		
					if(i == L-1 && k == i+1) continue;
					if(i == L && k >= i) continue;
					string a1=a.substr(((int)a.size())-k,k);				
					int cont=0;					
					for(int l=0;l<L;l++){
						if(a1[l] == s[l] ) cont++;
						else break;					
					}
					if(cont == k) pre[i][j]=max(pre[i][j],cont);			
				}			
			}		
		}
		/*for(int i=0;i<=L;i++){
			for(int j=0;j<26;j++){
				if(pre[i][j]) printf("pre[%d][%c]:%d\n",i,j+'A',pre[i][j]);			
			}
		}*/
		//printf("pre:%d , pre:%d\n",pre[0][6] , pre[1][14]);		
		/*pref=0;
		for(int i=1;i<L;i++){
			string a= s.substr(s.size()-i,i);
			int cont=0;					
			for(int l=0;l<L;l++){
				if(a[l] == s[l] ) cont++;
				else break;					
			}
			if(cont == i) pref=i;
		}
		
		printf("pref:%d\n",pref);*/
		pref=pre[s.size()-1][s[s.size()-1]-'A'];		
		printf("Case #%d: %.8lf\n",caso,doit2(0,0)-doit(0,0));	
	}	

}
