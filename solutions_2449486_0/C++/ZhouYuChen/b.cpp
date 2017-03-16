#include<iostream>
#include<string>
using namespace std;
int n,m,a[100][100],r[100],c[100];
string solve(){
	cin >> n >> m;
	int mr=0,mc=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			cin >> a[i][j];
			if(a[i][j]>a[mr][mc]){
				mr=i;mc=j;
			}
		}
	c[mc]=r[mr]=a[mr][mc];
	for(int i=0;i<n;++i)
		r[i]=a[i][mc];
	for(int j=0;j<m;++j)
		c[j]=a[mr][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		if(a[i][j]!=min(r[i],c[j]))
			return "NO";
	return "YES";
}
int main(){
	int T,tc=1;
	for(cin >>T;tc<=T;++tc)
		cout << "Case #"<<tc<<": " << solve()<< endl;
}
