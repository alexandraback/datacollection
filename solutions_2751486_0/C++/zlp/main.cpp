#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct point
{
    int a,b;
    bool operator==(point anop)
    {
        return (this->a == anop.a && this->b == anop.b);
    }
};

bool isCons(char c)
{
    switch(c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return false;
        break;
    default: return true;
        break;
    }
}
int main()
{
    ifstream in("cons.in");
    ofstream out("cons.out");

    int times = 0;
    in >> times;
    for (int num = 1;num <= times;num++)
    {
        string str;
        int n;
        in >> str >> n;
        int len = str.length();
        int lx = 0;
        int ans = 0;
        vector<point> vec;
        for (int i = 0;i <= len;i++)
        {
            if (i != len && isCons(str[i])) lx++;
            else
            {
                if (lx < n) { lx = 0; continue; }
                int temp = i - lx;
                for (int k = 0;k < lx - n + 1;k++)
                {
                    int temp2 = temp + k;
                    ans += (temp2 + 1) * (len - temp2 - n + 1);
                    point sss;
                    for (int j = 0;j <= temp2;j++)
                    {
                        for (int t = 0;t <= len - temp2 - n;t++)
                        {
                            sss.a = temp2 - j;
                            sss.b = n + t + j;

                            int flag = 1;
                            for (vector<point>::iterator it = vec.begin();it != vec.end();++it)
                            {
                                if (sss == *it) { ans--; flag = 0; }
                            }
                            if (flag) vec.push_back(sss);
                        }
                    }
                }
                lx = 0;
                continue;
            }
        }

        out << "Case #" << num << ": " << ans << '\n';
    }
    return 0;
}
