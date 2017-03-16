#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int getMod(char * str, int N, int base, int divBy){
    int mod = 0;
    
    for(int i=N-1;i>=0;i--){
        long long int modAdd = (str[i]-'0');
        for(int j=1;j<N-i;j++){
            modAdd*=base;
            modAdd%=divBy;
        }
        mod = (mod+modAdd)%divBy;
    }
    
    return mod;
}

void addOne(char * str, int N){
    int i=N-1;
    for(;str[i]=='1';i--){
        str[i]='0';
    }
    str[i]='1';
}

void addThree(char * str, int N){
    for(int i=0;i<6;i++) addOne(str,N);
}

int * eratosten(int size, int * numP){
    int * nums = new int[size];
    for(int i=0;i<size;i++) nums[i]=1;
    nums[0]=nums[1]=0; int numPrimes = 0;
    for(int i=0;i<size;i++){
        if(nums[i]==0) continue;
        numPrimes++;
        for(int j=i<<1;j<size;j+=i){
            nums[j]=0;
        }
    }
    
    int * primes = new int[numPrimes];
    int p = 0;
    for(int i=0;i<size;i++){
        if(nums[i]==0) continue;
        primes[p++]=i;
    }
    *numP = numPrimes;
    
    return primes;
}

void doThings(int N, int J, int numCase){
    cout << "Case #" << numCase << ":" << endl;
    
    int divArrayLen;
    int * divArray = eratosten(10000,&divArrayLen);
    
    long long int startingPoint = pow(2,N-1) + 1;
    startingPoint += 3-startingPoint%3;
    if(startingPoint%2==0) startingPoint+=3;
    char * str = new char[N+1];
    str[N]='\0';
    int pos = N-1;
    while(pos>=0){
        str[pos] = ('0'+startingPoint%2);
        startingPoint /= 2;
        pos--;
    }
    
    int doneCoins = 0;
    while(doneCoins < J && str[0]=='1'){
        addThree(str, N);
        int isCoin = 1;
        int * divBy = new int[9];
        for(int i=2;i<=10;i++){
            int isComposite = 0;
            for(int j=0;j<divArrayLen;j++){
                if(getMod(str,N,i,divArray[j])==0) {isComposite=1; divBy[i-2]=divArray[j]; break;}
            }
            isCoin *= isComposite;
        }
        
        if(isCoin){
            cout << str;
            for(int i=2;i<=10;i++){
                cout << " " << divBy[i-2];
            }
            cout << endl;
            
            doneCoins++;
        }
    }
}

int main() {
	int T;

	cin >> T;

	int sum = 0;
	for (int i = 0; i < T; i++) {
		int N, J;
		cin >> N >> J;

		doThings(N, J, i+1);
	}

	return 0;
}