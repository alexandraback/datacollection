#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>

using namespace std;

string d[20];
int mask[20][60];
int mk[30];
int ch[20];
int nm[20];

int main(){
	d[0]="ZERO";
	d[1]="ONE";
	d[2]="TWO";
	d[3]="THREE";
	d[4]="FOUR";
	d[5]="FIVE";
	d[6]="SIX";
	d[7]="SEVEN";
	d[8]="EIGHT";
	d[9]="NINE";
	for(int i=0;i<=9;i++){
		for(int j=0;j<d[i].size();j++){
			mask[i][d[i][j]-'A']++;
		}
	}

	ch[0]='Z'-'A';
	nm[0]=0;

	ch[1]='W'-'A';
	nm[1]=2;

	ch[2]='G'-'A';
	nm[2]=8;

	ch[3]='X'-'A';
	nm[3]=6;

	ch[4]='H'-'A';
	nm[4]=3;

	ch[5]='R'-'A';
	nm[5]=4;

	ch[6]='F'-'A';
	nm[6]=5;

	ch[7]='O'-'A';
	nm[7]=1;

	ch[8]='S'-'A';
	nm[8]=7;

	ch[9]='N'-'A';
	nm[9]=9;


	int tt;
	cin>>tt;
	for(int ii=0;ii<tt;ii++){
		string S;
		cin>>S;
		memset(mk,0,sizeof(mk));
		for(int i=0;i<S.size();i++){
			mk[S[i]-'A']++;
		}
		vector<int> digits;
		for(int i=0;i<=9;i++){
			while(mk[ch[i]]>0){
				digits.push_back(nm[i]);
				for(int j=0;j<30;j++){
					mk[j]-=mask[nm[i]][j];
				}
			}
		}
		for(int i=0;i<30;i++){
			if(mk[i]>0){
				cerr<<"ERROR"<<endl;
			}
		}
		sort( digits.begin(),digits.end());
		cout<<"Case #"<<ii+1<<": ";
		for(int i=0;i<digits.size();i++){
			cout<<digits[i];
		}cout<<endl;
	}


}
