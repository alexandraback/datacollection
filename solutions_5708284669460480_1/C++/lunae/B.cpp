#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	for(int tc=1;tc<=T;tc++){
		int nkeys,wordlen,txtlen; scanf("%d%d%d",&nkeys,&wordlen,&txtlen);
		string keyboard;cin>>keyboard;
		string word;cin>>word;
		if(txtlen<wordlen){printf("Case #%d: %lf\n",tc,0.0);continue;}
		bool can=true;
		for(int i=0;i<wordlen;i++)if(count(keyboard.begin(),keyboard.end(),word[i])==0)can=false;
		if(!can){printf("Case #%d: %lf\n",tc,0.0);continue;}
		double p=1.0;
		for(int i=0;i<wordlen;i++)p*=(double)count(keyboard.begin(),keyboard.end(),word[i])/(double)nkeys;
		int mx_overlap=0;
		for(int i=wordlen-1;i>=1;i--)if(word.substr(i)==word.substr(0,wordlen-i))mx_overlap=wordlen-i;
		int cnt_mx=1+(txtlen-wordlen)/(wordlen-mx_overlap);
		double cnt_expected = (txtlen-wordlen+1)*p;
		printf("Case #%d: %lf\n",tc,(double)cnt_mx-cnt_expected);
		nxt:;
	}
}
