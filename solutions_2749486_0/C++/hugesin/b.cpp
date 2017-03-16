#include<iostream>
using namespace std;

int main()
{
    int case_num, n;
    cin >> case_num;
    for (n = 1; n <= case_num; n++)
    {
        int x, y, i;
        int step = 1;
        cin >> x >> y;
        string str;
        bool odd = true;
        if (x == 0);
        else if (x > 0)
        {
            str.push_back('E');
            for (i = 1; i < x; i ++)
            {
                str += "WE";
            }
        }
        else if (x < 0)
        {
            str.push_back('W');
            for (i = 1; i < -x; i ++)
            {
                str += "EW";
            }
        }
        if (y == 0);
        else if (y > 0)
        {
            for (i = 0; i < y; i ++)
            {
                str += "SN";
            }
        }
        else if (y < 0)
        {
            for (i = 0; i < -y; i ++)
            {
                str += "NS";
            }
        }
        cout << "Case #" << n << ": " << str << endl;
    }
    return 0;
}
