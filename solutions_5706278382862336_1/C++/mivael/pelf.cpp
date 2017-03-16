
#include <iostream>
using std::clog;
using std::endl;
using std::flush;
using std::ostream;

// #include <vector>
// using std::vector;

// #include <string>
// using std::string;

// #include <map>
// using std::map;
// using std::multimap;

// #include <set>
// using std::set;

#include <algorithm>
using std::min;

#include <cassert>

typedef long long int  pq_t;

int main(void)
{
    using std::cin;  using std::cout;

    assert(sizeof(pq_t) * 8 == 64);  // 10^12 does not fit 32 bit

    if (!cin.good())  return 1;
    int T;  cin >> T;

    for (int tc = 1;  tc <= T;  ++tc)
    {
	cout << "Case #" << tc << ": " << flush;
	if (!cin.good())  return 2;
	pq_t P, Q;  char ch;  cin >> P >> ch >> Q;
	assert(ch == '/'  &&  Q > 0  &&  P >= 0);

	clog << "tc=" << tc << " p=" << P << " q=" << Q << "." << endl;

	bool impossible = false;
	pq_t divisor = ((pq_t)1 << 40);

	{
	    pq_t new_q = 1;
	    int pwr = 0;
	    for (;  (Q & 1) == 0;  Q >>= 1)  { new_q <<= 1;  ++pwr; }

	    clog << "\t\t" "q=" << Q << " new_q=" << new_q << "."  << endl;

	    if (P % Q == 0)  P /= Q;
	    else  impossible = true;

	    Q = new_q;

	    pq_t fpwr = 40 - pwr;
	    P <<= fpwr;  Q <<= fpwr;
	    assert(Q == divisor);
	}

	if (impossible)
	    clog << "\t" "impossible."  << endl;
	else
	    clog << "\t" "p=" << P << " q=" << Q << "."  << endl;

	int result = -1;
	if (!impossible)
	{
	    pq_t elf_part = P;
	    assert(divisor == ((pq_t)1 << 40));
	    result = 0;
	    for (;;)
	    {
		++result;
		divisor >>= 1;  assert(divisor > 0);
		elf_part = min(divisor, elf_part);
		if (elf_part == divisor)  break;
	    }
	}

	if (impossible)
	    cout << "impossible" << endl;
	else
	{
	    assert(0 < result  &&  result <= 40);
	    cout << result << endl;
	}
    }

    return 0;
}
