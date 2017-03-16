#include <cstdio>
#include <cstring>
#include <list>
using std::list;

int main(){
	int T;
	scanf("%d",&T);
	for(int Case = 1;Case<=T;Case++){
		char s[1086];
		scanf("%s",s);
		printf("Case #%d: ", Case);
		int n = strlen(s);
		char max = 0;
		list<char> newS;
		for(int i=0;i<n;i++){
			if(s[i]>=*newS.begin()) newS.push_front(s[i]);else newS.push_back(s[i]);
		}
		for(list<char>::iterator i = newS.begin();i!=newS.end();++i){
			putchar(*i);
		}
		putchar('\n');
	}
}