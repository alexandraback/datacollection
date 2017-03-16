#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int dp[2000*1000];

ifstream cin("D-small-attempt0.in");
ofstream cout("D-small0.out");
int f(vector <int> &vop, vector <vector<int> > & vtypes, vector <int> &vko, int myset, vector <int> &ret,vector <int> &vbest,bool &found){
	if(myset == (1<<vop.size()) -1 ){
		vbest = ret;
		found = true;
		return 1;
	}
	if(dp[myset]!=-1) return dp[myset];
	if(found) return 1;
	int mycount[50]={0};
	for(int i=0;i<vko.size();i++)
		mycount[vko[i]] ++;
	for(int i=0;i<vop.size();i++){
		if( ((1<<i) & myset)!=0){
			mycount[vop[i]]--;
			for(int j=0;j<vtypes[i].size();j++)
				mycount[vtypes[i][j]] ++;
		}
	}
	int mx =0,cand =-1;
	for(int i=0;i<vop.size();i++){
		if(mycount[vop[i]]>0 && ((1<<i) & myset) == 0){
			ret.push_back(i);
			cand =f(vop,vtypes,vko,(myset | (1<<i)),ret,vbest,found);
			ret.pop_back();
			if(found) return 1;
			mx= max(cand,mx);
		}
	}
	dp[myset] = mx;
	return mx;
}

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int N,K;
		cin >> K >> N;
		vector <int> vko;
		for(int i=0;i<K;i++){
			int z;
			cin >> z;
			vko.push_back(z);
		}
		for(int i=0;i<2000*1000;i++) dp[i] = -1;
		vector <int> vop;		
		vector <vector<int> > vtypes;
		for(int i=0;i<N;i++){
			int ti,ki;
			cin >> ti >>ki;
			vop.push_back(ti);
			vector <int> vt;
			for(int j=0;j<ki;j++){
				int newk;
				cin >> newk;
				vt.push_back(newk);
			}
			vtypes.push_back(vt);
		}
		int myset = 0;
		vector <int> vret,vbest;
		bool found = false;
		int ret = f(vop,vtypes,vko,myset,vret,vbest,found);
		if(ret ==0){
			cout << "Case #"<<t+1<< ": IMPOSSIBLE" << endl;
		}
		else{
			cout << "Case #"<<t+1<< ": ";
			for(int j=0;j<vbest.size()-1;j++){
				cout <<vbest[j]+1<< " ";	
			}
			cout<<vbest.back()+1<<endl;
		}

	}
	system("pause");
	return 0;
}

