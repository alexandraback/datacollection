#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int c, d, v;
int result;
set<int> dSet;

ifstream in("input.txt");
ofstream out("output.txt");

void input();
void process();

int main(int argc, const char * argv[]) {
    int i, T;
    in >> T;
    
    for ( i=0; i<T; i++ ) {
        input();
        process();
        out << "Case #" << i+1 << ": " << result << endl;
    }
    return 0;
}

void input() {
    int i;
    int value;
    in >> c >> d >> v;
    
    dSet.clear();
    for ( i=0; i<d; i++ ) {
        in >> value;
        dSet.insert(value);
    }
}

void process() {
    
    int i, j, k;
    vector<bool> isAble(v, false);
    isAble[0] = true;
    result = 0;
    
    for( set<int>::iterator it = dSet.begin(); it!=dSet.end(); it++ ) {
        for ( i=1; i<=c; i++ ) {
            int value = i * (*it);
            for ( j=v; j>=value; j-- ) {
                if ( isAble[j-value] ) {
                    isAble[j] = true;
                }
            }
        }
    }
    
    for ( i=v; i>0; i-- ) {
        if ( isAble[i] == false ) {
            for( j=i-1; j>=0; j-- ) {
                if ( isAble[j] ) {
                    if ( dSet.find(i-j) == dSet.end() ) {
                        int value = i-j;
                        dSet.insert(value);
                        result++;
                        for ( k=i; k>=value; k-- ) {
                            if ( isAble[k-value] ) {
                                isAble[k] = true;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    
}