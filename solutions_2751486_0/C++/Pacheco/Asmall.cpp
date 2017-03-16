#include <iostream>
#include <string>
using namespace std;

bool is_consonant(char l)
{
    return l != 'a' && l != 'e' && l != 'i' && l != 'o' && l != 'u';
}

int main()
{
    int T, case_ = 1, n, answ, consecutive;
    string name;
    bool can_count;
    
    cin >> T;
    
    while (T--) {
        cin >> name >> n;
        answ = 0;
        
        for (int i = 0; i < name.size(); i++) {
            consecutive = 0;
            can_count = false;
            for (int j = i; j < name.size(); j++) {
                consecutive = is_consonant(name[j]) ? consecutive+1 : 0;
                if (consecutive >= n) {
                    can_count = true;
                }
                
                if (can_count) {
                    ++answ;
                }
            }   
        }
        
        cout << "Case #" << case_++ << ": " << answ << endl;
    }

}
