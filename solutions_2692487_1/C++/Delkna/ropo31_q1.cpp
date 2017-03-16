#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	ifstream input;
	input.open("A-large.in");
	ofstream output;
	output.open("output1L.txt");

	int test_num;
	input>> test_num;
	
	for(int loop=0; loop<test_num; loop++){
		long long int player_size;
		int N;
		input>>player_size>>N;

		//
		cout<<player_size<<" "<<N<<endl;
		//

		vector<long long int> data;
		long long int sc;
		for(int temp=0; temp<N; temp++){
			input>>sc;
			data.push_back(sc);

			//
			cout<<sc<<" ";
			//

		}
		sort(data.begin(), data.end());

		//
		cout<<endl;
		//

		//	player_size, data, N
		////
		//
		while(1){
			if(data.size() == 0)
				break;
			sc = data.front();
			if(player_size > sc){
				player_size += sc;
				data.erase(data.begin());
			}
			else
				break;
		}
		int list_num = data.size();
		if(list_num == 0){
			output<<"Case #"<<loop+1<<": "<<"0"<<endl;
			cout<<0<<endl;
		}
		else{
			int t = 0;
			int count = data.size();
			long long int limit = data.back();
			int norm_size = data.size();
			sc = player_size;
			while(sc <= limit && data.size() != 0){
				sc += sc-1;
				t++;
				
				while(data.size() != 0){
					if(sc > data.front()){
						sc += data.front();
						data.erase(data.begin());
					}
					else
						break;
				}
				if((t+data.size()) <= count)
					count = t+data.size();
				if(t > norm_size)
					break;
			}
			output<<"Case #"<<loop+1<<": "<<count<<endl;
			cout<<count<<endl;
		}
	}

	input.close();	
	

	return 0;
}