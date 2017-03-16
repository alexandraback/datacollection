#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

pair<int,int> OptimalSplit(int k, int N){
    // number of special minutes needed to bring the max height of an initial stack of height N to <= k
    int height = N;
    int i =0;
    while (height > k){
        ++i;
        int quotient = N / (i+1);

        height = quotient;
        if ( N % (i+1) != 0){
            height += 1;
        }
    }
    return make_pair(height,i);
}

int main(){
    string line;
    getline(cin, line);
    int num = atoi(line.c_str());
    for (int i =0; i < num; ++i){
        getline(cin,line);
        int D = atoi(line.c_str());
        getline(cin,line);
        stringstream ss(line);
        int tmp;
        vector<int> diners;

        while (ss >> tmp) diners.push_back(tmp);
        sort(diners.rbegin(), diners.rend());
        int best = diners[0];
        for (int k = best; k > 0; --k){
            int candidate = 0, height = 0;
            for (auto it = diners.begin(); it != diners.end(); ++it){
                pair<int,int> p = OptimalSplit(k,*it);
                //cout << "optimal split = " << p.first << "," << p.second << endl;
                height = max(height, p.first);
                candidate += p.second;
            }
            candidate += height;
            //cout << "candidate = " << candidate << endl;
            best = min(best,candidate);
        } 

        cout << "Case #" << i+1 << ": " << best << endl;
    }
    return 0;
}

/* false solution 
int main(){
    string line;
    getline(cin, line);
    int num = atoi(line.c_str());
    for (int i =0; i < num; ++i){
        getline(cin,line);
        int D = atoi(line.c_str());
        getline(cin,line);
        stringstream ss(line);
        int tmp,a,b,best,step=0;
        vector<int> diners;
        while (ss >> tmp) diners.push_back(tmp);

        sort(diners.rbegin(), diners.rend());
        // the trick is that all special minutes occur in the beginning
        best = diners[0];
        while (diners[0] > 1){
            tmp = diners[0];
            diners.erase(diners.begin());
            a = tmp/2;
            b = tmp - a;
            diners.push_back(a);
            diners.push_back(b);
            ++ step;
            sort(diners.rbegin(), diners.rend());
            best = min(best, diners[0] + step);
        }
        cout << "Case #" << i+1 << ": " << best << endl;
    }
    return 0;
}

*/

/* https://code.google.com/codejam/contest/6224486/dashboard#s=p1 */

/*
 * Problem

At the Infinite House of Pancakes, there are only finitely many pancakes, but there are infinitely many diners who would be willing to eat them! When the restaurant opens for breakfast, among the infinitely many diners, exactly D have non-empty plates; the ith of these has Pi pancakes on his or her plate. Everyone else has an empty plate.

Normally, every minute, every diner with a non-empty plate will eat one pancake from his or her plate. However, some minutes may be special. In a special minute, the head server asks for the diners' attention, chooses a diner with a non-empty plate, and carefully lifts some number of pancakes off of that diner's plate and moves those pancakes onto one other diner's (empty or non-empty) plate. No diners eat during a special minute, because it would be rude.

You are the head server on duty this morning, and it is your job to decide which minutes, if any, will be special, and which pancakes will move where. That is, every minute, you can decide to either do nothing and let the diners eat, or declare a special minute and interrupt the diners to make a single movement of one or more pancakes, as described above.

Breakfast ends when there are no more pancakes left to eat. How quickly can you make that happen?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with D, the number of diners with non-empty plates, followed by another line with D space-separated integers representing the numbers of pancakes on those diners' plates.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the smallest number of minutes needed to finish the breakfast.

Limits

1 ≤ T ≤ 100.
Small dataset

1 ≤ D ≤ 6.
1 ≤ Pi ≤ 9.
Large dataset

1 ≤ D ≤ 1000.
1 ≤ Pi ≤ 1000.
Sample


Input 
 	
Output 
 
3
1
3
4
1 2 1 2
1
4

Case #1: 3
Case #2: 2
Case #3: 3

In Case #1, one diner starts with 3 pancakes and everyone else's plate is empty. One optimal strategy is:

Minute 1: Do nothing. The diner will eat one pancake.

Minute 2 (special): Interrupt and move one pancake from that diner's stack onto another diner's empty plate. (Remember that there are always infinitely many diners with empty plates available, no matter how many diners start off with pancakes.) No pancakes are eaten during an interruption.

Minute 3: Do nothing. Each of those two diners will eat one of the last two remaining pancakes.

In Case #2, it is optimal to let the diners eat for 2 minutes, with no interruptions, during which time they will finish all the pancakes.

In Case #3, one diner starts with 4 pancakes and everyone else's plate is empty. It is optimal to use the first minute as a special minute to move two pancakes from the diner's plate to another diner's empty plate, and then do nothing and let the diners eat for the second and third minutes.
*/
