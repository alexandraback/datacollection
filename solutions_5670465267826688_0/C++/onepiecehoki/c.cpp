#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

class Quat{
public:
	char val;
	bool neg;
	
	Quat(char ch='1', bool _neg=false){
		val = ch;
		neg = _neg;
	}
	
	bool isValid(){
		return val == '1' || val == 'i' || val == 'j' || val == 'k';
	}
	
	Quat mult(const Quat& q1, const Quat& q2){
		bool multNeg = q1.neg ^ q2.neg;
		if (q1.val == q2.val) return Quat('1', multNeg ^ (q1.val != '1'));
		else if (q1.val == '1') return Quat(q2.val, multNeg);
		else if (q2.val == '1') return Quat(q1.val, multNeg);
		else if (q1.val == 'i'){
			if (q2.val == 'j') return Quat('k', multNeg);
			else if (q2.val == 'k') return Quat('j',  !multNeg );
			else return Quat();
		}
		else if (q1.val == 'j'){
			if (q2.val == 'i') return Quat('k', !multNeg );
			else if (q2.val == 'k') return Quat('i', multNeg);
			else return Quat();
		}
		else if (q1.val == 'k'){
			if (q2.val == 'i') return Quat('j', multNeg);
			else if (q2.val == 'j') return Quat('i', !multNeg );
			else return Quat();
		}
		else return Quat();
	}
	
	Quat operator*(const Quat& q){
		return mult(*this, q);
	}
	
	Quat operator*(char ch){
		return mult(*this, Quat(ch));
	}
	
	const Quat& operator*= (const Quat& q){
		*this = mult(*this, q);
		return *this;
	}
	
	const Quat& operator*= (char ch){
		*this = mult(*this, Quat(ch));
		return *this;
	}
	
	bool operator==(const Quat& q){
		return ( (val == q.val) && (neg == q.neg) );
	}
	
	friend ostream& operator<< (ostream& fout, const Quat& q){
		if (q.neg) fout << "-";
		fout << q.val;
		return fout;
	}
	
};


int main(){
		int T;
	cin >> T;
	
	for (int t=1; t <= T; ++t){
		int L, X;
		cin >> L >> X;
		
		string seq;
		cin >> seq;
		
		int numIt = X > 8? 8 : X;
		Quat curTarget('i');
		Quat curVal;
		bool findI = false, findJ = false;
		for (int i = 0; i < numIt*seq.size(); ++i){
			int pos = i % seq.size();
			curVal *= seq[pos];
			if (curVal == curTarget){
				if (curVal == Quat('i'))	{
					curTarget = Quat('j');
					findI = true;
					//cout << "find I!" << endl;
				}
				else if (curVal == Quat('j')) {
					curTarget = Quat('k');
					findJ = true;
					//cout << "find J!" << endl;
				}
				else curTarget = Quat('x'); //Set to any unvalid Quat
				curVal = Quat();
			}
		}
		//cout << "curVal: " << curVal << endl;
		
		bool canSegment = false;
		if (findI && findJ){
			Quat segMult;
			for (int i=0; i < seq.size(); ++i) segMult *= seq[i];
			Quat total;
			for (int i=0; i < X; ++i) total *= segMult;
			if (total == Quat('1', true)) canSegment = true;
		}
		
		cout << "Case #" << t << ": ";
		if (canSegment) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
