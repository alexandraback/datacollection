#include "includes.h"


int main(int argc, char *args[]) {
    if (argc == 2 && strcmp(args[1], "sample") == 0) {

        freopen("sample.in", "rt", stdin);
        freopen("sample.out", "wt", stdout);
        debug << "Using sample input set" << endl;

    } else if (argc == 2 && strcmp(args[1], "small") == 0) {

        freopen("small.in", "rt", stdin);
        freopen("small.out", "wt", stdout);
        debug << "Using small input set" << endl;

    } else if (argc == 2 && strcmp(args[1], "large") == 0) {

        freopen("large.in", "rt", stdin);
        freopen("large.out", "wt", stdout);
        debug << "Using Large input set" << endl;

    } else {
        debug << "invalid argusments" << endl;
        debug << "usage: " << args[0] << " sample | small | large" << endl;
        return -1;
    }
    char cCurrentPath[FILENAME_MAX];

    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
        return errno;
    }
    debug << "CWD: " << cCurrentPath << endl;

    int N;
    cin >> N;
    debug << "N = " << N << endl;
    debug.flush();
    cout.flush();
    for (int casenum = 1; casenum <= N; casenum++) {
        cout << "Case #" << casenum << ": ";

        solve(casenum);
    }
    debug.flush();
    return 0;
}

