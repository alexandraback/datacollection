#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<char> > desk(4);

char pl[] = {'X', 'O'};

bool test(int x, int y, int dx, int dy, char c) 
{
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        if (desk[x][y] == c || desk[x][y] == 'T') {
            ++count;
        }
        x += dx;
        y += dy;
    }
    return count == 4;
}

int solve() 
{
    int a, n;
    cin >> a >> n;
    vector<int> b = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int count = 0;
    int min_c = 1000;

    sort(b.begin(), b.end());


    for (int i = 0; i < n; ++i) {
        if (b[i] < a) {
            a += b[i];
            if (a > 1000000) {
                min_c = min(min_c, count);
            }
           // min_c = min(min_c, count + n - i);
            continue;
        }
        
        min_c = min(min_c, count + n - i);
        if (a > 1) {
            while (b[i] >= a) {
                a += a - 1;
                ++count;
            }
            if (a > 1000000) {
                min_c = min(min_c, count);
            }
            a += b[i];
        } else {
            count = n;
            break;
        }
    }
    min_c = min(min_c, count);
   
    return min_c;
}

int main(int argc, char* argv[])
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
	return 0;
}

