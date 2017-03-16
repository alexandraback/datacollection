#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	while(cin >> T){
		for(int i=1;i<=T;i++){
			int in,ans=0,stand=0;
			char shy;
			cin >> in;
			for(int j=0;j<in+1;j++){
				cin >> shy;
				int n=shy-'0';
				if(stand<j && n>0) {
				   ans+=j-stand;
				   stand=j;
				}
				stand+=n;
			}
			printf("Case #%d: %d\n",i,ans);
		}
		
	}
	return 0;
}
