#include<cmath>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long int mint;
typedef vector<mint> vi;
typedef vector<vi> vvi;

/*Input

The first line of the input gives the number of test cases, T. T lines follow. Each line contains two numbers, A and B - the endpoints of the interval Little John is looking at.
Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the number of fair and square numbers greater or equal to A and smaller or equal than B. 

*/

int log(mint n){
	if(n<0)throw "ugh";
	int i=0;
	while(n)
		i++,n/=10;
	return i;
}

bool pal_q(mint n){
	if(n%10==0)return n==0; //because m will stay 0 too long
	mint m=0;
	while(n>m){
		m*=10;
		m+=n%10;
		n/=10;
	}
	return n==m || (n==m/10);
}

//returns a number concatenated with its reverse
//so 1456 becomes 14566541
mint flip(mint const num){
	mint shift=1, result =0, copy=num;
	
	while(copy){
		result *= 10;
		result += (copy%10);
		copy/=10;
		shift*=10;
	}
	return shift*num+result;
}
//1456 becomes 1456541
mint flip1(mint num){
	mint shift=1, result =0, copy=num/10;
	
	while(copy){
		result *= 10;
		result += (copy%10);
		copy/=10;
		shift*=10;
	}
	return shift*num+result;
}

//smallest palindrome at least as big as n
mint mpal(double const n){
	int sz=std::log(n);
	mint rv;
	
	//halve the copy
	mint cpy=(mint)n;
	for(int i=sz/2;i-->0;)
		cpy/=10;
	
	if(sz%2){
		if(flip1(cpy)<n){
			rv=flip1(cpy+1);
			if(rv<n)
				cerr<<"can't find mpal of "<<n<<endl;
		}
	}else{
		rv=flip(cpy);
		if(rv<n)
			rv=flip(cpy+1);
	}
	return rv;
}

int testmain(){
	// mint n;
	// cin>>n;
	// cout<<mpal(n)<<endl;
	for(mint i=0;i<10000000;i++) //7 digits
		if(pal_q(i) && pal_q(i*i))
			cout<<i<<"\t"<<i*i<<"\t"<<i%11<<endl;
	return 0;
}

vi init(){
	istringstream answers ("0 1 4 9 121 484 10201 12321 14641 40804 44944 1002001 1234321 4008004 100020001 102030201 104060401 121242121 123454321 125686521 400080004 404090404 10000200001 10221412201 12102420121 12345654321 40000800004 1000002000001 1002003002001 1004006004001 1020304030201 1022325232201 1024348434201 1210024200121 1212225222121 1214428244121 1232346432321 1234567654321 4000008000004 4004009004004 100000020000001 100220141022001 102012040210201 102234363432201 121000242000121 121242363242121 123212464212321 123456787654321 400000080000004 10000000200000000 10002000300020000 10004000600040000 10020210401202000 10022212521222000 10024214841242000 10201020402010200 10203040504030200 10205060806050200 10221432623412200 10223454745432200 12100002420000100 12102202520220100 12104402820440100 12122232623222100 12124434743442100 12321024642012300 12323244744232300 12343456865434300 12345678987654300 40000000800000000 40004000900040000");
	vi rv;
	mint temp;
	while(answers>>temp)
		rv.push_back(temp);
	return rv;
}

int solve(mint a,mint b){
	//even palindromes should add up to 11.
	//odd palindromes don't have to.
	/*	criteria
		- it's a palindrome
		- square is a palindrome
		- it's at least sqrt(a)
		- it's at most sqrt(b)
	*/
	/*
		must have an even number of digits.
	*/
	
	
	//lol precomputation (code in testmain)
	static vi db = init();
	auto min=lower_bound(db.begin(),db.end(),a),  max=upper_bound(db.begin(),db.end(),b);
	return max-min;
}

int main(int argc, char** argv){
	try{
		ifstream fin; //file in
		istringstream sin("3 1 4 10 120 100 1000"); //string in
		istream * istream_ptr;
		if(argc >1){
			fin.open(argv[1]);
			istream_ptr = &fin;
		}
		else
			istream_ptr = &sin;
		
		istream& cin = *istream_ptr;
		
		ofstream cout("output.txt");
		int t;
		cin>>t;
		for(int i = 0; i<t; i++){
			cout<<"Case #"<<(i+1)<<": ";
			
			mint a,b;
			cin>>a>>b;
			
			cout<<solve(a,b);
			
			cout<<endl;
		}
		return 0;
	}catch(char const* s){
		cerr<<s<<endl;
	}
}
