#include <bits/stdc++.h>

using namespace std;

int main(int argc,char *argv[])
{
    char buf[63556];
    int T;
    cin >> T;
    for (int t=0;t<T;t++)
    {
        int N;
        cin >> N;
        cin.getline(buf, 65536);

        vector< pair<string, string> > row;
        map<string, int> word1,word2;
        for (int i=0;i<N;i++)
        {
            cin.getline(buf, 65536);
            string s = buf;
            string A = s.substr(0, s.find(' '));
            string B = s.substr(s.find(' ')+1, s.length());
            row.push_back(make_pair(A,B));
            word1[A]++;
            word2[B]++;
        //    cout << A << ":" << B << endl;
        }
        int ans = 0;

        for (int b=0;b<(1<<row.size());b++)
        {
            map<string, int> tword1,tword2;
            for (int k=0;k<row.size();k++)
                if (((1<<k)&b)!=0)
                {
                    tword1[row[k].first]++;
                    tword2[row[k].second]++;
                }
            int tel = 0;
            for (int k=0;k<row.size();k++)
                if (((1<<k)&b)==0)
                {
                    if (tword1[row[k].first]>0 &&
                        tword2[row[k].second]>0)
                    {
                        tel++;
                    } else
                    {
                        tel = -1;
                        break;
                    }
                }
            if (tel>=0)
                ans = max(ans, tel);
        }

        cout << "Case #" << t+1 << ": " << ans << endl;
    }
    return 0;
}
