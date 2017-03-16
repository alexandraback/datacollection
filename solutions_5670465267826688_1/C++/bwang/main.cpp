#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int quatMult(int a, int b) {
    switch (a) {
        case 1: {
            switch (b) {
                case 1: return 1;
                case 2: return 2;
                case 3: return 3;
                case 4: return 4;
                case 5: return 5;
                case 6: return 6;
                case 7: return 7;
                case 8: return 8;
            }
        }
        case 2: {
            switch (b) {
                case 1: return 2;
                case 2: return 5;
                case 3: return 4;
                case 4: return 7;
                case 5: return 6;
                case 6: return 1;
                case 7: return 8;
                case 8: return 3;
            }
        }
        case 3: {
            switch (b) {
                case 1: return 3;
                case 2: return 8;
                case 3: return 5;
                case 4: return 2;
                case 5: return 7;
                case 6: return 4;
                case 7: return 1;
                case 8: return 6;
            }
        }
        case 4: {
            switch (b) {
                case 1: return 4;
                case 2: return 3;
                case 3: return 6;
                case 4: return 5;
                case 5: return 8;
                case 6: return 7;
                case 7: return 2;
                case 8: return 1;
            }
        }
        case 5: {
            switch (b) {
                case 1: return 5;
                case 2: return 6;
                case 3: return 7;
                case 4: return 8;
                case 5: return 1;
                case 6: return 2;
                case 7: return 3;
                case 8: return 4;
            }
        }
        case 6: {
            switch (b) {
                case 1: return 6;
                case 2: return 1;
                case 3: return 8;
                case 4: return 3;
                case 5: return 2;
                case 6: return 5;
                case 7: return 4;
                case 8: return 7;
            }
        }
        case 7: {
            switch (b) {
                case 1: return 7;
                case 2: return 4;
                case 3: return 1;
                case 4: return 6;
                case 5: return 3;
                case 6: return 8;
                case 7: return 5;
                case 8: return 2;
            }
        }
        case 8: {
            switch (b) {
                case 1: return 8;
                case 2: return 7;
                case 3: return 2;
                case 4: return 1;
                case 5: return 4;
                case 6: return 3;
                case 7: return 6;
                case 8: return 5;
            }
        }
    }
}

#define FOR(i, a, b) for(long long int i = a; i < b; i++)



int main()
{
    ifstream fin("C-large.in");
    ofstream fout("outputL.txt");
    long long int T, L, X;
    string aStr;
    fin >> T;
    FOR(i, 0, T) {
        bool isYes = false;
        fin >> L;
        fin >> X;
        fin >> aStr;
        FOR(j, 0, aStr.size()) {
            if (aStr[j] == 'i') {
                aStr[j] = '2';
            }
            else if (aStr[j] == 'j') {
                aStr[j] = '3';
            }
            else if (aStr[j] == 'k') {
                aStr[j] = '4';
            }
        }
        long long int LResult = 1;
        FOR(j, 0, aStr.size()) {
            LResult = quatMult(LResult, aStr[j] - '0');
        }
        long long int temp = 1;
        long long int counter = 0;
        FOR(j, 0, X%8) {
            temp = quatMult(temp, LResult);
        }
        if (temp == 5) {
            string totalStr = "";
            long long int minX8;
            if (X < 8) {
                minX8 = X;
            }
            else {
                minX8 = 8;
            }
            FOR(j, 0, minX8) {
                totalStr += aStr;
            }
            long long int leftResSoFar = 1;
            long long int counter2 = 0;
            while ((leftResSoFar != 2) && (counter2 < totalStr.size())) {
                leftResSoFar = quatMult(leftResSoFar, totalStr[counter2] - '0');
                counter2++;
            }
            counter2--;
            long long int counter3 = totalStr.size() - 1;
            long long int rightResSoFar = 1;
            while ((rightResSoFar != 4) && (counter3 > 0)) {
                rightResSoFar = quatMult(totalStr[counter3] - '0', rightResSoFar);
                counter3--;
            }
            if (counter2 < counter3) {
                fout << "Case #" << i + 1 << ": " << "YES" << endl;
                isYes = true;
            }
        }
        if (!isYes) {
            fout << "Case #" << i + 1 << ": " << "NO" << endl;
        }
    }
    return 0;
}
