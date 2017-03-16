#include<bits/stdc++.h>
#include <iostream>
using namespace std;
/*bool cmp(pair<int, int> a, pair<int,int> b){
	if(a.first!=b.first)
		return (a.first<b.first);
	else
		return (a.second<b.second);
}*/
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("sheep-large-output.txt", "w", stdout);
	int T,N;
	int temp;
	int i,j,k;
	int rem;
	
	cin>>T;
	for(i=1;i<=T;i++){
		vector <int> digits (10, 0);
		cin>>N;
		if(N==0){
			cout<<"Case #"<<i<<": INSOMNIA"<<endl;
			continue;
		}
		for(j=1;;j++){
			temp = j*N;
			while(temp!=0){
				rem = temp%10;
				digits[rem]=1;
				temp = temp/10;
			}
			for(k=0;k<10;k++){
				if(digits[k]==0)
					break;
			}
			if(k == 10){
				cout<<"Case #"<<i<<": "<<j*N<<endl;
				break;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
