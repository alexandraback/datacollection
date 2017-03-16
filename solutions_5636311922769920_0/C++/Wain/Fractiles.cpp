//
//  main.cpp / Fractiles
//  CodeJam2016
//
//
// Original sequence GLL: GGGGLLGLL
// Original sequence LGL: LGLGGGLGL
// Original sequence LLG: LLGLLGGGG
//                        122212221
//
// GLLL :: GGGG GLLL GLLL GLLL
// LGLL :: LGLL GGGG LGLL LGLL
// LLGL :: LLGL LLGL GGGG LLGL
// LLLG :: LLLG LLLG LLLG GGGG
//
// GLLL :: GGGG GGGG GGGG GGGG GGGG GLLL GLLL GLLL GGGG GLLL GLLL GLLL GGGG GLLL GLLL GLLL
// LGLL :: LGLL GGGG LGLL LGLL GGGG GGGG GGGG GGGG LGLL GGGG LGLL LGLL LGLL GGGG LGLL LGLL
// LLGL :: LLGL LLGL GGGG LLGL LLGL LLGL GGGG LGLL GGGG GGGG GGGG GGGG LLGL LLGL GGGG LLGL
// LLLG :: LLLG LLLG LLLG GGGG LLLG LLLG LLLG GGGG LLLG LLLG LLLG GGGG GGGG GGGG GGGG GGGG
//         1222 2233 2323 2332 2233 2122 3223 3322 2323 3223 2212 3322 2332 3232 3322 2221
//
//      123 456 789 012 345 678 901 234 567
// GLL  GGG GGG GGG GGG GLL GLL GGG GLL GLL :: L의 갯수는 2개가 4개, 8개로 늘어남. 나머지는 전부 G들.
// LGL  LGL GGG LGL GGG GGG GGG LGL GGG LGL
// LLG  LLG LLG GGG LLG LLG GGG GGG GGG GGG
//      211 110 101 110 121 011 101 011 112

//      첫번째 L : 1레벨 L1 > 2레벨 L1 > 3레벨 L1
//      두번째 L : 1레벨 L1 > 2레벨 L1 > 3레벨 L2
//      세번쨰 L : 1레벨 L1 > 2레벨 L1 > 3레벨 L3 의 순으로, 이루어진다.
//
//      즉, 3레벨의 각 칸의 결과값은 (1,1,1), (1,1,2), (1,1,3), (1,2,1), (1,2,2), (1,2,3) 의 순으로.
//      4레벨이 되면 (1,1,1,1), (1,1,1,2), (1,1,1,3) 이 되겠지. 3진법이랄까, 매트릭스랄까.
//      저기서 하나라도 G가 있다면, 그 값은 G가 됨.
//      따라서 4레벨인 상황에서 저걸 본다면 6번째 : (1,1,2,1), (1,1,2,2), (1,1,2,3) << 1,2,3 이 다 나옴.
//      이렇게 되므로 저 값으로 전부 다 확인할 수 있다. 이것은 진법으로 바꿀 수 있는데, 각 값에서 1을 빼면 됨.
//      즉, 6은 5로, 1,1,2,3 은 0,0,1,2 로 바꾼다. 이렇게 하면 3*1+2=5 가 되어서 진법과 동일 구조가 됨.
//
//      6, -1하면 5를 3진법으로 바꾸면, 0012 가 되는데, 이것은 0과 1과 2가 다 포함된 구조가 된다.
//      즉, 첫 구문의 길이 k글자 가 진법 (3진법), 전체 레벨 c가 진법의 자리 수가 된다. c자리의 k진법 숫자가 됨.
//
//      마찬가지 계산을 해보자. 8은 7이고, 이것은 3진법 변환시 0021 (3*2+1) 이 되어서 0,1,2를 다 포함한다. 오케이.
//      12는 11이고, 9+2니까 0102 가 된다.

//      거꾸로 말하면 그러니까 당연히 좌우대칭이 될 수 밖에 없다.
//      레벨이 커질수록 표현할 수 있는 숫자가 늘어나므로 당연히 더 표현가능성이 늘어날 수 밖에 없다.
//      즉, 이 문제는 이런 것이다.
//
//      k 진법의 숫자가 있다고 치자. 이 숫자의 길이가 c글자라고 할 때,
//      거기에서 0부터 k-1까지를 모두 표시하려면 숫자 몇 개가 필요할까?
//      씨발 이러니까 통찰력이 필요하지...
//
// GLL.. k글자 c레벨: k글자만큼의 G가 k+1번 나올테고 c개만큼의 G가 있고,

#include <iostream>
#include <string>
#include <sstream>

// http://gmplib.org/
#include <gmp.h>

using namespace std;


unsigned long long calcBase(const char* number, int length, int base) {
    // number: 10001 100001 1101101 등의 base 진수 글자.
    // return: char* 결과값.

    unsigned long long result = 0;
    unsigned long long baseValue = 1;

    for ( int i = length-1 ; i >= 0 ; i-- ) {
        if (number[i] != '0') result += baseValue * (number[i]-'0');
        baseValue *= base;
    }

    return result;
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
    int k_FirstTiles, c_CompLevel, s_Students;
    cin >> k_FirstTiles >> c_CompLevel >> s_Students;

    // test
    // char test[10] = "3157";
    // cout << calcBase(test, 4, 8) << endl;

    // setting
    // unsigned long long resultArray[100];
    mpz_t resultArray[100];
    int resultArrayLength = 0;

    // pre-processing
    for ( int i = 0 ; i < 100 ; i++ ) {
        // resultArray[i] = 0;
        mpz_init(resultArray[i]);
    }

    // calculation
    // length c , k base number > show 0~k-1 numbers
    // c 자리의 k 진법의 숫자 x에 대해, 그 숫자가 그 진법의 k개의 숫자를 모두 대변할 수 있는가?
    // 몇 개의 숫자가 있어야 k 개의 숫자를 표현할 수 있는가?
    if ( s_Students * c_CompLevel >= k_FirstTiles ) {
        short* tmpNumArray = new short[c_CompLevel];
        int howManyNumber = (k_FirstTiles-(k_FirstTiles%c_CompLevel))/c_CompLevel;
        if ( k_FirstTiles % c_CompLevel > 0 ) howManyNumber++;

        /*
        // 숫자가 너무 커지니까 감당이 안됨.
        // 그러니까, 작은 숫자로 표현할 수 있게 고치자.
        // 1) 뒤에서부터 큰 숫자를 채워나간다.
        // 2) 맨 앞에는 작은 숫자를 억지로 채운다.
        int currentNumber = 0;

        for ( int j = 0 ; j < howManyNumber ; j++ ) {
            for ( int i = 0 ; i < c_CompLevel ; i ++ ) {
                if ( currentNumber >= k_FirstTiles ) {
                    tmpNumArray[i] = '0';
                }
                else {
                    tmpNumArray[i] = '0' + currentNumber;
                }
                currentNumber++;
            }

            cout << "TEST Result: " << tmpNumArray << ", order: " << k_FirstTiles;
            resultArray[j] = calcBase(tmpNumArray, c_CompLevel, k_FirstTiles)+1;
            cout << ", in 10 base:: " << resultArray[j] << endl;
            resultArrayLength ++;
        }
        */

        int currentNumber = 0;
        short targetCharacter = 0;

        for ( int j = 0 ; j < howManyNumber ; j++ ) {
            currentNumber = k_FirstTiles - 1 - j;
            for ( int i = 0 ; i < c_CompLevel ; i++ ) {
                if ( currentNumber < 0 ) {
                    targetCharacter = 0;
                }
                else {
                    targetCharacter = currentNumber;
                    currentNumber = currentNumber - howManyNumber;
                }
                tmpNumArray[ c_CompLevel - 1 - i ] = targetCharacter;
            }
            // TEST
            // cout << "TEST Result: " << tmpNumArray << ", order: " << k_FirstTiles << endl;
            // resultArray[j] = calcBase(tmpNumArray, c_CompLevel, k_FirstTiles)+1;
            mpz_t calcBaseResult;
            mpz_init(calcBaseResult);

            calcBaseLarge(calcBaseResult, tmpNumArray, c_CompLevel, k_FirstTiles);
            // TEST
            // cout << "calcBaseLarge Results: ";
            // mpz_out_str(stdout, 10, calcBaseResult);
            // cout << endl;

            mpz_add_ui(resultArray[j], calcBaseResult, 1);
            mpz_clear(calcBaseResult);

            // TEST
            // cout << ", in 10 base:: " << resultArray[j] << endl;
            // cout << ", in 10 base:: ";
            // mpz_out_str(stdout, 10, resultArray[j]);
            // cout << endl;
            resultArrayLength ++;
        }
    }
    else {
        resultArrayLength = 0;
    }

    // output
    cout << "Case #" << number << ":" ;
    if ( resultArrayLength > 0 ) {
        for ( int i = 0 ; i < resultArrayLength ; i++ ) {
            // cout << " " << resultArray[i];
            cout << " ";
            mpz_out_str(stdout, 10, resultArray[i]);
        }
    }
    else {
        cout << " IMPOSSIBLE";
    }

    cout << endl;
}

int main(int argc, const char * argv[]) {
    // initialize

    int howManyTimes;

    scanf("%d", &howManyTimes);

    for ( int i = 0 ; i < howManyTimes ; i++ ) {
        runQuestion(i+1);
    }

    return 0;
}

