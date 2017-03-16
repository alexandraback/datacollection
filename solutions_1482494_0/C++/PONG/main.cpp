#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class Level {
public:
	int a;
	int b;
	
	int starObtained;
	
	friend bool operator<(const Level &o1, const Level &o2);
	friend bool operator>(const Level &o1, const Level &o2);
	friend bool operator==(const Level &o1, const Level &o2);
	friend bool operator!=(const Level &o1, const Level &o2);
};

bool operator<(const Level &o1, const Level &o2) {
	if (o1.b < o2.b)
		return true;
	if (o1.b == o2.b)
		return o1.a < o2.a;
	return false;
}
bool operator>(const Level &o1, const Level &o2) {
	if (o1.b > o2.b)
		return true;
	if (o1.b == o2.b)
		return o1.a > o2.a;
	return false;
}
bool operator==(const Level &o1, const Level &o2) {
	return (o1.a == o2.a) && (o1.b == o2.b);
}
bool operator!=(const Level &o1, const Level &o2) {
	return (o1.a != o2.a) || (o1.b != o2.b);
}

int main (int argc, char * const argv[]) {
    //ifstream in("..//..//sample.in.txt");
	ifstream in("..//..//B-small-attempt1.in.txt");
	
	if(!in) {
		cout << "Input file cannot be opened";
		return 1;
	}
	
	ofstream out("output.txt");
	if (!out) {
		cout << "Output file cannot be opened";
		in.close();
		return 1;
	}
	
	int T;
	in >> T;
		
	for (int t = 0; t < T; t++) {
		int N;
		in >> N;
		
		list<Level> levels;
		for (int n = 0; n < N; n++) {
			Level newLevel;
			in >> newLevel.a;
			in >> newLevel.b;
			
			levels.push_back(newLevel);
		}
		
//		int a[N], b[N];
//		for (int n = 0; n < N; n++) {
//			in >> a[n];
//			in >> b[n];
//		}
		
		// display the level
		list<Level>::iterator p = levels.begin();
		cout << "Levels: " << endl;
		while (p != levels.end()) {
			cout << p->a << " " << p->b << endl;
			p++;
		}
		
		// sort the list
		levels.sort();
		
		// display the level
		p = levels.begin();
		cout << "Levels SORTED: " << endl;
		while (p != levels.end()) {
			cout << p->a << " " << p->b << endl;
			p++;
		}
		
		int minimumPlay = 0;
		int starAcquired = 0;
		bool tooBad = false;
		
		// for each game
		while (true) {
			// 1. go through the list if it is possible to get 2-stars
			// 2. if not, find the level that contains the highest 2-star rating, and that 1-star is attainable			
			
			if (starAcquired >= N * 2) {
				// game endsz
				break;
			}
			
			
			
			cout << "Levels PLAYED: " << endl;
			p = levels.begin();
			while (p != levels.end()) {
				cout << p->a << " " << p->b << " : (" << p->starObtained << ")"  << endl;
				p++;
			}
			
			
			
			minimumPlay++;
			cout << "A = " << starAcquired << " : P = " << minimumPlay << endl;
			
			p = levels.begin();
			if (starAcquired >= p->b ) {
				// 2 star is attainable
				starAcquired += 2 - p->starObtained;
				levels.pop_front();
				cout << "pop front" << endl;
				continue;
			}
			
			// get 1-star at gate 2 first if available (gate 1 already done)
			bool oneStarObtained = false;
			p = levels.begin();
			while (p != levels.end()) {
				if (starAcquired >= p->b && p->starObtained == 1) {
					starAcquired++;
					oneStarObtained = true;
					levels.remove(*p);
					break;
				}
				p++;
			}
			if (oneStarObtained) {
				continue;
			}
			
			p = levels.end();
			while (p != levels.begin()) {
				p--;
				if (starAcquired >= p->a && p->starObtained == 0) {
					starAcquired++;
					p->starObtained = 1;
					oneStarObtained = true;
					break;
				}
			}
			
			if (oneStarObtained)
				continue;
			else {
				tooBad = true;
				break;
			}

		}
				
		
		cout << "Case #" << (t + 1) << ": ";
		out << "Case #" << (t + 1) << ": ";	
		if (tooBad) {
			cout << "Too Bad" << endl << endl;
			out << "Too Bad" << endl;
		}
		else {
			cout << minimumPlay << endl << endl;
			out << minimumPlay << endl;
		}

	}
	
	
	in.close();
	out.close();
	
    return 0;
}
