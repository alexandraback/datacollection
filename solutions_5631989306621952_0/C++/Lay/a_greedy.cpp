#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int main()
{
		
    int T;
    cin>>T;
	
    for(int t=1;t<=T;t++){
		string word,last_word;
		cin>>word;
		
		for(int i=0;i<word.size();i++){
			last_word=max(last_word+word[i],word[i]+last_word);
		}
		printf("Case #%d: %s\n",t,last_word.c_str());
    }
    
    return 0;
}