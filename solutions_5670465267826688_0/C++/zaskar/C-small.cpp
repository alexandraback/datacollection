#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

enum quat { ONE=0,I,J,K,MONE,MI,MJ,MK, NONE };

quat tmult [4][4] = { 
	{ONE,   I,   J,   K},
	{  I,MONE,   K,  MJ},
	{  J,  MK,MONE,   I},
	{  K,   J,  MI,MONE}
};

quat tabs [8] = { ONE,I,J,K, ONE,I,J,K };
quat tinv [8] = { MONE,MI,MJ,MK, ONE,I,J,K };

quat mult(quat q1, quat q2) {
	quat r = tmult[tabs[q1]][tabs[q2]];
	if ( (q1!=tabs[q1]) != (q2!=tabs[q2]) )
		r=tinv[r];
	return r;
}

quat reduce(vector<quat> &v) {
	quat q = v[0];
	for(unsigned int i=1;i<v.size();i++)
		q = mult(q,v[i]);
	return q;
}

int main(int argc, char *argv[]) {
	ifstream fin("C-small-attempt2.in");
//	ifstream fin("C-sample.in");
	ofstream fout("C-small-attempt2.out");
	int T;
	fin>>T;
	quat c2q[256]; 
	c2q[int(char('i'))] = I;
	c2q[int(char('j'))] = J;
	c2q[int(char('k'))] = K;
	for(int IC=0;IC<T;IC++) {
		int L,X;
		fin>>L>>X;
		fin.ignore();
		vector<quat>vals(L,NONE);
		for(int i=0;i<L;i++) { 
			char c;
			fin>>c;
			vals[i] = c2q[int(c)];
		}
		quat r = reduce(vals);
		bool can = (r==MONE && X%2==1) ||
			((r!=ONE&&r!=MONE) && X>=2 && (X-2)%4==0);
		if (can) {
			int N = L*X;
			quat q = vals[0];
			int p=1;
			while (p<N && q!=I) 
				q = mult(q,vals[(p++)%L]);
			if (q==I) {
				q = ONE;
				while (p<N && q!=J) 
					q = mult(q,vals[(p++)%L]);
				can = q==J;
//				if (can) {
//					q = ONE;
//					while (p<N) 
//						q = mult(q,vals[(p++)%L]);
//					cerr<<(q==K)<<endl;
//					if (q!=K) asm("int3"); asm("nop");
//				}
			} else {
				can = false;				
			}
		}
		fout<<"Case #"<<IC+1<<(can?": YES":": NO")<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

