#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string s;
int Q;
int cnt[256];
int res[10];

void update(string s,int c){
	int len=s.size();
	for (int i=0;i<len;i++)
		cnt[s[i]]-=c;
}
int main(){
	freopen("i.txt","r",stdin);
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cin>>s;
		cout<<"Case #"<<testcase<<": ";
		memset(cnt,0,sizeof(cnt));
		memset(res,0,sizeof(res));
		for (int i=0;i<s.size();i++){
			cnt[s[i]]++;
		}
		res[0]=cnt['Z'];
		update("ZERO",res[0]);
		res[2]=cnt['W'];
		update("TWO",res[2]);
		res[8]=cnt['G'];
		update("EIGHT",res[8]);
		res[6]=cnt['X'];
		update("SIX",res[6]);
		res[7]=cnt['S'];
		update("SEVEN",res[7]);
		res[5]=cnt['V'];
		update("FIVE",res[5]);
		res[4]=cnt['F'];
		update("FOUR",res[4]);
		res[9]=cnt['I'];
		update("NINE",res[9]);
		res[3]=cnt['R'];
		update("THREE",res[3]);
		res[1]=cnt['O'];
		update("ONE",res[1]);
		for (int i=0;i<10;i++){
			for (int j=0;j<res[i];j++)
				cout<<i;
		}
		cout<<endl;
		for (int i=0;i<256;i++)
			if (cnt[i]){
				cout<<char(i)<<" "<<cnt[i]<<endl;
			}
	}
	return 0;
}
