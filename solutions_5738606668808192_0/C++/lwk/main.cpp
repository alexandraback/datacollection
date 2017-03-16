
#include "utils.hpp"

#define G_CODE_JAM

#ifndef GDEBUG // debug or not
#define imshow(a,b)
#define waitKey(a)
#endif

#include<boost/lexical_cast.hpp>
#include<bitset>
using namespace boost;

/// Class representing our main test case
class TestCase{

	public:
		// Data of the problem
		int N;
		int J;

		set<uint32_t> denom;

		// Final score
		// int score = 0;
		vector<string> coins;
		vector<vector<int>> divs;

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


const vector<int> primes = {2,3,5,7,11};


int check(int n, char d)
{
	stringstream ss;
	int n2 = n;
	while(true)
	{
		ss << n2;
		// cout << "find " << d << " in " << ss.str() << endl;
		size_t ret = ss.str().find(d);
		if(ret != string::npos)
			return n2;
		n2 += n;
	}
}

string gen(int n, uint& seed)
{
	stringstream ss;
	ss << "1";
	assert(n > 2);
	for(int i = 0 ; i < n-2 ; i++)
		ss << rand_r(&seed)%2;

	ss << "1";
	return ss.str();
}

int64_t isPrime(int64_t number){

	if(number < 2) assert(false);
	if(number == 2) return -1;
	if(number % 2 == 0) return 2;
	for(int i=3; (i*i)<=number; i+=2){
		if(number % i == 0 ) return i;
	}
	return -1;
}

int validateModulo(const string& coin, int div)
{
	int n = 0;
	for(auto c : coin)
		n += (c == '1'); // boost::lexical_cast<int>(c);
	if(n%div == 0)
		return div;
	return -1;
}

/*
int validate(const string& coin, int base)
{
	switch(base)
	{
		case 2: return 1;
		case 3: return validateModulo(coin, 2);
		case 4: return validateModulo(coin, 3);
		case 5: return validateModulo(coin, 2);
		case 6: return validateModulo(coin, 5);
		case 7: return validateModulo(coin, 2);
		case 8: return validateModulo(coin, 7);
		case 9: return validateModulo(coin, 2);
		case 10: return validateModulo(coin, 3);
		default: assert(false);
	}
}
*/

bool modulo(const string& coin, int div, int base)
{
	int rem = 0;

	for(auto bit : coin)
	{
		rem *= base;
		if(bit == '1')
			rem += 1;
		//cout << "rem" << rem <<endl;
		rem %= div;
	}
	return rem == 0;
}

int validate(const string& coin, int base)
{
	for(auto p : primes)
	{
		if(modulo(coin, p, base))
			return p;
	}
	return -1;
}

/// Implement here the main work of the test case
void TestCase::doWork()
{
	/*
	uint seed = time(NULL);
	while(true)
	{
		string coin = gen(N, seed);
		vector<int> divs2;
		// cout << "test " << coin << endl;
		for(int i = 2 ; i <= 10 ; i ++)
		{
			int ret = validate(coin, i);
			if(ret>=0)
			{
				// cout << "ok " << coin << " for " << i << endl;
				divs2.push_back(ret);
			}
			else
				goto nexlab;
		}

cout<<divs2.size() <<endl;
		assert(divs2.size() == 9);
		coins.push_back(coin);
		cout << "Found " << coin << endl;
		divs.push_back(divs2);
		if(coins.size() == 10)
			break;
		nexlab:
		;
	}
	*/

	for(int t = 1 ; t <= 0xffff ; t++)
	{
		if((t & 0x8000) == 0 || (t & 1) == 0) continue;

		vector<int> divs2;
		stringstream ss;
		std::bitset<16> x(t);
		// std::bitset<32> x(t);
		ss << x;
		cout << "test " << ss.str() << endl;
		string coin = ss.str();
		for(int base = 2 ; base <= 10 ; base ++)
		{
			int ret = validate(coin, base);
			if(ret>=0)
			{
				// cout << "ok " << coin << " for " << i << endl;
				divs2.push_back(ret);
			}
			else goto nexlab;
		}
		cout<<divs2.size() <<endl;
		assert(divs2.size() == 9);
		cout << "Found " << coin << endl;

		coins.push_back(coin);
		divs.push_back(divs2);
		if(coins.size() == J)
			break;
		nexlab:
		;
	}
}

/// Write the result to file
ostream & operator << (ostream & os,TestCase &t){

	int i = 0;
	for(auto &elem : t.coins)
	{
		os << endl;
		os << elem;
		for(auto div : t.divs[i])
			os << " " << div;
		i++;
	}
	return os;
}

istream & operator >> (istream & is,TestCase &t){
	// Read input
	is >>t.N;
	is >>t.J;
	return is;
}


int main(int argc, char **argv){
	vector<TestCase *> tarr;
	
	assert(argc > 1);
	string filename(argv[1]); // TODO remove args first !!!

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



