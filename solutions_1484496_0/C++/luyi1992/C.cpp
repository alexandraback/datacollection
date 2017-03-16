#include<iostream>
#include<map>

using namespace std;

int T;
int n,len,l1,temp,la,lb;
long long a[600],list[4000000],sa[600],sb[600];

map<long long,long long> f;

bool gao()
{
    f.clear();
    list[0] = a[0];
    len = 1;
    f[a[0]] = a[0];
    for(int i = 1;i < n;i++)
    {
        //cout << i << "!\n";
        l1 = len;
        for(int j = 0;j < l1;j++)
        {
            temp = list[j] + a[i];
            if (f.count(temp) == 0)
            {
                f[temp] = a[i];
                list[len++] = temp;
                if (temp == 0) return true;
            }
            temp = list[j] - a[i];
            if (f.count(temp) == 0)
            {
                f[temp] = -a[i];
                list[len++] = temp;
                if (temp == 0) return true;
            }
        }
    }
    return false;
}

void outans()
{
    long long t = 0;
    la = lb = 0;
    do
    {
        temp = f[t];
        if (temp > 0) sa[la++] = temp; else
        sb[lb++] = -temp;
        t -= temp;
    } while (t != 0);
    for(int i = 0;i < la-1;i++) cout << sa[i] << " ";
    cout << sa[la-1] << endl;
    for(int i = 0;i < lb-1;i++) cout << sb[i] << " ";
    cout << sb[lb-1] << endl;
}

int main()
{
    cin >> T;
    for(int I = 1;I <= T;I++)
    {
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        cout << "Case #" << I <<":\n";
        if (gao()) outans(); else cout << "Impossible\n";
    }
    return 0;
}
