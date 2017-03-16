#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<queue>
#include<list>
#include<vector>
#define LL long long
#define INF 0x7fffffff
#define For(i,a,b) for(int i=a; i<b; ++i)
using namespace std;
typedef pair<int,int> ii;
#define M 1000000007
LL cal(int nn, char s[200][200], int order[20], int n, int valid[20]){
	LL ans = 0;
	if(n==0){
		int c[26];
		For(i,0,26) c[i]=0;
		for(int t =0; t<nn; ++t){
			int i = order[t];
			int len = strlen(s[i]);
			for(int j=0; j<len; ++j){
				if(c[s[i][j]-'a']==0){
					c[s[i][j]-'a']++;
				}
				else{
					if(j!=0 && s[i][j]!=s[i][j-1]) return 0;
					if(j==0 && s[i][j]!=s[order[t-1]][strlen(s[order[t-1]])-1]) return 0;
				}
			}
		}

		return 1;
	}
	else{
		for(int i=0; i<nn; ++i){
			if(valid[i]==1){
				n--;
				valid[i]--;
				order[n] = i;
				ans += cal(nn, s, order, n, valid);
				n++;
				valid[i]++;
			}
		}
	}
	
	return ans;
}
int main(){
	int T;
	cin>>T;
				
	for(int cas = 1; cas<=T; ++cas){
		int N;
		cin>>N;
		char s[200][200];
		int valid[200];
		for(int i=0; i<N; ++i){
			cin>>s[i];
			valid[i]=1;
		}

		int c[30];
		For(i, 0,26) c[i] = 1;
		

		//For(i, 0,26) For(j,0,26) if(c[i][j]>0) printf("%d %d %d\n", i,j,c[i][j]);
		
		LL ans = 0;
		int order[20];
		ans+= cal(N, s, order,N, valid);

		printf("Case #%d: ",cas); 
		cout<<ans<<endl;
	}
	return 0;
}
