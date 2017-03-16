#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int N;
        vector<pair<string, string> > topics;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            string s, t;
            cin >> s >> t;
            topics.push_back(make_pair(s, t));
        }

        int res = 0;
        int MAXX = 1 << N;
        for(int x = 0; x < MAXX; x++)
        {
            int y = x;
            int count = 0;
            set<pair<string, string> > badSet;
            set<string> goodSet1, goodSet2;
            for(int i = 0; i < N; i++)
            {
                bool fake = ((y % 2) == 1);
                if(fake)
                {
                    count++;
                    badSet.insert(topics[i]);
                }
                else
                {
                    goodSet1.insert(topics[i].first);
                    goodSet2.insert(topics[i].second);
                }
                y /= 2;
            }

            bool works = true;
            for(auto it = badSet.begin(); it != badSet.end(); it++)
            {
                string first = (*it).first; string second = (*it).second;
                if(goodSet1.count(first) == 0 || goodSet2.count(second) == 0)
                {
                    works = false;
                    break;
                }
            }

            if(works) res = max(res, count);
        }
                

        cout << "Case #" << t << ": " << res << endl;
    }


    return 0;
}
