#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/*
int ElapsedTime(const vector<int>& vecButtons, int index) {
	return abs(vecButtons[index] - vecButtons[index - 1]);
}
*/

bool findsolution(vector< vector<int> > &allsolution, vector<int> &all, vector<int> &news) {
    if (news.size() == 0) return false;
    for (int i=0; i<news.size(); i++) {
        for (int j=0; j<all.size(); j++) {
            if (news[i] == all[j]) {
                return true;
            }
        }
        all.push_back(news[i]);
        if (findsolution(allsolution, all, allsolution[news[i]-1]) == true)
            return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    
	if (argc != 2) {
		cerr << "wrong number of parameter" << endl;
		return -1;
	}

	ifstream inf(argv[1]);
	if (!inf) {
		cerr << "cannot open file " << argv[1] << endl;
		return -1;
	}

	string ln;  
    inf >> ln;

    int cases = atoi(ln.c_str());
    
	for (int i=0; i<cases; i++) 
    {
        inf >> ln; int classes = atoi(ln.c_str());
        vector <vector<int> > vecs; 
        for (int ii=0; ii<classes; ii++) {
            vector<int> vecOne; 
            inf >> ln; int hn = atoi(ln.c_str());
            for (int iii=0; iii<hn; iii++) {
                inf >> ln; 
                int j = atoi(ln.c_str());
                vecOne.push_back(j);
            }
            vecs.push_back(vecOne);
        }

        // find solution
        bool find = false;
        for (int ii=0; ii<classes; ii++) {
            vector<int> allhclass; 
            if (findsolution(vecs, allhclass, vecs[ii])) {
                
                find = true;
                break;
            }
                
        }

        if (find)
            cout << "Case #" << i+1 << ": " << "Yes" << endl;
        else
            cout << "Case #" << i+1 << ": " << "No" << endl;
        
	}

	return 0;
}

