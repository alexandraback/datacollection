#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

#define ASCII_SPACE 32
#define ASCII_NEWLINE 10


using namespace std;




#define PRINT_TOKEN(token)\
	do{\
		cout<<#token<<" is "<<token<<endl; \
	}while(0)


#define READ(arg)\
	do{\
		long long arg;\
		cin>>arg;\
	}while(0)

//#define PRINT_ARR()
typedef long long ll;



int main()
{
	long long T;

	cin>>T;

	for(long long i=0;i<T;i++){

		long long result=0 ;
		int N;
		int Mi;
		vector<int> path[100][10];
		int npath[1000]={0};
		cin>>N;
		for(int a=0;a<N;a++){
			cin>>Mi;
			for(int b=0;b<Mi;b++){
				int val;
				cin>>val;
				path[a][b].push_back(val);
				npath[a]++;

				//if val is included in previous path, add it

				for(int d=0;d<a;d++){
					for(int e=0;e<npath[d];e++)
						if(path[d][e].back() == b+1 ){
							path[d][e].push_back(val);
						}
				}
			}
		}
		

		//show all path
		for(int a=0;a<N;a++){
			for(int b=0;b<npath[a];b++){
				cout<<"point"<<a+1<<"="<<endl;
				for(int v=0;v<path[a][b].size();v++){
					cout<<path[a][b][v]<<" ";
				}
				cout<<endl;
			}
		}

		cout<<"Case "<<"#"<<i+1<<": "<<result;
		cout<<endl;

	}
	return 0;
}


