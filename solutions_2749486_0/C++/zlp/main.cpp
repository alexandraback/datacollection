#include <fstream>

using namespace std;

int main()
{
    ifstream in("B.in");
    ofstream out("B.out");

    int times = 0;
    in >> times;
    for (int num = 0;num < times;num++)
    {
        out << "Case #" << num + 1 << ": ";
        int a,b;
        in >> a >> b;
        if (a > 0)
        {
            for (int i = 0;i < a;i++) out << "WE";
        }
        else if(a < 0)
        {
            for (int i = 0;i < -a;i++) out << "EW";
        }
        if (b > 0)
        {
            for (int i = 0;i < b;i++) out << "SN";
        }
        else if(b < 0)
        {
            for (int i = 0;i < -b;i++) out << "NS";
        }
        out << '\n';
    }
    return 0;
}
