#include "math.h"
#include "stdio.h"
#include "algorithm"


#define I 2
#define J 3
#define K 4

int multiply_[4][4] = {
    { 1,  I,  J,  K},
    { I, -1,  K, -J},
    { J, -K, -1,  I},
    { K,  J, -I, -1}
};

int multiply(int a, int b) {
    int out = multiply_[abs(a)-1][abs(b)-1];
    if (a*b < 0) { return -out; }
    else         { return  out; }
}

int quatFromChar(char c) {
    switch (c) {
        case '1':  return 1;
        case 'i':  return I;
        case 'j':  return J;
        case 'k':  return K;
        default:
            printf("omg non-ijk character: %c\n", c);
            return 0;
    }
}

char charFromQuat(int q) {

    switch (q) {
        case  1:  return '1';
        case  I:  return 'i';
        case  J:  return 'j';
        case  K:  return 'k';
        case -1:  return '2';
        case -I:  return 'I';
        case -J:  return 'J';
        case -K:  return 'K';
        default:
            printf("bad quaternion: %d\n", q);
            return 'x';
    }
}


// all of these should be arguments to canMakeIJK
int s[10000];  // the expanded string (only feasible for small input)
int repetitions;
int lenS;

bool canMakeIJK() {

    // can we make a I at the start?
    int lastI = 0;
    int wantI = s[lastI];
    while (wantI != I && lastI < lenS-1) {
        lastI += 1;
        wantI = multiply(wantI, s[lastI]);
    }
    if (wantI != I) {
        // printf("  DEBUG: can not make I \n");
        return false;
    }


    // can we make a K at the end?
    int firstK = lenS-1;
    int wantK = s[firstK];
    while (wantK != K && firstK > 0) {
        firstK -= 1;
        wantK = multiply(s[firstK], wantK);
    }
    if (wantK != K) {
        // printf("  DEBUG: can not make K \n");
        return false;
    }

    // do we have a space for a J?
    if (firstK - lastI <= 1) {
        // printf("  DEBUG: no space for J \n");
        return false;
    }

    // is the stuff in between a J?
    int wantJ = s[lastI+1];
    for (int right=lastI+2; right<firstK; ++right) {
        wantJ = multiply(wantJ, s[right]);
    }
    if (wantJ != J) {
        // printf("  DEBUG: J is not between I and K\n");
        return false;
    }

    return true;
}

int main(int argc, char const *argv[]) {
    int test = multiply(K, J);

    int numCases = 0;
    scanf("%d", &numCases);


    int lenInput;
    char input[10000];

    for (int caseNum=0; caseNum<numCases; ++caseNum) {

        // input
        scanf("%d", &lenInput);
        scanf("%d", &repetitions);
        scanf("%s", input);
        lenS = lenInput * repetitions;
        for (int i=0; i<lenS; ++i) {
            s[i] = quatFromChar(input[i%lenInput]);
        }

        // output
        if (canMakeIJK()) {    printf("Case #%d: YES\n", caseNum+1);      }
        else              {    printf("Case #%d: NO\n",  caseNum+1);      }
    }


    // for (int i=0; i<10; ++i) {
    //     int a=-1;
    //     scanf("%d", &a);
    //     printf("%d\n", a);
    // }

    return 0;
}
