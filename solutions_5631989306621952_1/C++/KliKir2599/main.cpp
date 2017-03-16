#include <iostream>
#include <fstream>

using namespace std;

std::ifstream fin("input.in");
std::ofstream fout("output.out");


int main()
{
    int num;
    int i, j, ans, l;
    string s;
    char a [2010];
    int b [1010];

    fin >> num;
    for (i=0; i<num; i++)
    {
        fin >> s;
        l = s.size();
        for (j=0; j<l; j++)
        {
            for (j=0; j<1010; j++) b[j] = 0;
            int con = int('a');
            for (j=0; j<l; j++) b[j] = int(s[j]);
         //   for (j=0; j<10; j++) cout << b[j] << " ";
            int ind1 = 1006;
            int ind2 = 1004;
            for (j=0; j<2010; j++) a[j] = ' ';
            a[1005] = s[0];
            for (j=1; j<l; j++)
            {
                if (b[j]>=int(a[ind2+1]))
                {
                    a[ind2] = s[j];
                    ind2--;
                }
                else
                {
                    a[ind1] = s[j];
                    ind1++;
                }
            }
            string sans;
            sans = "";
            for (j=0; j<2010; j++) if (a[j]!=' ') sans += a[j];
          //  cout << sans << endl;
            fout << "Case #" << i + 1 << ": " << sans << endl;
        }
    }
    return 0;
}
