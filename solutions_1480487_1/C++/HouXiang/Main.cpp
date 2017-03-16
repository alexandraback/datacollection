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
    inf >> buf;

    int n = atoi(buf);
    
	for (int i=0; i<n; i++) 
    {
        int cn[200] = {0};

        double p[200] = {0};

        inf >> buf; int num = atoi(buf);
        for (int ii=0; ii<num; ii++) 
        {
            inf >> buf; cn[ii] = atoi(buf);
        }

        // find solution
        int sum = 0;
        for (int ii=0; ii<num; ii++){
            sum += cn[ii];
        }

        double evn = 2 * sum / num; 
        double sum2 = 0; int num2 = num; 
        for (int ii=0; ii<num; ii++) {
            if (cn[ii] > evn) {
                sum2 += cn[ii];
                num2--;
            }
        }

        double sum3 = sum * 2 - sum2; 
        double evn2 = sum3 / num2;

        for (int ii=0; ii<num; ii++) {
            if (cn[ii] > evn) {
                p[ii] = 0;
            }
            else {
                p[ii] = (evn2 - cn[ii]) / sum;
            }
        }

        cout << "Case #" << i+1 << ": ";
        for (int ii=0; ii<num; ii++) {
            printf("%f ", p[ii]*100);
        }
        printf("\n");
	}

	return 0;
}

