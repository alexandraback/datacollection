#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>


using namespace std;

int matchNum = 0;
int instanceNum = 0;

map<char, double> mapCnt;

int match(string& s, string& t)
{
	int count = 0;
	int ss = s.size();
	int ts = t.size();
	for (int i = 0; i <= ss-ts; i++){
		bool m = true;
		for (int j = 0; j < ts; j++){
			if (s[i+j] != t[j]){
				m = false;
				break;
			}   
		}   
		count += m;
	}   
	return count;
}
bool next(int eleNum, vector<int>& pos)
{
	bool has = false;
	for (int j = pos.size()-1; j >= 0; j--){
		if (pos[j]+1 < eleNum){
			pos[j] ++;
			for (int k = j+1; k < pos.size(); k++){
				pos[k] = 0;
			}
			has = true;
			break;
		}
	}
	return has;
}

double cal(int S, string& target)
{
	vector<char> element;
	map<char, double>::iterator it = mapCnt.begin();
	while (mapCnt.end() != it){
		element.push_back(it->first);
		it ++;
	}
	vector<int> index(S, 0);
	string tmp;
	tmp.resize(S);
	double e = 0;
	while (true){
		double ratio = 1;
		for (int i = 0; i < index.size(); i++){
			tmp[i] = element[index[i]];
			ratio *= mapCnt[element[index[i]]];
		}
		int cnt = match(tmp, target);
		e += cnt * ratio;
		if (!next(element.size(), index)){
			break;
		}
	}
	return e;
}
int main(int argc, char **argv)
{
	ifstream in(argv[1]);
	int nCase;
	in >> nCase;
	for (int i = 1; i <= nCase; i++){
		matchNum = 0;
		instanceNum = 0;
		int K,L,S;
		in >>K;
		in >>L;
		in >>S;
		string source;
		in >> source;
		string target;
		in >> target;
		int max = 0;
		bool m = true;
		for (int j = 0; j < target.size() && m; j++)
		{
			bool f = false;
			for (int k = 0; k < source.size(); k++){
				if (target[j] == source[k]){
					f = true;
					break;
				}
			}
			m = f;
		}
		if (m){
			string tmp;
			tmp.resize(S);
			for (int j = 0; j < S; j++){
				tmp[j] = target[j%target.size()];
			}
			max = match(tmp, target);
		}
		double r = 0;
		if (max > 0){
			mapCnt.clear();
			map<char, int> charcnt;
			for (int j = 0; j < source.size(); j++){
				charcnt[source[j]] ++;
			}
			for (int j = 0; j < source.size(); j++){
				mapCnt[source[j]] = 1.0 * charcnt[source[j]] / source.size();
			}
			r = cal(S, target);
		}

		printf("Case #%d: %.8f\n", i, max-r);
	}
	return 0;
}
