#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> BFFof[1001];
bool visited[1001];

int disttoleaf(int x){
//	cout << x << endl;
	visited[x] = true;
	if (BFFof[x].empty()) return 0;
	int ans = 0;
	for (int i=0;i<BFFof[x].size();i++){
		ans =  max(ans, 1+disttoleaf((BFFof[x])[i]));
	}
	return ans;
}

void init(){
	for (int i=1;i<=1000;i++) BFFof[i].clear();
	for (int i=1;i<=1000;i++) visited[i] = false;
}

int main(){
	ifstream cin("CS.in");
	ofstream cout("CS.txt");
	int T; cin >> T;

	for (int t=0;t<T;t++){
		int N; cin >> N;
		int BFF[N+1];
	
		int maxloop = 0, maxnloop = 0;
		init();
		for (int i=1;i<=N;i++){
			cin >>BFF[i];
			BFFof[BFF[i]].push_back(i);
		}
		
		for (int i=1;i<=N;i++){
			if (visited[i]) continue;
			
			int rabbit, turtle; rabbit = turtle = i;
			int loopsize = 0;
			do{
				rabbit = BFF[rabbit]; visited[rabbit] = true;
				rabbit = BFF[rabbit];
				turtle = BFF[turtle];
				visited[turtle] = visited[rabbit] = true;
			} while (rabbit != turtle);
			do{
				rabbit = BFF[rabbit];
				loopsize++;
			} while (rabbit != turtle);
			
		//	cout << i << " " << loopsize << endl;
			if (loopsize == 2){
				int tmpsize = 2, tmplength = 0;
				rabbit = BFF[rabbit];
				for (int j=0;j<BFFof[rabbit].size();j++){
					if ((BFFof[rabbit])[j] == turtle) continue;
					tmplength = max(tmplength, 1+disttoleaf((BFFof[rabbit])[j]));
				} //cout << tmplength << endl;
				tmpsize += tmplength; tmplength = 0; 
				for (int j=0;j<BFFof[turtle].size();j++){
					if ((BFFof[turtle])[j] == rabbit) continue;
					tmplength = max(tmplength, 1+disttoleaf((BFFof[turtle])[j]));
				} //cout << tmplength << endl;
				tmpsize += tmplength;
				maxnloop += tmpsize;
			} else maxloop = max(maxloop, loopsize);
		}
		cout << "Case #" << t+1 << ": " << max(maxnloop,maxloop) << endl;
	}
}
