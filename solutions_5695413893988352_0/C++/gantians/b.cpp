#include <iostream>
#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

char ch[110];
int a[200];
int ans1,ans2;
string s1,s2;
int now;
vector<int> v1,v2;


void gao1(int x){
	int tmp=now;
	if (x==s1.length()) v1.push_back(now);
		else{
			if (s1[x]=='?'){
				for (int i=0;i<10;i++){
					now=now*10+i;
					gao1(x+1);
					now=tmp;
				}
			}else{
				now = now*10+s1[x]-'0';
				gao1(x+1);
				now=tmp;
			}
		}
}

void gao2(int x){
	int tmp=now;
	if (x==s2.length()) v2.push_back(now);
		else{
			if (s2[x]=='?'){
				for (int i=0;i<10;i++){
					now=now*10+i;
					gao2(x+1);
					now=tmp;
				}
			}else{
				now = now*10+s2[x]-'0';
				gao2(x+1);
				now=tmp;
			}
		}
}


int main(){
	int T;
	cin >> T;
	for (int ti=1;ti<=T;ti++){
		cin >> s1 >> s2;
		
		v1.clear();
		v2.clear();
		now=0;
		gao1(0);
		now=0;
		gao2(0);
		ans1=v1[0];
		ans2=v2[0];
		for (int i=0;i<v1.size();i++)
			for (int j=0;j<v2.size();j++){
				int x=v1[i];
				int y=v2[j];
				if (abs(x-y)<abs(ans1-ans2)){
					ans1=x;
					ans2=y;
				}else
					if (abs(x-y)==abs(ans1-ans2) && x<ans1){
						ans1=x;ans2=y;
					}else
						if (abs(x-y)==abs(ans1-ans2) && x==ans1 && y<ans2){
							ans1=x;ans2=y;
						}
			}
		string ss1="";string ss2="";
		while (ans1){
			ss1+=char(ans1%10+48);
			ans1/=10;
		}
		while (ans2){
			ss2+=char(ans2%10+48);
			ans2/=10;
		}
		int l1=ss1.length();
		int l2=ss2.length();
		for (int i=0;i<s1.length()-l1;i++) ss1+='0';
		//cout<<ss2<<endl;
		for (int i=0;i<s2.length()-l2;i++) ss2+='0';
		//cout<<ss2<<endl;
		reverse(ss1.begin(),ss1.end());
		reverse(ss2.begin(),ss2.end());
		cout << "Case #" <<ti <<": ";
		cout << ss1<<" "<<ss2;
		cout<<endl;
	}
	return 0;
}
