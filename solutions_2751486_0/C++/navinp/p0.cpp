#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int N,L;

char s[200];

bool isgood(int x,int y)
{
	int i,j;
	for(i=x;i+N-1<=y;i++) {
	   bool good=true;
	   for(j=0;(j<N) && (i+j<L);j++)
		if((s[i+j]=='a') || (s[i+j]=='e') || (s[i+j]=='i') || (s[i+j]=='o') || (s[i+j]=='u'))
			good=false;


	if(good) return true;
		   
	}
	return false;
}

int main()
{
	int no,i,j;
	int tc=1;
	scanf(" %d",&no);
	while(no--){
		scanf(" %s %d",s,&N);
		L=strlen(s);

		long long cnt=0;
		for(i=0;i<L;i++)
		for(j=i+N-1;j<L;j++)
		if(isgood(i,j)) cnt++;

		printf("Case #%d: %lld\n",tc++,cnt);
		
		
	}
	return 0;
}
