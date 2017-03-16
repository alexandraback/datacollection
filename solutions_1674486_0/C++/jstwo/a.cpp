#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
int T =0;
std::set<int> data[1000];
bool checked[1000];
void init() {
}

bool check(int n) {
	char tmp[1000];
	if(checked[n] == true) {
		return false;
	}
	else if(data[n].size() ==0) {
		checked[n] = true;
		data[n].insert(n);
		return false;
	}
	else
	{
		memset(tmp, 0, sizeof(tmp));
		for(std::set<int>::iterator i= data[n].begin() ; i != data[n].end();++i) {
			if(check(*i)) {
				return true;
			}
		}
		for(std::set<int>::iterator i= data[n].begin() ; i != data[n].end();++i) { 
			for(std::set<int>::iterator j= data[*i].begin() ; j != data[*i].end();++j) {
				if(tmp[*j] !=0) {
					return true;
				}
				tmp[*j] = 1;
			}
		}
		data[n].clear();
		for(int i =0; i < T;++i) {
			if(tmp[i]) {
				data[n].insert(i);
			}
		}
		checked[n] = true;
		return false;
	}
}
void solve(int c) {
	std::cout << "Case #" << c << ": ";
	for(int i =0; i < T;++i) {
		if(check(i)) {
			std::cout << "Yes\n";
			return;
		}
	}
	std::cout << "No\n";
}
int main(int argc , char** argv)
{
	init();
	
	std::ifstream in(argv[1]);
	int count;
	in >> count;
	for(int i = 1; i <=count;++i) 
	{
		in >> T;
		for(int j =0; j < T;++j) {
			data[j].clear();
			int tmp;
			int sub;
			in >> sub;
			checked[j] = false;
			for(int k =0; k< sub;++k) {
				in >> tmp;
				data[j].insert(tmp -1);
			}
		}
		solve(i);
	}
	return 0;
}
