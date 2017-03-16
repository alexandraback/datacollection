#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
using namespace std;



int main(){
	
	ifstream in("A.txt");
	ofstream out("result.txt");
	int T;
	in >> T;

	for(int test = 0; test<T; test++){
		int N,S,p,res=0;
		in >> N >> S >> p;
		vector<int> total(N+1);
		for(int i = 0;i<N;i++)	in >> total[i];
		
		for(int i = 0; i<N; i++){
			int avg = total[i]/3;
			int s1 = avg, s2 = avg, s3 = avg;
			if(total[i]%3 ==1) s1++;
			else if(total[i]%3 == 2) {
				s1++;s2++;
			}
			if(p<=s1) res++;
			else if(p == s1+1 && s2>0){
				if((s1+1-s3)<2 && (s1+1-(s2-1))<2) res++;
				else if((s1+1-s3 <= 2 && s1+1-(s2-1)<=2) && S>0) {res++;S--;}
			}
		}
		out << "Case #" << test+1 << ": " << res << endl;
		cout << "Case #" << test+1 << ": " << res << endl;
	}

	return 0;
};