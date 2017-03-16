#include<iostream>
#include<string>
#include<set>

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
	
	cin >> cases;
	
	for (unsigned c = 0; c < cases; ++c) {
		
		if (c != 0) cout << endl;
			
		
		unsigned ans = 0;
		cin >> a >> b;
		
		Number num(a);
		string i = num.getString();
		while (i.compare(b) != 0) {
						
			set<string> pairs = num.getAllRec();
			for (set<string>::iterator it = pairs.begin();
										it != pairs.end(); it++) {
				if (i.compare(*it) < 0 && b.compare(*it) >= 0) {
					ans++;
//					cout << i << "--" << *it << endl;
				}
			}
			
			num.addOne();
			i = num.getString();
		}
		
		cout << "Case #" << c+1 << ": " << ans;
	}
	
	return 0;
}

