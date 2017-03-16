#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,i,j,ti,linecount,tmp,n;
	cin >> t;
	for(ti=1;ti<=t;++ti){
		vector<int> a(2500,0);
		cin >> n;
		linecount = (2*n)-1;
		for(i=0;i<linecount;++i){
			for(j=0;j<n;++j){
				cin >> tmp;
				a[tmp]++;
			}
		}
		cout << "Case #"<< ti << ": ";
		for(i=0;i<2500;++i){
			if(a[i]%2==1){
				cout << i << " ";
			}
		}
		cout << endl;
	}
}
