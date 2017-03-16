#include <iostream>
#include <fstream>
using namespace std;

fstream fin,fout;

int t,n;
int a[1000],b[1000];
int f[1000];
int ans,now;
bool flag,xx;

int main()
{   fin.open("B-small-attempt1.in",ios::in);
    fout.open("b_ans.out",ios::out);
    fin >> t;
    for (int l = 0; l < t; l++)
    {
        fin >> n;
        for (int i = 0; i < n; i++) {fin >> a[i] >> b[i]; f[i] = 0;}
        ans = 0; now = 0;

        flag = true;
        int k = n;
        while (true)
        {
            xx = true;
            while (xx)
            {
                xx = false;
                for (int h = 0; h < n; h++)
                    if (f[h] < 2 && b[h] <= ans)
                    {
                        xx = true;
                        if (f[h] == 0) k--;
                        now++;
                        ans += 2-f[h];
                        f[h] = 2;
                    }
            }
            if (ans == 2*n) break;
            int tmp = -1; int max = -10;
            for (int i = 0; i < n; i++)
                if (a[i] <= ans&& f[i] == 0)
                {
                    if (b[i] > max ) {tmp = i; max = b[i];}
                }
            if (tmp == -1) { break;}
            f[tmp] = 1;
            ans += 1;
            now++;
            if (ans == 2*n) break;
        }

        if (ans == 2*n) fout << "Case #" << l+1 << ": "<< now <<endl;
        else fout << "Case #" << l+1 << ": Too Bad" <<endl;
    }
    fout.close();
    return 0;
}
