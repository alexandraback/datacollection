#include <iostream>
#include <string>

using namespace std;

const int length = 10000;
int A[length];
int B[length];
int C[length][length];



int testm (string set, int a, int b) {

	int res = 1;
	int flag = 0;

	for (int j=a; j<b+1; j++) {
		flag = 0;
		if (res<0) {
			res = -1*res;
			flag = 1;
		}
		if (res==1)
		{
			res = set[j]-'h'+1;
//			A[j]=1;
//			cout<<"here"<<endl;
		}
		else if(res==2 && set[j]=='i'){
			res = -1;
		}
		else if(res==2 && set[j]=='j'){
			res = 4;
		}
		else if(res==2 && set[j]=='k'){
			res = -3;
		}
		else if(res==3 && set[j]=='i'){
			res = -4;
		}
		else if(res==3 && set[j]=='j'){
			res = -1;
		}
		else if(res==3 && set[j]=='k'){
			res = 2;
		}
		else if(res==4 && set[j]=='i'){
			res = 3;
		}
		else if(res==4 && set[j]=='j'){
			res = -2;
		}
		else if(res==4 && set[j]=='k'){
			res = -1;
		}
		if (flag)
			res = -1*res;
	}

	if (res==3)
		return 1;


	return 0;
}

int main() {

	freopen("debug\\C-small-attempt1.in","r",stdin);
//	freopen("debug\\in.txt","r",stdin);
	freopen("debug\\out.txt","w",stdout);
	int testcases = 0;

	cin>>testcases;
	int len = 0;
	int rep = 0;
	string temp;
	string set;
	int fflag = 0;

	int flag = 0;
	int res = 0;

	int res2 = 0;

	for (int i=0; i<testcases; i++) {
		cin>>len;
		cin>>rep;
		cin>>temp;
		set = "";
		for (int ii=0; ii<rep; ii++){
			set+=temp;
		}
	
		memset(A,0,length*sizeof(int));
		memset(B,0,length*sizeof(int));
		
		for(int j=0; j<set.size(); j++) {
			for (int j1=0; j1<set.size(); j1++){
				C[j][j1] = 0;
			}
		}
		
//		cout<<set<<endl;
		
		//cout<<set.size()<<endl;;
		res = 1;

		for(int j=0; j<set.size(); j++){
			flag = 0;
			if (res<0) {
				res = -1*res;
				flag = 1;
			}
			if (res==1)
			{
				res = set[j]-'h'+1;
//				A[j]=1;
//				cout<<"here"<<endl;
			}
			else if(res==2 && set[j]=='i'){
				res = -1;
			}
			else if(res==2 && set[j]=='j'){
				res = 4;
			}
			else if(res==2 && set[j]=='k'){
				res = -3;
			}
			else if(res==3 && set[j]=='i'){
				res = -4;
			}
			else if(res==3 && set[j]=='j'){
				res = -1;
			}
			else if(res==3 && set[j]=='k'){
				res = 2;
			}
			else if(res==4 && set[j]=='i'){
				res = 3;
			}
			else if(res==4 && set[j]=='j'){
				res = -2;
			}
			else if(res==4 && set[j]=='k'){
				res = -1;
			}
			if (flag)
				res = -1*res;

			if (res == 2)
				A[j] = 1;

//			cout<<A[j];

		}


//		cout<<endl;

		res = 1;
		for(int j=set.size()-1; j>=0; j--){
			flag = 0;
			if (res<0) {
				res = -1*res;
				flag = 1;
			}
			if (res==1)
			{
				res = set[j]-'h'+1;
//				A[j]=1;
//				cout<<"here"<<endl;
			}
			else if(res==2 && set[j]=='i'){
				res = -1;
			}
			else if(res==2 && set[j]=='j'){
				res = -4;
			}
			else if(res==2 && set[j]=='k'){
				res = 3;
			}
			else if(res==3 && set[j]=='i'){
				res = 4;
			}
			else if(res==3 && set[j]=='j'){
				res = -1;
			}
			else if(res==3 && set[j]=='k'){
				res = -2;
			}
			else if(res==4 && set[j]=='i'){
				res = -3;
			}
			else if(res==4 && set[j]=='j'){
				res = 2;
			}
			else if(res==4 && set[j]=='k'){
				res = -1;
			}
			if (flag)
				res = -1*res;

			if (res == 4)
				B[j] = 1;
//			cout<<B[j];

		}



		res = 1;



		for (int j1=0; j1<set.size(); j1++)
			C[0][j1] = A[j1];

		for (int j1=0; j1<set.size(); j1++)
			C[j1][set.size()-1] = B[j1];

		for (int j1=0; j1<set.size(); j1++)
			C[j1][j1] = set[j1]-'h'+1;

		if (i==3)
			i=i;

		for(int j1=1; j1<set.size()-1; j1++){
			
			for(int j=j1+1; j<set.size()-1; j++){
				res = C[j1][j-1];
				flag = 0;
				if (res<0) {
					res = -1*res;
					flag = 1;
				}
				if (res==1)
				{
					res = set[j]-'h'+1;
	//				A[j]=1;
	//				cout<<"here"<<endl;
				}
				else if(res==2 && set[j]=='i'){
					res = -1;
				}
				else if(res==2 && set[j]=='j'){
					res = 4;
				}
				else if(res==2 && set[j]=='k'){
					res = -3;
				}
				else if(res==3 && set[j]=='i'){
					res = -4;
				}
				else if(res==3 && set[j]=='j'){
					res = -1;
				}
				else if(res==3 && set[j]=='k'){
					res = 2;
				}
				else if(res==4 && set[j]=='i'){
					res = 3;
				}
				else if(res==4 && set[j]=='j'){
					res = -2;
				}
				else if(res==4 && set[j]=='k'){
					res = -1;
				}
				if (flag)
					res = -1*res;


				C[j1][j]=res;
/*				if (res == 3)
					C[j1][j] = 1;
				if (i==3)
					cout<<C[j1][j];
*/
			}
//			if (i==3)
//				cout<<endl;

//			cout<<A[j];

		}



		cout<<"Case #"<<i+1<<": ";

		fflag = 0;

		if (i==1)
			i=i;

//		cout<<endl;
//		cout<<set.size();
		
		for (int ii=0; ii<set.size()-2; ii++) {
			for (int jj=ii+2; jj<set.size(); jj++) {
//				if (A[ii] && B[jj]&&testm(set,ii+1,jj-1)) {
				if (A[ii] && B[jj]&&C[ii+1][jj-1]==3) {
					cout<<"YES"<<endl;
					fflag = 1;
					break;
					

				}
			}
			if (fflag == 1)
				break;
			
		}

		if (!fflag)
			cout<<"NO"<<endl;
		


	}//end for testcases
	


	return 0;
}