#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int solve();

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    cout<<"Case #"<<i+1<<": "<<solve()<<'\n';
  }
}

pair<int,int> original_location;

vector<string> read_map(int rows,int columns);
vector<string> build_grid(const vector<string> map,int length);
vector<string> horizontal_reflect(vector<string> map);
vector<string> vertical_reflect(vector<string> map);
void copy_map(vector<string>& grid,int x,int y,const vector<string>& map);
bool valid_distance(int x,int y,int d);
int gcd(int a,int b);

int solve(){
  int rows,columns,fog_distance;
  cin>>rows>>columns>>fog_distance;
  vector<string> map=read_map(rows,columns);
  vector<string> grid=build_grid(map,fog_distance);
  assert(grid[original_location.first][original_location.second]=='X');

  int ret=0;
  for(int i=0;i<grid.size();i++)
    for(int j=0;j<grid[i].size();j++){
      const int dx=i-original_location.first,dy=j-original_location.second;
      if(grid[i][j]=='X' && valid_distance(dx,dy,fog_distance)){
        int g=abs(gcd(dx,dy));
        bool good=true;
        for(int i=1;i<g;i++)
          if(grid[original_location.first+(dx/g)*i][original_location.second+(dy/g)*i]=='X')
            good=false;
        ret+=good;
      }
    }
  return ret;
}

bool valid_distance(int x,int y,int d){
  if(x==0 && y==0)
    return false;
  return x*x+y*y<=d*d;
}

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

vector<string> build_grid(const vector<string> map,int length){
  if(length%2==1) length++;
  const int side=2*length+1;
  vector<string> maps[2][2];
  maps[0][0]=map;
  maps[1][0]=horizontal_reflect(map);
  maps[0][1]=vertical_reflect(map);
  maps[1][1]=vertical_reflect(maps[1][0]);
  for(int i=0;i<map.size();i++)
    for(int j=0;j<map[i].size();j++)
      if(map[i][j]=='X')
        original_location=make_pair(length*map.size()+i,length*map[0].size()+j);
  vector<string> grid(map.size()*side,string(map[0].size()*side,'~'));
  for(int i=0;i<side;i++)
    for(int j=0;j<side;j++)
      copy_map(grid,map.size()*i,map[0].size()*j,maps[j%2][i%2]);
  //for(int i=0;i<grid.size();i++) cout<<grid[i]<<'\n';
  return grid;
}

void copy_map(vector<string>& grid,int x,int y,const vector<string>& map){
  for(int i=0;i<map.size();i++)
    for(int j=0;j<map[i].size();j++)
      grid[x+i][y+j]=map[i][j];
}

vector<string> read_map(int rows,int columns){
  vector<string> map(rows);
  for(int i=0;i<rows;i++)
    cin>>map[i];
  vector<string> ret(rows-2);
  for(int i=0;i<ret.size();i++)
    ret[i]=map[i+1].substr(1,columns-2);
  return ret;
}

vector<string> horizontal_reflect(vector<string> map){
  for(int i=0;i<map.size();i++)
    reverse(map[i].begin(),map[i].end());
  return map;
}

vector<string> vertical_reflect(vector<string> map){
  reverse(map.begin(),map.end());
  return map;
}
