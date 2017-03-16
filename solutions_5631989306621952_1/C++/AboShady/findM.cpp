#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream in("A-large.in");
    ofstream out("a.txt");
int T ; in >> T;
vector<char> result;
	for(int t = 1 ; t<=T; t++){
        string s; in >> s;
       result.clear();
       result.push_back(s[0]);
       for(int i = 1; i < s.size(); i++){
       if(s[i] - result.at(0) >= 0) result.insert(result.begin(), s[i]);
            else result.push_back(s[i]);
       }
       out << "Case #" << t << ": ";
       for(int i = 0 ; i < s.size(); i++)
       out << result.at(i);
       out << endl;
	}
	return 0;
	out.close();
}
