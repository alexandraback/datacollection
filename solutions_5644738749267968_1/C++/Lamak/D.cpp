#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>

using namespace std;

void print_list(list<float> l) {
	for (list<float>::iterator i=l.begin(); i!=l.end(); i++) {
		cout<<*i<<" ";
	}
	cout<<"\n";
}

int main () {
	
	ifstream in ("D-large.in");
    freopen("large.out","w",stdout);
	
	int T; in>>T;
	
	for (int t=0; t<T; t++) {
		
		int N; in>>N;
		
		list<float> naomi;
		list<float> ken;
		
		float temp;
		for (int i=0; i<N; i++) {in>>temp; naomi.push_back(temp);}
		for (int i=0; i<N; i++) {in>>temp; ken.push_back(temp);}
		
		naomi.sort();
		ken.sort();
		list<float> ken_dup(ken.begin(), ken.end());
		
		/*print_list(naomi);
		print_list(ken);
		cout<<endl;*/
		
		// WAR
		int round = 0;
		int naomi_pts = 0, ken_pts=0;
		for (list<float>::iterator i=naomi.begin(); i!=naomi.end(); i++) {
			for (list<float>::iterator j=ken.begin(); j!=ken.end(); j++) {
				if (*j>*i) {
					// Kens point
					ken_pts++;
					j = ken.erase(j);
					break;
				}
			}
			if (++round != naomi_pts + ken_pts) {
				//Naomis point
				ken.pop_back();
				naomi_pts ++;
			}
		}
		
		int naomi_pts_war = naomi_pts;
		
		// DECEITFUL WAR
		naomi_pts=0;
		ken=ken_dup;
		
		for (list<float>::iterator i=naomi.begin(); i!=naomi.end(); i++) {
			if (*i < ken.front()) {
				// Kens point
				ken.pop_back();
			} else {
				naomi_pts++;
				ken.pop_front();
			}
		}
		
		cout<<"Case #"<<t+1<<": "<<naomi_pts<<" "<<naomi_pts_war<<"\n";
		
	}
	
	return 0;
}

