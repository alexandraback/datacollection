/*
 * =====================================================================================
 *
 *       Filename:  tic-tac.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 13 April 2013 10:08:01  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
int main(){
	int T, R, N, M, K;
	cin >> T;
	cin >> R >> N >> M >> K;
	cout << "Case #1:" << endl;
	for(int r=0;r<R;r++){
		vector<int> I;
		for(int j=0;j<K;j++){
			int t;
			cin >> t;
			I.push_back(t);
		}
		int mxc, mxi,mxj,mxk;
		mxc=mxi=mxj=mxk=-1;
		for(int i=2;i<=M;i++){
			for(int j=i;j<=M;j++){
				for(int k=j;k<=M;k++){
					int cnt = 0;
					int N = I.size();
					for(int ii=0;ii<N;ii++){
						if(i*j*k == I[ii] || i*j == I[ii] || j*k == I[ii] || i*k == I[ii] || i== I[ii] || j==I[ii] || k == I[ii]) cnt++;
					}
					if( cnt > mxc){
						mxc = cnt;
						mxi=i;mxj=j;mxk=k;
					}
				}
			}
		}
		cout << mxi << mxj << mxk << endl;
	}

	return 0;
}
