#include <fstream>
using namespace std;

ifstream f("test.in");
ofstream g("test.out");

int T,R,C,W;
int answer;

int main()
{
    f >> T;
    for (int t = 1; t <= T; ++t)
    {
        f >> R >> C >> W;
        answer = C / W * R;
        if (C % W == 0)
        {
            answer = answer + W - 1;
            g << "Case #" << t << ": " << answer << '\n';
            continue;
        }
        answer += W;
        //g << answer;
        g << "Case #" << t << ": " << answer << '\n';
    }
}
