#include <iostream>
using namespace std;
int main()
{
    int T, n, count = 1;
    cin >> T;
    while(T>0)
    {
        int req = 0, sum = 0, *a;
        string s;
        cin >> n;
        cin >> s;
        a = new int[n+1];
        for(int i = 0; i<=n; i++)
            a[i] = s[i]-'0';
        sum = a[0];
        for(int i=1; i<=n; i++)
        {
            if(sum >= i || a[i] == 0)
            {
                sum += a[i];
                continue;
            }
            req += (i - sum);
            sum = sum + a[i] + req;    
        }
        cout << "Case #" << count << ": " << req << endl;  
        count++;
        T--;
        delete[] a;
    }
    return 0;
}