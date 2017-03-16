#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> ii;
void Solve(int);
int main()
{
    freopen("C:\\Users\\dell\\Downloads\\inputa.txt","r",stdin);
    freopen("C:\\Users\\dell\\Downloads\\outputa.txt","w",stdout);
    int tc,t;
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++) Solve(t);
    return 0;
}
void Solve(int TestCase)
{
    int ans[10] = {0};
    int order[] = {0,2,4,6,8,1,3,7,5,9};
    char imp[20] = {'Z','W','U','X','G','O','T','S','V','I',0};
    string rep[20] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    char inp[3000];
    scanf("%s",inp+1);
    int cnt[26] = {0};
    for(int i = 1 ; inp[i] ; i++)
    {
        cnt[inp[i] - 'A']++;
    }
    for(int i = 0 ; i<10 ; i++)
    {
        int id = imp[i] - 'A';
        ans[order[i]] = cnt[id];
        int sz = rep[order[i]].size();
        for(int j = 0 ; j<sz ; j++)
        {
            int ch = rep[order[i]][j] - 'A';
            cnt[ch] -= ans[order[i]];
        }
    }
    printf("Case #%d: ",TestCase);
    for(int i = 0 ; i<10 ; i++)
    {
        for(int j = 1 ; j<=ans[i] ; j++)
        {
            printf("%d",i);
        }
    }
    printf("\n");
}
