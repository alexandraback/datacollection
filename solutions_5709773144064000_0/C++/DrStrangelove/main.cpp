#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int nc;
    cin >> nc;
    for (int tc=1; tc<=nc; tc++)
    {
        double c, f, x, cant = 2.0, tiempototal = 0.0;
        cin >> c >> f >> x;
        while (true)
        {
            double todo = x/cant;
            double newfarm = c/cant;
            cant += f;
            double todo2 = x/cant;
            if (todo < newfarm + todo2)
            {
                tiempototal += todo;
                break;
            }
            //printf("%lf %lf %lf\n",todo,todo2+next,tiempototal);
            tiempototal += newfarm;
        }
        cout << "Case #" << tc << ": ";
        printf("%.7lf\n", tiempototal);
    }
    fclose (stdout);
    return 0;
}

