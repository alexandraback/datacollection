#include <iostream>

using namespace std;

char reverse_map[] = "yhesocvxduiglbkrztnwjpfmaq";
    
int main()
{
    int T, num = 1;
    
    cin >> T;
    
    cin.get();    
    for(int i = 0; i < T; i++)
    {
        cout << "Case #"<< num++ << ": ";
        string str;
        getline(cin, str);
        
        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == ' ')
                cout << " ";
            else
                cout << reverse_map[str[j] - 'a'];
        }
        cout << endl;
            
    }
    
    return 0;
}
