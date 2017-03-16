#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;


int main() {
    vector<char> transTable(26, 'a');

    transTable[0] = 'y';
    transTable[1] = 'h';
    transTable[2] = 'e';
    transTable[3] = 's';
    transTable[4] = 'o';
    transTable[5] = 'c';
    transTable[6] = 'v';
    transTable[7] = 'x';
    transTable[8] = 'd';
    transTable[9] = 'u';
    transTable[10] = 'i';
    transTable[11] = 'g';
    transTable[12] = 'l';
    transTable[13] = 'b';
    transTable[14] = 'k';
    transTable[15] = 'r';
    transTable[16] = 'z';
    transTable[17] = 't';
    transTable[18] = 'n';
    transTable[19] = 'w';
    transTable[20] = 'j';
    transTable[21] = 'p';
    transTable[22] = 'f';
    transTable[23] = 'm';
    transTable[24] = 'a';
    transTable[25] = 'q';
    
    

    
    FILE *f = fopen("A-small-attempt1.in", "r");
    FILE *out = fopen("out.txt", "w");

    int numberOfCases;
    fscanf(f, "%d\n", &numberOfCases);

    char c;
    int caseNum = 1;
    fprintf(out, "%s%d: ", "Case #", caseNum);
    caseNum++;
    do {    
        c = fgetc (f);
        if (c == EOF) break;
        if (c == '\n' && caseNum <= numberOfCases) {
            fprintf(out, "\n%s%d: ", "Case #", caseNum);
            ++caseNum;
        } else if (c == ' ') {
            fputc(c, out);
        } else if (c >= 'a' && c <= 'z'){
            fputc(transTable[c - 'a'], out);
        }
    }while (caseNum <= (numberOfCases+1) && c != EOF);

    fputc('\n', out);

    fclose(f);
    fclose(out);

    int a = 1;
}