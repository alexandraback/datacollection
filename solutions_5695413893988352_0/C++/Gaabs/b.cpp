#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < b; i++)
#define fre(i,a,b) for(int i = a; i <= b; i++)
#define frd(i,a,b) for(int i = a; i > b; i--)
#define fred(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define SET(a,v) memset(a,v,sizeof a)

#define INF 1e8
#define N 1010

typedef long long ll;
typedef pair<int,int> ii;

int t;
char C[10],J[10];
int len;
int c,j;
int ans;

int go(int i, int ct, int jt){
	//printf("i:%d ct:%d jt:%d len:%d\n",i,ct,jt,len);
	if (i == len){
		int dif = abs(ct - jt);
		if (dif < ans){
			ans = dif;
			c = ct;
			j = jt;
		} else if (dif == ans){
			if (ct < c){
				c = ct;
				j = jt;
			} else if (ct == c && jt < j){
				c = ct;
				j = jt;
			}
		}
		return 0;
	}
	
	int ret = INF;
	
	int cnum = C[len-i-1] - '0';
	int jnum = J[len-i-1] - '0';
	
	if (C[len-i-1] != '?' && J[len-i-1] != '?'){
		ret = min(ret,go(i+1,ct+cnum*pow(10,i),jt+jnum*pow(10,i)));
	} else if (C[len-i-1] != '?'){
		fr(d,0,10) ret = min(ret,go(i+1,ct+cnum*pow(10,i),jt+d*pow(10,i)));
	} else if (J[len-i-1] != '?'){
		fr(d,0,10) ret = min(ret,go(i+1,ct+d*pow(10,i),jt+jnum*pow(10,i)));
	} else{
		fr(d1,0,10){ 
			fr(d2,0,10){
				ret = min(ret,go(i+1,ct+d1*pow(10,i),jt+d2*pow(10,i)));
			}
		}
	}
	
}

void solve(){
	c = j = ans = INF;

	go(0,0,0);
	sprintf(C,"%d",c);
	sprintf(J,"%d",j);
	
	int len2 = strlen(C);
	int dif = len-len2;
	fr(i,0,dif) printf("0");
	printf("%d ",c);
	len2 = strlen(J);
	dif = len-len2;
	fr(i,0,dif) printf("0");
	printf("%d\n",j);
	//printf("%s %s\n",C,J);
}

int main(){
	scanf("%d",&t);
	fr(t2,0,t){
		printf("Case #%d: ",t2+1);
		scanf("%s%s",C,J);
		len = strlen(C);
		
		solve();		
	}

	return 0;
}