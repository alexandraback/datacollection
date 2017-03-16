/*
 * purpose: a template backbone for CodeJam solution
 * created: 2014-03-15
 * revised: 2014-03-29
 * author: Hoffman Tsui
 * 
 * start time: 10:50
 * end time: 11:00
 * time to completion: n min(s)
 */

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>


    

void help();

int main (int argc, char *argv[]) {
    int c;
    const char* in_file;
    //const char* out_file;
    while (( c = getopt(argc, (char **)argv, "f:h:?")) != -1) {
        char flag = (char)c;
        switch(flag) {
            case 'f':
                in_file = optarg;
                break;
            default:
                help();
        }
    }
    
    // declar data structure
    
    // read content from file, close the stream when finish
    std::ifstream is(in_file);
	if (!is) {
		return 2;
    } else {
        // load into data structure
        using namespace std;
        int T;
        is >> T;
        for (int i=1; i<=T; i++) {
            long A,B,K;
            is >> A;
            is >> B;
            is >> K;
            long long res = A*B;
            long long cnt =0;
            for (int i=K; i< A; i++) {
                for (int j=K; j< B; j++) {
                    int tmp = i & j;
                    if ( tmp >= K) {
                    //std::cout << "DEBUG: (" << i << ", " << j << ") = " << tmp ;
                        cnt++;
                        //std::cout << std::endl;
                    }
                        //std::cout << " 1" << std::endl;
                }
            }
                res -= cnt;
            cout << "Case #" << i << ": " << res << endl;
        }
    }
	is.close();


    // resolution
    {
        using namespace std;

    }


	return 0;
}

void help() {
    std::cerr << "Usage: command [-f filename]" << std::endl;
}
