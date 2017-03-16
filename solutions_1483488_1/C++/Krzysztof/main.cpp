#include <set>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int rotate(int num, int power) {
    int last = num % 10;
    num /= 10;
    num += last * pow(10, power);
    return num;
}

int main() {
    //istream& is = cin;
    ifstream is("input.txt");
    //ostream& os = cout;
    ofstream os("output.txt");

    int tests;
    is >> tests;

    for (int test = 1; test <= tests; ++test) {
        int a, b;
        is >> a >> b;

        const int power = (int) log10(a);
        int count = 0;

        for (int num = a; num <= b; ++num) {
            int rotated = num;
            set<int> recycled;

            for (int i = 0; i < power; ++i) {
                rotated = rotate(rotated, power);
                if (a <= rotated && rotated <= b && num < rotated)
                    recycled.insert(rotated);
            }

            count += recycled.size();
        }

        os << "Case #" << test << ": " << count << endl;

    }
}
