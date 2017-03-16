#include<iostream>
#include <string.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t=1; t<=T; t++) {
		string str;
		cin>>str;
		char p = str[0];
                int i = 1;
		while(str[i] != '\0') {
			if(str[i] >= p) {
				p = str[i];
				for(int j=i; j>0; j--)
					str[j] = str[j-1];
				str[0] = p;
			}
			i++;
		}
	cout<<"Case #"<<t<<": "<<str<<endl;
	}
}
