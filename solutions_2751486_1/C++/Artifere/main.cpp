#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n, strSize;
string str;

int main()
{
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
    int t = 1, nbT;
    bool isCons[256];
    for (int i = 0; i < 256; i++)
        isCons[i] = true;

    isCons['a'] = false;
    isCons['e'] = false;
    isCons['i'] = false;
    isCons['o'] = false;
    isCons['u'] = false;

    cin >> nbT;
    while (t <= nbT)
    {
        queue<long long> debs, fins;
        cin >> str >> n;

        long long curConsSuite = 0;
        strSize = str.size();

        for (long long pos = 0; pos < strSize; pos++)
        {
            if (isCons[str[pos]])
            {
                curConsSuite++;
                if (curConsSuite == n)
                {
                    debs.push(pos-curConsSuite+1);
                    fins.push(pos);
                    curConsSuite--;
                }
            }

            else
                curConsSuite = 0;
        }
        /*while (debs.size() > 0)
        {
            cout << debs.front() << "=>" << fins.front() << endl;
            debs.pop();
            fins.pop();
        }
        t++;
        continue;*/

        long long rep = 0;
        for (long long pos = 0; pos < str.size() && !debs.empty(); pos++)
        {
            if (pos > debs.front())
            {
                debs.pop();
                fins.pop();
                if (debs.empty())
                    break;
            }

            rep += (strSize-fins.front());
        }



        cout << "Case #" << t << ": " << rep << "\n";
        t++;
    }






    return 0;
}
