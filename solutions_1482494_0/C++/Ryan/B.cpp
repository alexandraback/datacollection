#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int bad=-1;
int solve(const vector<pair<int,int> >& tower);

int main(){
  int t;
  cin>>t;
  for(int z=0;z<t;z++){
    int towers;
    cin>>towers;
    vector<pair<int,int> > tower(towers);
    for(int i=0;i<tower.size();i++)
      cin>>tower[i].first>>tower[i].second;
    const int answer=solve(tower);
    if(answer==bad)
      cout<<"Case #"<<z+1<<": Too Bad\n";
    else
      cout<<"Case #"<<z+1<<": "<<answer<<'\n';
  }
}

void play(bool big,vector<bool>& bigs_done,vector<bool>& small_done,int tower,int& levels,int& stars);

int solve(const vector<pair<int,int> >& tower){
  vector<pair<int,int> > bigs;
  vector<vector<int> > smalls(tower.size(),vector<int>(3));
  vector<bool> big_done(tower.size()),small_done=big_done;
  for(int i=0;i<tower.size();i++){
    smalls[i][0]=tower[i].first;
    smalls[i][1]=-tower[i].second;
    smalls[i][2]=i;
    bigs.push_back(make_pair(tower[i].second,i));
  }
  sort(bigs.begin(),bigs.end());
  sort(smalls.begin(),smalls.end());

  int stars=0,levels=0,sp=0,bp=0;
  while(true){
    //cout<<" start loop with "<<stars<<'\n';
    while(bp<bigs.size() && stars>=bigs[bp].first)
      play(true,big_done,small_done,bigs[bp++].second,levels,stars);
    //cout<<" finished bigs with "<<stars<<'\n';
    while(sp<small_done.size() && small_done[smalls[sp][2]])
      sp++;
    if(stars==2*tower.size())
      return levels;
    if(sp<small_done.size() && stars>=smalls[sp][0])
      play(false,big_done,small_done,smalls[sp++][2],levels,stars);
    else
      return bad;
  }
}

void play(bool big,vector<bool>& bigs_done,vector<bool>& small_done,int tower,int& levels,int& stars){
  //cout<<"  play: "<<(big?"big":"small")<<" of "<<tower<<'\n';
  levels++;
  stars++;
  if(big){
    bigs_done[tower]=true;
    if(small_done[tower]==false)
      stars++;
  }
  small_done[tower]=true;
}
