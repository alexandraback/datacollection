#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int C;
int main(){
	
	cin>>C; 
	for(int j=0; j<C; j++){
	    string s;
	    cin>>s;
	    vector<int> lets(26, 0);
	    vector<char> ls = {'Z', 'W', 'U', 'X', 'G', 'F', 'T', 'S', 'I','O'};
	    vector<string> strs={"ZERO", "TWO",  "FOUR",  "SIX",  "EIGHT","FIVE","THREE","SEVEN", "NINE", "ONE",};
	    vector<int> ns = {0, 2,4,6,8, 5,3,7,9,1};
	    vector<int> nums(10, 0);
	    for(int i=0; i<s.length(); i++){
		lets[s[i]-'A']++;
	    }
	    for (int i=0; i<10; i++){
		int nd = lets[ls[i]-'A'];
		nums[ns[i]]=nd;
		for(int j=0; j<strs[i].size(); j++){
		    lets[strs[i][j]-'A']-=nd;
		}
	    }
	    cout<<"Case #"<<j+1<<": ";
	    for(int i=0; i<10; i++){
		for(int j=0; j<nums[i]; j++)cout<<i;
	    }
	    cout<<"\n" ;
	}
	
}
