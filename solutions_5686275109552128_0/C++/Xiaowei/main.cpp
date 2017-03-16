#include <iostream>

#include <cmath>
#include <vector>
using namespace std;


vector<int> pan(1001);
//vector<int> pantemp(1001);

int rec = 0;
int main() {
	
	vector<int> pantemp;

	freopen("debug\\B-small-attempt5.in","r",stdin);
	freopen("debug\\out.txt","w",stdout);

	int testcases = 0;
	int npl = 0;
	int maxp = 0;     //max number of pancakes in a plate
	int temp = 0;
	int tt = 0;			//total
	int gap = 0,tempm = 0, temptt;
	int ttime = 0;		//total time consumed
	int tm = 0;			//temp max
	int flag = 0;
	int temptt2 = 0;

	int t1 = 0,t2 = 0;
	int tempt = 0;

	cin>>testcases;
	for (int i=0; i<testcases; i++) {
//		cout<<i+1<<endl;}
		flag = 0;
//		cout<<i+1<<endl;
		maxp = 0;
		tt = 0;
		ttime = 0;
		for (vector<int>::iterator itor = pan.begin(); itor!=pan.end(); itor++) {
			*itor = 0;
		}

		cin>>npl;


		for (int j=0; j<npl; j++) {
			cin>>temp;
			pan[temp]++;
			tt+=temp;
			if (maxp<temp)
				maxp = temp;
		} //for j empty plates

		ttime = maxp;

		for (int k=1; k<=maxp; k++) {							//i
			flag = 0;
			for (int kk=1; kk<=k; kk++){					//j
				tempt = 0;
				for(int kkk = 1; kkk<=maxp; kkk++) {		//sum
					tempt += (int)(((double)kkk-1)/kk)*pan[kkk];
				}
				if (tempt<=k-kk)
				{
					cout<<"Case #"<<i+1<<": "<<tempt+kk<<endl;
					flag = 1;
					break;
					
						
				}

			}//end for kk
			if (flag==1)
				break;
		}



	}





}