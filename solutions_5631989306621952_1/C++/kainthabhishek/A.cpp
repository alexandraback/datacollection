#include<bits/stdc++.h>
using namespace std;
#define Int long long
#define p 1000000007
int main(){
	int t,i,j;char str[1005];
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>str;deque<char> D;
		D.push_front(str[0]);
		for(j=1;str[j]!='\0';j++){
			if(D.front()<=str[j]){
				D.push_front(str[j]);
			}else{
				D.push_back(str[j]);
			}
		}
		printf("Case #%d: ",i);
		while(!D.empty()){
			cout<<D.front();
			D.pop_front();
		}cout<<endl;
	}
	return 0;
}