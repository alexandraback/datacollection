#include <iostream>
#include <unordered_set>
#include <map>


using namespace std;


int main(){

	int tc;
	cin>>tc;
	int n;
	
	
	for(int i = 1; i <= tc; i++){
		cin>>n;
		map<int,int> hashmap;
		int a;
		int s = (n + n-1)*n;
		while(s--){
			cin>>a;
			hashmap[a]++;
		}
		string res = "";
		for(map<int,int>::iterator it = hashmap.begin(); it != hashmap.end(); it++){
			
			if((it->second % 2) != 0){
				
				res += to_string(it->first) + " ";
			}

		}


		cout<<"Case #"<<to_string(i)<<": "<<res<<endl;

	}
	

}

