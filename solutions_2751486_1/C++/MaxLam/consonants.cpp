#include <iostream>
#include <vector>

using namespace std;

bool is_cons(char a) {
  if (a != 'a' &&
      a != 'e' &&
      a != 'i' &&
      a != 'u' &&
      a != 'o')
    return true;
  return false;
}

int num_substr(int last_index, int endind,
	       int substr_length, int length) {
  int strt = endind - substr_length + 1;
  int end = endind;
  
  int before = strt - last_index;
  //cout << "last" << last_index << endl;
  //cout << strt << " " << end << endl;
  //cout << before << endl;
  int after = (length-1) - end;
  //cout << after << endl;
  return 1 + before + after + before * after;
} 
	       

int main(int argc, char *argv[]) {
  int n_cases;
  cin >> n_cases;

  for (int i = 0; i < n_cases; i++) {
    string str;
    int n_value;
    cin >> str >> n_value;
    cout << "Case #" << i+1 << ": ";

    int num_consonant = 0;
    int result = 0;
    int last_index = 0;
    bool first = true;
    

    for (int j = 0; j < str.length(); j++) {
      if (is_cons(str[j])) {
	num_consonant++;
      }
      else {
	num_consonant = 0;
      }

      if (num_consonant >= n_value) {
	result += num_substr(last_index, j,
			     n_value, str.length());
	last_index = j - n_value + 2;
      }
    }
    
    cout << result << endl;
  }
}
