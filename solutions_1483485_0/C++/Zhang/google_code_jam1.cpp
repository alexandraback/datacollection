#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

map <char, char> mapstr;


int main()
{
    string a = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
    string b = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
    
    mapstr['z'] = 'q';
    mapstr['q'] = 'z';
    for(int i  = 0; i < a.length(); i++)
    {
      mapstr[a[i]] = b[i];    
    }
    
    /*for(map<char, char>:: iterator it = mapstr.begin(); it != mapstr.end(); it++)
    {
      cout << it->first << "\t" << it->second << endl;
    }
    
    cout << mapstr.size() << endl;
    getchar();
    */
    
    ifstream cin("a.cpp");
    ofstream cout("b");
    
    int N;
    cin >> N;
                string line;
    getline(cin, line);
    for(int case_= 0; case_ < N; case_++)
    {

            getline(cin, line); 
            cout << "Case #" << case_+1 << ": "  ;
            for(int i = 0; i < line.length(); i++)
            {
                    cout << mapstr[line[i]];
            }
            cout << endl;
    }   
    
    //getchar();
}
