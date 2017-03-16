#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool all_same(string a,char &out){
	out = a[0];
	for(size_t i = 1;i < a.size();++i){
		if(a[i] != out){
			return false;
		}
	}
	return true;
}
long long stair(int a){
	long long result = 1;
	for(int i = 2;i <= a;++i)
		result *= i % 1000000007;
	return result;
}
bool findCircular(int Start,int End,int cir[26][26]){
	if(Start == End)return true;
	for(int i = 0;i < 26;++i){
		if(cir[Start][i]){
			if(findCircular(i,End,cir))return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	int TestCase,N,Case = 1;
	cin >> TestCase;
	while(TestCase--){
		long long result = 1;
		cin >> N;
		int circular[26][26] = {};
		vector<string> train;
		vector<int> same(26);
		vector<int> start(26);
		vector<int> end(26);
		vector<int> middle(26);
		string temp;
		for(int i = 0;i < N;++i){
			cin >> temp;
			train.push_back(temp);
		}
		for(int i = 0;i < N;++i){
			char out;
			if( all_same(train[i],out) ){
				 ++same[out - 'a'];
			}
			else if( train[i][0] == train[i][train[i].size()-1] ){
				result = 0;
				break;
			}else{
				int Start = train[i][0] - 'a';
				int End = train[i][train[i].size()-1] - 'a';
				circular[Start][End] = 1;
				if(findCircular(End,Start,circular)){result = 0;break;}
				++start[ train[i][0] - 'a' ];
				if(start[train[i][0] - 'a'] >= 2){ result = 0; break;}
				++end[ train[i][train[i].size()-1] - 'a' ];
				if(end[ train[i][train[i].size()-1] - 'a' ] >= 2){ result = 0; break;}
				

				//consider not start end all same but middle 
				char startchar = train[i][0];
				size_t ch = 0;
				bool breakflag = false;
				while(train[i][ch] == startchar)++ch;
				for( ;ch < train[i].size() -1;++ch){
					if(train[i][ch] != train[i][ch+1]){
						++middle[ train[i][ch] - 'a' ];
						if(middle[ train[i][ch] - 'a' ] >= 2){
							result = 0;
							breakflag = true;
							break;
						}
					}
				}
				if(breakflag)break;
			}
		}
		if(result){
			for(int i = 0;i < 26;++i){
				if(middle[i] && (same[i] || start[i] || end[i])){
					result = 0;
					break;
				}
			}
		}
		if(result){
			vector<int> toStair;
			for(int i = 0;i < 26;++i){
				if(same[i] >= 2)toStair.push_back(same[i]);
			}
			int k = 0;
			for(int i = 0;i < 26;++i){
				if(same[i] && (!start[i] && !end[i]))
					++k;
				else if(start[i] && !end[i])
					++k;
			}
			toStair.push_back(k);
			for(size_t i = 0;i < toStair.size();++i){
				result = (result * stair(toStair[i])) % 1000000007;
			}
		}
		printf("Case #%d: %lld\n",Case++,result);
	}
	return 0;
}
