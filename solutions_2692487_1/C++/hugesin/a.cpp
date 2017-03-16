#include<iostream>
#include<cstdlib>
using namespace std;

int comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int case_num, n;
    cin >> case_num;
    for (n = 1; n <= case_num; n++)
    {
        long long mote, m, i;
        cin >> mote >> m;
        int* array = new int[m];
        int* result = new int[m];
        for (i = 0; i < m; i++)
        {
            cin >> array[i];
            result[i] = 0;
        }
        qsort(array, m, sizeof(int), comp);
        if (mote == 1)
        {
            cout << "Case #" << n << ": " << m << endl;
            delete[] array;
            delete[] result;
            continue;
        }
        for (i = 0; i < m; i++)
        {
            if (i > 0)
            {
                result[i] = result[i-1];
            }
            if (mote > array[i])
            {
                mote += array[i];
                continue;
            }
            while (mote <= array[i])
            {
                mote = (mote << 1) - 1;
                result[i] += 1;
            }
            mote += array[i];
        }
        int min = m;
        for (i = 0; i < m; i++)
        {
            if (min > result[i] + m - i - 1)
            {
                min = result[i] + m -i - 1;
            }
        }
        cout << "Case #" << n << ": " << min << endl;
        delete[] array;
        delete[] result;
    }
    return 0;
}
