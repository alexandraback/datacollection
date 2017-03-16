#include <cstdio>
#include <vector>
using namespace std;
int reached_at_case[2000000];
bool used[2000000][500];
int numbers[500];
int n;
int curr;
bool curr_used[500];
int curr_case;
bool found;
void action(int ind){
	if(ind >= n){
		return;
	}
	if(found)
		return;
	action(ind+1);
	if(found)
		return;
	curr_used[ind]=true;
	curr += numbers[ind];
	//check if already exists
	if(reached_at_case[curr] == curr_case){
		//int a=0;
		//int b = 0;
		vector<int> a,b;
		for(int i = 0; i < n; ++i){
			if(used[curr][i]){
				if(!curr_used[i]){
					//res+= numbers[i];
					b.push_back(i);
				}
			}else{
				if(curr_used[i]){
					a.push_back(i);
				}
			}
		}
		for(vector<int>::iterator it = a.begin(); it != a.end(); ++it){
			printf("%d ", numbers[*it]);
		}
		printf("\n");
		for(vector<int>::iterator it = b.begin(); it != b.end(); ++it){
			printf("%d ", numbers[*it]);
		}
		printf("\n");
		found=true;
		return;
	}else{
		for(int i = 0; i < n; ++i){
			used[curr][i]=curr_used[i];
		}
		reached_at_case[curr]=curr_case;
	//clear everything
	}
	action(ind+1);
	curr-=numbers[ind];
	curr_used[ind]=false;
}
int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		curr_case=i+1;
		found=false;
		scanf("%d", &n);
		for(int j = 0; j < n; ++j){
			scanf("%d", &numbers[j]);
		}
		printf("Case #%d:\n", curr_case);
		action(0);
		if(!found){
			printf("Impossible\n");
		}
	}
	return 0;
}
