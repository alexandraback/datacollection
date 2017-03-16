#include <iostream>
#include <cassert>
using std::cin;
using std::cout;

const int key_max=5;
const int chest_max=5;
int keys, chests;
int keys_at[chest_max][key_max];
int chest_seq[chest_max];
int chest_open_with[chest_max];
int have_key[key_max];
bool chest_is_closed[chest_max];

bool try_chest(int chest_try)
{
  if(chest_try>chests) return true;
  for(int idx = 1; idx<=chests; idx++) {
    /* can we open? */
    if( chest_is_closed[idx] && have_key[ chest_open_with[idx] ] ) {
      /* try the chest */
      chest_is_closed[idx]=false;
      have_key[ chest_open_with[idx] ]--;
      for(int i=1; i<key_max; i++) have_key[i] += keys_at[idx][i];
      chest_seq[chest_try]=idx;
      if(try_chest(chest_try+1)) return true;
      for(int i=1; i<key_max; i++) have_key[i] -= keys_at[idx][i];
      have_key[ chest_open_with[idx] ]++;
      chest_is_closed[idx]=true;      
    }
  }
  return false;
}



int main(void)
{
  int  number_of_test_cases;
  cin >> number_of_test_cases;
  for(auto test_case=1; 
      test_case <= number_of_test_cases;
      test_case++) {
    cin >> keys >> chests;
    for(int k=0; k<key_max; k++) have_key[k]=0;
    for(int k=0; k<keys; k++) {
      int kc; cin >> kc;
      have_key[kc]++;
    }
    for(int c=1; c<=chests; c++) {
      int kc, nkeys;
      chest_is_closed[c]=true;
      cin >> kc >> nkeys;
      chest_open_with[c]=kc;
      for(int k=0; k<key_max; k++) keys_at[c][k]=0;
      for(int k=0; k<nkeys; k++) {
	cin >> kc;
	keys_at[c][kc]++;
      }
    }
    cout << "Case #" << test_case << ':';
    if(try_chest(1)) 
      for(int c=1; c<=chests; c++)
	cout << " " << chest_seq[c];
    else 
      cout << " IMPOSSIBLE";
    cout << std::endl;
  }
  return 0;
}
