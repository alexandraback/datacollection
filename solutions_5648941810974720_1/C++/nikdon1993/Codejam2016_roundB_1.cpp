#include<bits/stdc++.h>
using namespace std;
string aux[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void check(char x, int num, string &str, vector<int>& visited, vector<int>& ans)
{
    vector<int>vis = visited;
    int cnt = 0;
    for(int i=0; i<aux[num].size(); i++)
    {
        for(int j = 0; j<str.size() ; j++)
        {

            if(str[j] == aux[num][i] && visited[j]==0)
            {
                vis[j]=1;
                cnt++;break;
            }
        }
    }
    if(cnt == aux[num].size())
    {
        visited = vis;
        ans.push_back(num);
        check(x, num, str, visited, ans);
    }

}
int main()
{

    freopen("Codejam2016_roundB_1_input.txt", "r", stdin);
    freopen("Codejam2016_roundB_1_output.txt", "w", stdout);


    int t, tc;

    cin>>t;

    for(int tc=1; tc<=t ;tc++)
    {

        //long long ans=0, n;
        string str;
        cin>>str;
        vector<int>visited(str.size(), 0);



        vector<int>ans;
        int flag=1;
        check('Z', 0, str, visited, ans);
        check('G', 8, str, visited, ans);
        check('W', 2, str, visited, ans);
        check('U', 4, str, visited, ans);
        check('X', 6, str, visited, ans);
        check('H', 3, str, visited, ans);
        check('S', 7, str, visited, ans);
        check('F', 5, str, visited, ans);
        check('O', 1, str, visited, ans);
        check('N', 9, str, visited, ans);
        sort(ans.begin(), ans.end());

        cout<<"Case #"<<tc<<": ";
        for(int i=0;i<ans.size();i++)cout<<ans[i];
        cout<<endl;

    }


}
