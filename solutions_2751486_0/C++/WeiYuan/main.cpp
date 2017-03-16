
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <gmpxx.h> // could be downloaded from http://gmplib.org/
#include <unordered_map>
#include <sstream>

using namespace std; 

#define PRINT(array,length) {for(int i=0;i<length;i++){cout << array[i] << " ";} cout << endl;}
#define LL long long
#define INT mpz_class
#define MAP unordered_map

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

//Permutation(m)
#define MAX_P 20
long long permutation[MAX_P+1];
bool needPermpre=true;
void Permpre(){
	permutation[0]=1;
	for(long long i=1;i<MAX_P+1;i++){
		permutation[i]=i*permutation[i-1];
	}
}

long long Perm(long long m){
	if(needPermpre){
		Permpre();
		needPermpre=false;
	}
	return permutation[m];
}
//long long po=Perm(7);

//Combination(m,n)
#define MAX_C 50
long long combination[MAX_C+1][MAX_C+1];
bool needCombpre=true;
void Combpre(){
	for(int i=0;i<MAX_C+1;i++){
		combination[i][i]=combination[i][0]=1LL;
		for(int j=1;j<i;j++)
			combination[i][j]=combination[i-1][j]+combination[i-1][j-1];
	}
}

long long Comb(long long m,long long n){
	if((m<0)||(n<0)) return 0;
	if(m<n) return 0;
	if(needCombpre){
		Combpre();
		needCombpre=false;
	}
	return combination[m][n];
}
//long long co=Comb(7,2);

//Combination(m,n)
#define MAX_C_MPZ 3000
mpz_class combination_mpz[MAX_C_MPZ+1][MAX_C_MPZ+1];
bool needCombpre_mpz=true;
void Combpre_mpz(){
	for(int i=0;i<MAX_C_MPZ+1;i++){
		combination_mpz[i][i]=combination_mpz[i][0]=1;
		for(int j=1;j<i;j++)
			combination_mpz[i][j]=combination_mpz[i-1][j]+combination_mpz[i-1][j-1];
	}
}

mpz_class Comb_mpz(long m,long n){
	if((m<0)||(n<0)) return 0;
	if(m<n) return 0;
	if(needCombpre_mpz){
		Combpre_mpz();
		needCombpre_mpz=false;
	}
	return combination_mpz[m][n];
}
//mpz_class co=Comb_mpz(7,2);

mpf_class pow_mpf(mpf_class f,long long pow){
	mpf_class a=1.0;
	while(pow>0){
		if(1==(pow%2)) a*=f;
		f*=f;
		pow/=2;
	}
	return a;
}

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

LL searchGE(LL vines[][2],LL N,LL position){
	LL begin=0,end=N-1,middle=(begin+end)/2;

	while(begin!=end){
		if(position>vines[middle][0])
			begin=middle+1;
		else
			end=middle;
		middle=(begin+end)/2;
	}

	return middle;
}

LL searchLE(LL vines[][2],LL N,LL position){
	if(vines[0][0]>position) return 0;

	LL begin=0,end=N-1,middle=(begin+end+1)/2;

	while(begin!=end){
		if(position<vines[middle][0])
			end=middle-1;
		else
			begin=middle;
		middle=(begin+end+1)/2;
	}

	return middle;
}

string Str(long long i){
	stringstream s;
	s<<i;
	return s.str();
}

mpz_class Int(long long i){
	mpz_class a(Str(i));
	return a;
}

bool next_iteration(long long a[],int n,long long min,long long max){
	for(int i=n-1;i>=0;i--){
		if(a[i]<max){
			a[i]++;
			return true;
		}
		a[i]=min;
	}
	return false;
}

bool next_iteration_sorted(long long a[],int n,long long max){
	for(int i=n-1;i>=0;i--){
		if(a[i]<max){
			a[i]++;
			for(int j=i+1;j<n;j++) a[j]=a[i];
			return true;
		}
	}
	return false;
}

int main(){
	LL i=0,j=0,k=0;
	LL T,L,N;

	char str[MAX_LEN];
	char *ps;

//	fstream fin("sample.in", ios::in);
	fstream fin("A-small-attempt1.in", ios::in);
//	fstream fin("A-large.in", ios::in);
	fstream fout("result.txt", ios::out);

	//double precision
	//fout.setf(ios::fixed);
	//fout.precision(6);

	fin>>T;
	fin.getline(str,1024);
	ps=str;

	MAP<char,bool> vowel;
	vowel['a']=true;
	vowel['e']=true;
	vowel['i']=true;
	vowel['o']=true;
	vowel['u']=true;

	for(i=0;i<T;i++){

		string name;
		fin>>name;
		name += "a";
		L=name.size();
		fin>>N;
		fin.getline(str,1024);
		ps=str;

		LL consecutive[L][2];
		LL M=0,begin=0,end=0;

		while(begin<L-N+1){
			if(vowel.find(name[begin])!=vowel.end()){
					begin++;
					continue;
				}
			end=begin+1;
			while(vowel.find(name[end])==vowel.end()) end++;
			if(end-begin>=N){
				consecutive[M][0]=begin;
				consecutive[M][1]=end-1;
				M++;
			}
			begin=end;
		}

//		for(j=0;j<M;j++){
//			cout << "(" << consecutive[j][0] << "," << consecutive[j][1] << ")" << endl;
//		}

		LL count=0;

		if(0!=M)for(j=0;j<=consecutive[M-1][1]-N+1;j++){
			LL index=searchLE(consecutive, M, j);
			begin=consecutive[index][0];
			end=consecutive[index][1];
//			cout << "j:" << j << "; index: " << index << "; begin: " << begin << "; end: " << end << endl;
			if(end-j+1>=N){
				count+=(L-max(begin,j)-N);
//				cout << "count: " << count << endl;
				continue;
			}
			begin=consecutive[index+1][0];
			end=consecutive[index+1][1];
			count+=(L-max(begin,j)-N);
		}

		fout << "Case #" << i+1 << ": " << count << endl;
		cout << "Case #" << i+1 << ": " << count << endl;
	}

	return 0;
}
