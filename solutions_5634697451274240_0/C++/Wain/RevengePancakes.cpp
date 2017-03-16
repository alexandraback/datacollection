//
//  main.cpp / Revenge Pancakes.
//  CodeJam2016
//
//  주의: 전부 마이너스로 만들고 한 번 더 더해서 플러스로 만드는 비용이 하나씩 플러스로 만드는 것보다 저렴할 수 있다.

// 문제 : 위에서부터, -+--+ 로 이루어진 팬케이크의 묶음을 전부 + 로 만드는 데 몇 번을 뒤집어야 하는가?
// 단, 위에서부터 몇 개를 쥐어서 뒤집을 수 있다.
//
// 간단한 접근법: 전부 + 가 아니라면, 앞에서부터 동일한 마크의 - 혹은 + 를 뒤집는다. 다음 동일한 마크가 나올 때 까지 간다.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void runQuestion(int number)
{

    // input
    char inputCharacter[100];
    cin >> inputCharacter;

    // setting
    int result = 0;
    int targetData[100];
    int maxCount = 0;

    // pre-processing
    maxCount = strlen(inputCharacter);
    for ( int i = 0 ; i < maxCount ; i++ ) {
        if ( inputCharacter[i] == '-' ) targetData[i] = 0;
        else targetData[i] = 1;
    }

    // calculation
    if ( maxCount != 1 ) {
        for ( int i = 1 ; i < maxCount ; i++ ) {
            if ( targetData[i-1] != targetData[i] ) {
                result++;   // 앞의 것 까지를 뒤집는다
                for ( int j = 0 ; j < i ; j++ ) {
                    if ( targetData[j] == 1 ) targetData[j] = 0;
                    else targetData[j] = 1;
                }
            }
        }

        // 다 끝나고 이게 --- 로 정렬되었을 때, + 로 바꾼다.
        if ( targetData[0] == 0 ) result++;
    }
    else {
        if ( targetData[0] == 0 ) result = 1;
        else result = 0;
    }


    // output
    // if ( result == 0 ) {
    //     cout << "Case #" << number << ": INSOMNIA";
    // }
    // else {
        cout << "Case #" << number << ": " << result;
    // }
    cout << endl;
}

int main(int argc, const char * argv[]) {

    int howManyTimes;

    scanf("%d", &howManyTimes);

    for ( int i = 0 ; i < howManyTimes ; i++ ) {
        runQuestion(i+1);
    }

    return 0;
}

