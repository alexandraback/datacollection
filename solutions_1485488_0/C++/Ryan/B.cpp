#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dijkstra(int height,const vector<vector<int> >& floor,const vector<vector<int> >& ceiling);

int main(){
  int t;
  cin>>t;
  cout.setf(ios::fixed|ios::showpoint);
  cout.precision(1);
  for(int z=0;z<t;z++){
    int height,r,c;
    cin>>height>>r>>c;
    vector<vector<int> > floor(r,vector<int>(c)),ceiling=floor;
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        cin>>ceiling[i][j];
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        cin>>floor[i][j];
    cout<<"Case #"<<z+1<<": "<<dijkstra(height,floor,ceiling)/10.<<'\n';
  }
}

const int infinity=999999999,dirs=4;
const int dx[dirs]={0,0,1,-1};
const int dy[dirs]={1,-1,0,0};

bool good(const vector<vector<int> >& v,int x,int y);
bool is_50_below(int a,int b);
int get_next_time(int time,int height,int adjacent_ceiling,int current_floor);

int dijkstra(int height,const vector<vector<int> >& floor,const vector<vector<int> >& ceiling){
  vector<vector<int> > time(floor.size(),vector<int>(floor[0].size(),infinity));
  time[0][0]=0;
  set<pair<int,pair<int,int> > > q;
  q.insert(make_pair(0,make_pair(0,0)));
  while(q.size()){
    pair<int,int> current=q.begin()->second;
    const int t=q.begin()->first,x=current.first,y=current.second,current_height=height-t;
    q.erase(q.begin());
    //cout<<x<<','<<y<<" at "<<t<<" water is "<<height<<'\n';
    if(t>time[x][y])
      continue;

    const int current_floor=floor[x][y],current_ceiling=ceiling[x][y];
    for(int d=0;d<dirs;d++){
      const int nx=x+dx[d],ny=y+dy[d];
      if(!good(floor,nx,ny))
        continue;
      const int adjacent_floor=floor[nx][ny],adjacent_ceiling=ceiling[nx][ny];
      //cout<<" current floor="<<current_floor<<" adjacent_ceiling="<<adjacent_ceiling<<'\n';
      if(!is_50_below(current_floor,adjacent_ceiling))
        continue;
      if(!is_50_below(adjacent_floor,adjacent_ceiling))
        continue;
      if(!is_50_below(adjacent_floor,current_ceiling))
        continue;
      //cout<<" looking to go to "<<nx<<','<<ny<<'\n';
      int nt=get_next_time(t,current_height,adjacent_ceiling,current_floor);
      if(nt<time[nx][ny]){
        time[nx][ny]=nt;
        q.insert(make_pair(nt,make_pair(nx,ny)));
      }
    }
  }
  return time.back().back();
}

bool is_50_below(int a,int b){
  return a+50<=b;
}

bool is_20_above(int a,int b){
  return a-20>=b;
}

bool good(const vector<vector<int> >& v,int x,int y){
  return x>=0 & y>=0 && x<v.size() && y<v[x].size();
}

int get_next_time(int time,int height,int adjacent_ceiling,int current_floor){
  if(!is_50_below(height,adjacent_ceiling)){
    int target_height=adjacent_ceiling-50;
    int wait=height-target_height;
    //cout<<"  must wait for "<<wait<<"!\n";
    time+=wait;
    height=target_height;
  }
  if(time==0)
    return 0;
  if(is_20_above(height,current_floor))
    return time+10;
  return time+100;
}
