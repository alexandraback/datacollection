#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>


using namespace std;




int main(){

	int tc;
	cin>>tc;
	int n;
	
	
	for(int i = 1; i <= tc; i++){
		cin>>n;
		int a;
		
		int arr[n];
		unordered_map<int,int > hashmap;
		unordered_map<int,vector<int> > rev_hashmap;
		unordered_set<int> ans;
		ans.insert(1);

		for(int j = 1; j <= n; j++){
			cin>>a;
			arr[j-1] = a;
			hashmap[j] = a;
			rev_hashmap[a].push_back(j);
		}
		ans.insert(arr[0]);
		a = arr[0];
		bool is_in = false;
		while(n--){
			//7 8 10 10 9 2 9 6 3 3
			//cout<<a<<endl;
			is_in = ans.find(hashmap[a]) != ans.end(); 
			if(is_in){

						
						vector<int> t = rev_hashmap[a];
						for(int y = 0; y < t.size(); y++){
							
							is_in = ans.find(t[y]) != ans.end();
							if(!is_in){
								ans.insert(t[y]);
								a = hashmap[t[y]];
								is_in = false;
								break;
							}

						}
					
			}
			else{
				
				
				ans.insert(hashmap[a]);
				a = hashmap[a];
			}
			

			} 
			
		

		


		cout<<"Case #"<<to_string(i)<<": "<<ans.size()<<endl;
	
	

}
}

