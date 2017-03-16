#include <iostream>

using namespace std;

int a[20];

int aMin(int n)
{
    int aMin = a[0];
    for(int j = 1; j < n; j++) if(aMin > a[j]) aMin = a[j];
    return aMin;
}

int calc(int I, int n)
{
    for(int p = 1; p < 1048575; p++)//2^20
    {
        int s1 = 0;
        int i = 0;
        int p1 = p;
        while(i < n)
        {
            if(p1%2) s1 += a[i];
            p1=p1>>1;
            if(p1 == 0) break;
            i++;
        }
        for(int q = 1048576-1-p; q >=1; q--)
        {
            if(p==q) continue;
            if(p&q) continue;
            int s2 = 0;
            int j = 0;
            int q1 = q;
            while(j < n)
            {
                if(q1%2) s2 += a[j];
                q1=q1>>1;
                if(q1 == 0) break;
                j++;
            }
            if(s1 == s2)
            {
                int  k = 0;
                cout << "Case #" << I+1 << ":" << endl;
                while(k < n)
                {
                    if(p%2) cout << a[k] << " ";
                    p = p >> 1;
                    if(p == 0) break;
                    k++;
                }
                cout << endl;
                k = 0;
                while(k < n)
                {
                    if(q%2) cout << a[k] << " ";
                    q = q >> 1;
                    if(q == 0) break;
                    k++;
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 1;
}
 
int main(int argc, char *argv[])
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        for(int j = 0; j < 20; j++) a[j] = 0;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) cin >> a[j];
        if(calc(i, n))
        {
            cout << "Case #" << i+1 << ":" << endl;
            cout << "Impossible" << endl;
        }
    }
   
    return 0;
}
