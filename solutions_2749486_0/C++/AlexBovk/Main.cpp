#include <fstream>
#include <queue>
#include <stack>
#include <vector>

void SolveTask(std::ifstream& input,std::ofstream& output) {
  int x,y;
  input>>x>>y;x+=500;y+=500;
  
  std::vector<std::vector<char> > route(1000);
  std::queue<std::pair<int,std::pair<int,int> > > queue;
  
  for (size_t index=0;index<route.size();++index) route[index].resize(1000,0);
  
  route[500][500]='I';
  queue.push(std::make_pair(0,std::make_pair(500,500)));
  
  int step=0;
  
  while (!queue.empty()) {
    std::pair<int,std::pair<int,int> > position=queue.front();
    queue.pop();
    
    if (position.first<=500) {    
      if ((position.second.first==x)&&(position.second.second==y)) {
        step=position.first;
        break;
      }
      
      if ((position.second.first-position.first-1>=0)&&(route[position.second.first-position.first-1][position.second.second]==0)) {
        queue.push(std::make_pair(position.first+1,std::make_pair(position.second.first-position.first-1,position.second.second)));
        route[position.second.first-position.first-1][position.second.second]='W';
      }
      if ((position.second.first+position.first+1<1000)&&(route[position.second.first+position.first+1][position.second.second]==0)) {
        queue.push(std::make_pair(position.first+1,std::make_pair(position.second.first+position.first+1,position.second.second)));
        route[position.second.first+position.first+1][position.second.second]='E';
      }
      if ((position.second.second-position.first-1>=0)&&(route[position.second.first][position.second.second-position.first-1]==0)) {
        queue.push(std::make_pair(position.first+1,std::make_pair(position.second.first,position.second.second-position.first-1)));
        route[position.second.first][position.second.second-position.first-1]='S';
      }
      if ((position.second.second+position.first+1<1000)&&(route[position.second.first][position.second.second+position.first+1]==0)) {
        queue.push(std::make_pair(position.first+1,std::make_pair(position.second.first,position.second.second+position.first+1)));
        route[position.second.first][position.second.second+position.first+1]='N';
      }
    }
  }
  
  std::stack<char> result;
  
  while (route[x][y]!='I') {
    char c=route[x][y];c;
    result.push(route[x][y]);
    
    switch (route[x][y]) {
      case 'W': {
        x+=step;
        break;
      }
      case 'E': {
        x-=step;
        break;
      }
      case 'S': {
        y+=step;
        break;
      }
      case 'N': {
        y-=step;
        break;
      }
    }
    --step;
  }
              
  while (!result.empty()) {
    output<<result.top();
    result.pop();
  }
}

void main() {
  std::ifstream input("Input.Txt");
  std::ofstream output("Output.Txt");
  
  int numberOfCases;  
  input>>numberOfCases;
  
  for (int caseNumber=1;caseNumber<=numberOfCases;++caseNumber) {
    output<<"Case #"<<caseNumber<<": ";
    SolveTask(input,output);
    output<<std::endl;
  }
}