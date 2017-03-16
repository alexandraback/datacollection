#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int test;
    cin >> test;
    for (int testcase=1; testcase<=test; testcase++) {

        int db[10]={0};
        string s;
        cin >> s;
        db[0]= count(s.begin(), s.end(), 'Z');
        db[2]= count(s.begin(), s.end(), 'W');
        db[4]= count(s.begin(), s.end(), 'U');
        db[6]= count(s.begin(), s.end(), 'X');
        db[8]= count(s.begin(), s.end(), 'G');
        db[3]= count(s.begin(), s.end(), 'H') - db[8];
        db[5]= count(s.begin(), s.end(), 'F') - db[4];
        db[7]= count(s.begin(), s.end(), 'S') - db[6];
        db[9]= count(s.begin(), s.end(), 'I') - db[5]-db[6]-db[8];
        db[1]= count(s.begin(), s.end(), 'N') - db[7] - 2*db[9];



        cout << "Case #" << testcase << ": ";
        for (int i=0; i<10; i++)
            for (int j=0; j<db[i]; j++)
                cout<<i;
        cout<< endl;
    }
    return 0;
}
