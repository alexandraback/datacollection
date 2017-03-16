#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream fin("C-large-1.in");
    ofstream fout("aa111.out");
    int t = 0;
    fin >> t;
    long long a, b;
    long long ans[41] = {1 ,4 ,9 ,121 ,484 ,10201 ,12321 ,14641 ,40804 ,44944 ,
                         1002001 ,1234321 ,4008004 ,100020001 ,102030201 ,104060401 ,121242121 ,123454321 ,125686521 ,
                         400080004 ,404090404 ,10000200001 ,10221412201 ,12102420121 ,12345654321 ,40000800004 ,
                         1000002000001 ,1002003002001 ,1004006004001 ,1020304030201 ,1022325232201 ,
                         1024348434201 ,1210024200121 ,1212225222121 ,1214428244121 ,1232346432321 ,
                         1234567654321 ,4000008000004 ,4004009004004, 100000000000001
                        };
    for (int ww = 0; ww < t; ++ww)
    {
        fin >> a >> b;
        bool isOK = true;
        long long m_count = 0;

        for (int i = 0; i < 39; ++i) {
            if (a == ans[i]) {
                for (int j = i; j < 39; ++j) {
                    if (b >= ans[j] && b < ans[j+1]) {
                        m_count = j+1 - i;
                    }
                }
            } else if (a > ans[i] && a < ans[i+1]) {
                for (int j = i; j < 39; ++j) {
                    if (b >= ans[j] && b < ans[j+1]) {
                        m_count = j - i;
                    }
                }
            }
        }
        fout << "Case #" << ww+1 << ": " << m_count << endl;
    }
    return 0;
}
