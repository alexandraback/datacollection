
#include "utils.hpp"

#define G_CODE_JAM

#ifndef GDEBUG // debug or not
#define imshow(a,b)
#define waitKey(a)
#endif

#include<boost/lexical_cast.hpp>
using namespace boost;

/// Class representing our main test case
class TestCase{

	public:
		// Data of the problem
		int K;
		int C;
		int S;


		// Final score
		// int score = 0;
		vector<uint64_t> tiles;

		// Internal use
		const int test_num;

		// Params for optimization // code jam only
		struct Parameters
		{
			Parameters(size_t i){
				K3 = ks3.at(i % ks3.size());
				i /= ks3.size();
				K2 = ks2.at(i % ks2.size());
				i /= ks2.size();
				K1 = ks1.at(i % ks1.size());
				i /= ks1.size();
			}
			size_t size() {return ks1.size() * ks2.size() * ks3.size();}
			double K1;
			double K2;
			double K3;

			const vector<double> ks1 = {3,10,30,100};
			const vector<double> ks2 = {0.01,0.03,0.05,0.08,0.1,0.12};
			const vector<double> ks3 = {0};

			inline friend ostream& operator<< (ostream& os, const Parameters& p) {os << ".K1=" << p.K1 << ".K2=" << p.K2 << ".K3=" << p.K3; return os;}
		};
		Parameters params;

	public:
		TestCase(int _test_num, size_t _param_num) : test_num(_test_num), params(_param_num) {}
		~TestCase(){};
		void doWork();
		void WriteToFile(const string& inputFile, const string& directory)
		{
			ofstream fout;
			stringstream ss;
#ifdef G_CODE_JAM
			ss << directory << inputFile << ".out";
			fout.open(ss.str().c_str(), fstream::app);
			fout<< "Case #"<<(test_num + 1)<<": "<<*this<<endl;
#else
			ss << directory << inputFile << "." << OutputFileName() << ".out";
			fout.open(ss.str().c_str());
			fout<< *this << endl;
#endif
		}
		friend ostream & operator << (ostream & os,TestCase &t);
		friend istream & operator >> (istream & is,TestCase &t);

	private:
		bool started = false;
};

/// Implement here the main work of the test case
void TestCase::doWork()
{
	/* simple
	assert(S==K);

	for(int i = 0 ; i < S ; i++)
		tiles.push_back(i + 1);
	*/
	tiles.clear();
	if(S*C < K)
		return;
	// cout <<S*C<< "ADFASDF" << K << endl;
	
	int k = 0;
	int s = 0;

	while(k < K && s < S)
	{
		// compute tile number
		uint64_t tile = 0;
		int c = 0;
		while(k < K && c < C)
		{
			if(tile == 0)
				tile = k + 1;
			else
			{
				tile = (tile - 1) * K + k + 1; // (k++, k++, k++, k++)
			}
			cout << tile << " ";
			c++;
			k++;
		}
		cout << tile << endl;
		tiles.push_back(tile);
		s++;
	}
}

/// Write the result to file
ostream & operator << (ostream & os,TestCase &t){

	if(t.tiles.empty())
	{
		os << "IMPOSSIBLE";
		return os;
	}

	for(auto &elem : t.tiles)
		os << elem << " ";
	return os;
}

istream & operator >> (istream & is,TestCase &t){
	// Read input
	is >>t.K;
	is >>t.C;
	is >>t.S;
	return is;
}


int main(int argc, char **argv){
	vector<TestCase *> tarr;
	
	assert(argc > 1);
	string filename(argv[1]);

	// open in and out files

	string dirname = "out_" + timeStamp() + '/';
	stringstream cmd;
	cmd << "mkdir -p " << dirname << " && rm -f out_latest && ln -s " << dirname << " out_latest";
	if(system(cmd.str().c_str()) != 0)
	{
		cout << "error while making " << dirname << endl;
		exit(1);
	}

	
#ifndef G_CODE_JAM // Multiple problems in single file: e.g. google code jam
	// Some parameter to vary for optimization

	size_t gN = UINT_MAX;
#else
	size_t gN = UINT_MAX;
	ifstream fin;
	fin.open (filename.c_str());
	// read params
	fin>>gN;

	// HACK for getline
	// string a;
	// getline(fin,a);
#endif

	TestCase *tptr;
	for(size_t i=0;i<gN;i++){
#ifndef G_CODE_JAM
		ifstream fin;
		fin.open (filename.c_str());
		if(!fin.is_open()) {
			cout << "Cannot open " << filename << endl;
			exit(-1);
		}
#endif
		tptr = new TestCase(i, i);
		if(gN == UINT_MAX)
		{
			gN = tptr->params.size();
			cout << "Number of simulation: " << gN << endl;
		}
		fin >> *tptr;
		tarr.push_back(tptr);
	}

	int max_threads = thread::hardware_concurrency();
	if(argc > 2 && atoi(argv[2]) > 0)
		max_threads =  atoi(argv[2]);
#ifdef GDEBUG
	max_threads = 1;
#endif

	if(max_threads > 1)
	{
		cout << "Create a pool of " << max_threads << " working threads" << endl;
		vector< future<string> > results;
		ThreadPool pool(max_threads);

		for(auto& elem : tarr)
		{
			results.emplace_back(
				pool.enqueue([&elem,&filename,&dirname]{
					cout << "starting job" << endl;
					elem->doWork();
#ifndef G_CODE_JAM
					elem->WriteToFile(filename, dirname);
#endif
					stringstream ss;
					ss << endl << "Found solution " << *elem <<endl;
					return ss.str();
				})
			);
		}

		// for(auto && result: results)
			// cout << result.get() << ' ';
	}

#ifndef G_CODE_JAM
	// Write down results
	for(auto& elem : tarr)
	{
		if(max_threads <= 1)
		{
			elem->doWork();
			elem->WriteToFile(filename, dirname);
		}
	}
#else
	// Write down results
	for(auto& elem : tarr)
	{
		if(max_threads <= 1)
		{
			elem->doWork();
		}
		elem->WriteToFile(filename, dirname);
	}
#endif
}



