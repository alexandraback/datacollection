#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 100005
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int order[] = {0, 2, 6, 8, 4, 1, 3, 5, 7, 9};
char uni[] = {'Z', 'W', 'X', 'G', 'U', 'O', 'T', 'F', 'S', 'I'};

int main(){
	ios_base::sync_with_stdio(false);
	int t, T=1;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		int arr[26], cnt[26];
		for(int i=0 ; i<26 ; i++)
			arr[i] = 0, cnt[i] = 0;

		for(int i=0 ; i<s.size() ; i++)
			arr[s[i] - 'A']++;

		for(int i=0 ; i<10 ; i++){
			int times = arr[uni[i] - 'A'];
		
			cnt[order[i]] += times;

			
			for(int j=0 ; j<num[order[i]].size() ; j++)
				arr[num[order[i]][j] - 'A'] -= times;
		}

		cout<<"Case #"<<T++<<": ";

		for(int i=0 ; i<10 ; i++){
			for(int j=0 ; j<cnt[i] ; j++)
				cout<<i;
		}

		cout<<"\n";
	}

	return 0;
}