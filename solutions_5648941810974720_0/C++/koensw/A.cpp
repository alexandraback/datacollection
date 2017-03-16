#include <iostream>
#include <cassert>

int c[27] = {};
std::string l[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char i1[] = {'Z', 0, 'W', 0, 'U', 0, 'X', 0, 'G', 0};
char i2[] = {0, 'O', 0, 'H', 0, 'F', 0, 'S', 0, 0};
int ans[10] = {};

int main(){
    int T;
    std::cin >> T;
    for(int z=0; z<T; ++z){
        
        for(int i=0; i<=26; ++i){
            c[i] = 0;
            if(i < 10) ans[i] = 0;
        }
        
        std::string s;
        std::cin >> s;
        
        for(int i=0; i<s.size(); ++i){
            c[s[i]-'A']++;
        }
        
        for(int i=0; i<9; ++i){
            if(!i1[i]) continue;
            ans[i] = c[i1[i]-'A'];
            for(int j=0; j<l[i].size(); ++j){
                //if(l[i][j] == i1[i]) continue;
                c[l[i][j]-'A'] -= ans[i];
                assert(c[l[i][j]] >= 0);
            }
        }
        
        for(int i=0; i<9; ++i){
            if(!i2[i]) continue;
            ans[i] = c[i2[i]-'A'];
            for(int j=0; j<l[i].size(); ++j){
                //if(l[i][j] == i2[i]) continue;
                c[l[i][j]-'A'] -= ans[i];
                assert(c[l[i][j]] >= 0);
            }
        }
        
        ans[9] = c['I' - 'A'];
        for(int j=0; j<l[9].size(); ++j){
            c[l[9][j]-'A'] -= ans[9];
            assert(c[l[9][j]] >= 0);
        }
        
        for(int i=0; i<26; ++i){
            assert(c[i] == 0);
        }
        
        std::cout << "Case #" << z+1 << ": ";
        for(int i=0; i<10; ++i){
            for(int j=0; j<ans[i]; ++j){
                std::cout << i;
            }
        }
        std::cout << std::endl;
    }
}
