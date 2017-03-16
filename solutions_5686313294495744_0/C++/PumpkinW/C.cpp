#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
using namespace std;


int main(){	
    
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("myoutC-small.txt", "w", stdout);
	int T;
	cin >> T;
	int N;
	map<string, int> first;
	map<string, int> last;
	for(int t = 1; t <= T; ++t){
	    cin >> N;
	    first.clear();
	    last.clear();
		string firstname, lastname;
		for(int i = 0; i < N; ++i){
			cin >> firstname >> lastname;
			map<string, int> :: iterator it = first.find(firstname);
			if(it == first.end()){
				first.insert(make_pair(firstname, 1));
			}
			else{
				it->second ++;
			}
			
			it = last.find(lastname);
			if(it == last.end()){
				last.insert(make_pair(lastname, 1));
			}
			else{
				it->second++;
			}
		}	
		
		int maxFirst = 0;
		int maxLast = 0;
		for(map<string, int> :: iterator it = first.begin(); it!=first.end(); ++it){
			maxFirst += it->second -1;
		}
		
		for(map<string, int> :: iterator it = last.begin(); it!=last.end(); ++it){
			maxLast += it->second -1;
		}
        
        int ans = maxLast > maxFirst ? maxFirst : maxLast;
        
		cout << "Case #" << t << ": ";
		cout << ans <<endl;
	}
	
	return 0;
}
