#include<iostream>
#include<string>
#include<map>
#include<array>
#include<deque>
#include<algorithm>

long long unsigned abs(std::pair<std::string, std::string> p){
  return std::abs(std::stoll(p.first)-std::stoll(p.second));
}

std::string max(std::string c){
  for(char& ch: c)
    if(ch=='?')
      ch = '9';
  return c;
}

std::string min(std::string c){
  for(char& ch: c)
    if(ch=='?')
      ch = '0';
  return c;
}

std::pair<std::string, std::string> solve(std::string c, std::string j){
  // std::cerr << c << ' ' << j << '\n';
  if(c[0]!='?' and j[0]!='?'){
    if(c.size()==1)
      return {c, j};
    std::pair<std::string, std::string> p {};
    if(c[0]==j[0])
      p = solve(c.substr(1), j.substr(1));
    if(c[0]>j[0])
      p = solve(min(c.substr(1)), max(j.substr(1)));
    if(c[0]<j[0])
      p = solve(max(c.substr(1)), min(j.substr(1)));
    return {std::string(1, c[0])+p.first, std::string(1, j[0])+p.second};
  }
  if(c[0]=='?' and j[0]!='?'){
    if(c.size()==1)
      return {j, j};
    std::pair<std::string, std::string> bp {};
    std::pair<std::string, std::string> p {};
    long long unsigned diff {};
    long long unsigned bdiff {18730472};
    if(j[0]>'0'){
      c[0] = j[0]-1;
      p = solve(c, j);
      diff = abs(p);
      bdiff = diff;
      bp = p;
    }
    c[0] = j[0];
    p = solve(c, j);
    diff = abs(p);
    if(diff<bdiff or bdiff==18730472){
      bp = p;
      bdiff = diff;
    }
    if(j[0]<'9'){
      c[0] = j[0]+1;
      p = solve(c, j);
      diff = abs(p);
      if(diff<bdiff or bdiff==18730472){
	bp = p;
	bdiff = diff;
      }
    } 
    return bp;
  }
  if(c[0]!='?' and j[0]=='?'){
    if(c.size()==1)
      return {c, c};
    std::pair<std::string, std::string> bp {};
    std::pair<std::string, std::string> p {};
    long long unsigned diff {};
    long long unsigned bdiff {18730472};
    if(c[0]>'0'){
      j[0] = c[0]-1;
      p = solve(c, j);
      diff = abs(p);
      bdiff = diff;
      bp = p;
    }
    j[0] = c[0];
    p = solve(c, j);
    diff = abs(p);
    if(diff<bdiff or bdiff==18730472){
      bp = p;
      bdiff = diff;
    }
    if(c[0]<'9'){
      j[0] = c[0]+1;
      p = solve(c, j);
      diff = abs(p);
      if(diff<bdiff or bdiff==18730472){
	bp = p;
	bdiff = diff;
      }
    } 
    return bp;
  }
  if(c[0]=='?' and j[0]=='?'){
    if(c.size()==1)
      return {"0", "0"};
    std::pair<std::string, std::string> bp {};
    std::pair<std::string, std::string> p {};
    c[0]='0';
    j[0]='0';
    p = solve(c, j);
    long long unsigned diff {abs(p)};
    long long unsigned bdiff {diff};
    bp = p;
    c[0]='0';
    j[0]='1';
    p = solve(c, j);
    diff = abs(p);
    if(diff<bdiff){
      bp = p;
      bdiff = diff;
    }
    c[0]='1';
    j[0]='0';
    p = solve(c, j);
    diff = abs(p);
    if(diff<bdiff){
      bp = p;
      bdiff = diff;
    }
    return bp;
  }
}

int main(){
  unsigned T; std::cin >> T;
    for(unsigned i {0}; i<T; ++i){
    std::string r {};
    // std::string s; std::cin >> s;
    std::string c; std::cin >> c;
    std::string j; std::cin >> j;
    // bool b {false};
    // for(char ch: s){
    //   std::cout << ch << '\n';
    //   if(ch==' '){
    // 	b = true;
    // 	continue;
    //   }
    //   if(b)
    // 	j.push_back(ch);
    //   else
    // 	c.push_back(ch);
    // }
    auto p = solve(c, j);
    r = p.first+" "+p.second;
    std::cout << "Case #" << (i+1) << ": " << r << '\n';
  }
}
