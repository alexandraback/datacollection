#include <fstream>
#include <queue>
#include <utility>

using namespace std;

int rev (int n) {
    int aux = 0;
    while (n) {
        aux *= 10;
        aux += (n % 10);

        n /= 10;
    }

    return aux;
}

int d[1000005];
bool done[1000005];
priority_queue <pair <int, int> > coada;

//pair <pair <int, int>, pair <int, int> > stiva[100005];
//int pos;

int main()
{
    ifstream cin("A.in");
    ofstream cout("A.out");

    //for (int i = 1; i <= 105; i++)
    //    cout << i << ' ' << rev(i) << endl;

    for (int i = 1; i <= 1000000; i++)
        d[i] = 1000005;

    coada.push(make_pair(0, 0));

    int y;
    while (!coada.empty()) {
        y = coada.top().second;
        coada.pop();

        if (done[y])
            continue ;
        done[y] = true;

        if (1 + d[y] < d[y + 1] && y + 1 <= 1000000) {
            coada.push(make_pair(-1 - d[y], y + 1));
            d[y + 1] = 1 + d[y];
        }

        if (1 + d[y] < d[rev(y)] && rev(y) <= 1000000) {
            coada.push(make_pair(-1 - d[y], rev(y)));
            d[rev(y)] = 1 + d[y];
        }
    }

    //for (int i = 101; i <= 300; i++)
   //     cout << i << ' ' << d[i] << endl;

    //for (int i = 1; i <= 10000; i++)
    //    if (stiva[pos].second.second + 1 == d[i] && i != 1 && i != 10 && i != 100 && i != 1000 && i != 10000)
    //        stiva[pos].second.second ++, stiva[pos].first.second ++;
    //    else
    //        stiva[++ pos] = make_pair(make_pair(i, i), make_pair(d[i], d[i]));

    //for (int i = 1; i <= pos; i++)
    //    cout << stiva[i].first.first << ' ' << stiva[i].first.second << " -> " << ' ' << stiva[i].second.first << ' ' << stiva[i].second.second << endl;

    int t = 0;
    cin >> t;

    int x;
    for (int i = 1; i <= t; i++) {
        cin >> x;

        cout << "Case #" << i << ": " << d[x] << '\n';
    }

    cin.close();
    cout.close();
    return 0;
}
