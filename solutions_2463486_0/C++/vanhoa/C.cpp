#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct NumberString
{
	char s[200];
	int len;
	bool read(FILE* h){
		if(fscanf(h,"%s",s)!=1) return false;
		len=strlen(s);
		return true;
	}
	bool operator<(const NumberString& o) const{
		return len<o.len || (len==o.len && strcmp(s,o.s)<0);
	}
};

vector<NumberString> mResult;

int countAll(const NumberString& a, const NumberString b){
	vector<NumberString>::iterator fr = lower_bound(mResult.begin(),mResult.end(),a);
	vector<NumberString>::iterator to = upper_bound(mResult.begin(),mResult.end(),b);
	//printf("[%s|%d-%s|%d][%s - %s]\n",a.s,a.len,b.s,b.len,fr->s,to->s);
	return max(0,(int)(to-fr));
}

int main(int argc, char *argv[]) {
	NumberString a,b;
	FILE* h=fopen("C.val","r");
	for(;;){
		NumberString x;
		if(x.read(h)){
			mResult.push_back(x);
		}else break;
	}
	printf("sort %d\n",mResult.size());
	//sort(mResult.begin(),mResult.end());
	fclose(h);
	for(int i=0;i<20;i++) printf("%s\n",mResult[i].s);
	printf("start\n");
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int t;scanf("%d",&t);
	for(int ti=1;ti<=t;ti++){
		a.read(stdin);b.read(stdin);
		printf("Case #%d: %d\n",ti,countAll(a,b));
	}
}