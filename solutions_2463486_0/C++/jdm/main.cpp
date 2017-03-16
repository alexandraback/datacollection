#include <cassert>

#include <string>
using std::string;

// Boost libraries available from www.boost.org 
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;

#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

#include <cstdlib>
using std::abs;

#include <cmath>
using std::sqrt;

#include <algorithm>
using std::transform;
using std::max;
using std::min;

#include <vector>
using std::vector;
#include <set>
using std::set;
using std::multiset;

#include <utility>
using std::pair;
using std::make_pair;

#include <memory>
using std::auto_ptr;

#include <map>
using std::map;

#include <list>
using std::list;
#include <bitset>
using std::bitset;
#include <cstring>
using std::memset;

// Gnu multiprecision library available from www.gnu.org (package
// libgmpxx4ldbl in Debian).
#include <gmpxx.h>

typedef int64_t Int;

Int T;
string A, B;

string specials[] = {
    "1",
    "4",
    "9",
    "121",
    "484",
    "10201",
    "12321",
    "14641",
    "40804",
    "44944",
    "1002001",
    "1234321",
    "4008004",
    "100020001",
    "102030201",
    "104060401",
    "121242121",
    "123454321",
    "125686521",
    "400080004",
    "404090404",
    "10000200001",
    "10221412201",
    "12102420121",
    "12345654321",
    "40000800004",
    "1000002000001",
    "1002003002001",
    "1004006004001",
    "1020304030201",
    "1022325232201",
    "1024348434201",
    "1210024200121",
    "1212225222121",
    "1214428244121",
    "1232346432321",
    "1234567654321",
    "4000008000004",
    "4004009004004"
};

Int only_ones(Int len) 
{
    Int k = (len + 1) / 2 -1;
    /* kc3+kc2+kc1+kc0 where c=choose */
    return (k * (k-1) /2 * (k-2) / 3) + (k * (k -1) / 2)  + k + 1; 
}

Int mylog(Int x)
{
    //cerr << "(" << x << ")";
    return x;
}

Int choose(int n, int k) {
    Int total = 1;
    for (int i=1; i <=k; ++i) {
        total *= (n - k + i);
        total /= i;
    }
    //cerr << "(" << n << "c" << k << "=" << total << ")" << endl;
    return total;
}

Int only_ones_before(string num, int ones, string build, char val, size_t at)
{
    build[at] = val;
    build[build.size() - at - 1] = val;
    //cerr << ones << "@" << at << "P" << val << "[" << build << "]" << num <<endl;
    if (val == '1') --ones;
    if (ones == 0) return mylog(build <= num ? 1 : 0);
    if (at > (num.size()-1) / 2) return mylog(0);
    ++at;
    if (num[at] > '1') return mylog(choose((num.size()-1)/2-at+1, ones));
    if (num[at] == '0') return mylog(only_ones_before(num, ones, build, '0', at));
    Int tot = only_ones_before(num, ones, build, '1', at);
    num[at+1] = '2';
    tot += only_ones_before(num, ones, build, '0', at);
    return mylog(tot);
}

Int only_ones_before(string num)
{
    if (num[0] > '1') return mylog(only_ones(num.size()));
    return only_ones_before(num, 4, string(num.size(),'0'),'1',0)
        + only_ones_before(num, 3, string(num.size(),'0'),'1',0)
        + only_ones_before(num, 2, string(num.size(),'0'),'1',0)
        + only_ones_before(num, 1, string(num.size(),'0'),'1',0);
}

Int two_in_the_middle(Int len)
{
    return len/2 * (len%2);
}

Int two_in_the_middle_before(string num)
{
    if (num.size() % 2 == 0) return 0;
    string t(num.size(), '0');
    t[0] = '1';
    t[t.size()-1] = '1';
    t[t.size()/2] = '2';
    //cerr << "t: " << t << endl;
    for (Int i=t.size()/2; i >= 1; --i) {
        string s = t;
        if (i < t.size()/2) {
            s[i] = '1';
            s[t.size() -i -1] = '1';
        }
        //cerr << s << " " << num << " " << i << endl;
        if (s > num) return t.size()/2 - i;
    }
    return num.size() / 2;
}

Int two_on_the_outside() {return 2;}

Int two_on_the_outside_before(string num)
{
    string t(num.size(), '0');
    t[0] = '2';
    t[t.size()-1] = '2';
    if (t <= num) {
        t[t.size()/2] = '1';
        if (t <= num) {
            return 2;
        } else {
            return 1;
        }

    } else {
        return 0;
    }
}

Int count_range(const string& a, const string& b)
{
    Int tot = 0;
    if (a.size() == b.size()) {
        tot += only_ones_before(b);
        //cerr << "1 >>b>" << b << " " << tot << endl;
        tot -= only_ones_before(a);
        //cerr << "2 >>a>" << a << " " << tot << endl;
        tot += two_in_the_middle_before(b);
        //cerr << "3 >>>>" << tot << endl;
        tot -= two_in_the_middle_before(a);
        //cerr << "4 >>>>" << tot << endl;
        tot += two_on_the_outside_before(b);
        //cerr << "5 >>>>" << tot << endl;
        tot -= two_on_the_outside_before(a);
        //cerr << "6 >>>>" << tot << endl;
        return tot;
    }

    tot = only_ones(a.size());
    //cerr << "1>>>>" << a << " " << tot << endl;
    tot -= mylog(only_ones_before(a));
    //cerr << "2>>>>" << tot << endl;
    tot += two_in_the_middle(a.size()) - two_in_the_middle_before(a);
    //cerr << "3>>>>" << tot << endl;
    tot += two_on_the_outside() - two_on_the_outside_before(a);
    //cerr << "4>>>>" << tot << endl;
    //cerr << "loop" << a.size() + 1 << " to " << b.size() << endl;
    for (Int i = a.size() + 1; i < b.size(); ++i) {
        tot += only_ones(i) + two_in_the_middle(i) + two_on_the_outside();
        //cerr << i << " 5>>>>" << tot << endl;
    }
    tot += only_ones_before(b);
    //cerr << "6>>>>" << tot << endl;
    tot += two_in_the_middle_before(b);
    //cerr << "7>>>>" << tot << endl;
    tot += two_on_the_outside_before(b);
    //cerr << "8>>>>" << tot << endl;
    return tot;
}

    
Int answer()
{
    //cerr << "considering " << A << " and " << B << endl;
    mpz_class a, b, aa, bb;
    a = A;
    b = B;
    aa = sqrt(a-1);
    bb = sqrt(b);
    Int tot = 0;
    for (int i = 0; i <39; ++i) {
        mpz_class sp;
        sp = specials[i];
        //cerr << sp << " " << a << endl;
        if (sp >= a && sp <= b) ++tot;
    }
    mpz_class cutoff;
    cutoff = "100000020000001";
    if (b >= cutoff) {
        if (a < cutoff) aa = "10000000";
        tot += count_range(aa.get_str(), bb.get_str());
    }
    return tot;
    
    
}

int main(int argc, char** argv)
{
    cin >> T;

    string junk;
    for (Int testcase = 1; testcase <= T; ++testcase) {
        cin >> A >> B;

        cout << "Case #" << testcase << ": "
            << answer() << endl;

    }
}


    


int xmain(int argc, char** argv)
{

    cout << count_range("11011011",  "1010110101") << endl;
    //cout << count_range("121242363242121",  "1020322416142230201") << endl;

    
    mpz_class a, b;
    a="121242363242120";
    b=sqrt(a);
    cout << b << endl;
    a="121242363242121";
    b=sqrt(a);
    cout << b << endl;
    a="121242363242122";
    b=sqrt(a);
    cout << b << endl;
    


}

#if 0
int main(int argc, char** argv)
{

   

    uint32_t i = 1;

    while(i) {
        string s = lexical_cast<string>(i);

        for (size_t j=0, k=s.size()-1; j<s.size(); ++j, --k) {
            if (s[j] != s[k]) goto nxt;
        }
        {
            uint64_t sq = uint64_t( i) *uint64_t(i);
            s = lexical_cast<string>(sq);
            for (size_t j=0, k=s.size()-1; j<s.size(); ++j, --k) {
                if (s[j] != s[k]) goto nxt;
            }
            cout << i << " " << sq << endl;
        }
nxt:
        ++i;
    }
    return 0;

}

//This list was generated by the above program.
1 1
2 4
3 9
11 121
22 484
101 10201
111 12321
121 14641
202 40804
212 44944
1001 1002001
1111 1234321
2002 4008004
10001 100020001
10101 102030201
10201 104060401
11011 121242121
11111 123454321
11211 125686521
20002 400080004
20102 404090404
100001 10000200001
101101 10221412201
110011 yw12102420121
111111 12345654321
200002 40000800004
1000001 1000002000001
1001001 1002003002001
1002001 1004006004001
1010101 1020304030201
1011101 1022325232201
1012101 1024348434201
1100011 1210024200121
1101011 1212225222121
1102011 1214428244121
1110111 1232346432321
1111111 1234567654321
2000002 4000008000004
2001002 4004009004004
10000001 100000020000001
10011001 100220141022001
10100101 102012040210201
10111101 102234363432201
11000011 121000242000121
11011011 121242363242121
11100111 123212464212321
11111111 123456787654321
20000002 400000080000004
100000001 10000000200000001
100010001 10002000300020001
100020001 10004000600040001
100101001 10020210401202001
100111001 10022212521222001
100121001 10024214841242001
101000101 10201020402010201
101010101 10203040504030201
101020101 10205060806050201
101101101 10221432623412201
101111101 10223454745432201
110000011 12100002420000121
110010011 12102202520220121
110020011 12104402820440121
110101011 12122232623222121
110111011 12124434743442121
111000111 12321024642012321
111010111 12323244744232321
111101111 12343456865434321
111111111 12345678987654321
200000002 40000000800000004
200010002 40004000900040004
1000000001 1000000002000000001
1000110001 1000220014100220001
1001001001 1002003004003002001
1001111001 1002223236323222001
1010000101 1020100204020010201
1010110101 1020322416142230201
1011001101 1022123226223212201
1011111101 1022345658565432201
1100000011 1210000024200000121
1100110011 1210242036302420121
1101001011 1212203226223022121
1101111011 1212445458545442121
1110000111 1232100246420012321
1110110111 1232344458544432321
1111001111 1234323468643234321
2000000002 4000000008000000004
#endif

