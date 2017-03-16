#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;



int main()
{
    std::ios::sync_with_stdio(false);
    int t,T;
    cin >> T;
    for (t=0; t<T; t++)
    {
        int i,N,j,tmp,ans = 0;
        cin>>N;
        string s1,s2;
        vector<pair<string,string> > vps;
        for (i=0; i<N; i++) {
            cin>>s1>>s2;
            vps.push_back(make_pair(s1,s2));
        }
        for (i=1; i<(1<<N); i++)
        {
            j = 0;
            tmp = i;
            set<pair<string,string> > orig = {};
            set<pair<string,string> > fake = {};
            //cout<<"i="<<i<<endl;
            while (j<N) {
                if (tmp%2) {
                    fake.insert(vps[j]);
                    //cout<<vps[j].first<<':'<<vps[j].second<<endl;
                }
                else
                {
                    orig.insert(vps[j]);
                }
                tmp = tmp/2;
                j++;
            }
            set<string> first = {};
            set<string> last = {};
            for (pair<string,string> pss:orig) {
                first.insert(pss.first);
                last.insert(pss.second);
            }
            bool passes = true;
            for (pair<string,string> pss:fake) {
                if ((first.count(pss.first)==0)||(last.count(pss.second)==0)) {
                    passes = false;
                    break;
                }
            }
            if(passes)
            {
                ans = max(ans,(int)fake.size());
            }
        }
        
        cout <<"Case #"<<t+1<<": "<< ans <<endl;
    }
    return 0;
}

