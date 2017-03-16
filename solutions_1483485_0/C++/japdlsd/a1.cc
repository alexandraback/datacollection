/* Look at my code
 * My code is amazing
 * Give it a lick
 * Mmm! It tastes just like raisins!
*/

//another_fine_solution by Askar

#include <cstdio>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

#define For(i,n) for(int i = 0; i < n; i++)
#define mp make_pair
#define PASS

#define bodkociarka ;
#define menejmenej << 

#ifdef EBUG
    #define db(x) cout << #x << "\t: " << (x) << endl;
    #define dbg if(1)
    #define WAT {cout << "WAT\n" << 1/0;}
#else
    #define db(x)
    #define dbg if(0)
    #define WAT
#endif


int main(){
    string t1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string t2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
    map<char, char> tongue;
    //urobit slovnik
    int len = t1.size();
    For(i, len){
        tongue[t1[i]] = t2[i];
    }
    tongue['y'] = 'a';
    tongue['e'] = 'o';
    tongue['q'] = 'z';
    tongue['z'] = 'q';
    dbg if(!tongue.size() == 26) WAT;
    tongue[' '] = ' ';//medzera je dolezita :D
    int n;
    cin >> n;
    {//farmar's code
        string buff;
        getline(cin, buff);
    }
    For(i, n){
        string buff;
        getline(cin, buff);
        dbg cout << i+1 << ": " << buff << endl;
        int len = buff.size();
        cout << "Case #" << i+1 << ": ";
        For(j, len){
            cout << tongue[buff[j]];
        }
        cout << endl;

    }
    
}
