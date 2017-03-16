#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <set>

#define MOD 1000000007

using namespace std;
//LL?
long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= (i % MOD);
        res %= MOD;
    }
    return res;
}

long long findsame(vector<pair<char, char> > &cars, char c, vector<string> carstrs, string &curr)
{
    int count = 0;
    for (int i = 0; i < cars.size(); i++) {
        pair<char, char> car = cars[i];
        if ((car.first == c) && (car.second == c)){
            cars[i] = make_pair('X','X');
            curr += carstrs[i];
            count++;
        }
    }
    return factorial(count);
}

int main()
{
    int ncases;
    cin >> ncases;

    for (int i = 0; i < ncases; i++){
        int ncars;
        cin >> ncars;

        vector<pair<char, char> > cars;
        vector<string> carstrs;

        for (int j = 0; j < ncars; j++) {
            string car;
            cin >> car;
            cars.push_back(make_pair(car[0], car[car.length()-1]));
            carstrs.push_back(car);
        }
        string final = "";
        long long comb = 1;        
        int groups = 0;
        for (int j = 0; j < cars.size(); j++) {
            pair<char, char> group = cars[j];//first and last letter
            if (group.first == 'X')
                continue;
            
            string curr = "";
            groups++;
            if (group.first == group.second) {
                comb *= findsame(cars, group.first, carstrs, curr);
            } else {
                string str = "";
                comb *= findsame(cars, group.first, carstrs, str);
                comb *= findsame(cars, group.second, carstrs, curr);
                curr = str+carstrs[j]+curr;
            }
            cars[j] = make_pair('X','X');
            comb %= MOD;
            bool exit = false;
            while(!exit) {
                for (int k = 0; k < ncars; k++) {
                    pair<char, char> car = cars[k];
                    if (group.first == car.second) {
                        string str = "";
                        comb *= findsame(cars, car.first, carstrs, str);
                        group.first = car.first;
                        cars[k] = make_pair('X','X');
                        curr = str+carstrs[k]+curr;
                        break;
                    } else if (group.second == car.first) {
                        string str = "";
                        comb *= findsame(cars, car.second, carstrs, str);
                        group.second = car.second;
                        cars[k] = make_pair('X','X');
                        curr = curr+carstrs[k]+str;
                        break;
                    }
                    if (k == ncars-1)
                        exit = true;
                }
                comb %= MOD;
            }
           
            final += curr;
        }
        comb *= factorial(groups);

        set<char> usec;
        set<char>::iterator it;
        bool poss = true;
        for (int l = 0; l < final.length(); l++) {
            char c = final[l];
            it = usec.find(c);
            usec.insert(c);
            if (it != usec.end()) {
                poss = false;
                break;
            }
            while (true) {
                if (l == final.length()-1)
                    break;
                if (final[l+1] != c)
                    break;
                l++;
            }
        }
        cout << "Case #" << i+1 << ": "; 
        if (!poss)
            cout << 0 << endl;
        else
            cout << comb%MOD << endl;
    }



    return 0;
}
