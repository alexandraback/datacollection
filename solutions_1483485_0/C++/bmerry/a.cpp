#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    const string cipher =
        "ejp mysljylc kd kxveddknmc re jsicpdrysi"
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
        "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    const string plain =
        "our language is impossible to understand"
        "there are twenty six factorial possibilities"
        "so it is okay if you want to just give up";

    map<char, char> decode;
    decode['y'] = 'a';
    decode['e'] = 'o';
    decode['q'] = 'z';
    for (int i = 0; i < SZ(cipher); i++)
        if (isalpha(cipher[i]))
        {
            assert(!decode.count(cipher[i]) || decode[cipher[i]] == plain[i]);
            decode[cipher[i]] = plain[i];
        }
    assert(decode.size() == 25);
    int missing_plain = ('a' + 'z') * 13;
    int missing_cipher = missing_plain;
    for (map<char, char>::const_iterator i = decode.begin(); i != decode.end(); i++)
    {
        missing_cipher -= i->first;
        missing_plain -= i->second;
    }
    assert(!decode.count(missing_cipher));
    assert(missing_cipher == 'z');
    decode[missing_cipher] = missing_plain;

    int cases;
    cin >> cases >> ws;
    for (int cas = 0; cas < cases; cas++)
    {
        string line;
        getline(cin, line);
        for (int i = 0; i < SZ(line); i++)
            if (isalpha(line[i]))
                line[i] = decode[line[i]];
        printf("Case #%d: %s\n", cas + 1, line.c_str());
    }
    return 0;
}
