#include<bits/stdc++.h>
using namespace std;


const int SIZE = 100000000;

int  a[SIZE+1]={0};
int prime[SIZE+1];
int prefactor[SIZE+1]={0};

int p=1;
void generate(int y)
    {int i,j;
     prime[0]=2;
     for(int i=2;i<=y;i+=2)
      prefactor[i]=2;
     prefactor[1]=1;
     
	 for(i=3;i*i<=y;i+=2)
        {if(a[i])
          continue;
         prime[p++]=i;
         prefactor[i]=i;
		for(j=i*i;j<=y;j+=2*i)
           {a[j]=1;
            prefactor[j]=i;
           }
        }
        for(i;i<=y;i+=2)
          if(!a[i])
            {
			 prime[p++]=i;
			 prefactor[i]=i;
			} 
    }


int BITS;

string getBin(int x){
	int bit = BITS;
	vector<int> a(bit);
	a[0]=a[bit-1]=1;
	for(int i=bit-2;i>0;i--){
		a[i]=x%2;
		x/=2;
	}
	string s;
	for(int i=0;i<bit;i++){
		if(a[i])
			s+="1";
		else
			s+="0";
	}
	return s;
}

vector<long long> primeHash(11);

long long checkPrime(long long v){
	for(int i=0;i<p;i++){
		if(v%prime[i]==0)
			return prime[i];
	}
	return v;
}

bool test(string s){
	int bits = BITS;
	for(int base = 2;base<=10;base++){
		long long number = 0;
		long long v = 1;
		for(int i=bits-1;i>=0;i--){
			if(s[i]=='1'){
				number+=v;
			}
			v*=base;
		}
		long long pr = checkPrime(number);
		if(pr==number)
			return false;
		primeHash[base] = pr;
	}
	return true;
}

int main(){
     generate(SIZE);
	int t,J;
	cin>>t;
	cin>>BITS>>J;
	int c=0;
	int max = 1<<(BITS-2);
	cout<<"Case #"<<c+1<<": \n";
	
	for(int i=0;i<max;i++){
		string binary = getBin(i);
		if(c<J && test(binary)){
			cout<<binary<<" ";
			for(int base = 2;base<=10;base++)
				cout<<primeHash[base]<<" ";
			cout<<endl;
			c++;
		}
	}

}
