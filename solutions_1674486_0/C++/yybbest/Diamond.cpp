#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

#define FILEPRE "A-small-attempt0 (1)"
#define NN  50

int path[NN];
	int Mnum[NN];
	int M[NN][10];
void search(int n);



int main(void)
{
	char c;
	int i,j,k;
	int T=0;
	string result = "No";
	string tmp;


	string infilename(FILEPRE".in"), outfilename( FILEPRE".out");
	ifstream sr(infilename.c_str(),ios::in);
	ofstream sw(outfilename.c_str(),ios::out);
	if(!sr){
      cerr<<infilename<<" can't read!";
	  cin>>c;
	  exit(1);
	}
	if(!sw){
      cerr<<outfilename<<" can't read!";
	  cin>>c;
	  exit(1);
	}

    sr>>T;

	int N=0;
	//int Mnum[NN];
	//int M[NN][10];
	//int path[NN];
	bool isFound=false;
	int index=0;
	int next=0;

	for (int t = 1; t <= T; ++t)
	{

		sr>>N;
        for (int i = 0; i < N; ++i)
        {
              sr>>Mnum[i];
			  for (int j = 0; j < Mnum[i]; ++j)sr>>M[i][j];
        }

		isFound=false;
		int index=0;
		while(index<N){
			if(Mnum[index]<2){++index;continue;}
			for (int i = 0; i < N; ++i)path[i]=0;
			search(index);
			for (int i = 0; i < N; ++i)
		    {
				if(path[i]>=2)
				{
					isFound=true;
				}
		    }
			if(isFound)break;else ++index;
		}
		if(isFound)result="Yes";else result="No";
		cout<<"Now:"<<t<<endl;
		sw<<"Case #"<<t<<":"<<" "<<result;
		sw<<endl;
	}


	return 0;
}

void search(int n)
{
	++path[n];
	if(Mnum[n]==0)
	{
		return;
	}
	for (int j = 0; j < Mnum[n]; ++j)
	{
		search(M[n][j]-1);
	}
}
