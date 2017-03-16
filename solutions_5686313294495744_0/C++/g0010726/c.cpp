#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void exe();
int main(void)
{	
	int T;	cin >> T;
	for(int caseNum=1; caseNum<=T ; ++caseNum){
		cout << "Case #" << caseNum << ": ";
		exe();
		cout << endl;	
	}
	return 0;
}

void exe()
{
	map<string, int> ma, mb;
	int n; cin >> n;
	string a[1000], b[1000];
	for(int i=0;i<n;++i){
		cin >> a[i] >> b[i];
		++ma[a[i]];++mb[b[i]];
	}
	int sum = 0;
	for(int i=0;i<n;++i){
		auto &na = ma[a[i]], &nb=mb[b[i]];
		if(na>1 && nb>1){
			++sum;
			--na; --nb;
		}
	}
	cout << sum;
}
