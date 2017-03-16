#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


int N;
int main(int argc, char *args[]) {
    if (argc == 2 && strcmp(args[1], "small") == 0) {
        freopen("A-small-attempt0.in","rt",stdin);
        freopen("small.out","wt",stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("A-large-attempt0.in","rt",stdin);
        freopen("large.out","wt",stdout);
    }
    else {
	    freopen("a.txt", "rt", stdin);
    }
    
    cin >> N;
    for (int i=0; i<N; ++i) {
        string line, trash;
        cin >> trash;
        cin >> line;        

        vector<int> shyness;
        for (char c : line) {
                shyness.push_back(c - '0');
        }

        int required_friends = 0;
        int up = 0;

        for (int i=0; i<shyness.size(); ++i) {
            up += shyness[i];
            if (up < i+1) {
                required_friends += i+1-up;
                up += i+1-up;
            }
        }

        cout << "Case #" << i+1 << ": " << required_friends << endl;
    }
	
    return 0;
}
