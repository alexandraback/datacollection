#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	int casos=1;
	while (t--){
	
		printf("Case #%d: ",casos++);
		string x;
		cin>>x;
		deque <char> y;
		
		y.push_back(x[0]);
		
		for (int i=1;i<x.size();++i){
			if (x[i]>=y.front()){
				y.push_front(x[i]);
			}else{
				y.push_back(x[i]);
			}
		}
		
		for (int i=0;i<y.size();++i){
			printf("%c",y[i]);
		}
		
		printf("\n");
	}

	return 0;
}
