#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

vector<string> cps;
vector<string> jps;
string C, J;

void genpairC(int level, char tmp[4]){
    if(level == C.length()){
	tmp[level] = '\0';
	cps.push_back(string(tmp));
	return;
    }
    if(C[level] == '?'){
	for(int i=0; i<10; ++i){
	    tmp[level] = '0'+i;
	    genpairC(level+1, tmp);
	}
    }else{
	tmp[level] = C[level];
	genpairC(level+1, tmp);
    }
    return;
}
void genpairJ(int level, char tmp[4]){
    if(level == J.length()){
	tmp[level] = '\0';
	jps.push_back(string(tmp));
	return;
    }
    if(J[level] == '?'){
	for(int i=0; i<10; ++i){
	    tmp[level] = '0'+i;
	    genpairJ(level+1, tmp);
	}
    }else{
	tmp[level] = J[level];
	genpairJ(level+1, tmp);
    }
    return;
}

int main(){
    int T;
    char tmpc[4];
    char tmpj[4];
    cin >> T;
    for(int t=1; t<=T; ++t){
	cin >> C >> J;
	cps.clear();
	jps.clear();
	genpairC(0, tmpc);
	genpairJ(0, tmpj);
	string minc, minj;
	int mindf = 1000;
	int indj = 1;
	for(string cp: cps){
	    int icp = stoi(cp);
	    int tmdf = abs(icp-stoi(jps[indj-1]));
	    while(indj < jps.size() && abs(icp-stoi(jps[indj])) < tmdf){
		tmdf = abs(icp-stoi(jps[indj]));
		++indj;
	    }
	    if(abs(icp-stoi(jps[indj-1])) < mindf){
		mindf = abs(icp-stoi(jps[indj-1]));
		minc = cp;
		minj = jps[indj-1];
	    }
	}
	cout << "Case #" << t << ": " << minc << " " << minj << endl;
    }
    return 0;
}
