
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std; 


struct sid{
	double pos;
	double speed;
	int line;
	int fixed;
};

struct tid{
	double t;
	int m;
	int n;
};

//large to small, structure
int compareS1(const void *arg1, const void *arg2) {
	if(( (*(sid *)arg1).pos < (*(sid *)arg2).pos ))
		return 1;
	else if(( (*(sid *)arg1).pos > (*(sid *)arg2).pos ))
		return -1;
	else
		return 0;
}
//qsort((void *)si, count, sizeof(sid), compareS1);


//small to large, structure
int compareS2(const void *arg1, const void *arg2) {
	if(( (*(tid *)arg1).t > (*(tid *)arg2).t ))
		return 1;
	else if(( (*(tid *)arg1).t < (*(tid *)arg2).t ))
		return -1;
	else
		return 0;
}
//qsort((void *)ti, count, sizeof(tid), compareS2);

//small to large, double
int compareD(const void *arg1, const void *arg2) {
	if(( *(double *)arg1 > *(double *)arg2 ))
		return 1;
	else if(( *(double *)arg1 < *(double *)arg2 ))
		return -1;
	else
		return 0;
}
//qsort((void *)dary, count, sizeof(double), compareD);

//small to large, long
int compareL(const void *arg1, const void *arg2) {
	if(( *(long *)arg1 > *(long *)arg2 ))
		return 1;
	else if(( *(long *)arg1 < *(long *)arg2 ))
		return -1;
	else
		return 0;
}
//qsort((void *)dary, count, sizeof(long), compareL);

//small to large, long long
int compareLL(const void *arg1, const void *arg2) {
	if(( *(long long *)arg1 > *(long long *)arg2 ))
		return 1;
	else if(( *(long long *)arg1 < *(long long *)arg2 ))
		return -1;
	else
		return 0;
}
//qsort((void *)dary, count, sizeof(long long), compareLL);





//Greatest Common Divisor, if a or b is equal or less than 0, return -1
int GCD(int a, int b)
{
	if(a<=0||b<=0)
		return -1;
		
	while(a!=b){
		if (a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
//Least Common Multiple, if a or b is equal or less than 0, return -1
int LCM(int a, int b)
{
	if(a<=0||b<=0)
		return -1;
		
	return a*b/GCD(a,b);
}

//Radical, sqrt(num)
//double mm=2.0;
//double nn=sqrt(mm);

//Power, pow(N,m)
//double xx=2.5;
//double yy=pow(2,xx);

//Permutation(m,n)
long long Perm(long long m,long long n){
	long long i;
	long long res=1;

	res=1;
	for(i=0;i<n;i++){
		res*=(m-i);
	}

	return res;
}
//long long po=Perm(7,2);

//Combination(m,n)
#define MAX_C 50
long long combination[MAX_C+1][MAX_C+1];
void Combpre(){
	for(int i=0;i<MAX_C+1;i++){
		combination[i][i]=combination[i][0]=1LL;
		for(int j=1;j<i;j++)
			combination[i][j]=combination[i-1][j]+combination[i-1][j-1];
	}
}

long long Comb(long long m,long long n){
	Combpre();
	return combination[m][n];
}
//long long co=Comb(7,2);

vector<char> Vmul(vector<char> a,vector<char> b){
	unsigned int i=0,j=0;
	int carry=0;
	vector<char> result(a.size()+b.size(),0);
	
	for(i=0;i<a.size();i++){
		carry=0;
		for(j=0;j<b.size();j++){
			result[i+j]+=a[i]*b[j];
			result[i+j]+=carry;
			carry=result[i+j]/10;
			result[i+j]-=carry*10;
		}
		if(carry>0){
			result[i+j]+=carry;
		}
	}
	while((result.size()>1)&&(result.back()==0)){
		result.pop_back();
	}
	return result;
}

vector<char> Vadd(vector<char> a,vector<char> b){
	unsigned int i=0,j=0;
	int carry=0;
	vector<char> result(a.size()>b.size()?a.size()+1:b.size()+1,0);
	
	carry=0;
	for(i=0;i<result.size();i++){
		result[i]+=(i<a.size()?a[i]:0)+(i<b.size()?b[i]:0);
		result[i]+=carry;
		carry=result[i]/10;
		result[i]-=carry*10;
	}
	while((result.size()>1)&&(result.back()==0)){
		result.pop_back();
	}
	return result;
}

vector<char> Vsquare(vector<char> a) {
	return Vmul(a,a);
}




#define MAX_LEN	1024

//get token length
int gettokenlen(char* str){
	int i;
	for(i=0;i<MAX_LEN;i++){

		if(str[i]==' '||str[i]=='\t')
			return i+1;

		if(str[i]=='\n'||str[i]=='\0')
			return i;
	}
	return 0;
}

int searchGE(int vines[][2],int N,int position){
	int begin=0,end=N-1,middle=(begin+end)/2;

	while(begin!=end){
		if(position>vines[middle][0])
			begin=middle+1;
		else
			end=middle;
		middle=(begin+end)/2;
	}

	return middle;
}

int searchLE(int vines[][2],int N,int position){
	int begin=0,end=N-1,middle=(begin+end+1)/2;

	while(begin!=end){
		if(position<vines[middle][0])
			end=middle-1;
		else
			begin=middle;
		middle=(begin+end+1)/2;
	}

	return middle;
}

bool next_iteration(long long a[],int n,long long min,long long max){
	for (int i=n-1;i>=0;i--){
		if (a[i] < max){
			a[i]++;
			return true;
		}
		a[i] = min;
	}
	return false;
}

int main() {
	long i=0,j=0,k=0;
	int T;

	char str[MAX_LEN];
	char *ps;

//	fstream fin("sample.in", ios::in);
	fstream fin("B-small-attempt4.in", ios::in);
//	fstream fin("B-large.in", ios::in);
	fstream fout("result.txt", ios::out);


	fin >> T;
	fin.getline(str,1024);
	ps=str;

	for (i=0;i<T;i++){

		long long E=0,R=0,N=0;

		fin>>E;
		fin>>R;
		fin>>N;
		fin.getline(str,1024);
		ps=str;

		long long value[N],spent[N];

		for(j=0;j<N;j++){
			fin>>value[j];
			spent[j]=0;
		}

		fin.getline(str,1024);
		ps=str;

		long long sum=0;

		do{
			long long current=E;
			bool valid=true;

			for(j=0;j<N;j++){
				current-=spent[j];
				if(current<0){
					valid=false;
					break;
				}
				current+=R;
				if(current>E){
					current=E;
				}
			}

			if(!valid) continue;

			long long total=0;
			for(j=0;j<N;j++)
				total+=value[j]*spent[j];
			sum=max(sum,total);
		}while(next_iteration(spent,N,0,E+1));

		fout << "Case #" << i+1 << ": " << sum << endl;
		cout << "Case #" << i+1 << ": " << sum << endl;
	}

	return 0;
}
