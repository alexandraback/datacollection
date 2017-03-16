#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <iterator>
#include <set>


using namespace std;

double answer;
int k;
int l;
int s;

char keyboard[100];
char target[100];
char tmp[100];
int indexes[1000];

map <char, int> keyboard_map;

bool incriment_indexes(){ // return true if all done
    int i;
    for(i = 0; i < s; i++){
        if(indexes[i] < k - 1){
            indexes[i] ++;
            return false;
        } else{
            indexes[i] = 0;
        }
    }
    if( i >= s){
        return true;
    }
    return false;
}


int get_needed_banana(){
    int banana_no = 0;
    for(int i = 0; i <= s - l; i++){
        for(int j = 0; j < l; j++){
            if(tmp[i + j] != target[j]){
                break;
            }
            if(j == (l - 1)){
                banana_no ++;
            }
        }
    }
    return banana_no;

}
double get_probability(){
    double result = 1;
    for(int i = 0; i < s; i++){
        result *= 1.0 / (double) k;
    }
    return result;
}

void solve(int case_no){
	//input
    cin >> k >> l >> s;
    cin >> keyboard;
    cin >> target;
	

	//calculate
    bool done = false;
    answer = 0.0;
    for(int i = 0; i < k; i++){
        if(keyboard_map.find(keyboard[i]) != keyboard_map.end()){
            keyboard_map[keyboard[i]] ++;
        } else{
            keyboard_map.insert(pair<char, int>(keyboard[i], 1));

        }
    }

    for(int i = 0; i < l; i++){
        if(keyboard_map.find(target[i]) == keyboard_map.end()){
            answer = 0.0;
            done = true;
        }
    }

    if(!done){
        int max_banana_no = 0;
        for(int i = 0; i < s; i++){
            indexes[i] = 0;
        }

        do{
#ifdef DEBUG
            cout << "indexes: ";
            for(int i = 0; i < s; i++){
                cout << indexes[i] << " ";
            }
            cout << endl;
#endif
 
            for(int i = 0; i < s; i++){
               tmp[i] = keyboard[indexes[i]];
               
            }
#ifdef DEBUG
               cout << "get_needed_banana, get_probability: " << get_needed_banana() << ", " << get_probability() << endl;
               cout << "tmp: ";
               for(int j = 0; j < s; j++){
                   cout << tmp[j];
               }
               cout << endl;
#endif
 
            answer += get_needed_banana() * get_probability();
            max_banana_no = max(max_banana_no, get_needed_banana());
        } while(!incriment_indexes());

        answer = max_banana_no - answer;
	
    }

	//output
	cout << "Case #" << case_no << ": " << fixed << setprecision(6) << answer << endl;
}

int main(){
	int test_case_no;
	cin >> test_case_no;
	for (int i = 0; i < test_case_no; i++){
		solve(i + 1);
	}
	return 0;
}
