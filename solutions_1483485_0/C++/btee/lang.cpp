#include <cstdlib>
#include <cstdio>

#include <algorithm>
#include <map>
#include <sstream>
#include <bitset>

#include <iostream>

using namespace std;

void learn(map<char, char>& t) {
    string in  = "z" "y qee"
    "ejp mysljylc kd kxveddknmc re jsicpdrysi"
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
    "de kr kd eoya kw aej tysr re ujdr lkgc jv";

    string out = "q" "a zoo"
    "our language is impossible to understand"
    "there are twenty six factorial possibilities"
    "so it is okay if you want to just give up";
    
    for ( 
        string::iterator ot = out.begin(), it = in.begin(); 
        ot != out.end(); 
        ++ot, ++it
    ) {
        t[*it] = *ot;
    }
    
    bitset<('z'-'a'+1)> used;
    
    for(char c = 'a'; c<='z'; ++c) {
        clog << c << " --> " << t[c] << endl;
        
        if(0 == t[c]) {
            clog << "there might be a problem for letter '" << c << "'" << endl;
        } else {
            used.set(t[c]-'a');
        }
    }
    
    if(!used.all()) {
        for(char c = 'a'; c<='z'; ++c) {
            if(!used.test(c-'a')){
                clog << "'" << c << "' is not used" << endl;
            }
        }
    }
}

int main(){
    map<char, char> t;
    learn(t);
        
    int cases;
    cin >> cases;
    {   /* read the rest of the line */
        string tmp;
        getline(cin,tmp);
    }
    
    for(int i=0; i<cases; ++i) {
        string input;
        noskipws(cin);
        getline(cin,input);

        stringstream output;
        
        string::iterator it = input.begin();
        for(;it!=input.end();++it) {
            output << t[*it];
        }
        
        printf("Case #%d: %s\n", 
            (i+1), output.str().c_str()
        );
    }
    
    return 0;
}
