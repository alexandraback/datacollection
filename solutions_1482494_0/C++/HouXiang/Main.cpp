#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/*
int ElapsedTime(const vector<int>& vecButtons, int index) {
	return abs(vecButtons[index] - vecButtons[index - 1]);
}
*/



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
    char buf[200] = {0};
    inf.getline(buf, 200);

    int n = atoi(buf);
    
	for (int i=0; i<n; i++) 
    {
        int level = 0; 
        int s[1000][2] = {0};

        string buf;
        inf >> buf; level = atoi(buf.c_str());
        for (int nn=0; nn<level; nn++) {
            inf >> buf; s[nn][0] = atoi(buf.c_str());
            inf >> buf; s[nn][1] = atoi(buf.c_str());
        }

		// find solution
        bool possible = true;
        int completlevel = 0, play = 0, stars = 0; 
        while ((possible) && (completlevel < level)) {
            // find level 2
            bool con = false;
            for (int nnn = 0; nnn<level; nnn++)
            {
                if ((s[nnn][1] < 10000) && (s[nnn][1] <= stars)) {
                    if (s[nnn][0] == 10000) stars += 1;
                    else stars += 2;

                    s[nnn][1] = 10000;
                    s[nnn][0] = 10000;
                    play++;
                    completlevel ++;
                    con = true;
                    break;
                }
            }
            if (con) continue;

            // find level 1
            int back = -1, max = 0;
            for (int nnn = 0; nnn<level; nnn++)
            {
                if ((s[nnn][0] < 10000) && (s[nnn][0] <= stars)) {
                    if (s[nnn][1] > max) {
                        max = s[nnn][1];
                        back = nnn;
                    }
                }
            }

            if (back >= 0) {
                s[back][0] = 10000;
                stars++;
                play++;
                con = true;
            }

            if (!con) {
                possible = false;
            }
        }
        if (possible)
		    cout << "Case #" << i+1 << ": " << play << endl;
        else
            cout << "Case #" << i+1 << ": " << "Too Bad" << endl;
	}

	return 0;
}

