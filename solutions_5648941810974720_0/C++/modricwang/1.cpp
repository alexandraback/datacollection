#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string s;
int T;
int cnt[255],su[10];

int main() {
	freopen("A.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for (int ii=1; ii<=T; ii++) {
		cin>>s;
		memset(cnt,0,sizeof(cnt));
		memset(su,0,sizeof(su));
		for (int i=0; i<s.length(); i++) {
			cnt[s[i]]++;
		}
		cout<<"Case #"<<ii<<": ";
		su[0]=cnt['Z'];
		cnt['E']-=su[0];
		cnt['R']-=su[0];
		cnt['O']-=su[0];
		cnt['Z']=0;
		su[8]=cnt['G'];
		cnt['T']-=su[8];
		cnt['E']-=su[8];
		cnt['H']-=su[8];
		cnt['I']-=su[8];
		cnt['G']=0;
		su[6]=cnt['X'];
		cnt['S']-=su[6];
		cnt['I']-=su[6];
		cnt['X']=0;
		su[7]=cnt['S'];
		cnt['N']-=su[7];
		cnt['E']-=su[7];
		cnt['E']-=su[7];
		cnt['V']-=su[7];
		cnt['S']=0;

		su[5]=cnt['V'];
		cnt['F']-=su[5];
		cnt['I']-=su[5];
		cnt['E']-=su[5];
		cnt['V']=0;
		su[9]=cnt['I'];
		cnt['E']-=su[9];
		cnt['N']-=su[9];
		cnt['N']-=su[9];
		cnt['I']=0;
		su[4]=cnt['U'];
		cnt['F']-=su[4];
		cnt['O']-=su[4];
		cnt['R']-=su[4];
		cnt['U']=0;
		su[3]=cnt['H'];
		cnt['T']-=su[3];
		cnt['R']-=su[3];
		cnt['E']-=su[3];
		cnt['E']-=su[3];
		cnt['H']=0;
		su[2]=cnt['W'];
		cnt['T']-=su[6];
		cnt['O']-=su[6];
		cnt['W']=0;
		su[1]=cnt['N'];
		cnt['O']-=su[6];
		cnt['E']-=su[6];

		for (int k=0; k<=9; k++) {
			for (int j=1; j<=su[k]; j++) cout<<k;
		}
		cout<<endl;
	}
}
