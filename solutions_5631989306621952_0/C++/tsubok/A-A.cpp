#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;	

	for(int i=0;i<n;i++){
		string x;
		cin >> x;
		char head[100], tail[100];
		
		int h=0, t=0;
		head[h++] = x[0];
		for(int j=1;j<x.length();j++){
			if(x[j] < head[h-1]) tail[t++] = x[j];
			else head[h++] = x[j];
		}
		tail[t++] = '\0';
		while(h > 0) cout << head[--h];
		cout << tail << endl;
	}
	
	return 0;
}