#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

using namespace std;

#define false 0
#define true 1
#define bool int
#define read fscanf

bool isInFile, isOutFile;
FILE *inFile, *outFile;

void write(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    if (isOutFile)
        vfprintf(outFile, fmt, ap);
    va_end(ap);
}

void solveOne();

void main(int argc, char **argv) {
    isInFile = (argc > 1);
    if (isInFile) {
        inFile = fopen(argv[1], "r");
        if (inFile == NULL) {
            printf("infile not found");
            exit(0);
        }
    } else {
        inFile = stdin;
    }
    isOutFile = (argc > 2);
    if (isOutFile) {
        outFile = fopen(argv[2], "w");
        if (outFile == NULL) {
            printf("outfile error");
            exit(0);
        }
    }

    int T;
    read(inFile, "%d\n", &T);
    for (int i = 1; i <= T; i++) {
        write("Case #%d: ", i);
        solveOne();
        write("\n");
    }

}

int checkFn(int n, int line[100], int h) {
    for (int i = 0; i < n; i++) {
        if (line[i] > h)
            return false;
    }
    return true;
}

void print2D(int m, int n, int d[100][100]) {
    write("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            write("%d ", d[i][j]);
        write("\n");
    }
}

void solveOne() {
    int m, n;
    int a[100][100];
    int cut[100][100];
    int line[100];
    int hasHeight[100];

    /* read data */
    read(inFile, "%d %d\n", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            read(inFile, "%d", &a[i][j]);
        read(inFile, "\n");
    }

    /* solve */
    //init hasHeight
    for (int i = 0; i <= 100; i++) {
        hasHeight[i] = false;
    }
    //init cut & hasHeight
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cut[i][j] = false;
            hasHeight[a[i][j]] = true;
        }
    }

    //
    for (int h = 1; h <= 100; h++) {
        if (hasHeight[h]) {
            //l2r
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++)
                    line[j] = a[i][j];
                if (checkFn(n, line, h) == true)
                    for (int j = 0; j < n; j++)
                        if (a[i][j] == h)
                            cut[i][j] = true;
            }
            //t2b
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    line[j] = a[j][i];
                if (checkFn(m, line, h) == true)
                    for (int j = 0; j < m; j++)
                        if (a[j][i] == h)
                            cut[j][i] = true;
            }
            //print2D(m, n, cut);
        }
    }

    //check
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (cut[i][j] == false) {
                write("NO");
                return;
            }
        }
    write("YES");
}
