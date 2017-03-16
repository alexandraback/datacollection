#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cctype>

using namespace std;

int main()
{

    freopen ("A-small-attempt0.in", "r", stdin);
    freopen ("A-small-attempt0.out", "w", stdout);

    string line;
    int T;
    scanf("%d", &T);
    getline(cin,line);
    for(int prob = 1; prob <= T; prob++) {
        getline(cin, line);
        //cout << line << endl;
        printf("Case #%d: ", prob);
        int l = line.size();
        int j = l - 1;
        while (!isspace(line[j])) {j--;}// cout << line[j] << ' ';
        int N = j; j++; int n = 0; while(j < l) {n *= 10; n += line[j] - '0';  j++;}
        //cout << "N = " << N << endl;
        //cout << "n = " << n << endl;
        int count = 0;
        for(int i = 0; i < N; i++)
        for(int j = i + 1; j <= N; j++) {
                int sum = 0;
                int current = 0;
                for(int k = i; k < j; k++) {
                    if (line[k] != 'a' && line[k] != 'e' && line[k] != 'i'
                        && line[k] != 'u' && line[k] != 'o') current++;
                    else {sum = max(sum, current); current = 0;}
                }
                if (max(sum, current) >= n) count++; //{cout << "from " << i  << " to " << j << endl;}
        }
        printf("%d\n", count);

    }

    return 0;
}
