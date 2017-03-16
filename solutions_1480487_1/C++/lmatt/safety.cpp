#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    int n;
    double total = 0;
    int data[201];
    cin >> t;
    for(int ti = 1; ti <= t; ti++)
    {
        cin >> n;
        total = 0;
        for(int i = 0; i < n; i++) 
        {
            cin >> data[i];
            total += data[i];
        }
        //sort(data, data + n);
        int rn = n;
        int rt = total;
        double avg = (rt + total) / rn;
        for(int i = 0; i < n; i++)
        {
            int find = 0;
            for(int j = 0; j < n; j++)
            {
                if(data[j] > avg)
                {
                    rt -= data[j];
                    data[j] = -data[j];
                    rn--;
                    find++;
                }
            }
            //cout << find << " " << rt << " " << rn << endl;
            if(find == 0) break;
            avg = (rt + total) / rn;
        }
        cout << "Case #" << ti << ": ";
        for(int i = 0; i < n; i++)
        {
            if(i != 0) cout << " ";
            if(data[i] < 0) cout << 0;
            else printf("%.8lf", (avg - data[i]) / total * 100);
        }
        cout << endl;
    }
    return 0;
}
