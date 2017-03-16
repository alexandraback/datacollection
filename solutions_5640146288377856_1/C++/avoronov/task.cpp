#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print_answer(int id, int x) {
    cout << "Case #" << id << ": " << x << endl;
}

void process_test(int id) {
    int rows, cols, width;
    cin >> rows >> cols >> width;
    int turns = rows * (cols / width) + ((cols % width ? width : width - 1));
    print_answer(id, turns);
}

int main() {
    int test_count;
    cin >> test_count;
    for (int i = 0; i < test_count; ++i) {
        process_test(i + 1);
    }
    return 0;
}