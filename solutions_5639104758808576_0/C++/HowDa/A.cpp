#include<iostream>
using namespace std;

int main() {
	int testcases, temp;
	cin>>testcases;
	temp=testcases;
	while(testcases--) {
		int ans=0, num=0, line_int[2000];
		string line;
		cin>>num;
		cin>>line;
		line_int[0]=0;
		for(int i=1; i<=num; i++) {
			line_int[i]=line_int[i-1]+(int)((char)line[i-1]-'0');
			if ((char)line[i]!='0' && i > line_int[i]) {
				ans=ans+i- line_int[i];
				line_int[i]=i;
			}
		}
		cout<<"Case #"<<temp-testcases<<": "<<ans<<endl;
	}
	return 0;
}
