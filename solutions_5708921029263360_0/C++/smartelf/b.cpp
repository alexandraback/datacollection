#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

inline int min3(int a, int b, int c){
	return min(min(a,b),c);
}

inline int max3(int a, int b, int c){
	return max(max(a,b),c);
}


int main(){
	//ifstream in("in.txt");
	//ifstream in("A-large.in");
	ifstream in("C-small-attempt3.in");
	ofstream out("out.txt");
	
	unsigned cases(0), size(0), n(0);
	in >> cases;
	for(int c = 1; c <= cases; ++c){
		if(c > 1) out <<"\n";
		out << "Case #" << c << ": " ;
		int j, p, s, k;
		in >> j >> p >> s >> k;
		int jps[10][10][10], jp[10][10],js[10][10], ps[10][10];
		for(int a = 0; a < 10; ++a){
			for(int b = 0; b < 10; ++b){
				for(int c = 0; c < 10; ++c){
					jps[a][b][c] = 0;
				}
				jp[a][b] = 0;
				js[a][b] = 0;
				ps[a][b] = 0;
			}
		}
		
		stringstream ss("");
		int count = 0;
		for(int c = 0 ;c < s; ++c){
			for(int b = 0; b < p; ++b){
				for(int a = 0; a < j; ++a){
					if(jps[a][b][c] == 0 &&  jp[a][b] < k && js[a][c] < k && ps[b][c] < k){
						ss << "\n" << a + 1 << " " << b + 1 << " " << c + 1 ;
						jps[a][b][c]++;
						jp[a][b]++;
						js[a][c]++;
						ps[b][c]++;
						++count;
					}
				}
			}
		}
		out << count << ss.str();
	
		out.flush();
	}
	out.flush();
	return 0;
}