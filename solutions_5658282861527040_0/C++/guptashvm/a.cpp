#include <fstream>

using namespace std;

int t;
int n;
int a, b, k;
int main()
{
    ifstream in("in.in");
    ofstream out("out.out");
    in >> t;

    int cur = 0;
    while(cur < t)
    {
         in >> a >> b >> k;
        int result = 0;
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                int temp =i & j;
                if((i & j) < k)
                {
                    result++;
                }
            }
        }
        out << "Case #" << cur + 1 << ": " << result << endl;
        cur++;
    }
}
