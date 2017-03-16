#include<iostream>
#include<map>
#include<queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int nt = 1;
    while(nt <= t)
    {
        int n;
        cin >> n;
        map<int,vector<int> >Map;
        for(int i = 1;i <= n;i++)
        {
            int m;
            cin >> m;
            for(int j = 0;j < m;j++)
            {
                int k;
                cin >> k;
                Map[i].push_back(k);
            }
        }   
        int test = 0;
        cout <<"Case #" << nt <<": "; 
        for(int i = 1;i < n+1;i++)
        {
            vector<int>B(n+1,0);
            queue<int>C;
            C.push(i);
            while(!C.empty())
            {   
                int x = C.front();
                C.pop();
                if(B[x] == 1)
                {
                    cout << "Yes" << endl;
                    test = 1;
                    break;
                }
                B[x] = 1;
                for(int j = 0;j < Map[x].size();j++)
                {
                    C.push(Map[x][j]);
                }
            }
            if(test)break;
        }
        if(!test) cout << "No" << endl;
        nt += 1;
    }
    return 0;
}
