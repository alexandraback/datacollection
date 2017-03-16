# include <string> 
# include <vector> 
# include <iostream> 
# include <sstream> 
# include <cstdio> 
# include <cstdlib> 
# include <cmath> 
# include <cctype> 
# include <cstring> 
# include <map> 
# include <queue> 
# include <deque> 
# include <set> 
# include <algorithm> 
# include <utility> 
# include <functional> 
# include <stack> 
# include <bitset> 
# include <complex> 
# include <cassert> 
# include <ctime> 
# include <list> 
# include <valarray>

using namespace std;

string words[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void work(string s)
{
    int count_letters[26];
    int count_numbers[10];
    
    memset(count_letters, 0, sizeof(count_letters));
    memset(count_numbers, 0, sizeof(count_numbers));
    
    for(int i = 0; i < s.length(); i++)
    {
        count_letters[(int)(s[i] - 'A')]++;
    }
    
    for(int i = 0; i < 26; i++)
    {
        int num = -1;
        
        switch((char)('A' + i))
        {
            case 'X':
                num = 6;
                break;
            default:
                continue;
        }
        
        count_numbers[num] = count_letters[i];
        
        for(int k = 0; k < count_numbers[num]; k++)
        {
            for(int j = 0; j < words[num].length(); j++)
            {
                count_letters[(int)(words[num][j] - 'A')]--;
            }
        }
    }
    
    for(int i = 0; i < 26; i++)
    {
        int num = -1;
        switch((char)('A' + i))
        {
            case 'Z':
                num = 0;
                break;
            case 'V':
                num = 5;
                break;  
            case 'S':
                num = 7;
                break;
            case 'G':
                num = 8;
                break;
            case 'W':
                num = 2;
                break;
            case 'U':
                num = 4;
                break;
            default:
                continue;
        }
            
        count_numbers[num] = count_letters[i];
        
        for(int k = 0; k < count_numbers[num]; k++)
        {
            for(int j = 0; j < words[num].length(); j++)
            {
                count_letters[(int)(words[num][j] - 'A')]--;
            }
        }
    }
    
    for(int i = 0; i < 26; i++)
    {
        int num = -1;
        
        switch((char)('A' + i))
        {
            case 'I':
                num = 9;
                break;
            case 'R':
                num = 3;
                break;
            case 'O':
                num = 1;
                break;
            default:
                continue;
        }
        
        count_numbers[num] = count_letters[i];
        
        for(int k = 0; k < count_numbers[num]; k++)
        {
            for(int j = 0; j < words[num].length(); j++)
            {
                count_letters[(int)(words[num][j] - 'A')]--;
            }
        }
    }
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < count_numbers[i]; j++)
        {
            cout << i;
        }
    }
    cout << endl;
}
int main()
{
	int T;
    cin >> T;
    
    for(int i = 1; i <= T; i++)
    {
        string s;
        cin >> s;
        
        cout << "Case #" << i << ": "; 
        work(s);
    }
	return 0;
}

