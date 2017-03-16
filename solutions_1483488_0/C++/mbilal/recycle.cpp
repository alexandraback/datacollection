#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
//#define DEBUG
using namespace std;

int main()
{
	int t;
	freopen("ip.txt", "r", stdin);
	freopen("op.txt", "w", stdout);
	scanf("%d\n",&t);
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		long int a, b;
		scanf("%ld %ld\n", &a, &b);
		vector<bool> arr;
		long long int count = 0;
		for(int i=a; i<=b; i++)
			arr.push_back(true);
		
		for(int i=0; i<=b-a; i++){
			if(arr[i] == false){
				#ifdef DEBUG
					printf("\nleaving %d\n", i+a);
				#endif
				continue;
			}
			int num = i+a;			
			char str[10];
			sprintf(str, "%d", num);
			int numdigit = strlen(str);
			string cppstr = str;
			int permute = 0;
			for(int r = 1; r<numdigit; r++){
				rotate(cppstr.begin(),cppstr.begin()+1,cppstr.end());
				strcpy(str, cppstr.c_str());
				num = atoi(str);
				if(num > a && num <= b && num != i+a){
					if(arr[num - a]){
						permute++;
						arr[num - a] = false;
					}					
				}
				#ifdef DEBUG
					printf("permutation of %d is %d ", i+a, num);
				#endif
			}
			count += (((permute*(permute+1))/2));
			#ifdef DEBUG
				printf("\n Count = %ld", count);
			#endif
		}
		printf("%lld\n", count);
	}
	return 0;
}	
	
	