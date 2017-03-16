#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int main(){
	int T;
	char str[1001];
	deque <char> list;
	cin >> T;
	for(int t = 1;t <= T;t ++){
		memset(str,' ',1001);
		cin >> str;
		list.clear();
		int l = strlen(str);
		for(int i = 0;i < l;i ++){
			if(list.empty()){
				list.push_back(str[i]);
			}
			else{
				bool found = false;
				for(int j = 0;j < list.size();j ++){
					
					if(str[i] != list[j]){
						if(str[i] > list[j]){
							list.push_front(str[i]);
						}
						else {
							list.push_back(str[i]);
						}
						found = true;
						break;
					}
				}
				if(!found)
				list.push_back(str[i]);
			}
		}
		cout << "Case #" << t << ": ";
		for(int i = 0;i < l;i ++){
			cout << list[i];
		}
		cout << endl;
	}
	
	return 0;
}
