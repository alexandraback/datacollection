#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

string norm(string str, int size){
	string res = str;
	while(res.size() != size){
		res = "0" + res;		
	}
	return res;
}

string build(int numb, int size){
	stringstream out;
	out<<numb;
	string res;
	out>>res;
	res = norm(res, size);
	return res;
}

bool check(string temp, string str){
	for(int i=0; i<temp.size(); i++){
		if(temp[i] == '?')
			continue;
		if(temp[i] != str[i])
			return false;
	}
	return true;
}

void solveSlow(string a, string b, int test){
	string ra, rb;
	int numb1 = -1, numb2 = -1;
	int n = a.size();
	int mx = pow(10.0, n);

	for(int i=0; i<mx; i++){
		string cura = build(i, n);
		if(!check(a, cura))
			continue;
		for(int j=0; j<mx; j++){
			string curb = build(j, n);
			if(!check(b, curb))
				continue;
			if(numb1 == -1){
				numb1 = i;
				numb2 = j;
			}
			else{
				int r1 = abs(numb1 - numb2);
				int r2 = abs(i - j);
				if(r2 < r1){
					numb1 = i;
					numb2 = j;
				}
				else{
					if(r1 == r2){
						if(i < numb1){
							numb1 = i;
							numb2 = j;
						}
						else{
							if(i == numb1){
								if(j < numb2){
									numb2 = j;
								}
							}
						}
					}
				}
			}
		}
	}

	stringstream out;
	out<<numb1<<" "<<numb2;
	out>>ra>>rb;

	ra = norm(ra, n);
	rb = norm(rb, n);

	printf("Case #%d: ", test);
	cout<<ra<<" "<<rb<<"\n";
}

int main(){

#ifdef _CONSOLE
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int countTest;
	cin>>countTest;
	
	for(int test = 1; test <= countTest; test++){
		string a, b;
		cin>>a>>b;
		solveSlow(a, b, test);
		cerr<<test<<"\n";
	}
	
	return 0;
}

