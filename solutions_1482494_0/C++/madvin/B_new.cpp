#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=true)
    {reverse=revparam;}
  bool operator() (const pair<int,int>& lhs, const pair<int,int>&rhs) const
  {
    if (reverse) return (lhs.second>rhs.second);
    else return (lhs.second<rhs.second);
  }
};

#define PQ priority_queue<pair<int,int>, vector<pair<int,int> >, mycomparison>

int main() {
		int T,N;
		cin >> T;
		for ( int i = 1; i <= T; i++ ) {
				cin >> N;
				PQ s1,s2;
				int x1,x2;
				vector<int> status;
				for ( int j = 0; j < N; j++ ) {
					cin>>x1>>x2;
					s1.push(make_pair(j,x1));
					s2.push(make_pair(j,x2));
					status.push_back(0);
				}/*
				for ( int j = 0; j < N; j++ ) {
						cout << s1.top().second << " ";
						s1.pop();
				}
				cout << endl;*/
				int s = 0;
				int count = 0;
				pair<int,int> x;
				while (!s2.empty() && ( (!s1.empty() && s >= s1.top().second) || s >= s2.top().second )) {
					//cout << s << " " << s1.top().second << " " << s2.top().second << endl;
					if ( s >= s2.top().second ) {
						//cout <<"2 comes\n";
						x = s2.top();
						if ( status[x.first] == 0 ) {
							s+=2;
						}
						else {
							s+=1;
						}
						count++;
						status[x.first] = 2;
						s2.pop();
					}
					else if (s >= s1.top().second ) {
						//cout << "1 comes\n";
						x = s1.top();
						while(status[x.first] == 2) {
								s1.pop();
								x = s1.top();
						}
						if ( s >= x.second ) {
							//cout << "comes\n";
							s+= 1;
							s1.pop();
							status[x.first] = 1;
							count++;
						}
					}
				}
				if (s2.empty()) {
					printf("Case #%d: %d\n",i,count);
				}
				else {
						printf("Case #%d: Too Bad\n",i);
				}
		}
}
