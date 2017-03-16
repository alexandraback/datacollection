#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

int T;
int A;
int B;
int out;

void get(){
	scanf("%d %d",&A,&B);
	return;
}

int count(int num){
	int ret=0;
	int keta=10;
	set<int> s;
	while(keta<=num){keta*=10;}
	for(int i=10;i*10<=keta;i*=10){
		int cycled = (num % i)*(keta/i)+(num/i);
		if(cycled == num)continue;
		if(cycled < num && cycled >= A)continue;
		if(cycled >= A && cycled <=B && s.count(cycled)==0){
			ret++;
			//fprintf(stderr,"%d %d\n",num,cycled);
			s.insert(cycled);
		}
	}
	return ret;
}

void solve(){
	out=0;
	for(int i=A;i<=B;i++){
		out+=count(i);
	}
	return;
}

int main(int argc,char **argv){
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		get();
		solve();
		printf("Case #%d: %d\n",i+1,out);
	}
}
