#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
	int count;
	cin >> count;
	for(int i=0; i<count; i++){
		int n;
		cin >> n;
		vector<double> Naomi;
		vector<double> Ken;

		double tmp;
		for(int j=0; j<n; j++){
			cin >> tmp;
			Naomi.push_back(tmp);
		}
		for(int j=0; j<n; j++){
			cin >> tmp;
			Ken.push_back(tmp);
		}
		
		// a copy of Naomi and Ken
		vector<double> Naomi2(Naomi);
		vector<double> Ken2(Ken);
		// War
		int pointsWar = 0;
		sort(Naomi.begin(), Naomi.end());
		sort(Ken.begin(), Ken.end());
		for(int j=0; j<n; j++){
			double naomiChosen = Naomi.at(j);
			vector<double>::iterator it;
			//whether Ken could get this point
			bool get_point = false;
			for(it=Ken.begin();it!=Ken.end();it++){
				if( *it > naomiChosen ){
					get_point = true;
					Ken.erase(it);
					break;
				}
			}
			if(!get_point){
				pointsWar++;
				Ken.erase(Ken.begin());
			}
		}

		//Deceitful War
		int pointsDecdWar = 0;
		
		sort(Naomi2.begin(), Naomi2.end());	
		sort(Ken2.begin(), Ken2.end());
		vector<double>::iterator it;
		for(it=Naomi2.begin(); it<Naomi2.end(); it++){
			if(*it<*Ken2.begin()){
				Ken2.pop_back();
			}else{
				Ken2.erase(Ken2.begin());
				pointsDecdWar++;
			}
		}
		cout << "Case #" << i+1 << ": " << pointsDecdWar << " " 
			<< pointsWar <<endl;
		
	}
	return 0;
}
