#include <bits/stdc++.h>

using namespace std;

string in, out;
int l;

void init(){
	int T;
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		cin >> in;
		l = in.length();
		out = "";
		out += in[0];
		for(int i = 1; i < l; i++){
			string s1 = in[i] + out;
			string s2 = out + in[i];
			if(s1 > s2) out = s1;
			else out = s2;
		}
		printf("Case #%d: %s\n",t,out.c_str());
	}
}

void fread(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int main(){
	fread();
	init();
	return 0;
}