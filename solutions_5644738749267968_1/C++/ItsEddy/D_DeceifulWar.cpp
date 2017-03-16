#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	int TestCase,Case = 1;
	scanf("%d",&TestCase);
	while(TestCase--){
		int Round,WinCount = 0,WinCheatCount=0;
		scanf("%d",&Round);
		set<double> me, oppenent;
		
		double temp;
		for(int i = 0;i < Round;++i){
			scanf("%lf",&temp);
			me.insert(temp);
		}
		for(int i = 0;i < Round;++i){
			scanf("%lf",&temp);
			oppenent.insert(temp);
		}

		set<double> Me(me),Oppenent(oppenent);
		
		int meH = 0,opH = 0;
		while(me.size()){
			 set<double>::iterator Bigger = me.lower_bound(*(--oppenent.end()));
			 if( Bigger == me.end() ){
				me.erase(me.begin());
				oppenent.erase(--oppenent.end());
			}else{
				me.erase(Bigger);
				oppenent.erase(--oppenent.end());
				++WinCheatCount;
			}
		}
		while(Me.size()){
			 set<double>::iterator Bigger = Oppenent.lower_bound(*(--Me.end()));
			 if( Bigger == Oppenent.end() ){
				Oppenent.erase(Oppenent.begin());
				Me.erase(--Me.end());
				++WinCount;
			}else{
				Oppenent.erase(Bigger);
				Me.erase(--Me.end());
			}
		}

		printf("Case #%d: %d %d\n",Case++, WinCheatCount , WinCount );
	}
	return 0;
}
