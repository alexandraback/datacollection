#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char map[26]={'y','h','e','s','o',
              'c','v','x','d','u',
              'i','g','l','b','k',
              'r','z','t','n','w',
              'j','p','f','m','a',
              'q'};
int T;
char input[128];
char out[128];

void get(){
	gets(input);
	//fprintf(stderr,"%s\n",input);
}

void solve(){
	for(int i=0;input[i]!='\0';i++){
		if(input[i]==' ')
			{out[i]=' ';}
		else
			{out[i]=map[input[i]-'a'];
	}
		out[strlen(input)]='\0';
	}
}

int main(int argc,char **argv){
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		get();
		solve();
		printf("Case #%d: %s\n",i+1,out);
	}
}
