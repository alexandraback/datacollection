#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#define NEXT_LINE() \
  line.clear(); getline(cin,line); ss.clear(); ss.str(line);

using namespace std;



void getInherits ( vector < vector < int > > &cls, int classn, vector< int > &out ) {
  for( int i = 0; i < cls[classn-1].size(); ++i) {
    out.push_back(cls[classn-1][i]);
    getInherits(cls,cls[classn-1][i],out);
  }
}



int main(int argc, char **argv) {
    string line;
    stringstream ss;
    int T;

    NEXT_LINE();

    ss >> T;

    for ( int i = 1; i <= T; ++i ) {
        int N;
        vector< vector < int > > classes;
        bool diamond = false;
        NEXT_LINE();
        ss >> N;
        for ( int j = 0; j < N; ++j ) {
            int M;
            NEXT_LINE();
            ss >> M;
            vector< int > inherits;
            for ( int k = 0; k < M; ++k ) {
                int iclass;
                ss >> iclass;
                inherits.push_back(iclass);
            }
            classes.push_back(inherits);
        }
        for (int j = 0; j < N; ++j ) {
           if ( classes[j].size() < 2 )
             continue;
           vector < int >  all_inherits;
           getInherits(classes,j+1,all_inherits);
           sort (all_inherits.begin(), all_inherits.end());
           vector<int>::iterator it;
           it = adjacent_find ( all_inherits.begin(), all_inherits.end());
           if ( it != all_inherits.end()) {
            diamond = true;
            break;
           }

        }
        
        cout << "Case #" << i << ": ";
        if ( diamond ) cout << "Yes";
        else cout << "No";

        cout << endl;
    }



    return 0;
}
