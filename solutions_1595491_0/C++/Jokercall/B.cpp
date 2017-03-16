#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int T;
int S;
int p;
int n;
int t[200];

FILE *fp = fopen("out.out","w");



int smax(int s){
	if(s==0) return 0;
	return (s+4)/3;
}
int nonsmax(int s){
	if(s==0) return 0;
	return (s+2)/3;
}
void input(){
	int i;
	cin>>n>>S>>p;
	for(i=0; i< n;i++)
		cin>>t[i];
}
void solve(){
	sort(t,t+n);
	int i;
	int sc = S;
	int cnt=0;
	for(i = n-1; i>=0 ;i--){
		if( nonsmax( t[i] ) >= p ){
			cnt++;
		}
		else if( smax( t[i] ) >= p ){
			if( sc > 0){
				sc--;
				cnt++;
			}
			else
				break;
		}
		else
			break;
	}
	fprintf(fp,"%d\n",cnt);
}

int main(){
	char dummy[100];
	cin>>T;
	for(int k=0; k<T;k++){
		input();
		fprintf(fp,"Case #%d: ",k+1);
		solve();
	}
}