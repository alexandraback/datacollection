#include <stdio.h>
#include <algorithm>  // abs

#define I 2
#define J 3
#define K 4


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

// allows printing/debugging of quaternions
char charFromQuat(int q) {
    switch (q) {
        case  1:  return '1';
        case  I:  return 'i';
        case  J:  return 'j';
        case  K:  return 'k';
        case -1:  return '-';
        case -I:  return 'I';
        case -J:  return 'J';
        case -K:  return 'K';
        default:
            printf("bad quaternion: %d\n", q);
            return 'x';
    }
}

// used in multiply()
int multiply_[4][4] = {
    { 1,  I,  J,  K},
    { I, -1,  K, -J},
    { J, -K, -1,  I},
    { K,  J, -I, -1}
};

// does quaternion multiplication.
// this has a special case where multiplying be zero is the same as multiplying by one
int multiply(int a, int b) {
    if (a==0) { return b; }
    if (b==0) { return a; }

    int out = multiply_[abs(a)-1][abs(b)-1];
    if (a*b < 0) { return -out; }
    else         { return  out; }
}


// a table used in pow_quat()
int powerTable[8][4];
// 1:    1    1    1    1
// -:    1    -    1    -
// i:    1    i    -    I
// I:    1    I    -    i
// j:    1    j    -    J
// J:    1    J    -    j
// k:    1    k    -    K
// K:    1    K    -    k
void precomputePowerTable() {
    int exponents[8] = {
        1, -1,
        I, -I,
        J, -J,
        K, -K
    };
    for (int i=0; i<8; ++i) {
        int exponent = exponents[i];
        int current = 1;
        // printf("// %c:", charFromQuat(exponent));
        for (int power=0; power<4; ++power) {
            powerTable[i][power] = current;
            // printf("    %c", charFromQuat(current));
            current = multiply(current, exponent);
        }
        // printf("\n");
    }
}

// raises a quaterion exponent to a positive integer exponent.
// properties:
//    pow_quat(X, 0) == 1
//    pow_quat(X, 1) == X
//    pow_quat(X, 2) == multiply(X, X)
//    pow_quat(X, Y) == pow_quat(X, Y%4)
int pow_quat(int exponent, long long power) {
    if (exponent == 0) {  printf("pow error: bad exponent: %d\n",   exponent);  return 0;  }
    if (power     < 0) {  printf("pow error: bad power:    %lld\n", power   );  return 0;  }

    int row = (exponent > 0)? 2*(exponent-1) : 2*(-exponent-1) + 1;  // match the rows of the table
    return powerTable[row][power % 4];
}

// all of these should be arguments to canMakeIJK
int s[10000];  // the string of quaternions
long long repetitions;  // X
int L;  // the length of the repeated string

bool canMakeIJK() {

    // find the shortest I
    int i=0;  // index to s
    int wantI = 1; // quaternion that should eventually equal to I
    for (i=0; wantI != I && i<L*repetitions && i<L*5; ++i) {
        wantI = multiply(wantI, s[i % L]);
    }
    if (wantI != I) {
        // printf("  DEBUG: can not make I \n");
        return false;
    }

    // find the shortest J after I
    // we continue with i where we left off
    int wantJ = 1;       // quaternion that should eventually equal to J
    for (; wantJ != J && i<L*repetitions && i<L*9; ++i) {
        wantJ = multiply(wantJ, s[i % L]);
    }
    if (wantJ != J) {
        // printf("  DEBUG: can not make J \n");
        return false;
    }

    // the remaining thing should equal K
    int wantK = 1;           // quaternion that should eventually equal to K
    for (; i%L != 0; ++i) {  // iterate to the last repetition
        wantK = multiply(wantK, s[i % L]);
    }
    // multiply wantK by the rest in O(1) time :D
    int usedRepetitions = i/L;
    int squashed = 1; // a quaterion of everything in s multiplied together
    for (i=0; i<L; ++i) {
        squashed = multiply(squashed, s[i]);
    }
    long long remainingRepetitions = repetitions - usedRepetitions;
    // printf("  DEBUG: remainingRepetitions: %lld\n", remainingRepetitions);
    wantK = multiply(wantK, pow_quat(squashed, remainingRepetitions));
    if (wantK != K) {
        // printf("  DEBUG: can not make K \n");
        return false;
    }

    return true;
}



int main(int argc, char const *argv[]) {
    precomputePowerTable();


    int numCases = 0;
    scanf("%d", &numCases);

    char input[10000];


    for (int caseNum=0; caseNum<numCases; ++caseNum) {

        // input
        scanf("%d", &L);
        scanf("%lld", &repetitions);  // X
        scanf("%s", input);
        for (int i=0; i<L; ++i) {
            s[i] = quatFromChar(input[i]);
        }

        // output
        if (canMakeIJK()) {    printf("Case #%d: YES\n", caseNum+1);      }
        else              {    printf("Case #%d: NO\n",  caseNum+1);      }
    }

    return 0;
}
