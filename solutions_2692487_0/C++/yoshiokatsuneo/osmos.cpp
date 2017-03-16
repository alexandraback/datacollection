#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define decltype(X) __typeof(X)
#define REP(i, n) for(int i=0; i<(int)n; i++)
#define FOR(it, c) for(decltype((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

void testcase(int t)
{
	string result_str = "OK";
    int A, N;
    cin >> A >> N;
    // printf("t=%d, A=%d, N=%d\n", t, A, N);
    vector<int> motes;
    for(int i=0;i<N;i++){
        int val;
        cin >> val;
        motes.push_back(val);
    }
    sort(motes.begin(), motes.end());
    int motes_pos = 0;
    int motes_added = 0;
    int result = INT_MAX;
    if(A==1){
        result = (int)motes.size();
    }else{
        while(true){
            int motes_left = (int)motes.size() - motes_pos;
            
            result = min(result, (motes_added + motes_left));
            
            if(motes_pos == motes.size()){
                break;
            }
            int mote = motes[motes_pos];
            while(A<=mote){
                A += (A-1);
                motes_added++;
            }
            A+=mote;
            motes_pos++;
        }
    }
    
    
	cout << "Case #" << (t+1) << ": " << result << endl;
}

int main(int argc, char *argv[]) {
	int T;
	// ios::sync_with_stdio(false);
    if(argc >= 2){
        int fd = open(argv[1], O_RDONLY);
        if(fd == -1){
            fprintf(stderr, "failed to open [%s]\n", argv[1]);
            exit(1);
        }
        int ret = dup2(fd, 0);
        if(ret == -1){
            fprintf(stderr, "failed to dup2[%s]\n", argv[1]);
            exit(1);
        }
    }
	cin >> T;
	for(int t=0;t<T;t++){
		testcase(t);
	}
	return 0;
}

