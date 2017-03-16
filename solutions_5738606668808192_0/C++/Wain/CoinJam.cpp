//
//  main.cpp / Coin Jam
//  CodeJam2016
//

#include <iostream>
#include <string>
#include <sstream>

// http://gmplib.org/
#include <gmp.h>

using namespace std;

unsigned long long calcBase(const short* number, int length, int base) {
    // number: 10001 100001 1101101 등의 base 진수 숫자
    // return: 결과 숫자

    unsigned long long result = 0;
    unsigned long long baseValue = 1;

    for ( int i = length-1 ; i >= 0 ; i-- ) {
        if (number[i] != 0) {
            result += baseValue * number[i];
        }
        baseValue *= base;
    }

    return result;
}

void checkPrimeLarge(mpz_t target, mpz_t input) {
    // result가 1이면 input 은 Prime
    mpz_t result;
    mpz_t rootOfInput;
    mpz_t tmpLarge;

    // int MAX_INT = 2147483601;
    int MAX_TEST_SIZE = 30000000;

    // init
    mpz_init(result);
    mpz_init(rootOfInput);
    mpz_init(tmpLarge);

    // setting
    mpz_set_ui(result, 1);

    // pre-processing
    mpz_sqrt(rootOfInput, input);
    mpz_add_ui(rootOfInput, rootOfInput, 1);

    // unsigned long int result = mpz_mod_ui()

    if ( mpz_divisible_ui_p(input, 2) != 0 ) {
        mpz_set_ui(result, 2);
    }
    else {
        for ( int i = 3 ; i < MAX_TEST_SIZE ; i = i + 2 ) {
            if ( mpz_cmp_ui(rootOfInput, i) < 0 ) { // nothing find. prime.
                break;
            }
            if ( mpz_divisible_ui_p(input, i) != 0 ) {
                mpz_set_ui(result, i);
                break;
            }
        }
    }

    // if ( mpz_cmp_ui(result, 1) == 0 ) {
    //     // continue the process
    //     mpz_set_ui(tmpLarge, MAX_INT);
    //     while(1) {
    //         mpz_add_ui(tmpLarge, tmpLarge, 2);
    //         if ( mpz_divisible_p(input, tmpLarge) != 0 ) {
    //             mpz_set(result, tmpLarge);
    //             break;
    //         }
    //         if ( mpz_cmp(tmpLarge, rootOfInput) > 0 ) { // nothing find. prime.
    //             break;
    //         }
    //     }
    //     mpz_clear(tmpLarge);
    // }

    // results...
    mpz_set(target, result);

    // clear
    mpz_clear(result);
    mpz_clear(rootOfInput);
}

void calcBaseLarge(mpz_t target, const short* number, int length, int base) {
    mpz_t result;
    mpz_t baseValue;

    mpz_init(result);
    mpz_init(baseValue);

    mpz_set_ui(baseValue, 1);

    for ( int i = length-1 ; i >= 0 ; i-- ) {
        if (number[i] != 0) {
            // cout << "calcBaseLarge Results: ";
            // mpz_out_str(stdout, 10, result);
            // cout << endl;

            mpz_addmul_ui(result, baseValue, number[i]);

            // cout << "calcBaseLarge Results: ";
            // mpz_out_str(stdout, 10, result);
            // cout << endl;
        }
        mpz_mul_si(baseValue, baseValue, base);
    }

    mpz_set(target, result);

    // TEST
    // cout << "calcBaseLarge Target: ";
    // mpz_out_str(stdout, 10, target);
    // cout << endl;

    mpz_clear(result);
    mpz_clear(baseValue);
}

void runQuestion(int number)
{

    // input
    int n_length, j_jamCoins;
    cin >> n_length >> j_jamCoins;

    // test
    // char test[10] = "100110110";
    // cout << calcBase(test, 9, jamCoins) << endl;

    cout << "Case #" << number << ":" << endl;

    // setting
    // 0, 1 은 안 쓰이고, 2부터 10까지만 쓰일 것이다.
    unsigned long int resultDivisor[11] = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int targetValue = 0;
    char numberChar[33] = {};
    char minNumberChar[33] = {};    //  10000001 //
    char maxNumberChar[33] = {};    // 100000000 //
    mpz_t targetNumber[11];
    mpz_t currentNum;
    mpz_t maxNum;
    mpz_t calcResult;

    // pre-processing
    for ( int i = 0 ; i < 33 ; i++ ) {
        numberChar[i] = 0;
        if ( i < n_length ) {
            maxNumberChar[i] = '0';
            minNumberChar[i] = '0';
        }
        else {
            maxNumberChar[i] = 0;
            minNumberChar[i] = 0;
        }
    }
    maxNumberChar[0] = '1';
    minNumberChar[0] = '1';
    maxNumberChar[n_length] = '0';
    minNumberChar[n_length-1] = '1';

    // TEST
    // cout << "MAX: " << maxNumberChar << endl;
    // cout << "MIN: " << minNumberChar << endl;

    for ( int i = 0 ; i < 11 ; i++ ) mpz_init(targetNumber[i]);

    mpz_init(currentNum);
    mpz_init(maxNum);
    mpz_init(calcResult);

    unsigned int MAX_INT_OVER = 2147483647 + 2;
    // calculation
    // mpz_set_ui(currentNum, MAX_INT_OVER);
    // mpz_set_str(maxNum, "100000000000000000000000000000000", 2);

    mpz_set_str(currentNum, minNumberChar, 2);
    mpz_set_str(maxNum, maxNumberChar, 2);

    int count = 0;
    while ( 1 ) {
        // mpz_get_str(numberChar, 2, currentNum);
        // cout << "NUMBER:" << numberChar << endl;

        mpz_get_str(numberChar, 2, currentNum);

        // TEST
        // cout << "Number:" << numberChar << endl;

        // make every number
        for ( int i = 2 ; i <= 10 ; i ++ ) resultDivisor[i] = 1;
        for ( int i = 2 ; i <= 10 ; i ++ ) {
            mpz_set_str(targetNumber[i], numberChar, i);
            checkPrimeLarge(calcResult, targetNumber[i]);
            resultDivisor[i] = mpz_get_ui(calcResult);
            // cout << "C " << count << " DivisorResult (" << i << "): " << resultDivisor[i] << endl;
            if ( resultDivisor[i] == 1 ) break;
        }

        if ( resultDivisor[10] != 1 ) { // it's JamCoin.
            count++;
            cout << numberChar ;
            for ( int i = 2 ; i <= 10 ; i++ ) {
                cout << " " << resultDivisor[i];
            }
            cout << endl;
        }

        if ( count >= j_jamCoins ) {
            // cout << "OVER!" << endl;
            break;
        }
        mpz_add_ui(currentNum, currentNum, 2);

        if ( mpz_cmp(currentNum, maxNum) > 0 ) {
            break;
        }
    }
    mpz_clear(currentNum);

    // for ( long i = 0 ; i < MAX_INT ; i ++ ) {
    //     // 0000000000 0000000000 0000000000 ~ 1111111111 1111111111 1111111111
    //     mpz_set_ui(currentNum, i);
    //     mpz_mul_ui(currentNum, currentNum, 2);
    //     mpz_add_ui(currentNum, currentNum, MAX_INT_OVER);

    //     mpz_get_str(numberChar, 2, currentNum);
    //     if ( i < 10 || i > MAX_INT - 10 )
    //         cout << "NUMBER:" << numberChar << endl;
    // }

    // clear
    for (int i = 0 ; i < 11 ; i++ ) {
        mpz_clear(targetNumber[i]);
    }

//    cout << endl;
}

int main(int argc, const char * argv[]) {

    int howManyTimes;

    scanf("%d", &howManyTimes);

    for ( int i = 0 ; i < howManyTimes ; i++ ) {
        runQuestion(i+1);
    }

    return 0;
}

