#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

long long reverse(long long a)
{
    long long result = 0;
    while(a)
    {
        result *= 10;
        result += a%10;
        a /= 10;
    }
    return result;
}

long long dp[1000005];
struct node {
    long long num;
    long long step;
    node(long long a, long long b)
    {
        num = a;
        step = b;
    }
};
long long BFS(long long target)
{
    queue<node> q;
    q.push(node(1, 1));
    while(!q.empty())
    {
        node temp = q.front();
        q.pop();
        if(temp.num == target)
            return temp.step;
        if(dp[temp.num] != 0) continue;
        dp[temp.num] = temp.step;
        long long t = reverse(temp.num);
        if(t != temp.num && t != temp.num+1)
        {
            q.push(node(t, temp.step+1));
        }
        q.push(node(temp.num+1, temp.step+1));
    }
    return target;
}
int main() {
    int T;
    cin>>T;
    int case_number = 1;
    while(T--)
    {
        long long target;
        memset(dp, 0, sizeof(dp));
        cin >> target;
        
        cout<<"Case #"<<case_number++<<": "<<BFS(target)<<endl;
    }
}
