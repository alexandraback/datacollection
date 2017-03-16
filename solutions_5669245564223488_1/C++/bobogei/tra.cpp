#include<bits/stdc++.h>

using namespace std;

typedef long long i64;

const int MAX = 155;
const int MOD = 1000000007;

int T;
int N;
char ip[MAX][MAX];
char ls[MAX],fs[MAX];
int id[MAX],od[MAX];
int nt[MAX],bf[MAX];
int sm[MAX];
int md[MAX];
bool us[MAX];
bool ffg;

int frac(int n){
	i64 ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	return ans;
}

void aozora(){
	ffg=0;
	memset(ip,0,sizeof(ip));
	memset(ls,0,sizeof(ls));
	memset(fs,0,sizeof(fs));
	memset(id,0,sizeof(id));
	memset(od,0,sizeof(od));
	memset(sm,0,sizeof(sm));
	memset(us,0,sizeof(us));
	memset(md,0,sizeof(md));
	memset(nt,0,sizeof(nt));
	memset(bf,0,sizeof(bf));
}

void input(){
	cin >> N;

	for(int i=0;i<N;i++){
		cin >> ip[i];
		int len=strlen(ip[i]);

		fs[i]=ip[i][0];
		if(ip[i][len-1]!=ip[i][0])	nt[ip[i][0]-'a']=ip[i][len-1]-'a';
		ls[i]=ip[i][len-1];

		od[fs[i]-'a']++;
		id[ls[i]-'a']++;

		if(fs[i]==ls[i]){
			sm[fs[i]-'a']++;
			od[fs[i]-'a']--;
			id[fs[i]-'a']--;
		}

		for(int j=0;j<len;){
			char nc=ip[i][j];
//			cout << nc;
			us[ip[i][j]-'a']=1;

			if(nc!=ls[i]&&nc!=fs[i]){
				md[nc-'a']++;
				if(ls[i]==fs[i]) ffg=1;
			}

			while(ip[i][j]==nc) j++;
		}

	}
}

int check(){
	//cout << md[1] << endl;
	for(int i=0;i<26;i++){
		if(ffg) return 0;
		if(od[i]>1||id[i]>1) return 0;
		if((od[i]||id[i]||sm[i])&&md[i]) return 0;
		if(md[i]>1) return 0;
	}

	int li=0;

	for(int i=0;i<26;i++){
		if(id[i]!=0) continue;
		if(od[i]==0){
			if(sm[i]!=0) li++;
			continue;
		}

		int nv=i;
		for(;od[nv]!=0;nv=nt[nv]){
			us[nv]=0;
		}

		li++;
	}
	i64 ans=1;

	for(int i=0;i<26;i++){
		if(us[i]&&(od[i]!=0)){
	//		cout << i << endl;
			return 0;
		}

		ans*=frac(sm[i]);
		ans%=MOD;
	}
//	cout << frac(2);

	ans*=frac(li);
	ans%=MOD;

	//cout << li << endl;
	return ans;

}

int main(){
	
	cin>>T;

	for(int _T=1;_T<=T;_T++){
		aozora();

		input();
		int t = check();

		cout << "Case #" << _T << ": " << t << endl;

	}
}
