#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdint.h>
#include<map>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

/*
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("test.txt");
	out.open("out.txt");
	in>>CaseNum;
	for(int Case=0;Case<CaseNum;Case++){



	out<<"Case #"<<Case+1<<":";
	}
	return 0;
}
*/


char train[200][2];
unsigned int flag[200];
int num[200];
unsigned int p2[30]={0};
unsigned int pp[104]={0};
unsigned int R=1000000007;
int N;

int findc(char c){
	int n=0;
	for(int i=0;i<N;i++){
		if(num[i]==1&&train[i][0]==c){
			n++;
			num[i]=0;
		}
	}
	return n;
}
int findc1(char c){
	int n=0;
	unsigned int f=p2[c-'a'];
	for(int i=0;i<n;i++){
		if(num[i]>0&&(flag[i]&f))n++;
	}
	return n;
}


int fnal[200]={0};
int gotId[200]={0};
int findans(int lvl,unsigned int fl,char ed){
	unsigned int n=0;
	char c;
	if(lvl>=N)
		return 1;
	unsigned int f=0;
	for(int i=0;i<N;i++){
		if(!gotId[i]){
			if((fl&flag[i])&&ed!=train[i][0])continue;
					f=fl&flag[i]&(~p2[ed-'a']);
			if(f!=0)continue;
	//		if(lvl==0&&train[i][0]>train[i][1]){
	//			c=train[i][1];train[i][1]=train[i][0];train[i][0]=c;
	//		}
			gotId[i]=1;
			fnal[lvl]=i;
			n+=findans(lvl+1,fl|flag[i],train[i][1]);
			n=n%R;
			gotId[i]=0;
		}

	}
	return n;
}

int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	//in.open("test.txt");
	in.open("B-small-attempt3.in");
	//in.open("A-large.in");
	out.open("out.txt");
	in>>CaseNum;
	p2[0]=1;
	for(int i=1;i<28;i++){
		p2[i]=(p2[i-1]<<1);
	}
	pp[0]=1;
	for(int i=1;i<104;i++){
		pp[i]=uint64_t(pp[i-1])*uint64_t(i)%uint64_t(R);
	}

	
	char c,pc;
	char buf[3];
	unsigned int f;
	bool IM;
	char cur[2];
	unsigned int fcur;
	int nc;
	int ans;
	for(int Case=0;Case<CaseNum;Case++){
		if(Case==49)
			Case=Case;
		
		in>>N;
		IM=false;
		in.get(c);
		for(int i=0;i<N;i++){
			train[i][0]=0;
			train[i][1]=0;
			flag[i]=0;
			num[i]=0;
			pc=0;
			do{
				in.get(c);
				if(c==' '||c==10)break;
				if(c<'a'||c>'z')continue;
				f=p2[c-'a'];
				if(flag[i]&f){
					if(pc!=c)IM=true;
					continue;
				}
				else{
					flag[i]=(flag[i]|f);
					num[i]++;
					if(train[i][0]==0)train[i][0]=c;
				}

				pc=c;

			}while(c!=' ');
			train[i][1]=pc;

		}


		ans=findans(0,0,0);
		

		out<<"Case #"<<Case+1<<": "<<ans<<endl;
	}
	return 0;
}

