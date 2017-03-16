#include <fstream>
#include <string>
#include <deque>


using namespace std;

const unsigned ALL_DIGITS = 1023;

string fun(string s){
	deque<char> q;
	q.push_front(s[0]);
	for(int i = 1; i < s.length(); ++i){
		if(s[i] >= q.front()){
			q.push_front(s[i]);
		}else{
			q.push_back(s[i]);
		}
	}
		string rval;
		while(q.size()){
			rval += q.front();
			q.pop_front();
		}
		return rval;

}

int main(){
	ifstream in("A-large.in");
	ofstream out("out.txt");
	unsigned cases(0);
	string s;
	in >> cases;
	for(int c = 1; c <= cases; ++c){
		in >> s;
		out << "Case #" << c << ": " << fun(s) << "\n";
	}
	out.flush();
	return 0;
}
