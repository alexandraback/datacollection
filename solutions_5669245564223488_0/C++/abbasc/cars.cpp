#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#define MOD 1000000007

typedef long long LL;
using namespace std;

LL fac[101];
int visited[27];
int repeat[26];
map< char, vector<string> > graph;


int invalid = 0;

LL traversal(char a)
{

    int aval = a - 'a';
    visited[aval] = 1;
    if(graph[a].size() == 0)
    {
        return fac[repeat[aval]];
    }
    if(graph[a].size()> 1)
    {
        invalid = 1;
         //cout<<"invalid2"<<endl;
        return 0;
    }
    else
    {
        string str = graph[a][0];
        for(int i = 1;i < str.length(); i++)
        {
            if(visited[str[i]] && str[i] != str[i-1])
            {
                invalid = 1;
                //cout<<"invalid3"<<endl;
                return 0;
            }

            visited[str[i] - 'a'] = 1;
        }
        return (fac[repeat[aval]]*traversal(str[str.length()-1]))%MOD;
    }

}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    fac[0] = fac[1] = 1;
    for(int i = 2; i < 101; i++)
    {
        fac[i] = (fac[i-1]*i)%MOD;
    }
    for(int x = 1;x <= t; x++)
    {
        int n;
        cin>>n;
        int start[26] = {0};
        int present[26] = {0};
        LL ans = 1;
        for(int i = 0; i < 26; i++)
            repeat[i] = 0;

        string tmp;
        invalid = 0;

        for(int i = 0; i < n; i++)
        {
            cin>>tmp;
            int first = tmp[0] - 'a';
            int last = tmp[tmp.length() - 1] - 'a';
            present[first] = 1;

            if(first != last)
            {
                start[last] = 1;
                graph[tmp[0]].push_back(tmp);
            }
            else
            {
                for(int j = 1; j < tmp.length(); j++)
                {
                    if(tmp[j] != tmp[0])
                    {
                        invalid = 1;
                        //cout<<"invalid1"<<endl;
                        break;
                    }
                }
                if(invalid == 0)
                    repeat[first]++;
            }

        }
        int sets = 0;
        if(invalid == 0)
        {
            for(int i = 0; i < 26; i++)
                visited[i] = 0;

            for(int i = 0; i < 26; i++)
            {
                if(present[i] == 1 && start[i] == 0)
                {
                    if(visited[i])
                    {
                        invalid = 1;
                        break;
                    }
                    ans *= traversal('a' + i);
                    ans %= MOD;
                    sets++;
                }


                if(invalid == 1)
                    break;
            }

            ans *= fac[sets];
            ans %= MOD;


        }
        if(invalid == 1 || sets == 0)
            ans = 0;
        printf("Case #%d: %lld\n",x,ans);
        graph.clear();

    }
    return 0;
}
