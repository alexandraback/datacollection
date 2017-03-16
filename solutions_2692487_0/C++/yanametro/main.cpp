#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("A-small-attempt1.in");
ofstream cout("output.txt");


int main()
{
    int T;
    cin >> T;
    for (int j=0; j<T; ++j)
    {
        int A;
        cin >> A;
        int N;
        cin >> N;
        vector <int> v;
        v.clear();
        for (int i=0; i<N; ++i)
        {
            int d;
            cin >> d;
            v.push_back(d);
        }
        sort(v.begin(),v.end());

        int ans=100500;
        int num=0;
        while (v.size()>0 && A>v[0])
        {
            A+=v[0];
            v.erase(v.begin(),v.begin()+1);
        }

        int cur=0;


        if (A==1)
            ans=v.size();
        else
        while (v.size()>0)
        {
            ans=min(ans,cur+(int)v.size());
            A+=A-1;
            cur++;
            while (v.size()>0 &&  A>v[0])
            {
                A+=v[0];
                v.erase(v.begin(),v.begin()+1);
            }
            ans=min(ans,cur+(int)v.size());
        }

        if (ans==100500)
        cout << "Case #" << j+1 <<": "<<0 << endl;
        else
        cout << "Case #" << j+1 <<": "<<ans << endl;





    }
    return 0;
}
