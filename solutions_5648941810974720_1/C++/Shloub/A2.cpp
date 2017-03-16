#include<iostream>
#include<string>
#include<map>
#include<array>
#include<deque>
#include<algorithm>

int main(){
  unsigned T; std::cin >> T;
  std::array<std::string, 10> digits {{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}};
  std::array<std::map<char, unsigned>, 10> letters {};
  for(unsigned i {0}; i<10; ++i){
    std::map<char, unsigned> lcount {};
    for(char c: digits[i])
      ++lcount[c];
    letters[i] = lcount;
  }
  for(unsigned i {0}; i<T; ++i){
    std::string r {};
    std::string s; std::cin >> s;
    std::map<char, unsigned> count {};
    for(char c: s)
      ++count[c];
    unsigned nb_zero {count['Z']};
    for(unsigned j {0}; j<nb_zero; ++j){
      r += "0";
      --count['Z'];
      --count['E'];
      --count['R'];
      --count['O'];
    }
    unsigned nb_two {count['W']};
    for(unsigned j {0}; j<nb_two; ++j){
      r += "2";
      --count['T'];
      --count['W'];
      --count['O'];
    }
    unsigned nb_four {count['U']};
    for(unsigned j {0}; j<nb_four; ++j){
      r += "4";
      --count['F'];
      --count['O'];
      --count['U'];
      --count['R'];
    }
    unsigned nb_five {count['F']};
    for(unsigned j {0}; j<nb_five; ++j){
      r += "5";
      --count['F'];
      --count['I'];
      --count['V'];
      --count['E'];
    }
    unsigned nb_six {count['X']};
    for(unsigned j {0}; j<nb_six; ++j){
      r += "6";
      --count['S'];
      --count['I'];
      --count['X'];
    }
    unsigned nb_seven {count['S']};
    for(unsigned j {0}; j<nb_seven; ++j){
      r += "7";
      --count['S'];
      --count['E'];
      --count['V'];
      --count['E'];
      --count['N'];
    }
    unsigned nb_eight {count['G']};
    for(unsigned j {0}; j<nb_eight; ++j){
      r += "8";
      --count['E'];
      --count['I'];
      --count['G'];
      --count['H'];
      --count['T'];
    }
    unsigned nb_nine {count['I']};
    for(unsigned j {0}; j<nb_nine; ++j){
      r += "9";
      --count['N'];
      --count['I'];
      --count['N'];
      --count['E'];
    }
    unsigned nb_one {count['O']};
    for(unsigned j {0}; j<nb_one; ++j){
      r += "1";
      --count['O'];
      --count['N'];
      --count['E'];
    }
    unsigned nb_three {count['T']};
    for(unsigned j {0}; j<nb_three; ++j){
      r += "3";
      --count['T'];
      --count['H'];
      --count['R'];
      --count['E'];
      --count['E'];
    }
    std::sort(begin(r), end(r));
    std::cout << "Case #" << (i+1) << ": " << r << '\n';
  }
}
