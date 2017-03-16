#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


int parent(long long n, long long d){

	int st = 1;
	int e = 0;
	int f = 0;
	long long nn;
	while(st < 41){
		nn = 2*n;
		if(nn >= d){
			if(f==0)
				f = st;

			if(nn == d){
				e = 1;
				break;
			}

			n = nn%d;
		}
		else
			n = nn;

		st++;
	}

	if(e!=1)
		return -1;
	else
		return f;

}
int main(){

	int t;
	cin >> t;
	string str;
	long long n1,n2;
	int cc = 0;
	while(t--){
		cc++;
		cout << "Case #"<< cc << ": ";
		cin >> str;
		vector<string> vs = split(str,'/');

		//cout << vs[0] << " " << vs[1] << endl;
		std::stringstream sstr(vs[0]);
		sstr >> n1;
		std::stringstream sstr1(vs[1]);
		sstr1 >> n2;
		if(parent(n1,n2) != -1)
			cout << parent(n1,n2) << endl;
		else
			cout << "impossible" << endl;

	}
}