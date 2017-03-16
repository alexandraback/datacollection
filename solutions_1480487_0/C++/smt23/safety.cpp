#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	ifstream in(argv[1]);
	ofstream out(argv[2]);

	int N;
	in >> N;

	out.precision(10);

	for(int i = 0; i < N; ++i) {
		int np; in >> np;
		int *scores = new int[np];
		int sum = 0;

		for(int j = 0; j < np; ++j) {
			in >> scores[j];
			sum += scores[j];
		}

		double avg = 1.0*sum/np;

		out << "Case #" << i+1 << ": ";

		cout << "Case #" << i+1 << endl;

		bool *exclude = new bool[np];
		for(int j = 0; j < np; ++j) {
			exclude[j] = 1.0*(2.0*avg - scores[j])/sum <= 0;
			if(exclude[j]) cout << "excluding " << scores[j] << endl;
		}

		cout << "np: " << np << endl;

		int fp = 0; double avg2 = 0;
		for(int j = 0; j < np; ++j) {
			if(!exclude[j]) {
				cout << "adding " << scores[j] << endl;
				++fp;
				cout << "fp " << fp << endl;
				avg2 += scores[j];
			}
		}

		avg = 1.0*sum/fp; // If everyone low score received same amount of points
		avg2 = 1.0*avg2/fp; // If all low scores were the same

		cout << "avg1: " << avg << "\t\tavg2: " << avg2 << endl << endl;

		for(int j = 0; j < np; ++j) {
			if(!exclude[j])
				out << 100.0*(avg + avg2  - scores[j])/sum << " ";
			else
				out << "0 ";
		}

		out << endl;

		delete exclude;
		delete scores;
	}

	in.close();
	out.close();

	return 0;
}
