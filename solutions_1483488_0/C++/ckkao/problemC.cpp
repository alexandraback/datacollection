#include<iostream>
#include<set>
#include<fstream>
using namespace std;

void rotate(char* s) {
	char c = s[0];
	int len = strlen(s)-1;
	for(int i=0; i<len; ++i) s[i] = s[i+1];
	s[len] = c;
}

bool same(char* s) {
	int len = strlen(s);
	int count = 0;
	for(int i=0;s[i]==s[i+1];++i,++count) ;
	return (count==len-1) ? true : false;
}

int main() {
	int nCount;
	int min;
	int max;
	char current[20]={0};
	set<pair<int,int>> list;
	ifstream cin("input");
	ofstream cout("output");
	
	
	cin >> nCount;
	for(int i=1; i<=nCount; ++i) {
		cin >> min >> max;
		list.clear();
		for(int j=min; j<=max; ++j) {
			sprintf(current,"%d",j);
			if(same(current)) continue;

			int len = strlen(current);
			for(int k=1; k<len; ++k) {
				rotate(current);
				int number = atoi(current);
				if(number <= max && number >= min && number > j) { list.insert(make_pair(j,number)); }
			}
		}
		cout<<"Case #"<<i<<": "<<list.size()<<endl;
	}
	//system("pause");
}


