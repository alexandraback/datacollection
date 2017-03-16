#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

void quickSort(int array[], int start, int end);

int main() {
  	ifstream testCase ("./B-small-attempt0.in");
  	ofstream testCaseAns ("./output.txt");

  	int T = 0;
  	testCase >> T;
  	for (int i = 0; i < T; i++) {
    		int N = 0;
    		testCase >> N;
        unordered_map<int, int> myMap;
        for (int j = 0; j < 2 * N - 1; j++) {
            for (int k = 0; k < N; k++) {
                int ele = 0;
                testCase >> ele;
                if (myMap.find(ele) == myMap.end()) {
                    myMap[ele] = 1;
                }
                else {
                    myMap[ele]++;
                }
            }
        }
        int str[N + 5];
        int index = 0;
        for (auto e: myMap) {
            if ((e.second & 1) == 1) {
                str[index] = e.first;
                index++;
            }
        }
        quickSort(str, 0, N - 1);
        testCaseAns << "Case #" << i + 1 << ":";
        for (int j = 0; j < N; j++) {
            testCaseAns << " " << str[j];
        }
        testCaseAns << "\n";
  	}
  	testCase.close();
  	testCaseAns.close();
  	return 0;
}


void quickSort(int array[], int start, int end) {
    if (end - start < 2) {
        if (start + 1 == end && array[start] > array[end]) {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }
    else {
        int pivot = array[start];
        int head = start + 1, tail = end;
        while (tail > head) {
            while (array[head] <= pivot) {
                head++;
            }
            while (array[tail] > pivot) {
                tail--;
            }
            if (tail > head && array[head] > pivot && array[tail] <= pivot) {
                int temp = array[head];
                array[head] = array[tail];
                array[tail] = temp;
            }
        }
        array[start] = array[tail];
        array[tail] = pivot;
        quickSort(array, start, tail - 1);
        quickSort(array, head, end);
    }
}
