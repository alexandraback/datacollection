#include <istream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;
#define INPFILE "input.in"
#define OUTFILE "output.out"

ifstream inp;
ofstream out;

class Linker {
public:
	Linker(int num, string nm) :mNum(num), name(nm), mParent(nullptr) {

	}
	void join(shared_ptr<Linker> par) {
		//par = par->GetParent();
		while (par->mParent) 
			par = par->mParent;
		if (mParent == nullptr)
			mParent = par;
		else {
			shared_ptr<Linker> npar = GetParent();
			npar->mParent = par;
		}
	}
	int getnum() {
		if(mParent == nullptr)
			return mNum;
		shared_ptr<Linker> npar = GetParent();
		return npar->mNum;
	}
protected:
	shared_ptr<Linker> GetParent() {
		if (mParent == nullptr)
			return nullptr;
		shared_ptr<Linker> npar = mParent;
		while (npar->mParent)
			npar = npar->mParent;
		return npar;
	}
	shared_ptr<Linker> mParent;
	int mNum;
	string name;
};

template <typename T>
struct DLLNode {
	T mVal;
	shared_ptr<DLLNode> prev, next;
	DLLNode(T val):mVal(val), prev(nullptr), next(nullptr){}
};


void calculate(int t) {

	int J, P, S, K;
	inp >> J >> P >> S >> K;
	if (K > S)
		K = S;
	int tot = J*P*K;
	out << "Case #" << t + 1 << ": " << tot << endl;
	for (int i = 1; i <= J; i++) {
		//string str;
		char chi = '0' + i;
		for (int j = 1; j <= P; j++) {
			char chj = '0' + j;
			for (int k = 0; k < K; k++) {
				int t = i + j + k;
				if (t > S)
					t -= S;
				char chk = '0' + t;
				out << chi << " " << chj << " " << chk << endl;
			}
		}
	}

}


int main() {
	int T;
	inp.open(INPFILE);
	out.open(OUTFILE);
	inp >> T;
	for (int t = 0; t < T; t++) {
		calculate(t);
	}
}
