#include <iostream>
#include <string>
using namespace std;




int main() {

    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
	int friends_needed = 0;
	int total = 0;
	string people;
	int s_max;
	
	cin >> s_max;
	cin >> people;
	for(int j = 0; j < people.length(); j++) {
            
	    if(total < j) {
		friends_needed+= j-total;
		people[j]+= j-total;
	    }
		total += people[j] - '0';
	}
            
	
	cout << "Case #" << i+1 << ": " << friends_needed << endl;
    }






}
