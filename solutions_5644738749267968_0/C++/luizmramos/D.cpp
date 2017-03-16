#include <stdio.h>
#include <algorithm>
#include <set>
#define EPS 1.0e-10
int t;
std::set<double>naomi;
std::set<double> ken;
std::set<double> naomi2;
std::set<double> ken2;

int main(){
	scanf("%d",&t);
	for(int xxx=0;xxx<t;xxx++){
		int n;
		naomi.clear();
		ken.clear();
		naomi2.clear();
		ken2.clear();
		scanf("%d",&n);
		double x;
		for(int i =0;i<n;i++){
			scanf("%lf",&x);
			naomi.insert(x);
			naomi2.insert(x);
		}
		for(int i =0;i<n;i++){
			scanf("%lf",&x);
			ken.insert(x);
			ken2.insert(x);
		}
		//war
		int points=0;
		for(int turn=0;turn<n;turn++){
			std::set<double>::iterator naomiBlock = naomi.begin();
			std::set<double>::iterator kenBlock = ken.lower_bound(*naomiBlock);
			if(kenBlock == ken.end())kenBlock = ken.begin();
			if(*naomiBlock>*kenBlock){
				points++;
			}
			//printf("%d %lf %lf\n",turn, *naomiBlock, *kenBlock );
			naomi.erase(naomiBlock);
			ken.erase(kenBlock);
		}
		
		int points2=0;
		for(int turn=0;turn<n;turn++){
			std::set<double>::iterator naomiBlock = naomi2.begin();
			std::set<double>::iterator kenBlock = ken2.begin();
			//printf("%d %lf ",turn, *naomiBlock);
			if(*naomiBlock>*kenBlock){
				points2++;
				//printf("%lf\n", *kenBlock);
				ken2.erase(kenBlock);
			}
			else {
				//printf("%lf\n", *ken2.rbegin());
				ken2.erase(ken2.lower_bound((*ken2.rbegin())-EPS));
			}
			
			naomi2.erase(naomiBlock);
		}
		printf("Case #%d: %d %d\n",xxx+1,points2, points);
	}
}