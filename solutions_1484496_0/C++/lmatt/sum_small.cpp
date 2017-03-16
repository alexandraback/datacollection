#include <iostream>
using namespace std;

int help[501];

int over(int *data, int s, int n)
{
    if(s == n)
    {
        int left = 0;
        int right = 0;
        for(int i = 0; i < n; i++) 
        {
            if(help[i] > 0) left += data[i];
            else if(help[i] < 0) right += data[i];
        }
        if(left == right && left != 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(help[i] > 0)
                cout << data[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < n; i++)
            {
                if(help[i] < 0)
                cout << data[i] << " ";
            }
            cout << endl;
            return 1;
        }
        else return 0;
    }
    help[s] = 0;
    int ret = over(data, s + 1, n);
    if(ret) return ret;
    help[s] = 1;
    ret = over(data, s + 1, n);
    if(ret) return ret;
    help[s] = -1;
    ret = over(data, s + 1, n);
    return ret; 
}

void func(int *data, int n)
{
    for(int i = 0; i < n; i++) help[i] = 0;
    if(over(data, 0, n) == 0) cout << "Impossible" <<endl;
}

int main()
{
    int t;
    int data[501];
    cin >> t;
    for(int ti = 1; ti <= t; ti++)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> data[i];
        cout << "Case #" << ti << ":" << endl;
        func(data, n);
    }
    return 0;
}
