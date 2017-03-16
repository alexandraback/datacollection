#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double solve(const int sum,const vector<pair<int,int> >& scores,int n);

int main(){
  int t;
  cin>>t;
  cout.setf(ios::fixed|ios::showpoint);
  for(int c=0;c<t;c++){
    int n,sum=0;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
      int score;
      cin>>score;
      v.push_back(make_pair(score,i));
      sum+=score;
    }
    cout<<"Case #"<<c+1<<':';
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
      cout<<' '<<100*solve(sum,v,i);
    cout<<'\n';
  }
}

bool acceptable(const int sum,const vector<pair<int,int> >& scores,int n,double percent);

double solve(const int sum,const vector<pair<int,int> >& scores,int n){
  double low=0,high=1;
  for(int i=0;i<50;i++){
    double guess=(low+high)/2;
    if(acceptable(sum,scores,n,guess))
      high=guess;
    else
      low=guess;
  }
  return low;
}

const double epsilon=1e-9;

bool acceptable(const int sum,const vector<pair<int,int> >& scores,int n,double percent){
  double divy=1-percent,score;
  for(int i=0;i<scores.size();i++)
    if(scores[i].second==n)
      score=scores[i].first+percent*sum;
  for(int i=0;i<scores.size();i++){
    if(scores[i].second==n)
      continue;
    if(scores[i].first>score)
      continue;
    double need=(score-scores[i].first)/sum;
    if(need+epsilon>divy)
      return true;
    divy-=need;
  }
  return false;
}
