
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

#define REP(i,s,n)  for (int i=(s),_n=(n);i<=_n;i++)
#define FOR(i,s,n)  for (int i=(s),_n=(n);i<_n;i++)
#define REPD(i,e,s)  for (int i=(e),_s=(s);i>=_s;i--)
#define tr(container, it) \
	for (typeof(container.begin()) it=container.begin(); it!=container.end();it++)
#define PB push_back
#define MP make_pair

typedef long long LL;
int INF=100000;

int cmpstr(char a[],char b[]) {
	int l1=strlen(a);
	int l2=strlen(b);
	if (l1!=l2) return INF;
	int cnt=0;
	FOR(i,0,l1) if (a[i]!=b[i]) cnt++;
	return cnt;
}

map<string,int> M1;
void init() {
	FILE *fp;
	fp=fopen("garbled_email_dictionary.txt","r");
	char wrd[500];
	int flag=0;
	while (fscanf(fp," %s",wrd)!=EOF) {
		M1[wrd]=1;
	}
	fclose(fp);
}

int main() {
	init();
	int t;
	cin >> t;
	FILE *fp;
	REP(tc,1,t) {
		char S[5000],cur[500],prev[500];
		scanf(" %s",S);
		int l=strlen(S);
		int rc=0;
		int ans=0;
		int ind=l,gf=1;
		int i=0;
		strcpy(cur,S);
		int cov=0;
		int iter=0;
		while (1) {
			iter++;
			//	cout << cur << endl;
			if (iter>100000) break;
			if (cov==l) break;
			if (ind==0) {
				ind=strlen(S);
				strcpy(cur,S);
				gf=-1;
			}
			cur[ind--]='\0';
			if (gf==1) {
				int flag=0;
				if (M1[cur]==1) {
					//	cout << cur << endl;
					cov+=strlen(cur);
					flag=2;
					string tmp=S;
					strcpy(cur,tmp.substr(ind+1,l-ind-1).c_str());
					strcpy(S,cur);
					ind=strlen(cur);
					//	break;
				}
			}
			if (gf==-1) {
				char wrd[500];
				int flag=0;
				//	fp=fopen("garbled_email_dictionary.txt","r");
				if (rc==0) {
					tr(M1,it) {
						strcpy(wrd,it->first.c_str());
						if (cmpstr(wrd,cur)==1) {
							//						cout << wrd << endl;
							cov+=strlen(wrd);
							flag=1;
							string tmp=S;
							strcpy(cur,tmp.substr(ind+1,l-ind-1).c_str());
							strcpy(S,cur);
							ind=strlen(cur);
							ans++;
							rc=5;
							gf=1;
							break;
						}
					}
				}
				else rc--;
				//	fclose(fp);
			}
			//if (flag==1 || flag==2) ind=0;
			i++;
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
