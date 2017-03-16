#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <functional>

using namespace std;
int main()
{
	freopen("C-small-attempt0.in" ,"r" ,stdin);
	freopen("test.out" ,"w" ,stdout);
	int T ,N;
	int data[512];
	cin >> T;
	for (int t = 1 ;t <= T ;++t){
		cin >> N;
		for (int i = 0 ;i < N ;++i)
			cin >> data[i];
		map<int ,int> mmap;
		vector< vector<int> > table;
		int x ,y;
		bool ok = false;
		for (int i = 1 ;i < (1<<20) && !ok ;i++){
			int sum = 0 ;
			for (int j = 0 ;j < 20 ;++j){
				if (((1<<j) & i) != 0)
					sum += data[j];
			}
			map<int ,int>::iterator it = mmap.find(sum);
			if (it != mmap.end()){
				vector<int> v = table[it->second];
				for (int j = 0 ;j < v.size() ;j++){
					if ((v[j] & i) == 0){
						ok = true;
						x = i;
						y = v[j];
					}
				}
				table[it->second].push_back(i);
				//mmap.insert(make_pair(sum,v));
				
			}else{
				mmap.insert(make_pair(sum ,table.size()));
				vector<int> v;
				v.push_back(i);
				table.push_back(v);
			}
		}
		if (ok){
			cout << "Case #" <<t <<":" << endl;
			for (int j = 0 ;j < 20 ;++j){
				if (((1<<j) & x) != 0)
					cout << data[j] << " ";
			}
			cout << endl;
			for (int j = 0 ;j < 20 ;++j){
				if (((1<<j) & y) != 0)
					cout << data[j] << " ";
			}
			cout << endl;
		}else{
			cout << "Case #" <<t <<":" << endl;
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
