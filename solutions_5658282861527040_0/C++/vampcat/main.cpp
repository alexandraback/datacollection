#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[i])
                swap(arr[j], arr[i]);
}

int main()
{
    int t;
    std::cin >> t;

    for (int caseNo = 0; caseNo < t; caseNo++)
    {
        int a, b, k;
        std::cin >> a >> b >> k;

        int ans = 0;

        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                if ((i&j) < k)
                    ans++;

        std::cout << "Case #" << (caseNo + 1) << ": ";
        std::cout << ans;
        std::cout << std::endl;
    }

    return 0;
}
