#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#include<string.h>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MN = 2000+10;

char buf[MN];
int cnt[300];
int ans[10];
char db[10][10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

bool f(char c){
	return cnt[c]>0;
}

bool sub(int n){
	for(int i=0;i<strlen(db[n]);i++){
		if(!f(db[n][i]))return false;
	}
	for(int i=0;i<strlen(db[n]);i++){
		cnt[db[n][i]]--;
	}
	ans[n]++;
	return true;
}

void c(int n){
	while(sub(n));
}

void print(){
	for(int i=0;i<10;i++)for(int j=0;j<ans[i];j++)printf("%d",i);
	puts("");
}

int main(){
	freopen("A-small-attempt0.in","r",stdin),freopen("output.txt","w",stdout);
	II(T);
	for(int tc=1;tc<=T;tc++){
		for(int i=0;i<300;i++)cnt[i]=0;
		for(int i=0;i<10;i++)ans[i]=0;

		scanf("%s",buf);
		int len=strlen(buf);
		for(int i=0;i<len;i++)cnt[buf[i]]++;
		c(0); c(2); c(4); c(6); c(5); c(7); c(3); c(8); c(9); c(1);

		printf("Case #%d: ",tc);print();
	}
	return 0;
}