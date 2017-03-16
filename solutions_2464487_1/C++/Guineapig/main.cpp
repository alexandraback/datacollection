#include "my_header.h"


typedef unsigned long long ullong;


class solver
{
public:
    
	ullong solve(ullong r0, ullong t)
	{
        ullong n_low = 1;
        ullong n_high = 1000000000;
        
        while (n_low < n_high-1) {
//            cout << n_low << " - " << n_high << endl;
            ullong n = (n_low + n_high) / 2;
            ullong a = n * (2 * r0 + 2 * n - 1);
            if (a == t)
                return n;
            else if (a < t)
                n_low = n;
            else
                n_high = n;
        }
        
        assert(n_low == n_high || n_low == n_high - 1);
        
        ullong a = n_high * (2 * r0 + 2 * n_high - 1);
        if (a <= t)
            return n_high;
        else
            return n_low;
        
//        ullong r = r0;
//        ullong max_n = 0;
//        ullong total_a = 0;
//        for (ullong n=1 ; ; n++)
//        {
////            ullong a = n * n + 2 * n * r;
//            ullong a = 2 * r + 1;
////            if (n < 10)
////            cout << "*** " << a << endl;
//            total_a += a;
//            ullong total_a_2 = n * (2 * r0 + 2 * n - 1);
//            if (total_a != total_a_2) {
//                cout << total_a << " - " << total_a_2 << " - " << n << " - " << r << endl;
//            }
//            assert(total_a == total_a_2);
//            if (total_a <= t)
//                max_n = n;
//            else
//                break;
//            r += 2;
//        }
//		return max_n;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
    unsigned long long r, t;
    ifs >> r >> t;
    
	ullong res = solver().solve(r, t);
    
	cout << "Case #" << case_num << ": " << res << endl;
	ofs << "Case #" << case_num << ": " << res << endl;
}

/*************************************************************************************/

int main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);
    
	ofs.precision(7);
	ofs << fixed;
    
	int n = to_int(get_line(ifs));
    
//	assert(n > 0 && n < 200);
    
	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
    
    return 0;
}
