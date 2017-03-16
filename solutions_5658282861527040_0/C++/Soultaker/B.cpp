/* This is my Google Code Jam C++ solution template.
 *
 * For the real solution code, scroll down to part 6. The rest of the file
 * contains pre-written library and framework code.
 *
 * The code is intended to work with a C++11 compiler on a POSIX platform.
 * I use GCC 4.7.3 on Linux with an x86-64 processor.
 *
 * All code in this file was written by me, unless otherwise noted.
 * I hereby grant permission to copy, modify and reuse my code for any purpose.
 *
 * Maks Verver  [Soultaker]  <maksverver@geocities.com>  July 2008 - May 2013
 */

/* GCJ template part 01 -- Common headers */
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/* GCJ template part 02 -- Common macro definitions */
#define FOR(i, a, b)    for(int i = int(a); i < int(b); ++i)
#define REP(i, n)       FOR(i, 0, n)
#define FORE(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define REPE(i, n)      FORE(i, 0, n)
#define FORD(i, a, b)   for(int i = int(b) - 1; i >= int(a); --i)
#define REPD(i, n)      FORD(i, 0, n)
#define FORDE(i, a, b)  for(int i = int(b); i >= int(a); --i)
#define REPDE(i, n)     FORDE(i, 0, n)
#define IT(c)           __typeof((c).begin())
#define FORIT(i, c)     for(IT(c) i = (c).begin(); i != (c).end(); ++i)
#define SZ(c)           (int((c).size()))
#define ALL(c)          (c).begin(), (c).end()
#define SET(m, v)       memset((m), (v), sizeof(m))
#define REVERSE(c)      reverse(ALL(c))
#define SORT(c)         sort(ALL(c))
#define UNIQ(c)         SORT(c), (c).erase(unique(ALL(c)), (c).end())
#define MAPRET(m, x)    { IT(m) _ = m.find(x); if(_ != m.end()) return _->second; }

/* GCJ template part 03 -- Common type definitions */
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;
typedef vector<VD> VVD;

/* GCJ template part 04 -- Utility function definitions */

/* Reads and returns the next line from standard input. */
inline string LINE()
{
    string line;
    getline(cin, line);
    assert(cin);
    return line;
}

/* Convert a value to a string */
template<class T> inline string STR(const T &v) {
    ostringstream oss;
    oss << v;
    return oss.str();
}

template<> inline string STR(const double &v) {
    ostringstream oss;
    oss.precision(numeric_limits<double>::digits10 + 1);
    oss << fixed << v;
    return oss.str();
}

//
// Basic parsing
//

template<class T> T PARSE(const string &s) {
    T r;
    istringstream iss(s);
    if(!(iss >> r)) throw "Type conversion failed!";
    return r;
}

VI PARSEVI(const string &s) {
    VI vi;
    istringstream iss(s);
    int i;
    while(iss >> i) vi.push_back(i);
    return vi;
}

VVI PARSEVVI(const VS &vs) {
    VVI vvi;
    vvi.reserve(SZ(vs));
    FORIT(i, vs) vvi.push_back(PARSEVI(*i));
    return vvi;
}

// Split string 's' by single characters, occuring in "sep"
VS SPLITC(const string &s, const string &seps = " ") {
    VS vs;
    if (s.empty()) return vs;
    string::size_type i, j;
    for(i = 0; (j = s.find_first_of(seps, i)) != string::npos; i = j + 1) vs.push_back(string(s, i, j - i));
    vs.push_back(string(s, i, j));
    return vs;
}

// Split string 's' by string 'sep'
VS SPLITS(const string &s, const string &sep) {
    VS vs;
    if (s.empty()) return vs;
    string::size_type i, j;
    for(i = 0; (j = s.find(sep, i)) != string::npos; i = j + SZ(sep)) vs.push_back(string(s, i, j - i));
    vs.push_back(string(s, i, j));
    return vs;
}

// Note: these are 32-bit functions
#define BIT(n) (1<<(n))
#define BITL(n) (1LL<<(n))
inline int BITCOUNT(unsigned x)             { return __builtin_popcount(x); }
inline int BITCOUNTL(unsigned long long x)  { return __builtin_popcountll(x); }
inline int TZEROS(unsigned x)               { return __builtin_ctz(x); }
inline int TZEROSL(unsigned long long x)    { return __builtin_ctzll(x); }
inline int LZEROS(unsigned x)               { return __builtin_clz(x); }
inline int LZEROSL(unsigned long long x)    { return __builtin_clzll(x); }
#define LOBIT(x) TZEROS(x)
#define HIBIT(x) (31 - LZEROS(x))
#define LOBITL(x) TZEROSL(x)
#define HIBITL(x) (63 - LZEROSL(x))

// Tests if string a starts with string b
inline bool startswith(const string &a, const string &b) {
    return a.size() >= b.size() && a.compare(0, b.size(), b) == 0;
}

// Tests if string a end with string b
inline bool endswith(const string &a, const string &b) {
    return a.size() >= b.size() && a.compare(a.size() - b.size(), b.size(), b) == 0;
}

template<class T> inline T SQR(T x) { return x*x; }

inline LL GCD(LL a, LL b) { while(b) { LL c = b; b = a%b; a = c; } return a; }
inline LL LCM(LL a, LL b) { return (a / GCD(a, b))*b; }

// Tests wether an integer is prime
// Testing all integers from 1 to 1,000,000 takes about 1.5s
bool PRIME(int n) {
    if (n < 2) return false;
    if ((n&1) == 0) return n == 2;
    for (int d = 3; d*d <= n; d += 2) if(n%d == 0) return false;
    return true;
}

// A fast prime sieve, generating prime numbers upto (and including)
// `max` using `max`/16 bytes of memory.
 // Takes about 0.2s for max=10M.
void GENPRIMES(vector<int> &primes, int max) {
    primes.clear();
    if (max < 2)
        return;

    /* Sieve (odd numbers only) */
    vector<bool> comp((max + 1)/2);
    for (int n = 3; n*n <= max; n += 2)
        if (!comp[n/2])
            for (int m = n*n; m <= max; m += 2*n)
                comp[m/2] = true;

    /* Collect primes */
    primes.push_back(2);
    for (int n = 3; n <= max; n += 2)
        if (!comp[n/2])
            primes.push_back(n);
}

// Hashing
template<class It> ULL HASH(It i, It j) {
    ULL h = 14695981039346656037ULL;
    while (i != j)
    {
        h *= 1099511628211ULL;
        h ^= *(i++);
    }
    return h;
}
inline ULL HASH(const string &s) { return HASH(ALL(s)); }

// Binary searches for the first index '_' in the range [a,b) so that (cond)
// is true, and returns this index if found, or b otherwise.
// Note that a and b should be of the same integral type!
#define BINSEARCH(a,b,cond) ({ __typeof((a)+(b)) l = (a), h = (b), _; \
    while(l<h) { _=(l>>1)+(h>>1)+(l&h&1); if(cond) h=_; else l=_+1; } h; })

// Printing of expressions (for debugging)
#define DUMP(expr) dump(cerr, #expr, expr)
template<class T> void dump(ostream &os, const char *desc, const T &value) {
    os << desc << " = " << value << '\n';
}
template<class T> void dump(ostream &os, const char *desc, const vector<T> &v) {
    os << desc << " = <"; REP(i, SZ(v)) os << (i?",":"") << v[i]; os << ">\n";
}
template<> void dump(ostream &os, const char *desc, const vector<string> &vs) {
    os << desc << " = \n"; FORIT(it, vs) os << '"' << *it << '"' << '\n';
}
/* GCJ template part 05 -- Execution framework */

class Result
{
    bool single;
    VS results;

public:
    Result()                        { clear(); };
    void clear()                    { results.clear(); single = true; };
    bool isEmpty() const            { return single && results.empty(); };
    bool isSingle() const           { return single; };
    void set(const string &s)       { clear(); results.push_back(s); };
    void set(const VS &vs)          { single = false; results = vs; };
    void add(const string &s)       { single = false; results.push_back(s); };
    const string getSingle() const  { return results.empty() ?
                                          string() : results.front(); };
    const VS &getMany() const       { return results; };
};


/* Represents a test case */
struct AbstractCase
{
    virtual ~AbstractCase() { }
    virtual void solve(Result &res) = 0;
};

/* To be implemented for the problem: */
static void initialize();       /* called once (at start-up) */
AbstractCase *read_case();      /* called for each test-case */

/*
 * Framework code starts here.
 */

#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

struct Job
{
    int  filedes;
    bool success;

    Job(int fd) : filedes(fd), success(0) { };
    virtual ~Job() { };
    virtual bool wait() { return success = true; };
};

struct ForkedJob : public Job
{
    pid_t pid;
    int   status;

    ForkedJob(int fd, pid_t pid) : Job(fd), pid(pid) { };
    bool wait() {
        if (waitpid(pid, &status, 0) < 0) { perror("waitpid failed"); abort(); }
        return success = (status == 0);
    }
};

static int num_cores()
{
    cpu_set_t mask;
    int res = 0;
    if (sched_getaffinity(0, sizeof(mask), &mask) == 0)
    {
        int i = CPU_COUNT(&mask);
        while (i-- > 0) if (CPU_ISSET(i, &mask)) ++res;
    }
    return res;
}

static int max_procs = num_cores(), first_case = 0, last_case = -1;
static bool show_prog = false, do_fork = true, dump_input = false;

static char path_in[512];       /* problem input file */
static char path_out[512];      /* problem output file (overwritten) */
static char path_ref[512];      /* reference output file (for comparison) */
static FILE *fp_out = stdout;

/* Options understood:
    -p N    Use at most N child processes (0 to prevent forking)
    -c N    Only process case N (useful for debugging; implies -p 0)
    -c N-M  Process cases N-M
    -d N-M  Dump input for cases N-M
    <name>  Read input from <name>.in and write output to <name>.out
*/
static void parse_args(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "p:c:d:v")) != -1)
    {
        switch (opt)
        {
        case 'p':
            max_procs = atoi(optarg);
            if (max_procs < 0 || max_procs > 1000)
            {
                cerr << "Invalid number of processes: " << max_procs << endl;
                exit(1);
            }
            break;

        case 'c':
        case 'd':
            dump_input = opt == 'd';
            if (sscanf(optarg, "%d-%d", &first_case, &last_case) == 2)
            {
                if (first_case >= 1 && last_case >= first_case ) break;
            }
            else
            if (sscanf(optarg, "%d", &first_case) == 1)
            {
                if ((last_case = first_case) >= 1) break;
            }
            cerr << "Invalid range of cases: " << optarg << endl;
            exit(1);
            break;

        case 'v':
            show_prog = true;
            break;

        default:
            cerr << "Unrecognized option!\n" << endl;
            exit(1);
        }
    }

    if (max_procs == 0 || first_case == last_case)
    {
        max_procs = 1;
        do_fork   = false;
    }

    if (optind < argc)
    {
        if (argc - optind > 1)
        {
            cerr << "Too many arguments!" << endl;
            exit(1);
        }

        strncpy(path_in, argv[optind], sizeof(path_in));
        strncat(path_in, ".in", sizeof(path_in));
        strncpy(path_out, argv[optind], sizeof(path_out));
        strncat(path_out, ".out", sizeof(path_in));
        strncpy(path_ref, argv[optind], sizeof(path_ref));
        strncat(path_ref, ".ref", sizeof(path_ref));

        if (freopen(path_in, "rt", stdin) == NULL)
        {
            cerr << "Unable to open input file " << path_in << endl;
            exit(1);
        }

        if (!dump_input)
        {
            /* Open output file (overwrites existing file!) */
            if ((fp_out = fopen(path_out, "wt")) == NULL)
            {
                cerr << "Unable to open output file " << path_out << endl;
                exit(1);
            }
        }

        show_prog = true;
    }
}

static Job *create_job(int id, AbstractCase *test_case)
{
    /* Open output file */
    char out_path[] = "job-XXXXXX";
    int fd = mkstemp(out_path);
    if (fd < 0) {
        perror("mkstemp failed");
        abort();
    }
    unlink(out_path);

    /* Create child process (if forking) */
    pid_t child_pid = 0;
    if (do_fork)
    {
        child_pid = fork();
        if (child_pid < 0)
        {
            perror("fork failed");
            abort();
        }
    }

    if (child_pid == 0)
    {
        /* Child process */

        /* Enable core dumps */
        struct rlimit rlim = { RLIM_INFINITY, RLIM_INFINITY };
        setrlimit(RLIMIT_CORE, &rlim);

        /* Create log file */
        char log_path[64];
        if (do_fork) {
            sprintf(log_path, "job-%03d.txt", id);
            if (freopen(log_path, "wt", stdout) == NULL) abort();
        }

        /* Solve case */
        Result result;
        test_case->solve(result);

        if (do_fork)
        {
            if (ftell(stdout) == 0) unlink(log_path);
        }

        /* Write output to file */
        if (!result.isEmpty())
        {
            char buf[64];
            sprintf(buf, "Case #%d:", id);
            write(fd, buf, strlen(buf));
            if (result.isSingle())
            {
                string line = result.getSingle();
                write(fd, " ", 1);
                write(fd, line.data(), line.size());
                write(fd, "\n", 1);
            }
            else
            {
                write(fd, "\n", 1);
                const VS &vs = result.getMany();
                FORIT(it, vs) {
                    write(fd, it->data(), it->size());
                    write(fd, "\n", 1);
                }
            }
        }

        /* Succesfully terminate to signal parent */
        if (do_fork) exit(0);
    }

    return do_fork ? new ForkedJob(fd, child_pid) : new Job(fd);
}

static void sig_handler(int sig)
{
    fprintf(stderr, "Process %d exiting on signal %d!\n", (int)getpid(), sig);
    exit(sig);
}

int main(int argc, char* argv[])
{
    parse_args(argc, argv);

    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    int cases = PARSE<int>(LINE());
    if (cases == 0) return 0;
    if (first_case < 1) first_case = 1;
    if (last_case < first_case || last_case > cases) last_case = cases;

    if (dump_input)
    {
        if (first_case > last_case) return 0;
        REP(_, first_case - 1) delete read_case();
        istream::streampos p = cin.tellg();
        REP(_, last_case - first_case + 1) delete read_case();
        istream::streampos q = cin.tellg();
        if (!cin || (p == q))
        {
            cerr << "Failed to read input data " << endl;
            exit(1);
        }
        if (!cin.seekg(p, ios::beg))
        {
            cerr << "Can't seek in input data!" << endl;
            exit(1);
        }
        vector<char> data(q - p);
        if (!cin.read(&data[0], q - p))
        {
            cerr << "Couldn't read input data!" << endl;
            exit(1);
        }
        if (data.back() != '\n') data.push_back('\n');
        if (data.front() == '\n') data.erase(data.begin());
        cout.write(&data[0], data.size());
        return 0;
    }

    time_t time_start = time(NULL);

    initialize();

    vector<Job*> jobs;
    int caseno = 1;
    REP(n, cases + max_procs)
    {
        if (n >= max_procs)
        {
            int jobid = n - max_procs + 1;
            Job *job = jobs[jobid - 1];

            if (!job)
                ;
            else
            if (job->wait())
            {
                char buffer[4096];
                size_t total_read = 0;
                ssize_t nread;

                lseek(job->filedes, 0, SEEK_SET);
                while ((nread = read(job->filedes, buffer, sizeof(buffer))) > 0)
                {
                    total_read += nread;
                    fwrite(buffer, nread, 1, fp_out);
                }
                if (!total_read)
                {
                    job->success = false;
                    fprintf(fp_out, "Case #%d produced no output!\n", jobid);
                }
                close(job->filedes);
            }
            else  /* job failed */
            {
                fprintf(fp_out, "Case #%d failed!\n", jobid);
            }
            fflush(fp_out);
        }
        if (n < cases)
        {
            AbstractCase *case_ = read_case();
            if (!cin)
            {
                cerr << "Failed to read input case " << caseno << endl;
                exit(1);
            }
            jobs.push_back((caseno >= first_case && caseno <= last_case)
                           ? create_job(caseno, case_) : 0);
            delete case_;
            ++caseno;
        }

        if (show_prog)
        {
            int secs = (int)(time(NULL) - time_start);
            fprintf(stderr, "\r%02d:%02d [", secs/60, secs%60);
            REP(c, cases) fputc(c > n ? '.' : c > n - max_procs ? '~' :
                !jobs[c] ? '/' : jobs[c]->success ? 'v' : '-', stderr);
            fprintf(stderr, "] %3d%% ", 100*(max(0, n - max_procs + 1))/cases);
            fflush(stderr);
        }
    }
    if (show_prog) fputc('\n', stderr);
    fclose(fp_out);

    if (*path_ref && *path_out && first_case == 1 && last_case == cases)
    {
        execlp("diff", "diff",
               "--minimal", "--suppress-common-lines", "--side-by-side",
               path_out, path_ref, NULL);
        perror("Could not execute diff");
        exit(1);
    }
}

/* GCJ template part 06 -- Solution implementation */

static void initialize()
{
    /***** GLOBAL INITIALIZATION GOES HERE *****/
}

struct Case : public AbstractCase
{
    Case();
    void solve(Result &result);
    LL calc(int pos, bool ltA, bool ltB, bool ltK);

    int A, B, K;
    LL memo[30][2][2][2];
};

AbstractCase *read_case() { return new Case(); }

Case::Case()
{
    cin >> A >> B >> K;
}

LL Case::calc(int pos, bool ltA, bool ltB, bool ltK)
{
    if (pos < 0) return 1;
    LL &m = memo[pos][ltA][ltB][ltK];
    if (m >= 0) return m;
    LL res = 0;
    REP(bitA, 2) if (ltA || bitA <= (((A - 1) >> pos)&1)) {
        REP(bitB, 2) if (ltB || bitB <= (((B - 1) >> pos)&1)) {
            int bitK = bitA & bitB;
            if (ltK || bitK <= (((K - 1) >> pos)&1)) {
                res += calc(pos - 1, ltA || bitA < (((A - 1) >> pos)&1),
                                     ltB || bitB < (((B - 1) >> pos)&1),
                                     ltK || bitK < (((K - 1) >> pos)&1));
            }
        }
    }
    return m = res;
}

void Case::solve(Result &result)
{
    SET(memo, -1);
    result.set(STR(calc(29, false, false, false)));
}
