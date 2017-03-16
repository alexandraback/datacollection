//#include <bits/stdc++.h>
//#include <QtCore>

//using namespace std;

//vector <int> mmd [110];
//vector <int> man [110];
//string eth;

//int moves (int j, const string &s1)
//{
//    string a1;
//    char prc = 0; int temp = 0;
//    for (int i = 0; i < s1.length(); ++i)
//        if (s1[i] != prc && prc != 0)
//        {
//            mmd[j].push_back(temp);
//            a1.push_back(prc);
//            prc = s1[i];
//            temp = 1;
//        }
//        else if (0 == prc)
//            prc = s1[i];
//        else
//            ++temp;
//    if (!eth.empty() && a1 != eth)
//        return INT_MAX;
//    if (eth.empty())
//        eth = a1;
//    mmd[j].push_back(temp);
//    return 0;

//}

//int main ()
//{
//    ios_base::sync_with_stdio(0);
//    ifstream cin ("/home/misha/in");
//    //ofstream cout ("/home/misha/AOut");
//    int t;
//    cin >> t;
//    vector <string> data(110);
//    for (int i = 0; i < t;)
//    {

//        HELL: ++i;
//        if (i >= t)break;
//        for (int j = 0; j < 110; ++j){
//            mmd[j].clear(); man[j].clear();}
//        int n;
//        cin >> n;
//        vector <long long> answers;
//        cout << "Case #" << i + 1 << ": ";

//        for (int j = 0; j < n; ++j)
//        {
//            cin >> data[j];
//        }

//        for (int j = 0; j < n; ++j)
//        {
//            if (moves(j, data[j]) != 0)
//            {
//                cout << "Fegla Won" << endl;
//                goto HELL;
//            }
//        }

//        for (int j = 0; j < mmd[0].size(); ++j)
//        {
//            for (int k = 1; k <= 100; ++k)
//            {
//                for (int l = 0; l < n; ++l)
//                {
//                    man[j].push_back(abs(mmd[l][j] - k));
//                }
//            }
//        }

//        for (int j = 0; j < mmd[0].size();++j)
//        {
//            answers.push_back(*min_element(man[j].begin(), man[j].end()));
//        }
//        cout << *max_element(answers.begin(), answers.end()) << endl;



//    }
//}
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin ("/home/misha/B-small-attempt0.in");
    ofstream cout ("/home/misha/BOUT");
    int t;
    cin >> t;
    for(int p = 0; p < t; p++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        int answ  = 0;
        for(int i = 0; i < a; ++i)
            for(int j = 0; j < b; ++j)
                if((i & j) < k)
                    ++answ;
        cout << "Case #" << p + 1 << ": " << answ << endl;
    }

    return 0;
}
