#include <iostream>
#include <math.h>

//YOLO
//code by loyolman

using namespace std;

int main() {
	int T;
	cin>>T;
	for (int j=1;j<=T;j++) {
		int C,R,W;
		int answer=0;
		cin>>R>>C>>W;
		answer+=(C/W-1)*R;
		answer+=R;
		if (C%W>0) answer+=1;//bad choice of side
		answer+=W-1;
		cout<<"Case #"<<j<<": "<<answer<<endl;
	}
	return 0;
}
