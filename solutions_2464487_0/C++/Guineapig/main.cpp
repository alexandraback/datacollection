#include "my_header.h"


typedef unsigned long long ullong;


class solver
{
public:
    
	ullong solve(ullong r, ullong t)
	{
        ullong max_n = 0;
        ullong total_a = 0;
        for (ullong n=1 ; ; n++)
        {
//            ullong a = n * n + 2 * n * r;
            ullong a = 2 * r + 1;
//            if (n < 10)
//            cout << "*** " << a << endl;
            total_a += a;
            if (total_a <= t)
                max_n = n;
            else
                break;
            r += 2;
        }
		return max_n;
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
