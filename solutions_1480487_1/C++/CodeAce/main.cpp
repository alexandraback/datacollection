#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;


int t;
int n;
int p[1000];
double z[1000];

int main() {

    ifstream fin("a2.in");
    ofstream fout("a2.out");

    string s;

    fin >> t;
	    
    for (int tc=0; tc<t; tc++) {
        fin >> n;

		double sum = 0, sum2 = 0;
		for (int i=0; i<n; i++) {
			fin >> p[i];
			sum += p[i];
		}
		
		double avg = 2*sum/n;

		int k = 0;
		for (int i=0; i<n; i++) {			
			if (p[i] >= avg) 
				z[i] = 0;			
			else {
				k++;
				sum2 += p[i];
			}
		}

		double avg2 = (sum+sum2)/k;
		for (int i=0; i<n; i++)
			if (p[i] < avg) {
				z[i] = abs(100*(avg2-p[i])/sum);
			}
		
        fout << "Case #" << tc+1 << ":";
		fout.precision(6);
		for (int i=0; i<n; i++)
			fout << fixed << " " << z[i];
		fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
