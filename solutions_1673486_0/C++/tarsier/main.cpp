#include <iostream>
#include <iomanip>
using namespace std;

double p[100010] = {0};
double kind[100010] = {0.0};
double right_rate[100010] = {0.0};

int main()
{
    int T;
    cin >> T;
    for (int testcase=1; testcase<=T; testcase++) {

        int haveTyped, B;
        cin >> haveTyped >> B;

        int i, j, k;

        right_rate[0] = 1.0;

        for (i=1; i<=haveTyped; i++)
            cin >> p[i];

        for (i=1; i<=haveTyped; i++)
            right_rate[i] = right_rate[i-1]*p[i];

        // 1.press backspace [0, haveTyped] 如何算？

        for (j=0; j<=haveTyped; j++)
        {
        // 删除掉了最后j个
        kind[j] = right_rate[haveTyped-j]*(j+B-(haveTyped-j)+1)
                    +(1-right_rate[haveTyped-j])*(j+B-(haveTyped-j)+1 + B+1);

        }

        // 2. press enter right away
        kind[haveTyped+1] = B+1+1;

        double min = 9999999999999999;
        for(j=0; j<=haveTyped+1; j++)
            if(min > kind[j])
                min = kind[j];

        cout << "Case #" << testcase << ": " <<setiosflags(ios::fixed)<<setprecision(6) << min << endl;

    }

    return 0;
}
