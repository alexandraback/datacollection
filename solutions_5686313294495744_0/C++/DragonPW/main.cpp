#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define FORI(A,B,C) for(int I=(A);I<=(B); I++)
#define FORLL(A,B,C) for(LL I=(A);I<=(B); I++)
#define VLL vector<LL>
#define VVLL vector<vector<LL>>
#define VI vector<int>
#define VVI vector<vector<int>>

#define showv(A) for(auto &x:A){cout<<x<<" ";}cout<<endl;

//int help(vector<string> A,vector<string> B,int N){
//	int sz=A.size();
//	set<string> As,Bs;
//	for (int i=0;i<N-1;i++){
//		As.insert(A[i]);
//		Bs.insert(B[i]);
//	}
//	if (As.find(A[N-1])!=As.end() && Bs.find(B[N-1])!=Bs.end())
//	return -1;
//}

int help(int curFake,vector<string> &A,vector<string> &B,int Acnt, int Bcnt,
		set<string> &Aset, set<string> &Bset,
		unordered_map<string,int> &Amap, unordered_map<string,int> &Bmap,
		int i, int N){
	int res1=-1,res2=-1;
	if (Aset.size()==Acnt && Bset.size()==Bcnt) return curFake+N-i;
	if (i==N) return INT_MIN;
	if ((Amap[A[i]]>1 || Aset.find(A[i])!=Aset.end()) && (Bmap[B[i]]>1 || Bset.find(B[i])!=Bset.end())) {
		Amap[A[i]]--;
		Bmap[B[i]]--;
		res1 = help(curFake+1,A,B,Acnt,Bcnt,Aset,Bset,Amap,Bmap,i+1,N);
		Amap[A[i]]++;
		Bmap[B[i]]++;
	}
	bool a1=0,b1=0;
	if (Aset.find(A[i])==Aset.end()){
		Aset.insert(A[i]);
		a1=1;
	}
	if (Bset.find(B[i])==Bset.end()){
		Bset.insert(B[i]);
		b1=1;
	}
	res2 = help(curFake,A,B,Acnt,Bcnt,Aset,Bset,Amap,Bmap,i+1,N);
	if (a1) Aset.erase(A[i]);
	if (b1) Bset.erase(B[i]);

	return max(res1,res2);
}

int fun(vector<string> A,vector<string> B, int N){

    vector<bool> flag(N,-1);
	int res=0;
	unordered_map<string,int> Amap,Bmap;
	set<string> Aset,Bset;
	for (int i=0;i<N;i++){
		Amap[A[i]]++;
		Bmap[B[i]]++;
		Aset.insert(A[i]);
		Bset.insert(B[i]);
	}
	int Acnt = Aset.size(),Bcnt = Bset.size();
	Aset.clear();
	Bset.clear();
	return help(0,A,B,Acnt,Bcnt,Aset,Bset,Amap,Bmap,0,N);
}



int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("Input.txt");
    ofile.open("Output.txt");

    int CaseIdx,TotalCase;
    string line;
    getline(ifile,line);
    stringstream ss(line);
    ss>>TotalCase;

    for (CaseIdx = 1; CaseIdx<=TotalCase; CaseIdx++)
    {
//  begin of code
  //  1. prepare data for current test case
    	vector<string> A,B;
    	LL N;


		string line;
		{getline(ifile,line);stringstream ss(line);ss>>N;}
		{
			for (int i=0;i<N;i++)
			{getline(ifile,line);stringstream ss(line);
			string temp;
			ss>>temp;A.push_back(temp);
			ss>>temp;B.push_back(temp);
			}
		}

  //  2. data_pre_processing if possible. (significantly reduced time/space complextity

  //  3. data_processing to get the result
		//int res = fun(A,B,C);
		int res = fun(A,B,N);

  //  4. Output results;
		string caseResult="";
		caseResult += to_string(res);

    	cout<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;
    	ofile<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;

// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

