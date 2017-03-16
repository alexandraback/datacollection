#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl
#define sp system("pause")

typedef long long ll;

int m[26] = {};

void init() {
	m[0]=24;
	m[1]=7;
	m[2]=4;
	m[3]=18;
	m[4]=14;
	m[5]=2;
	m[6]=21;
	m[7]=23;
	m[8]=3;
	m[9]=20;
	m[10]=8;
	m[11]=6;
	m[12]=11;
	m[13]=1;
	m[14]=10;
	m[15]=17;
	m[16]=-1;//16, 25
	m[17]=19;
	m[18]=13;
	m[19]=22;
	m[20]=9;
	m[21]=15;
	m[22]=5;
	m[23]=12;
	m[24]=0;
	m[25]=-1;//16, 25
	
	m[16]=25;
	m[25]=16;
}

string s;

int main() {
	init();
	freopen("A-input.txt", "r", stdin);
	freopen("A-out.txt", "w", stdout);
	int n;
	cin>>n;getline(cin, s);
	for(int k = 1; k <= n; ++k){
		getline(cin, s);
 			int l = s.size();
			for(int i = 0; i < l; ++i) {
				if(s[i] <= 'z' && s[i] >= 'a') {
					s[i] = m[s[i]-'a']+'a';
				}
			}
			cout<<"Case #"<<k<<": ";
			cout<<s<<endl;
	}
}