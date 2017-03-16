#include<cstdio>
#include<algorithm>
#include<list>

using namespace std;

int T;
int n;
double Naomi[1000];
double Ken[1000];
list<double> Naomi_d;
list<double> Ken_d;

void process(){
	int dwn = 0;
	int wn = 0;
	int ks=0, kl=n-1;

	// Play Deceitful
	sort(Naomi, Naomi+n);
	sort(Ken, Ken+n);

	Naomi_d.clear();
	Ken_d.clear();

	for(int i=0;i<n;i++){
		Naomi_d.push_back(Naomi[i]);
		Ken_d.push_back(Ken[i]);
	}

	while(!Naomi_d.empty()){
		double a = *Naomi_d.rbegin(), b = *Ken_d.rbegin();
		if(*Naomi_d.rbegin() < *Ken_d.rbegin()){
			// Ken win, but naomi use smallest one
			Naomi_d.pop_front();
			Ken_d.pop_back();
		}
		else{
			// Naomi bids largest one
			// Ken knows that he couldn't win
			// He will use smallest

			double tmp = *Ken_d.begin();
			list<double>::iterator iterPos;
			for(iterPos = Naomi_d.begin(); 
				iterPos != Naomi_d.end(); ++iterPos){
				if(*iterPos > tmp){
					break;
				}
			}

			Ken_d.pop_front();
			Naomi_d.erase(iterPos);

			dwn++;
		}
	}

	for(int i=n-1;i>=0;--i){
		if(Naomi[i] > Ken[kl]){
			ks++;
			wn++;
		}
		else{
			kl--;
		}
	}

	printf("%d %d\n",dwn,wn);
}

int main(void){
	int i,t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lf",&Naomi[i]);
		}
		for(i=0;i<n;i++){
			scanf("%lf",&Ken[i]);
		}
		printf("Case #%d: ", t);
		process();
	}
	return 0;
}