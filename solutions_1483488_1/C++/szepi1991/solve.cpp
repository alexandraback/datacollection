#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<utility>

using namespace std;

// reverse the string
string reverse(string const& in) {
	string out;
	for (unsigned i = in.length(); i > 0 ; --i) {
		out += in.at(i-1);
	}
	return out;
}


class Number {
private:
	// holds number reversed
	string number;
	
	// adds 1*10^dec to this number 
	void addOne(unsigned dec) {
		if (dec > number.length()) 
			cout << "\n\nNOT IMPLEMENTED\n\n";
		
		if (dec == number.length()) {
			number += "1";
			return;
		}
		
		if (number[dec] != '9') {
			number[dec]++;
		} else {
			number[dec] -= 9;
			addOne(dec+1);
		}
	}
	
public:
	
	Number(string number) {
		this->number = reverse(number);
	}
	
	Number& addOne() {
		addOne(0);
		return *this;
	}
	
	string getString() {
		return reverse(number);
	}
	
	// return all recycled pairs
	set<string> getAllRec() {
		// this moving business might create duplicates. (1212)
		// use a SET!
		set<string> ret;
		
		// how many digits to move
		for (unsigned i = 1; i < number.length(); ++i) {
			// take last i chars of number and move it to front
			string ns (number, number.length()-i, i);
			// and now add the rest of it
			ns += number.substr(0, number.length()-i);
// 			cout << "i=" << i << ":" << reverse(ns) << endl;
			
			// TODO what to do about leading 0s?
			if (ns[ns.length()-1] != '0')
				ret.insert(reverse(ns));
		}
		return ret;
	}
	
};


// returns
// - if a < b
// 0 if a == b
// + if a > b
// assumes no leading 0s
int compStrings(string a, string b) {
	if (a.length() < b.length()) return -1;
	if (a.length() > b.length()) return 1;
	return (a.compare(b));
}

vector< pair<string, string> > getAll() {
	
	vector< pair<string, string> > ret;
	// nothing for a <= 11
	string a ("12");
	string b ("2000000");
	
	Number num(a);
	string i = num.getString();
	while (i.compare(b) != 0) {
					
		set<string> pairs = num.getAllRec();
		for (set<string>::iterator it = pairs.begin();
									it != pairs.end(); it++) {
			// i is smaller than *it AND b is larger or equal to *it
			if (i.compare(*it) < 0 && compStrings(b, *it) >= 0) {
//				cout << i << "--" << *it << endl;
				ret.push_back( make_pair(i, *it) );
			}
		}
		
		num.addOne();
		i = num.getString();
	}
	
	return ret;
}


int main() {
	
// 	// TEST
// 	string s = "1234";
// 	cout << s << " <--> " << reverse(s) << endl;
// 	Number num(s);
// 	cout << num.getString() << endl;
// 	num.addOne().addOne().addOne();
// 	num.addOne();
// 	num.addOne();
// 	num.addOne();
// 	cout << num.getString() << endl;
// 	
// 	num.getAllRec();
// 	
// 	// we can simply compare these by string comparision
// 	// needs taht they have the same length
// 	string s1 ("1234");
// 	string s2 ("0234");
// 	string s3 ("2234");
// 	cout << s1.compare("1235") << endl;
// 	cout << s2.compare("1235") << endl;
// 	cout << s3.compare("1235") << endl;
	
	unsigned cases;
	string a, b;
	
	// find all pairs first
	vector< pair<string, string> > all = getAll();
	vector< pair<string, string> >::iterator allIt;
	
	cin >> cases;
	
	for (unsigned c = 0; c < cases; ++c) {
		
		if (c != 0) cout << endl;
		
		cin >> a >> b;
// 		cout << "from " << a << " to " << b << endl;
		unsigned ans = 0;
		
		for (allIt = all.begin(); allIt != all.end(); allIt++) {
			// binary search for starting position
			// for now just search...
			if (allIt->first.length() < a.length()) continue;
			if (allIt->first.length() > b.length()) continue;
			
			if ( // first allIt is big enough
				(allIt->first.length() > a.length() || a.compare(allIt->first) <= 0)
				&& // and allIt is not too big
				(allIt->first.length() < b.length() || b.compare(allIt->first) >= 0)) {
				
// 				cout << allIt->first << endl;
				
				// check if second is less than b
				if (b.compare(allIt->second) >= 0)
					ans++;
			}
		}
		
		cout << "Case #" << c+1 << ": " << ans;
	}
	
	return 0;
}

