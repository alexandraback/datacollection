#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL SQN=10000000;
char buf[111];
bool ispal(LL x){
	sprintf(buf,"%I64d",x);
	int len=strlen(buf);
	for(int i=0;i<len/2;i++){
		if(buf[i]!=buf[len-i-1]) return false;
	}
	return true;
}
vector<LL> table;
int T;
int casno=1;
int main() {
	for(LL i=0;i<SQN;i++) if(ispal(i)&&ispal(i*i)) table.push_back(i*i);
	cin>>T;
	while(T--){
		LL a,b;
		cin>>a>>b;
		printf("Case #%d: ",casno++);
		cout<<upper_bound(table.begin(),table.end(),b)-lower_bound(table.begin(),table.end(),a)<<endl;
	}


 	return 0;
}
