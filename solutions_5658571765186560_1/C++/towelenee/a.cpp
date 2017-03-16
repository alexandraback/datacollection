#include<cassert>
#include<vector>
#include<set>
#include<iostream>
const int maxX = 4;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
typedef std::set<std::pair<int, int> >  maze;
std::vector<std::set<maze> > generateSets()
{
  std::vector<std::set<std::set<std::pair<int, int> > > > answer;
  answer.push_back({{std::make_pair(0,0), std::make_pair(0,1)}});
  //std::cerr << answer[].size() << std::endl;;
  
  answer.resize(maxX + 1);
  for (int i = 0; i < maxX; ++i)
  {
    for(const auto& maze: answer[i])
    {
      assert(maze.size() == i + 2);
      for (int j = 0; j < 4; ++j)
      {
	for (auto point: maze)
	{
	  auto pair = std::make_pair(point.first + dx[j], point.second + dy[j]);
	  if(!maze.count(pair))
	  {
            auto copy = maze;
	    copy.insert(pair);
	    answer[i + 1].insert(copy);
	  }
	}
      }
    }
  }
  return answer;  
}

void outputMaze(const maze& maz)
{
  std::vector<std::string> out(15, std::string(15, '.'));
  for(auto& point: maz)
  {
    out[point.first + 7][point.second + 7] = 'X';
  }
  for(std::string& str: out)
    std::cout << str << std::endl;
}

bool checkContain(int x, int n)
{
  return x >= 0 && x < n;
}

int dfs(int x, int y, std::vector<std::vector<bool> >& map)
{
  if (!checkContain(x, map.size()) || !checkContain(y, map[0].size()) || map[x][y])
    return 0;
  map[x][y] = true;
  int sum = 1;
  for (int i = 0; i < 4; ++i)
    sum += dfs(x + dx[i], y + dy[i], map);
  return sum;
}

bool tryToHandle(const maze& maz, int r, int c)
{
  int numberOfPoints = maz.size();
  for(int shiftX = -numberOfPoints; shiftX <= numberOfPoints; shiftX++)
  {
    for(int shiftY = -numberOfPoints; shiftY <= numberOfPoints; shiftY++)
    {
      std::vector<std::vector<bool> > map(r, std::vector<bool>(c, false));
      bool flag = true;
      for (auto pair: maz)
      {
	int x = pair.first + shiftX;
	int y = pair.second + shiftY;
	if (checkContain(x, r) && checkContain(y, c))
	  map[x][y] = true;
	else
	{
	  flag = false;
	  break;
	}
      }
      if (!flag)
      {
	continue;
      }
      for (int x = 0; x < r; ++x)
      {
	for (int y = 0; y < c; ++y)
	{
 	  if ((dfs(x, y, map) % numberOfPoints) != 0)
	  {
	    flag = false;
	  }
	}
      }
      if (flag)
      {
	return true;
      }
    }
  }
  return false;
}
int main()
{
  auto allMazes = generateSets();
  int testNo;
  std::cin >> testNo;
  for (int testId = 1; testId <= testNo; ++testId)
  {
    std::cout << "Case #" << testId << ": ";
    int x, r, c;
    std::cin >> x >> r >> c;
    bool canHandle = false;
    if( x == 1)
    {
      std:: cout << "GABRIEL" << std::endl;
      continue;
    }
    if ( x <= 6 && ((r * c) % x == 0))
    {	  
      canHandle = true;
      std::cerr << x << " " << allMazes[x - 2].size() <<  std::endl;
      for(const maze& maz: allMazes[x - 2])
      {
	if(!tryToHandle(maz, r, c) && !tryToHandle(maz, c, r))
	{
	  canHandle = false;
 	  outputMaze(maz);
	  break;
	}
      }
				  
    }
    else
    {
      canHandle = false;
    }
    std::cout << (canHandle ? "GABRIEL" : "RICHARD") << std::endl;
  }
}
