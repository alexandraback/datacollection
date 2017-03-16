#include<bits/stdc++.h>
using namespace std;
  
                  //left, right
pair<bool, char> convert[4][4] ={
  {make_pair(true, '1'), make_pair(true, 'i'), make_pair(true, 'j'), make_pair(true, 'k')},
  {make_pair(true, 'i'), make_pair(false, '1'), make_pair(true, 'k'), make_pair(false, 'j')},
  {make_pair(true, 'j'), make_pair(false, 'k'), make_pair(false, '1'), make_pair(true, 'i')},
  {make_pair(true, 'k'), make_pair(true, 'j'), make_pair(false, 'i'), make_pair(false, '1')}
};
map<char, int> ch2num ={{'1', 0}, {'i', 1}, {'j', 2}, {'k',3}};
map<int, char> num2ch ={{0, '1'}, {1, 'i'}, {2, 'j'}, {3, 'k'}};



pair<bool, char> mul(pair<bool, char> left, pair<bool, char> right){
  bool ret = left.first&right.first;
  pair<bool, char> ans = convert[ch2num[left.second]][ch2num[right.second]];
  ans.first = (ans.first == ret);
  return ans;
}

pair<bool, char> gen(int lpos, int rpos, string st){
  pair<bool, char> now = make_pair(true, st[lpos]);
  for(int i = lpos+1; i <=rpos; i++){
    now = mul(now, make_pair(true, st[i]));
  }
  return now;
}

void solve(int CASE){
  pair<bool, char> tmp1;
  long L, X;
  cin >> L >> X;
  string tmpst, st="";
  cin >> tmpst;
  for(long i = 0; i < X; i++){
    st += tmpst;
  }
  bool flag1=false;
  bool flag2=false;
  pair<bool, char> now = make_pair(true, st[0]);
  if(!flag1 && now.second == 'i'){
    flag1 = true;
  }
  for(int i = 1; i < st.size(); i++){
    now = mul(now, make_pair(true, st[i]));
    if(!flag1 && now.second == 'i'){
      flag1 = true;
    }
    if(flag1 &&  !flag2 && now.second == 'k'){
      flag2 = true;
    }
  }
  if(flag1 && flag2 &&now.second == '1' && !now.first){
    cout << "Case #" << CASE << ": YES" << endl;
    return;

  }else{
    cout << "Case #" << CASE << ": NO" << endl;
    return;


  }
}

int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    solve(i+1);
  }
}

