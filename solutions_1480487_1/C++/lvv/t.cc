#include "scc/cj.h"		// http://github.com/lvv/scc
//#include "lvv/lvv.h"


int main() {
	size_t tt(in);  NL;
	double e = 0.000001;

	for(size_t t=1;  t<=tt;  t++)  {
		cout << "Case #" <<  t << ": ";
		long N(in); vlong J=in(N);
		double X=0.0;
		//__ N, J;
		for(auto j: J) X+=j;
		//__ X;
		
		auto JJ = J;	
		sort(+JJ, -JJ);
		

							//__ JJ;

		while(!!JJ) {
			double Pm=JJ++;
			double Ys = 0.0;
			for(auto j: JJ) 
				Ys += (Pm - j)/X;
			if (Ys < 1.0+e) break;
			JJ--;
		} 

		double JJs=0.0;
		for (auto j: JJ)  JJs += j;

		double Pm = JJs/~JJ + X/~JJ;
							//__ JJ;

		iFOR(N) {
			if(Pm + e < J[i])		_ 0.0; 
			else			_ std::setprecision (9) << (Pm - J[i])/X * 100;
			_  " "; 
		}
		_ endl;
	}
}
