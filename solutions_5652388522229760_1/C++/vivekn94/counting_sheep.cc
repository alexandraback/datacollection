#include <iostream>
#include <fstream>

int arr[10];

void reset(int arr[]) {
    for(int i = 0; i < 10; i++) {
        arr[i] = 0;
    }
}

int isDone(int arr[]) {
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        if (arr[i] == 1) {
            cnt++;
        }
    }
    if(cnt == 10)
        return 1;
    else
        return 0;
}

int check(int n) {
    int i = 1, done = 0, n1, n2;
    if(n == 0) return -1;
    while(done == 0) {
        n2 = i * n;
        n1 = n2;
        i++;
        //printf("i is %d\n", i);
        while(n1 > 0) {
            arr[n1 % 10] = 1;
            n1 = n1 / 10;
        }
        done = isDone(arr);
    }
    return n2;
}

int main() {

    std::ifstream infile;
    std::ofstream outfile;
    infile.open("in1s.txt");
    outfile.open("out1s.txt");
    reset(arr);
    int t, val, n;
    infile >> t;
    for(int i = 0; i < t; i++) {
        infile >> n;
        //printf("%d\n", n);
        val = check(n);
        reset(arr);
        if(val == -1) {
            outfile << "Case #" << i+1 << ": INSOMNIA" << "\n";
        }
        else {
            outfile << "Case #" << i+1 << ": " << val << "\n";
        }
    }
    return 0;
}
