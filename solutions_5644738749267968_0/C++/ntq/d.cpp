#include <iostream>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

int main(){
	int T; cin >> T;

	for(int t=0; t<T; t++){
		cout << "Case #" << t+1 << ": ";

		int N; cin >> N;

		set<double> masses_naomi;
		set<double> masses_ken;

		for(int n=0; n<N; n++){
			double mass;
			cin >> mass;
			masses_naomi.insert(mass);
		}

		for(int n=0; n<N; n++){
			double mass;
			cin >> mass;
			masses_ken.insert(mass);
		}

		int points_war = 0;
		int points_deceitful_war = 0;

		set<double> masses_naomi_orig(masses_naomi);
		set<double> masses_ken_orig(masses_ken);

		//play normal war
		while(masses_naomi.size() > 0){
			double max_naomi = *masses_naomi.rbegin();
			masses_naomi.erase(max_naomi);

			set<double>::iterator upper = 
					masses_ken.upper_bound(max_naomi);
			if(upper != masses_ken.end()){
				masses_ken.erase(upper);
			} else {
				points_war ++;
				masses_ken.erase(masses_ken.begin());
			}
		}

		//play deceitful war
		masses_naomi = masses_naomi_orig;
		masses_ken = masses_ken_orig;

		while(masses_naomi.size() > 0){
			double min_ken = *masses_ken.begin();
			
			set<double>::iterator upper = 
					masses_naomi.upper_bound(min_ken);

			if(upper != masses_naomi.end()){
				masses_ken.erase(min_ken);
				masses_naomi.erase(upper);
				points_deceitful_war++;
			} else {
				double min_naomi = *masses_naomi.begin();
				masses_naomi.erase(min_naomi);
				masses_ken.erase(--masses_ken.end());
			}
		}

		cout << points_deceitful_war << " " << points_war << endl;
	}
	return 0;
}
