#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int maze[26][26];
bool ans = true;
int visited[26];
int num[26];
int head[26];
int tail[26];
int ingree[26];
long long mod = 1000000007;
long long fg(long long k)
{
    long long res= 1;
    for(long long i = 1;i <=k;++i)
        res = (res * i)%mod;
    return res;
}
void dfs(int k)
{
    for(int i=0;i<26;i++)
        if(i != k && maze[k][i])
        {
         if(visited[i]==2)
         {
             //cout<<"----"<<char(k+'a')<<","<<char(i+'a')<<endl;
             ans = false;
         }
         else {
            visited[i]=2;
            dfs(i);
         }
        }
}

int main()
{
    int T;
    cin>> T;
    for(int cas=1;cas <=T;++cas)
    {
        int N;
        cin>>N;
        vector<string> cars;

        memset(maze,0,sizeof(maze));
        for(int i=0;i<N;++i)
        {
            string str;
            cin>> str;
            //cout<<str<<endl;
            cars.push_back(str);
        }
        memset(visited,0,sizeof(visited));
        memset(head,0,sizeof(head));
        memset(tail,0,sizeof(tail));
        ans =true;
        memset(num,0,sizeof(num));
        memset(ingree, 0,sizeof(ingree));
        for(int i=0;i<N;++i)
        {
            char last = cars[i][0];
            visited[last -'a'] = 1;
            bool change= false;
            for(int j =1;j<cars[i].length();++j)
            {
                if(cars[i][j] != last)
                {
                    change =true;
                    if(head[last-'a']== 1 || tail[cars[i][j]-'a']==1)
                        ans = false;
                    head[last-'a'] =1;
                    tail[cars[i][j]-'a']=1;
                    maze[last-'a'][cars[i][j]-'a']=1;
                    last = cars[i][j];
                    ingree[cars[i][j]-'a']++;
                }
                visited[cars[i][j]-'a']=1;
            }
            if(change == false)
            {
                num[last-'a']++;
            }
        }
        //cout<<"-------"<<ans<<endl;
        int cnt =0;
        for(int i=0;i<26;i++)
            if(visited[i] == 1 && ingree[i] ==0)
        {
            visited[i] =2;
            dfs(i);
            cnt++;
        }

        long long res;
        if(ans == false)
        {
            res = 0;
        }
        else{
            res = fg(cnt);
            for(int i=0;i<26;i++)
            {
                res = (res * fg(num[i]))%mod;
            }
        }
        cout<< "Case #"<<cas<<": "<<res<<endl;

    }
    return 0;
}

