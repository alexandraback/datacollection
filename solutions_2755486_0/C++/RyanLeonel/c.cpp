#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct attack {
  int t, d, w, e, s;
};

bool compare_d(attack i,attack j)
{
  return (i.d<j.d);
}

int main()
{
    bool success;
    int cnt, i, j, n1, n2, num, res, t, temp, temp1;
    vector <int> d, n, w, e, s, delta_d, delta_p, delta_s, days;
    vector < vector <int> > wall;
    vector <int> wall1;
    vector <attack> a;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> num;
        d.resize(num); n.resize(num); w.resize(num); e.resize(num); s.resize(num);
        delta_d.resize(num); delta_p.resize(num); delta_s.resize(num);
        n1 = 0;
        for (i = 0; i < num; i++)
        {
            cin >> d[i]; cin >> n[i]; cin >> w[i]; cin >> e[i]; cin >> s[i];
            cin >> delta_d[i]; cin >> delta_p[i]; cin >> delta_s[i];
            a.resize(n1 + n[i]);
            for (j = 0; j < n[i]; j++)
            {
                a[n1 + j].t = i;
                a[n1 + j].d = d[i] + (j * delta_d[i]);
                a[n1 + j].w = w[i] + (j * delta_p[i]);
                a[n1 + j].e = e[i] + (j * delta_p[i]);
                a[n1 + j].s = s[i] + (j * delta_s[i]);
            }
            n1 += n[i];
        }
        //sort t1, d1, w1, e1, s1
        stable_sort(a.begin(), a.end(), compare_d);
        n2 = 0; temp = -1;
        for (i = 0; i < n1; i++)
        {
            if (a[i].d != temp)
            {
                temp = a[i].d;
                days.push_back(temp);
                n2++;
            }
        }
        wall.resize(n2);
        for (i = 0; i < n2; i++)
        {
            wall[i].resize(400);
            for (j = 0; j < 400; j++) wall[i][j] = 0;
            /*a[n1 + j].t = i; //tribe
            a[n1 + j].d = d[i] + (j * delta_d[i]); //day
            a[n1 + j].w = w[i] + (j * delta_p[i]); //left
            a[n1 + j].e = e[i] + (j * delta_p[i]); //right
            a[n1 + j].s = s[i] + (j * delta_s[i]); //str*/
        }
        res = 0; temp1 = 0; wall1.resize(400); for (i = 0; i < 400; i++) wall1[i] = 0;
        //for (i = 0; i < n2; i++) cout << days[i] << endl;
        for (i = 0; i < n1; i++)
        {
            //cout << a[i].t << " " << a[i].d << " " << a[i].w << " " << a[i].e << " " << a[i].s << endl;
            temp = 0;
            for (j = 1; j < n2; j++) if (a[i].d == days[j]) temp = j;
            if (temp != temp1) // update wall height
            {
                for (j = 0; j < 400; j++) wall[temp][j] = wall1[j];
                temp1 = temp;
            }
            success = false;
            for (j = a[i].w + 200; j < a[i].e + 200; j++)
            {
                if (wall[temp][j] < a[i].s)
                {
                    //cout << wall[temp][j] << " " << a[i].s << " ";
                    success = true;
                    break;
                }
            }
            //cout << "success" << endl;
            if (success)
            {
                res++;
                for (j = a[i].w + 200; j < a[i].e + 200; j++)
                {
                    if (wall1[j] < a[i].s) wall1[j] = a[i].s;
                }
            }
        }
        cout << "Case #" << cnt << ": " << res << endl;
    }
    return 0;
}
