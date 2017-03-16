#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;
int cnt['Z'+10];
string arr[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
/*
void test()
{
    for(char a = 'A'; a<='Z';a++)
    {
        cout << a <<" ";
        for(int i=0;i<10;i++)
        {
            if(arr[i].find(a) != string::npos) cout << arr[i] <<" ";
        }
        cout<<endl;
    }
}
*/

void reduce(int ch, string digit, int num)
{
    while(cnt[ch] >0)
    {
        for(int i=0;i<digit.size();i++)
        {
            cnt[digit[i]]--;
        }
        answer.push_back(num);
    }
}

void solve(int testn)
{
    string target;
    char temp[2010]; answer.clear();
    gets(temp); target = string(temp);
    fill(cnt,cnt+'Z'+10,0);
    for(int i=0;i<target.size();i++) cnt[target[i]]++;
    reduce('Z', "ZERO", 0);
    reduce('X', "SIX", 6);
    reduce('W', "TWO", 2);
    reduce('U', "FOUR", 4);
    reduce('S', "SEVEN", 7);
    reduce('G', "EIGHT", 8);
    reduce('H', "THREE", 3);
    reduce('O', "ONE", 1);
    reduce('N', "NINE", 9);
    reduce('F', "FIVE", 5);
    sort(answer.begin(), answer.end());
    printf("Case #%d: ",testn);
    for(int i=0;i<answer.size();i++) printf("%d",answer[i]);
    puts("");
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d\n",&t);
    for(int i=1;i<=t;i++) solve(i);
}
