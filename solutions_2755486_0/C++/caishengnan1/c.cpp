#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class att{
    public:
    int w;
    int e;
    int s;

    att(int ww, int ee, int ss)
    {
        w = ww;
        e = ee;
        s = ss;
    }
};

int main(int argc, char** argv)
{
    int T;
    cin >> T;

    for (int i = 0 ; i < T; i++)
    {
        //cout << "getting" << endl;
        int N;
        cin >> N;

        multimap <int, att> event;
        typedef multimap <int, att>::iterator mmit;

        for (int nn = 0; nn < N; nn++)
        {
            int d, n, w, e,s, dd, dp, ds;
            cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;

            int day = d;
            int power = s;
            int west = w;
            int east = e;

            //cout << n << " attacks" << endl;
            for (int ev = 0; ev < n; ev++)
            {
                att tmp(west, east, power);
                //event[day] = tmp;
                event.insert(pair<int,att>(day, tmp));

                //cout << day << " " << west << " " << east << " " << power << endl;

                // update
                day += dd;
                power += ds;
                west += dp;
                east += dp;

            }
            //cout << endl;
        }

        //cout << "getting done" << endl;

        // simulation
        int cnt = 0;
        int day = 0;
        int wall[2000];
        int ups[2000];
        memset(wall, 0, sizeof(wall));
        memset(ups, 0, sizeof(ups));
        
        int update = 0;

        for (mmit it = event.begin(); it != event.end(); ++it)
        {
            //cout << "check 0" << endl;

            int cur = it->first;
            att attack = it->second;

            {
            //cout << "day: " << cur << endl;
            }

            int aw = attack.w+1000;
            int ae = attack.e+1000;
            int as = attack.s;

            bool flag = false;
            // attack
            for (int aa = aw; aa < ae; aa++)
            {
                if (wall[aa] < as)
                {
                    //cout << wall[aa] << " < " << as << " at " << aa << endl;

                    flag = true;
                    break;
                }
            }


            //cout << "check 1" << endl;

            if (flag)// attack success
            {
                //cout << "yes" << endl;

                cnt++;
                if (day < cur) // if different day from previous
                {
                    //cout << "update wall!" << endl;
                    // update wall
                    for (int walli = 0; walli < 2000; walli++)
                        wall[walli] += ups[walli];

                    // clear ups
                    memset(ups, 0, sizeof(ups));
                }

                // update ups
                for (int upi = aw; upi < ae; upi++)
                {
                    ups[upi] = max(as, ups[upi]);
                    //cout << ups[upi] << " " ;
                }
                //cout << endl;

            }

            //cout << "check 2" << endl;
            // update days
            day = cur;
            //cout << "next day: " << day << endl;
        }
        

        cout << "Case #" << i+1 << ": ";
        cout << cnt << endl;
        event.clear();
    }

    return 0;
}

