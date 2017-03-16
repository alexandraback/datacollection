#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void exe();
int main(void)
{	
	int T;	cin >> T;
	for(int caseNum=1; caseNum<=T ; ++caseNum){
		cout << "Case #" << caseNum << ": ";
		exe();
		cout << endl;	
	}
	return 0;
}

void exe()
{
	int a[3], b[3];
	string str; cin >> str;
	int l = str.size();
	for(int i=0;i<l;++i){
		if(str[i] == '?') a[i] = -1;
		else a[i] = str[i]-'0';
	}
	cin >> str;
	for(int i=0;i<l;++i){
		if(str[i] == '?') b[i] = -1;
		else b[i] = str[i]-'0';
	}
	int mind = 99999, ma = 99999, mb= 99999;
	int bound=1;
	for(int i=0;i<l;++i) bound*=10;
	for(int na=0;na<bound;++na)
		for(int nb=0;nb<bound;++nb){
			int i=na;
			if(a[l-1]==-1 || a[l-1]==i%10){
				i/=10;
			if(l<=1 ||  a[l-2]==-1 || a[l-2]==i%10 ){
				i/=10;
			if(l<=2 ||  a[l-3]==-1 || a[l-3]==i%10 ){
				i=nb;
			if(b[l-1]==-1 || b[l-1]==i%10){
				i/=10;
			if(l<=1 ||  b[l-2]==-1 || b[l-2]==i%10 ){
				i/=10;
			if(l<=2 ||  b[l-3]==-1 || b[l-3]==i%10 ){
				if(na>=nb){
					if(na-nb < mind) mind = na - nb, ma=na,mb=nb;}
				else if(nb-na < mind) mind = nb - na, ma=na,mb=nb;
			}}}}}}
		}
	if(l==1) cout << ma <<' '<<mb;
	else if(l==2) printf("%02d %02d",ma,mb);
	else printf("%03d %03d",ma,mb);
}
