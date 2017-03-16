#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

int main(){
  int t;std::cin >> t;
  for(int i {0}; i<t; ++i){
    int n; std::cin >> n;
    std::vector<int> bff {};
    for(int j {0}; j<n; ++j){
      int pal; std::cin >> pal;
      bff.push_back(pal-1);
    }
    std::vector<bool> in2loop(n, false);
    int nbin2loop {0};
    for(int j {0}; j<n; ++j){
      if(bff[bff[j]]==j){
	in2loop[j] = true;
	++nbin2loop;
      }
    }
    int r {nbin2loop};
    int maxfree {0};
    
    std::map<int, int> longest {};
    std::map<int, bool> ok {};
    std::map<int, bool> okk {};
    for(int j {0}; j<n; ++j){
      std::vector<bool> in(n, false);
      std::vector<int> order {j};
      int cur {j};
      int nb {1};
      in[cur] = true;
      while(!in[bff[cur]]){
	cur = bff[cur];
	++nb;
	in[cur] = true;
	order.push_back(cur);
      }
      if(order[0]==bff[order.back()] or in2loop[order.back()])
	r = std::max(r, nb);
      if(in2loop[order.back()]){
	if(nb>longest[order.back()]){
	  okk[order.back()] = true;
	  okk[bff[order.back()]] = false;
	}
	if(nb==longest[order.back()]){
	  okk[order.back()] = true;
	}

	longest[order.back()] = longest[bff[order.back()]] = std::max(longest[order.back()], nb);
      } 
      // else(!in2loop[order.back()])
      // 	maxfree = std::max(maxfree, nb);
	for(int k {0}; k<n; ++k){
	  if(!in[k] and bff[k]==order.back())
	    ok[order.back()] = true;
	}
	
    }    
    int sum {0};
    for(int j {0}; j<n; ++j){
      if(bff[bff[j]]==j){
	bff[j] = j;
	sum += longest[j];
      }
    }
    bool p {false};
    for(int j {0}; j<n; ++j)
      if(ok[j] and okk[j])
	p = true;
    r = std::max(r, sum+p);
    std::cout << "Case #" << i+1 << ": " << r << '\n';
    
    // std::cout << sum << ' ' << maxfree << '\n';
  }
}
