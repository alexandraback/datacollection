// By Aman Jain(jainaman224)
// 16/4/16

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main(){
	int array[2501]={0};
	set <int> ans;
	set <int>::iterator it;
	int i,t,x,j,k,l;
	cin >> t;
	for(i=1;i<=t;i++){
		ans.clear();
		cin >> x;
		for(j=1;j<2*x;j++){
			for(k=0;k<x;k++){
				cin >> l;
				array[l]++;
			}
		}
		for(j=1;j<2501;j++){
			if(array[j]%2==1)
				ans.insert(j);
			array[j]=0;
		}
		cout << "Case #" << i << ": ";
		for(it=ans.begin();it!=ans.end();++it)
    		cout << *it << " ";
		cout << endl;
	}
	return 0;
}