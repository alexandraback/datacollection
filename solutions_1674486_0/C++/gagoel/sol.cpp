#include<iostream>
#include<vector>
using namespace std;



int main() {

  int T, pos = 1;
  cin >> T;
  
  int buff[1001][11];
  bool flags[1001];
  
  while(T--) {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
      int curr;
      cin >> curr;
      buff[i][0] = curr;
      for(int j = 0; j < curr; j++) {
        cin >> buff[i][j+1]; 
      }
    }

    for(int i = 0; i < n; i++) {
      memset(flags, 0, sizeof(flags));
      vector<int> stack;

      flags[i+1] = true;
      for(int j = 0; j < buff[i][0]; j++) 
        stack.push_back(buff[i][j+1]);
        
      while(stack.size() > 0) {
        int val = stack.back();
	stack.pop_back();     
        if(flags[val] == true) goto Yes; 
	flags[val] = true;
        for(int j = 0; j < buff[val-1][0]; j++) {
          stack.push_back(buff[val-1][j+1]);
	}
      }
     }
  
    No:
       printf("Case #%d: No\n", pos++); 
       continue;
    Yes:
       printf("Case #%d: Yes\n", pos++);
  }
  return 0;
}
