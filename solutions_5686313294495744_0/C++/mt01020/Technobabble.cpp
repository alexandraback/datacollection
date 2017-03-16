#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

unordered_map<string, unordered_set<string> > fword;
unordered_map<string, unordered_set<string> > sword;
vector<string> infw;
vector<string> insw;
int res;

void bfs(int curc, int curi){
    if(curi == infw.size()){
	if(curc > res)	res = curc;
	return;
    }
    if(fword[infw[curi]].size() > 1 && sword[insw[curi]].size() > 1){
	// choose true
	bfs(curc, curi+1);
	// choose fake
	fword[infw[curi]].erase(insw[curi]);
	sword[insw[curi]].erase(infw[curi]);
	bfs(curc+1, curi+1);
	fword[infw[curi]].insert(insw[curi]);
	sword[insw[curi]].insert(infw[curi]);
    }else{
	// must true
	bfs(curc, curi+1);
    }
    return;
}

int main(){
    int T, N;
    string fw, sw;
    cin >> T;
    for(int t=1; t<=T; ++t){
	fword.clear();
	sword.clear();
	infw.clear();
	insw.clear();
	cin >> N;
	for(int i=0; i<N; ++i){
	    cin >> fw >> sw;
	    fword[fw].insert(sw);
	    sword[sw].insert(fw);
	    infw.push_back(fw);
	    insw.push_back(sw);
	}
	res = 0;
	bfs(0, 0);
	cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
