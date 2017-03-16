#include <iostream>
#include <string>
#include <set>
#include <cstdlib>

using namespace std;

bool sortWord(string totalWord, string check, int quaternion[5][5]) {
  if (check.empty() && totalWord.empty()) return true;
  else if (check.empty() || totalWord.empty()) return false;
  else {
    int result = 1;
    int tmp = 1;
    int sign = 1;
    for (int i = 0; i < totalWord.length(); i++) {
      tmp = totalWord[i] - '0';
      result = quaternion[result][tmp];
      sign = result > 0 ? sign : -sign;
      result = abs(result);
      if (sign == 1 && result == check[0] - '0') {
         if (sortWord(totalWord.substr(i + 1), check.substr(1), quaternion)) return true; 
      }
    } 
    
    return false;   
  }
}




int main(int argc, char *argv[])
{
  string name = "C-small-attempt1";
  string path = "";

  freopen((path + name + ".in").c_str(), "r", stdin);
  freopen((path + name + ".out").c_str(), "w", stdout);

  int quaternion[5][5] = {{}, 
                          {0, 1, 2, 3, 4},
                          {0, 2, -1, 4, -3},
                          {0, 3, -4, -1, 2},
                          {0, 4, 3, -2, -1}
  };
  
  int test_cases;
  cin >> test_cases;
  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int number;
    cin >> number;

    int count;
    cin >> count;

    if (count >12) count = 12 + count%4;
    string word;
    cin>>word;
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == 'i') word[i] = '2';  
      else if (word[i] == 'j') word[i] = '3';  
      else if (word[i] == 'k') word[i] = '4';  
    }

    string totalWord;
    
    while (count--) {
      totalWord += word;
    }
    bool ifexist = false;
    int result = 1;
    int tmp = 1;
    int sign = 1;

    for (int i = 0; i < totalWord.length(); i++){
        tmp = totalWord[i] - '0';
        result = quaternion[result][tmp];
        sign = result > 0 ? sign : -sign;
        result = abs(result);
        if (sign == 1 && result == 2) {
          int result2 = 1;
          int tmp2 = 1;
          int sign2 = 1;
          for (int j = i+1; j < totalWord.length(); j++) {
            tmp2 = totalWord[j] - '0';
            result2 = quaternion[result2][tmp2];
            sign2 = result2 > 0 ? sign2 : -sign2;
            result2 = abs(result2);
            if (sign2 == 1 && result2 == 3) {
              int result3 = 1;
              int tmp3 = 1;
              int sign3 = 1;
              for (int x = j+1; x < totalWord.length(); x++) {
                tmp3 = totalWord[x] - '0';
                result3 = quaternion[result3][tmp3];
                sign3 = result3 > 0 ? sign3 : -sign3;
                result3 = abs(result3);
                
              }
              if (result3 == 4 && sign3 == 1) ifexist = true;
            }
            if (ifexist) break;
          }  
        }

        if (ifexist) break;

    }


    cout << "Case #" << test_case << ": " << (ifexist ? "YES" : "NO") << endl;
    //cout << "Case #" << test_case << ": " << (sortWord(totalWord, "234", quaternion) ? "YES" : "NO") << endl;
    cout.flush();
  }
  fclose(stdout);
  fclose(stdin);
  return 0;
}

