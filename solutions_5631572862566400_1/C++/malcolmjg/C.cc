using namespace std;
#include <iostream>
#include <vector>
#include <unordered_set>

int main(){
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    int n;
    cin >> n;
    int bff[n+1];
    for (int i=1; i<=n; i++) cin >> bff[i];

    // step 1: find the cycles
    int cycle_name[n+1] = {};
    unordered_set<int> cycles;
    for (int i=1; i<=n; i++){
      int current = i;
      unordered_set<int> seen_so_far;
      while(true){
        current = bff[current];
        if (seen_so_far.count(current)) {
          // we're in a cycle. let's start again from current and find the name
          int smallest_seen = current;
          while(true){
            current = bff[current];
            if (current == smallest_seen){
              cycle_name[i] = current;
              cycles.insert(current);
              break;
            }
            smallest_seen = min(current, smallest_seen);
          }
          break;
        }
        seen_so_far.insert(current);
      }
    }

    // step 2: find the size of each cycle
    int cycle_length[n+1] = {};
    unordered_set<int> two_cycles;
    int biggest_cycle_length = 0;
    for (int name : cycles){
      int length = 0;
      int current = name;
      while(true){
        current = bff[current];
        length++;
        if (current == name){
          cycle_length[name] = length;
          if (length == 2) two_cycles.insert(name);
          biggest_cycle_length = max(length, biggest_cycle_length);
          break;
        }
      }
    }

    // step 3: find the lengths of the tails to the two cycles
    int longest_tail_to_name[n+1] = {};
    int longest_tail_to_next[n+1] = {};
    for (int i=1; i<=n; i++){
      if (two_cycles.count(cycle_name[i])){
        int current = i;
        int length = 0;
        int name = cycle_name[i];
        int next = bff[cycle_name[i]];
        if (i == name) continue;
        if (i == next) continue;
        while(true){
          current=bff[current];
          length++;
          if (current == name){
            longest_tail_to_name[name] = max(length, longest_tail_to_name[name]);
            break;
          }
          if (current == next){
            longest_tail_to_next[name] = max(length, longest_tail_to_next[name]);
            break;
          }
        }

      }
    }

    // step 4: either we use the biggest cycle, or all the two cycles + tails
    int two_cycle_total = 0;
    for (int name : two_cycles){
      two_cycle_total += (2 + longest_tail_to_name[name] + longest_tail_to_next[name]);
    }
    int output = max(two_cycle_total, biggest_cycle_length);
    cout << "Case #" << t << ": " << output << endl;
  }
}
