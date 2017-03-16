#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cs=1;cs<=t;++cs){
		int mas[10][10];
		int b,m;
		cin>>b>>m;
		for(int i=1;i<=b;++i){
			for(int j=1;j<=b;++j){
				mas[i][j]=0;
			}
		}
		mas[1][b]=1;
		--m;
		if(b>2){
			int i=2;
			while(m>0&&i<b){
				mas[1][i]=1;
				mas[i][b]=1;
				++i;
				--m;
			}
		}
		if(b>3){
			int i=2,j=3;
			while(m>0&&i<b-1){
				mas[j][i]=1;
				++j;
				if(j==b){
					++i;
					j=i+1;
				}
				--m;
			}
		}
		if(m>0){
			cout<<"Case #"<<cs<<": IMPOSSIBLE"<<endl;
		}else{
			cout<<"Case #"<<cs<<": POSSIBLE"<<endl;
			for(int i=1;i<=b;++i){
				for(int j=1;j<=b;++j){
					cout<<mas[i][j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}