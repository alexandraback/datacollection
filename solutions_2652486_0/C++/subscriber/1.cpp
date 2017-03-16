#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int r,n,m,k,x,h[11][11],c[11];

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> r >> n >> m >> k;
		cout << "Case #" << E << ":" << endl;
		for (int q=0;q<r;q++){
			m0(h);
			for (int i=0;i<k;i++){
				cin >> x;
				m0(c);
				while (x%3==0)x/=3,c[3]++;
				while (x%2==0)x/=2,c[2]++;
				while (x%5==0)x/=5,c[5]++;
				h[2][c[2]]=1;
				h[3][c[3]]=1;
				h[5][c[5]]=1;
			}
			string ans="";
			if (h[5][3])ans+="555";else if (h[5][2])ans+="55";else if (h[5][1])ans+="5";
			if (h[3][3])ans+="333";else if (h[3][2])ans+="33";else if (h[3][1])ans+="3";
			if (h[5][6])ans+="444";
			if (ans.size()==0){
				if (h[2][1]||h[2][3]||h[2][5])ans+="2";
				if (h[2][5])ans+="44";else if (h[2][4])ans+="4";
				while (ans.size()<3)ans+="2";
			}else if (ans.size()==1){
				if (h[2][1]||h[2][3]||h[2][5])ans+="2";
				if (h[2][4])ans+="44";else if (h[2][3])ans+="4";
				while (ans.size()<3)ans+="2";
			}else if (ans.size()==2){
				if (h[2][1]||h[2][3]||h[2][5])ans+="2";
				if (h[2][2]||h[2][3]||h[2][4]||h[2][5]||h[2][6])ans+="4";
				while (ans.size()<3)ans+="2";
			}
			cout << ans << endl;
		}
	}
	return 0;
}


