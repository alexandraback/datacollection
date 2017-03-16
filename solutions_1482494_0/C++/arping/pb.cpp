#include <iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstdlib>
using namespace std;
class Level{public:
	int m_state;
	int m_star1;
	int m_star2;
	Level(){m_state=m_star1=m_star2=0;};
	int Eat(int k){
		if(k<=m_state)return 0;
		int star=k-m_state;
		m_state=k;
		return star;
	}
};

int main() {
	int ts;cin>>ts;
	for(int t=0;t<ts;t++){
		int n;cin>>n;vector<Level> lvs(n);
		for(int k=0;k<n;k++){
				cin>>lvs[k].m_star1>>lvs[k].m_star2;
		}
		int stars=0;
		int ans=0;
		while(true){
			bool modified=false;
			for(int k=0;k<n;k++){
				int diff=0;if(stars>=lvs[k].m_star2)diff=lvs[k].Eat(2);
				if(diff){
					stars+=diff;ans++;modified=true;
				}
			}
			if(modified){
				continue;
			}

			int cand=-1,max2=-1;;
			for(int k=0;k<n;k++){
				if(lvs[k].m_state>=1)continue;
				if(stars<lvs[k].m_star1)continue;
				if(lvs[k].m_star2>max2){
					cand=k;max2=lvs[k].m_star2;
				}
			}
			if(cand==-1)break;
			int diff=lvs[cand].Eat(1);
			if(diff){
					stars+=diff;ans++;modified=true;
			}

			if(modified){
				continue;
			}
			break;
		}
		int k;for(k=0;k<n;k++){
			if(lvs[k].m_state<2)break;
		}
		cout<<"Case #"<<(t+1)<<": ";
		if(k==n){	cout<<ans;
		}else{			cout<<"Too Bad";
		}
		cout<<endl;
	}
	return 0;
}