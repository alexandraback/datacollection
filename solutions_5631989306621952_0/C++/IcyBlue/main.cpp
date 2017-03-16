#include <iostream>

using namespace std;

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int time_limits;
    cin >> time_limits;
    for (int time_count = 0; time_count < time_limits; time_count++)
    {
        printf("Case #%d: ",time_count+1);
        string input;
        cin >> input;
        string ans;
        ans = input[0];
        for (int i = 1; i < input.length(); i++)
        {
            if (input[i] >= ans[0])
            {
                ans = input[i] + ans;
            }
            else
                ans = ans + input[i];
        }

        cout << ans;


        printf("\n");
    }
}