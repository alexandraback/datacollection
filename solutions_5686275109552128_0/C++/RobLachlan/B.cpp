#include <vector>
#include <iostream>
#include <algorithm>



using namespace std;


vector<int> group_by_size(vector<int> plates) {
  int max = *max_element(plates.begin(), plates.end());
  auto grouped = vector<int>(max + 1, 0);
  for (auto p : plates){
    grouped[p]++;
  }
  return grouped;
}




int total_time(vector<int> plates_by_size){
  auto extra_minutes = 0;
  const auto Pmax = plates_by_size.size() - 1;
  auto min_minutes = Pmax;
  for (auto Pi = Pmax; Pi > 1; --Pi){
    min_minutes = min(min_minutes, Pi + extra_minutes);
    extra_minutes += plates_by_size[Pi];
    plates_by_size[Pi / 2] += plates_by_size[Pi];
    plates_by_size[Pi / 2 + Pi % 2] += plates_by_size[Pi];
  }
  return min_minutes;
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 0;
  cin >> T;
  for (int i = 1; i <= T; ++i){
    int D = 0;
    cin >> D;
    auto plates = vector<int>(D);
    for (int i=0; i<D; ++i){
      cin >> plates[i];
    }
    auto grouped_plates = group_by_size(plates);
    auto time = total_time(grouped_plates);
    cout << "Case #" << i << ": " << time << '\n';
  }
  return 0;
}
