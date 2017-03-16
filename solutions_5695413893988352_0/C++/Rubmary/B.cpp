#include <bits/stdc++.h>
using namespace std;

#define FOR(i, to, from) for(int i=to; i<from; i++)
#define ri(n) scanf("%d", &n)
#define rii(n, m) scanf("%d %d", &n, &m);
#define ms(obj,val) memset(obj, val, sizeof(obj))
#define pb push_back
typedef long long ll;
typedef vector<int> vi;

typedef unsigned long long ull;
string S1, S2;

int n;
void menor(int k, vector<int> &res1, vector<int> &res2, string S1, string S2){
	FOR(i, 0, k){
		if(S1[i]==S2[i]){
			if(S1[i]=='?') res1[i]=res2[i]=0;
			else           res1[i]=res2[i]=S1[i]-'0';
		}
		else if(S1[i]=='?') res1[i]=res2[i]=S2[i]-'0';
		else if(S2[i]=='?') res1[i]=res2[i]=S1[i]-'0';
	}
	FOR(i, k, n){
		if(S1[i]=='?') res1[i]=9;
		else           res1[i]=S1[i]-'0';
		if(S2[i]=='?') res2[i]=0;
		else           res2[i]=S2[i]-'0';
	}
}


void mayor(int k, vector<int> &res1, vector<int> &res2, string S1, string S2){
	int j=k-1;
	for(; j>=0; j--){
		if(S1[j]=='?' && S2[j]=='?'){
			res1[j]=1;
			res2[j]=0;
			break;
		}
		if(S1[j]=='?' && S2[j]<9){
			res2[j]=S2[j]-'0';
			res1[j]=res2[j]+1;
			break;
		}
		if(S2[j]=='?' && S1[j]>0){
			res1[j]=S1[j]-'0';
			res2[j]=res1[j]-1;
			break;
		}
		res1[j]=0;
		res2[j]=9;
	}
	FOR(i, 0, j){
		if(S1[i]==S2[i]){
			if(S1[i]=='?') res1[i]=res2[i]=0;
			else           res1[i]=res2[i]=S1[i]-'0';
		}
		else if(S1[i]=='?') res1[i]=res2[i]=S2[i]-'0';
		else if(S2[i]=='?') res1[i]=res2[i]=S1[i]-'0';
	}
	FOR(i, k, n){
		if(S1[i]=='?') res1[i]=0;
		else           res1[i]=S1[i]-'0';
		if(S2[i]=='?') res2[i]=9;
		else           res2[i]=S2[i]-'0';
	}
}


ull num(vector<int> &A1){
	ull res=0;
	ull pot10=1;
	FOR(i, 0, n){
		res+=A1[n-i-1]*pot10;
		pot10*=10;
	}
	return res;
}
int T;
int main(){
	cin >>T;
	FOR(t, 1, T+1){
		cout <<"Case #"<< t << ": ";
		cin >> S1 >> S2;
		n=S1.length();
		vi res1(n), res2(n);
		vi A1(n), A2(n), B1(n), B2(n);
		
		int k=0;
		for(; k<n && (S1[k]==S2[k] || S1[k]=='?' || S2[k]=='?'); k++);
		
		if(k==n){
			FOR(i, 0, n){
				if(S1[i]==S2[i]){
					if(S1[i]=='?') res1[i]=res2[i]=0;
					else           res1[i]=res2[i]=S1[i]-'0';
				}
				else if(S1[i]=='?') res1[i]=res2[i]=S2[i]-'0';
				else if(S2[i]=='?') res1[i]=res2[i]=S1[i]-'0';
			}
		}
		if(k==0){
			if(S1[k]<S2[k]){
				menor(k, res1, res2, S1, S2);
			}else{
				menor(k, res2, res1, S2, S1);
			}
		}
		else{
			if(S1[k]<S2[k]){
				menor(k, A1, A2, S1, S2);
				mayor(k, B1, B2, S1, S2);
				ull x1=num(A1), x2=num(A2), y1=num(B1), y2=num(B2);
				if(x2+y2<=x1+y1) {
					res1 = A1;
					res2 = A2;
				}
				else{
					res1 = B1;
					res2 = B2;
				}
			} else{
				menor(k, A2, A1, S2, S1);
				mayor(k, B2, B1, S2, S1);
				ull x1=num(A1), x2=num(A2), y1=num(B1), y2=num(B2);
				if(x1+y1<y2+x1 || (x1+y1==y2+x2 && x1<=y1)){
					res1 = A1;
					res2 = A2;
				}
				else{
					res1 = B1;
					res2 = B2;
				}
			}
			
			
		}
		
		FOR(i, 0, n) cout << res1[i];
		cout << ' ';
		FOR(i, 0, n) cout << res2[i];
		cout << endl;
		
	}	
}


