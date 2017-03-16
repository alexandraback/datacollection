#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int cnt[1080];
void solve(){
  string str;
  int ans[] = {0,0,0,0,0,0,0,0,0,0,0,0};
  fill(cnt, cnt + 300, 0);
  cin >> str;
  int p = str.size();
  for(int i = 0;i < str.size();i++){
    cnt[str[i]]++;
  }
  while(p){
    
    if(cnt['Z'] > 0 && cnt['E'] > 0 && cnt['R'] > 0 && cnt['O'] > 0 ){
      ans[0]++;
      cnt['Z']--;
      cnt['E']--;
      cnt['R']--;
      cnt['O']--;
      p -= 4;
      continue;
    }


    
    if(cnt['S'] > 0 && cnt['I'] > 0 && cnt['X'] > 0){
      ans[6]++;
      cnt['S']--;
      cnt['I']--;
      cnt['X']--;
      p -= 3;
      continue;
    }
    
    if(cnt['S'] > 0 && cnt['E'] > 1 && cnt['V'] > 0 && cnt['N'] > 0){
      ans[7]++;
      cnt['S']--;
      cnt['E']--;
      cnt['V']--;
      cnt['E']--;
      cnt['N']--;
      p -= 5;
      continue;
    }
    
    if(cnt['F'] > 0 && cnt['I'] > 0 && cnt['V'] > 0 && cnt['E'] > 0){
      ans[5]++;
      cnt['F']--;
      cnt['I']--;
      cnt['V']--;
      cnt['E']--;
      p -= 4;
      continue;
    }
    
    if(cnt['F'] > 0 && cnt['O'] > 0 && cnt['U'] > 0 && cnt['R'] > 0){
      ans[4]++;
      cnt['F']--;
      cnt['O']--;
      cnt['U']--;
      cnt['R']--;
      p -= 4;
      continue;
    }

    if(cnt['T'] > 0 && cnt['H'] > 0 && cnt['R'] > 0 && cnt['E'] > 1){
      ans[3]++;
      cnt['T']--;
      cnt['H']--;
      cnt['R']--;
      cnt['E']--;
      cnt['E']--;
      p -= 5;
      continue;
    }

    
    if(cnt['T'] > 0 && cnt['W'] > 0 && cnt['O'] > 0 ){
      ans[2]++;
      cnt['T']--;
      cnt['W']--;
      cnt['O']--;
      p -= 3;
      continue;
    }

        
    if(cnt['O'] > 0 && cnt['N'] > 0 && cnt['E'] > 0 ){
      ans[1]++;
      cnt['O']--;
      cnt['N']--;
      cnt['E']--;
      p -= 3;
      continue;
    }


    
    if(cnt['E'] > 0 && cnt['I'] > 0 && cnt['G'] > 0 && cnt['H'] > 0 && cnt['T'] > 0){
      ans[8]++;
      cnt['E']--;
      cnt['I']--;
      cnt['G']--;
      cnt['H']--;
      cnt['T']--;
      p -= 5;
      continue;
    }

    

    
    if(cnt['N'] > 1 && cnt['I'] > 0 && cnt['E'] > 0){
      ans[9]++;
      cnt['N']--;
      cnt['I']--;
      cnt['N']--;
      cnt['E']--;
      p -= 4;
      continue;
    }
  }
  for(int i = 0;i < 10;i++){
    while(ans[i]--)cout << i;
  }
  cout << endl;
  return;
}



int main(){
  int t;
  cin >> t;
  for(int i = 1;i <= t;i++){
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
