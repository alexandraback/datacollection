#include<iostream>
#include<stdio.h>
using namespace std;

long nPos[101], mPos[101];
long long nPosVal[101], mPosVal[101];
int n, m;

long check1(int x, int pos) {
	long curResult, maxResult = 0;
	curResult = 0;
	for(int j = 0; j < m; j++) {
        if(mPos[j] == x) curResult = min(nPosVal[pos], mPosVal[j]);  
        if(curResult > maxResult) maxResult = curResult;
	}
	return maxResult;
}

long check2(int x, int y, int pos1, int pos2) {
	long xResult, yResult, maxResult = 0;
	for(int j = 0; j < m; j++) {
      if(mPos[j] == x) {
	    xResult = min(nPosVal[pos1], mPosVal[j]);
		if(xResult > maxResult) maxResult = xResult;
		for(int k = j+1; k < m; k++) {
		    if(mPos[k] == y) {
				yResult = xResult + min(nPosVal[pos2], mPosVal[k]); 	
			    if(yResult > maxResult) 
					maxResult = yResult;
			}
		}
	  }
	}
	return maxResult;
}

long check3(int x, int y, int z, int pos0, int pos1, int pos2) {

  long xResult = 0, yResult = 0, zResult = 0, maxResult = 0;
	for(int j = 0; j < m; j++) {
		if(mPos[j] == x) {
			xResult = min(nPosVal[pos0], mPosVal[j]);
			if(xResult > maxResult) maxResult = xResult;
			for(int k = j+1; k < m; k++) {
				if(mPos[k] == y) {
					yResult = xResult + min(nPosVal[pos1], mPosVal[k]);
					if(yResult > maxResult ) 
						maxResult = yResult;
					
					for(int l = k+1; l < m; l++) {
						if(mPos[l] == z) {
							zResult = yResult + min(nPosVal[pos2], mPosVal[l]);
							if(zResult > maxResult)maxResult = zResult;	
						}
					}
				}
			}
		}
	}
	return maxResult;
}

int main() {
  int T, tPos = 1;
  cin >> T;
  while(T--) {
    cin >> n >> m; 
    for(int i = 0; i < n; i++) {
      cin >> nPosVal[i]; 
      cin >> nPos[i];
    }
  
    for(int i = 0; i < m; i++) {
      cin >> mPosVal[i] >> mPos[i];
    }

    long maxResult = 0, curResult; 

    if(n == 1) {
		maxResult = check1(nPos[0], 0);     
	
	}
    if(n == 2) {
		maxResult = check1(nPos[0], 0);
		if((curResult = check1(nPos[1], 1)) > maxResult) maxResult = curResult;
        if((curResult = check2(nPos[0], nPos[1], 0, 1)) > maxResult) maxResult = curResult;
	}
  
	if(n == 3) {
	   	maxResult = check1(nPos[0], 0);
		//cout << curResult << endl;
		if((curResult = check1(nPos[1], 1)) > maxResult) maxResult = curResult;
	//	cout << curResult << endl;
		if((curResult = check1(nPos[2], 2)) > maxResult) maxResult = curResult;
//cout << curResult << endl;
if((curResult = check2(nPos[0], nPos[1], 0 , 1)) > maxResult) maxResult = curResult;  
//		cout << curResult << endl;
		if((curResult = check2(nPos[0], nPos[2], 0 , 2)) > maxResult) maxResult = curResult;  
//		cout << curResult << endl;
		if((curResult = check2(nPos[1], nPos[2], 0 ,2)) > maxResult) maxResult = curResult;  
  //      cout << curResult << endl;
	if((curResult = check3(nPos[0], nPos[1], nPos[2], 0, 1 , 2)) > maxResult) maxResult = curResult;  
//	cout << curResult << endl;
	}
	 
	cout << "Case #" << tPos++ << ": " << maxResult << endl; 

  }

  return 0;
}
