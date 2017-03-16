#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

string print(int a, int len)
{
  string ans;

  while(len>0)
  {
    ans.push_back(a%10 + '0');
    a/=10;
    len--;
  }
  string revans;
  int i;
  for(i=ans.length()-1;i>=0;i--)
    revans.push_back(ans[i]);
  return revans;

}
pair<int,int> get(vector<int> r, string com)
{
  int pos = 0;
  int i;
  for(i=0;i<com.length();i++)
  {
    if(com[i] == '?')
    {
      com[i] = r[pos] + '0';
      pos++;

    }
  }
  //cout<<com<<endl;
  int len = com.length()/2;
  int num1 = 0;
  for(i=0;i<len;i++)
    num1= num1*10 + com[i] - '0';

  int num2 = 0;
  for(i=len;i<com.length();i++)
    num2 = num2*10 + com[i] - '0';

  return make_pair(num1, num2);

}

bool better(pair<int,int> a, pair<int, int> b)
{
  if(b.first == -1 && b.second == -1)
    return true;
  int dif1 = abs(a.first-a.second);
  int dif2 = abs(b.first - b.second);

  if(dif1<dif2)
  return true;
  if(dif1 > dif2)
  return false;

  if(a.first< b.first)
  return true;
  if(a.first> b.first)
  return false;


  if(a.second < b.second)
  return true;

  return false;
}

int main()
{
  int t;
  cin>>t;
  int i;
  int count = 1;
  while(t--)
  {
    string c,j;
    cin>>c>>j;

    pair<int, int> ans = make_pair(-1, -1);
    int len = c.length();
    string com = c.append(j);
    int num_q = 0;
    for(i=0;i<com.length();i++)
    {
      if(com[i] == '?')
        num_q++;
    }
    //cout<<com<<endl;
    vector<int> r;
    for(i=0;i<num_q;i++)
    r.push_back(0);

    int cnt = 0;
    while(cnt<pow(10,num_q))
    {
      pair<int, int> temp = get(r, com);
      //cout<<temp.first<<" "<<temp.second<<endl;
      if(better(temp, ans))
        ans = temp;

      for(i=r.size()-1;i>=0;i--)
      {
        if(r[i] == 9)
          r[i] = 0;
        else
        {
          r[i]++;
          break;
        }
      }

      cnt++;
    }

    cout<<"Case #"<<count<<": "<<print(ans.first, len)<<" "<<print(ans.second,len)<<endl;

    count++;
  }

}
