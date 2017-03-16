#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

string result[100000];
int cmp(string a, string b)
{
    int len_a = a.length();
    int len_b = b.length();
    if (len_a > len_b)
    {
        return 1;
    }
    else if (len_a < len_b)
    {
        return -1;
    }
    for (int i = 0; i < len_a; i++)
    {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return 0;
}
int bsearch(int low, int high, string word)
{
    if (low == high)
    {
        return low;
    }
    int mid = (low + high) / 2;
    int ans = cmp(result[mid], word);
    if (ans > 0)
    {
        return bsearch(low, mid, word);
    }
    else if (ans < 0)
    {
        return bsearch(mid + 1, high , word);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int case_num, i, j, k, l;
    j = 5;
    result[0] = "1";
    result[1] = "2";
    result[2] = "3";
    result[3] = "11";
    result[4] = "22";

    string a;
    queue<string> odd;
    queue<string> even;
    odd.push(result[0]);
    odd.push(result[1]);
    for (i = 0; i < 25; i++)
    {
        while (!odd.empty())
        {
            string t = odd.front();
            odd.pop();
            string reverse;
            for (k = t.length() - 1; k >= 0; k--)
            {
                reverse.push_back(t[k]);
            }
            int sum = 0;
            even.push(t);
            result[j++] = t + "0"+ reverse;
            for (k = 0; k < t.length(); k++)
            {
                sum += (t[k] - '0') * (t[k]-'0') * 2;
            }
            if (sum + 1 < 10)
            {
                result[j++] = t + "1"+ reverse;
            }
            if (sum + 4 < 10)
            {
                result[j++] = t + "2"+ reverse;
            }
        }
        while(!even.empty())
        {   string t = even.front();
            even.pop();
            string reverse;
            for (k = t.length() - 1; k >= 0; k--)
            {
                reverse.push_back(t[k]);
            }
            odd.push(t + "0");
            int sum = 0;
            result[j++] = t + "00"+ reverse;
            for (k = 0; k < t.length(); k++)
            {
                sum += (t[k] - '0') * (t[k] - '0') * 2;
            }
            if (sum + 2 < 10)
            {
                result[j++] = t + "11"+ reverse;
                odd.push(t + "1");
            }
            if (sum + 8 < 10)
            {
                result[j++] = t + "22"+ reverse;
                odd.push(t + "2");
            }
        }
    }
    for (i = 0; i < j; i++)
    {
        string temp;
        for (k = 0; k < result[i].length() * 2 - 1;k++)
        {
            temp.push_back('0');
        }
        for (k = 0; k < result[i].length(); k++)
        {
            if (result[i][k] != '0')
            {
                for (l = 0; l < result[i].length(); l++)
                {
                    temp[k + l] += (result[i][k] - '0') * (result[i][l] - '0');
                }
            }
        }
        result[i] = temp;
    }
    i = 0;
    cin >>case_num;
    while (i++ < case_num)
    {
        string low, high;
        cin >> low >> high;
        j = bsearch(0, 48851, low);
        k = bsearch(0, 48851, high);
        cout << "Case #" << i << ": ";
        if (cmp(result[k], high) == 0)
        {
            cout << k -j + 1 << endl;
        }
        else
        {
            cout << k - j << endl;
        }
    }
}
