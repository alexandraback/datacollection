#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
//#include <omp>
using namespace std;

vector<vector<int> > quat;
map<char, int> char_num;
map<int, char> num_char;

/* MAPPINGS
	Char   Num
	1	0
	i	1
	j 	2
	k	3
	-1      4
	-i	5
	-j	6
	-k	7
*/
void setup();


int mult(int x, int y, bool& neg);



int main() {

	setup();


	int tests;
	cin >> tests;
	
	for( int i = 1; i <= tests; i++ ) {

	    int chars;
	    cin >> chars;
	    unsigned long long reps;
	    cin >> reps;
	    unsigned long long old_reps = reps;
	    reps = reps % 8;
	    string inp, input = "";
	   
	    cin >> inp;
	    input = inp;
	    int ans = 0;
	    int check_sum = 0;
	    unsigned long long rep_count = -1;
	    bool found = false;
	    bool neg = false;
	    bool neg2 = false;
	    bool foundi = false;
	    bool foundj = false;
	    bool foundk = false;
	    int rep_start = 0;
	    for(int j = 0; j < input.length(); j++) {
		if(j == rep_start) {
		    rep_count++;
		    if(rep_count >= reps) break;
		}

                ans = mult(ans, char_num[input[j]], neg);
		if(!foundi) {
		    if(ans == 1 && !neg) {
		        foundi = true;
			ans = 0;
			rep_start = j;
			rep_count = 0;
		    }
		}
		else if(!foundj) {
		    if(ans == 2 && !neg) {
			foundj = true;
			ans = 0;
			rep_start = j;
			rep_count = 0;
		    }
		}
		else if(!foundk) {
		    if(ans == 3 && !neg) {
			foundk = true;
			ans = 0;
			break;
			//if(j == input.length() -1) {
			//    found = true;
			//    break;
			//}
		    }
		}
		if((j == input.length() -1)) {
		    j = -1;
		}
	    }
		rep_count = 0;
		reps = old_reps;
		reps = reps % 8;
		int new_ans = 0;
		bool new_neg = false;
		for(int m = 0; m < input.length(); m++) {
		    new_ans = mult(new_ans, char_num[input[m]], new_neg);
		    if(m == input.length() -1) {
			rep_count++;
			if(rep_count < reps) m = -1;
		   }
		}
		if(new_ans == 0 && new_neg && foundk) found = true;
		cout << "Case #" << i << ": ";
		if(found) cout << "YES" << endl;
		else cout << "NO" << endl;
	
	}

}

int mult(int x, int y, bool& neg) {
	//if(neg) cout << "-";
	//cout << num_char[x] << " * " << num_char[y] << " = " ;
	if(quat[x][y]/4 == 1) {
	    if(neg) neg = false;
	    else neg = true;
	}
	//if(neg) cout << "-";
	//cout << num_char[quat[x][y] % 4] << endl;
	return quat[x][y] % 4;
	



}

void setup() {
	quat.resize(8);
	for(int i = 0; i < 8; i++) 
	    quat[i].resize(8);
	
	char_num['1'] = 0;
	char_num['i'] = 1;
	char_num['j'] = 2;
	char_num['k'] = 3;
	num_char[0] = '1';
	num_char[1] = 'i';
	num_char[2] = 'j';
	num_char[3] = 'k';
	
	quat[0][0] = 0;
	quat[1][1] = 4;
	quat[2][2] = 4;
	quat[3][3] = 4;

	quat[0][1] = 1;
	quat[1][0] = 1;
	quat[0][2] = 2;
	quat[2][0] = 2;
	quat[3][0] = 3;
	quat[0][3] = 3;

	quat[1][2] = 3;
	quat[1][3] = 6;
	
	quat[2][1] = 7;
	quat[2][3] = 1;
	
	quat[3][1] = 2;
	quat[3][2] = 5;



}


void test_stuff() {
	
	for(int i = 0; i < 4; i++) {
	   for(int j = 0; j < 4; j++) {
		char ans = num_char[quat[i][j] % 4];
		if(quat[i][j]/4 == 1) cout << "-";
		cout << ans << " ";
	   }
	   cout << endl;

	}

	string test = "ijki";
	int ans = char_num[test[0]];
	bool neg = false;
	for(int i = 1; i < test.length(); i++) {
	       ans = mult(ans, char_num[test[i]], neg);
	}
	if(neg) cout << "-";
	cout << num_char[ans] << endl;


}
