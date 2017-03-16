#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int T;

vector<string> dic;

string line;

int D[52][52];

long N;

int len;

int get_ans(int pos, int last){

	if(pos >= len + 1)	return 0;

	if(D[pos][last] >= -1)
		return D[pos][last];

	int ret = -1;

	int POS = pos - 1;

	for(long i = 0; i < N; i++){

		if(int(dic[i].size()) > len - POS)
			continue;

		int llast = last;
		int acc = 0;
		bool good = true;
		for(int j = POS; j < POS + int(dic[i].size()); j++){

			if(line[j] == dic[i][j - POS])	continue;

			if(llast && j + 1 - llast < 5){
				good = false;
				break;
			}

			llast = j + 1;
			acc++;

		}

		if(good){

			int t = get_ans(pos + dic[i].size(), llast);
			if(t >= 0 && lt(acc + t, ret))
				ret = acc + t;
		}
	}

	return D[pos][last] = ret;
}

int main()
{
	dic.clear();

	ifstream infile;
  infile.open ("garbled_email_dictionary.txt");

	for(long i = 0; i < 521196; i++){
		getline(infile, line);
		dic.push_back(line);
	}
	infile.close();

	N = dic.size();

	getline(cin, line);
	stringstream ss(line);

	ss >> T;

	for(int caseidx = 1; caseidx <= T; caseidx++){

		getline(cin, line);
		
		len = line.size();

		for(int i = 0; i < 52; i++)
			for(int j = 0; j < 52; j++)
				D[i][j] = -2;

		printf("Case #%d: %d\n", caseidx, get_ans(1, 0));
	}

	return 0;
}

// vi: ts=2 sw=2
