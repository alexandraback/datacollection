#include<iostream>
#include<fstream>
using namespace std;

char tran[26];
int mark[26];

void gettran(char *s, char *t){
	int i=0;	
	while(s[i]){
		tran[s[i]-'a']=t[i];
		i++;
	}
}

int main(){
	ifstream ins;
	ofstream outs;
	ins.open("A-small-attempt0.in");
	outs.open("lang.out");
	for(int i=0; i<26 ;i++)
		tran[i]=0;
	tran['y'-'a']='a';
	tran['e'-'a']='o';
	tran['q'-'a']='z';
	gettran("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand");
	gettran("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities");
	gettran("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up");
	for(int i=0; i<26; i++)
		mark[i]=0;
	for(int i=0; i<26; i++){
		if(tran[i])
			mark[tran[i]-'a']=1;
	}
	for(int i=0; i<26; i++){
		if(mark[i]==0)
			tran[25]=i+'a';
	}
	int n;
	char s[200];
	ins >> n;	
	ins.ignore();
	for(int i=0; i<n; i++){
		ins.getline(s, 200);	
		outs << "Case #" << i+1 << ": ";
		for(int j=0; s[j]; j++){
			if(s[j]==' ')
				outs << ' ';
			else
				outs << tran[s[j]-'a']; 
		}
		outs << endl;
	}
	return 0;
}
