#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <map>
#include <set>

using namespace std;
using namespace boost;

string solve(int,int,int,vector<int>);

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    int r, n, m, k;
    cin >> r >> n >> m >> k;
    cout << "Case #" << i+1 << ": " << endl;
    for(int j = 0; j < r; j++) {
      vector<int> prods(k);
      for(int x = 0; x < k; x++) cin >> prods[x];
      string res = solve(n,m,k,prods);
      cout << res << endl;
    }
  }
}

map<vector<int>, set<int> > possible_set;

void create_possible_set(vector<vector<int> > cand) {
  for(int i = 0; i < cand.size(); i++) {
    vector<int> cards = cand[i];
    set<int> s;
    s.insert(1); // no cards;
    for(int j = 0; j < cards.size(); j++) s.insert(cards[j]); // one card
    for(int j = 0; j < cards.size(); j++){ // two cards
      for(int k = 0; k < cards.size(); k++) {
	s.insert(cards[j] * cards[k]);
      }
    }
    s.insert(cards[0]*cards[1]*cards[2]);
    possible_set[cards] = s;
  }
}


bool is_possible(vector<int> card, int prod) {
  set<int> possible_prod = possible_set[card];
  if(possible_prod.find(prod) == possible_prod.end()) return false;
  else return true;
}

vector<vector<int> > prune(vector<vector<int> > cand, int prod) {
  vector<vector<int> > newcand;
  for(int i = 0; i < cand.size(); i++) {
    if(is_possible(cand[i], prod)) {
      newcand.push_back(cand[i]);
    }
  }
  return newcand;
}

string solve(int n, int m, int k, vector<int> prods){
  vector<int> card(m-1);
  for(int i = 0; i < m - 1; i++) card[i] = i+2;
  vector<vector<int> > cand;
  //n == 3
  for(int i = 0; i < card.size(); i++) {
    for(int j = 0; j < card.size(); j++) {
      for(int k = 0; k < card.size(); k++) {
	vector<int> tmp;
	tmp.push_back(card[i]);
	tmp.push_back(card[j]);
	tmp.push_back(card[k]);
	cand.push_back(tmp);
      }
    }
  }
  create_possible_set(cand);
  vector<vector<int> > current_cand = cand;  
  for(int i = 0; i < prods.size(); i++) {
    current_cand = prune(current_cand, prods[i]);
  }
 
  if(current_cand.size() == 0) return string("222");
  return lexical_cast<string>(current_cand[0][0]) +
    lexical_cast<string>(current_cand[0][1]) +
    lexical_cast<string>(current_cand[0][2]);
}
