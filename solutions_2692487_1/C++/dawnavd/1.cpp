#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int ans;
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.in");
	fout.open("out");
	int t;
	int m,n;
	fin >> t;
	int cs = 1;
	//cout<<t<<endl;
	while (t--) {
		fin >> m >> n;
		ans = n;
		vector<int> mote;
		int i = 0;
		while (i < n) {
			int temp;
			fin >> temp;
			mote.push_back(temp);
			i++;
		}
		sort(mote.begin(),mote.end());
		i = 0;
		int count = 0;
		unsigned long long size = m;
		while (i < n) {
			if(mote[i] >= size) {
				if(n-i+count < ans) {
					ans = n-i+count;
				}
				if(size == 1) {
					break;
				}
				while (size <= mote[i]) {
					size += size;
					size -= 1;
					//cout<<"s";
					count++;
				}
				size += mote[i];
			}
			else{
				size += mote[i];
			}
			i++;
		}
		if(i == n && count < ans) {
			ans = count;
		}
		fout<<"Case #"<<cs++<<": "<<ans<<endl;
		//cout<<"Case #"<<cs<<": "ans<<endl;
	}
	return 0;
}
