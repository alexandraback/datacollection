#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;


// ====== Defines ======


// ------ Defines ------


// ====== Types ======


// ------ Types ------


// ====== Global Variables ======

#ifdef DBG
std::fstream logs;
#endif

int R, C, W;

// ------ Global Variables ------


// ====== Function declarations ======


// ------ Function declarations ------


int init_only_once()
{
#ifdef DBG
	logs << ">>>>init_only_once()" << endl;
#endif



#ifdef DBG
	logs << "<<<<init_only_once()" << endl << endl;
#endif
        return 0;
}

int handle_input()
{
#ifdef DBG
	logs << ">>>>>>handle_input()" << endl;
#endif

	cin >> R >> C >> W;


#ifdef DBG
	logs << "<<<<<<handle_input()" << endl << endl;
#endif
        return 0;
}

int init_per_case()
{
#ifdef DBG
	logs << ">>>>>>init_per_case()" << endl;
#endif



#ifdef DBG
	logs << "<<<<<<init_per_case()" << endl << endl;
#endif
        return 0;
}

long long run()
{
#ifdef DBG
	logs << ">>>>>>run()" << endl;
#endif

	long long ans = 0;

	const int x = C / W;
	const int r = C % W;

	if (0 == r)
		ans = x + W - 1;
	else
		ans = x + W;

	ans += x * (R - 1);

#ifdef DBG
	logs << "<<<<<<run() = " << ans << endl << endl;
#endif
	return ans;
}

int main()
{
#ifdef DBG
        logs.open("log.txt", std::fstream::out);
	logs << ">>main()" << endl << endl;
#endif

        init_only_once();

        int total_cases_count = 0;
        cin >> total_cases_count;

        long long run_ret = 0;

        for (int tt = 1; tt <= total_cases_count; tt++) {

                handle_input();

                init_per_case();

                run_ret = run();

                cout << "Case #" << tt << ": " << run_ret << endl;

#ifdef DBG
		logs << "Case #" << tt << ": " << run_ret << endl;
#endif
        }


#ifdef DBG
	logs << "<<main()" << endl;
	logs.close();
#endif
        return 0;
}

