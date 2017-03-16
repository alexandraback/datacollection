#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<climits>
#include<vector>
#include<iterator>
#include<set>

#define fr(i,a,b) for(int i=a; i<b; i++)
#define s(a) scanf("%d", &a)
#define p(a) printf("%d\n", a)
#define w(t) while(t--)
#define pb push_back
#define CLR(a) memset(a, 0, sizeof(a))

using namespace std;

typedef long long int lli;
typedef vector<int> VI;
typedef vector<string> VS;


void solve() {
	

}

int main() {
	int test;
	scanf("%d\n", &test);
	fr(t, 1, test+1) {
		int x, y;
		s(x);	s(y);
		cout<<"Case #"<<t<<": ";
		//char s[1000];
		//char s2[1000];
		//char * ans = (char *)malloc(2000*sizeof(char));
		string s = "";
		string s2 = "";
		string ans = "";
		if(x>0) {
			fr(i,0,x-1) 	cout<<"EW";
			cout<<"E";
		}
		if(x<0) {
			x = -x;
			fr(i,0,x-1) 	cout<<"WE";
			cout<<"W";
		}
		if(y>0) {
			fr(i,0,y-1) 	cout<<"NS";
			cout<<"N";
		}
		if(y<0) {
			y = -y;
			fr(i,0,y-1) 	cout<<"SN";
			cout<<"S";
		}
		cout<<endl;
		//ans = s+s2;
		//ans = strcat(s, s2);
		//int len = s2.length();
		//int len = strlen(ans);
		//cout<<len<<endl;
		//cout<<"Case #"<<t<<": "<<ans<<endl;
		//puts(ans);
		//fr(i,0,len) 	
		//int i;
		//while(ans[i] != '\0')
		//printf("%c", ans[i]);
		//printf("\n");
	}
	return 0;
}
