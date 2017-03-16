#include <iostream>
#include <vector>

using namespace std;

double solve();

int main(){
  int t;
  cin>>t;
  cout.setf(ios::fixed|ios::showpoint);
  cout.precision(6);
  for(int i=0;i<t;i++)
    cout<<"Case #"<<i+1<<": "<<solve()<<'\n';
}

double compute(const int back,const vector<double>& typed_prob,const int total);
double right_prob;

double solve(){
  int typed,total;
  cin>>typed>>total;
  vector<double> typed_prob(typed);
  for(int i=0;i<typed_prob.size();i++)
    cin>>typed_prob[i];
  double best=2+total;
  right_prob=1;
  for(int back=typed;back>=0;back--)
    best=min(best,compute(back,typed_prob,total));
  return best;
}

double compute(const int back,const vector<double>& typed_prob,const int total){
  const int keep=typed_prob.size()-back;
  const int right_cost=back+(total-keep)+1;
  const int wrong_cost=right_cost+total+1;
  if(keep>0)
    right_prob*=typed_prob[keep-1];
  const double wrong_prob=1-right_prob;
  return right_cost*right_prob+wrong_cost*wrong_prob;
}
