#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void runTest()
{
    int N; cin >> N;
    double read;
    vector<double> a;
    vector<double> b;
    for (int i=0; i<N; i++)
    {
        cin >> read; a.push_back(read);
    }
    for (int i=0; i<N; i++)
    {
        cin >> read; b.push_back(read);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int newScore=0, oldScore=0;
    int i=0, j=0;
    while ((i<N) && (j<N))
    {
        if (a[i]>b[j])
        {
            newScore++; j++;
        }
        i++;
    }
    i=0; j=0;
    while ((i<N) && (j<N))
    {
        if (b[i]>a[j])
        {
            oldScore++; j++;
        }
        i++;
    }
    cout << newScore << " " << (N - oldScore) << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int test=1; test<=T; test++)
    {
        cout << "Case #" << test << ": ";
        runTest();
    }
    return 0;
}
