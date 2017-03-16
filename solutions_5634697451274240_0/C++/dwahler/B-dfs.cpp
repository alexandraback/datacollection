#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <unordered_set>

#define D(x)

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
    	string stack;
    	cin >> stack;

        string target = stack;
        for (char& c : target) {
            c = '+';
        }

    	vector<string> current { stack }, next, parent { "beginning" }, next_parent;
    	unordered_set<string> visited;
        int flips = 0;
        bool found = false;

        while (true) {
            for (int index = 0; index < current.size(); index++) {
            	const string& s = current[index];
            	//const string& ps = parent[index];
                //D(cerr << s << " @ " << flips << " from " << ps << endl);
                if (s == target) {
                	found = true;
                	break;
                }
                if (visited.find(s) != visited.end()) continue;
                visited.insert(s);

                for (int flipEnd = 0; flipEnd < s.length(); flipEnd++) {
                    string t = s;
                    reverse(&t[0], &t[flipEnd+1]);
                    for (int i = 0; i <= flipEnd; i++) {
                    	t[i] = (t[i] == '-') ? '+' : '-';
                    }
                    next.push_back(t);
                    //next_parent.push_back(s);
                }
            }
            if (found) break;

            swap(current, next);
            next.clear();
            swap(parent, next_parent);
            next_parent.clear();
            flips++;
        }

        cout << "Case #" << testCase << ": " << flips << endl;
    }
}