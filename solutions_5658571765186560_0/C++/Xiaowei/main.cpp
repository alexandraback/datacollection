#include <iostream>
#include <vector>

using namespace std;

int graph[4][4];

vector<vector<int>> omi1;
vector<vector<int>> omi2;
vector<vector<int>> omi3;
vector<vector<int>> omi4;



int main() {

	


	freopen("debug\\D-small-attempt2.in","r",stdin);
//	freopen("debug\\in.txt","r",stdin);
	freopen("debug\\out.txt","w",stdout);
	int testcases;
	int X,R,C;


	vector<int> temp;
	temp.push_back(1);
	temp.push_back(1);
	omi1.push_back(temp);

	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	omi2.push_back(temp);

	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(3);
	omi3.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	omi3.push_back(temp);
	


	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(3);
	temp.push_back(1);
	temp.push_back(4);
	omi4.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(2);
	temp.push_back(2);
	omi4.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(3);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	omi4.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(3);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(2);
	omi4.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(2);
	omi4.push_back(temp);




	cin>>testcases;
	for (int i=0; i<testcases; i++) {
		
		cin>>X;
		cin>>R;
		cin>>C;
		cout<<"Case #"<<i+1<<": ";
//		memset(graph,0,16*sizeof(int));

		if (X==1){
			cout<<"GABRIEL"<<endl;
		}
		if(X==2){
			if ((R*C)%X!=0)
				cout<<"RICHARD"<<endl;
			else if (R==3&&C==3)
				cout<<"GABRIEL"<<endl;
			else if ((R>=2||C>=2)&&(!((R==3||R==1)&&(C==3||C==1))))
				cout<<"GABRIEL"<<endl;
			else
				cout<<"RICHARD"<<endl;
		}
		if(X==3){
			if ((R*C)%X!=0)
				cout<<"RICHARD"<<endl;
			else if (R<3&&C!=3)
				cout<<"RICHARD"<<endl;
			else if (C<3&&R!=3)
				cout<<"RICHARD"<<endl;
			else if (C==3&&R==1)
				cout<<"RICHARD"<<endl;
			else if (C==1&&R==3)
				cout<<"RICHARD"<<endl;
			else if (C==3&&R==2)
				cout<<"GABRIEL"<<endl;
			else if (C==2&&R==3)
				cout<<"GABRIEL"<<endl;
			else 
				cout<<"GABRIEL"<<endl;;




		}
		if(X==4){
			if ((R*C)%X!=0)
				cout<<"RICHARD"<<endl;
			else if (R<4&&(C!=4||R!=3))
				cout<<"RICHARD"<<endl;
			else if (C<4&&(R!=4||C!=3))
				cout<<"RICHARD"<<endl;
			else if (R==3&&C==4)
				cout<<"GABRIEL"<<endl;
			else if (R==4&&C==3)
				cout<<"GABRIEL"<<endl;
			else if (R==4&&C==4)
				cout<<"GABRIEL"<<endl;

		}
		


	}//end for cases
	

	return 0;
}