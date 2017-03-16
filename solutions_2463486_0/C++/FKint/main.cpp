#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

using namespace std;
/*long long palindrome_start;
long long palindrome_end;
*/
int digit_count(long long n){
	int counter = 0;
	while(n != 0){
		++counter;
		n/=10;
	}
	return counter;
}
int temp_stack[102];
int palindrome_digits[102];
bool is_palindrome(long long n){
	int length = 0;
	while(n!=0){
		temp_stack[length]=n%10;
		n/=10;
		++length;
	}
	for(int i = 0; i < length/2; ++i){
		if(temp_stack[length-i-1] != temp_stack[i])
			return false;
	}
	return true;
}
bool sq_is_palindrome[10000002];
long long check_palindromes(int index, int length){
	if(index == (length+1)/2){
		long long num = 0;
		for(int i = 0; i < index; ++i){
			num *= 10;
			num += palindrome_digits[i];
		}
		for(int i = index-((length%2==1)?2:1); i >= 0; --i){
			num *= 10;
			num += palindrome_digits[i];
		}
		/*if(num <palindrome_start)
			return 0;
		if(num > palindrome_end)
			return 0;*/
		if(num > 10000000)
			return 0;
		if(is_palindrome(num*num)){
			//printf("%lld*%lld=%lld is palindromic square\n", num, num, num*num);
			sq_is_palindrome[num]=true;
			return 1;
		}
		return 0;
	}
	long long counter = 0;
	for(int i = (index == 0)?1:0; i < 10; ++i){
		palindrome_digits[index]=i;
		counter += check_palindromes(index+1, length);
	}
	return counter;
}
int palindromes[10000002];
int main(){
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= 14; ++i){
		check_palindromes(0,i);
	}
	for(int i = 1; i <= 10000000; ++i){
		palindromes[i]=palindromes[i-1];
		if(sq_is_palindrome[i])
			++palindromes[i];
	}
	for(int curr_case = 1; curr_case <= T; ++curr_case){
		long long A, B;
		scanf("%lld%lld", &A, &B);
		long long counter=0;
		long long left = 0, right = min(A, 10000000ll);
		while(left != right){
			long long mid = (left+right)/2;
			long long sq = mid*mid;
			if(sq < A){
				left = mid+1;
			}else{
				right = mid;
			}
		}
		long long palindrome_start = right;
		left = 0; right = min(B, 10000000ll);
		while(left != right){
			long long mid = right-(right-left)/2;
			long long sq = mid*mid;
			if(sq<=B){
				left = mid;
			}else{
				right = mid-1;
			}
		}
		long long palindrome_end = left;
		/*int start_digit_count = digit_count(palindrome_start);
		int end_digit_count = digit_count(palindrome_end);
		for(int i = start_digit_count; i <= end_digit_count; ++i){
			counter += check_palindromes(0, i);
		}*/
		//printf("Case #%d: %lld\n", curr_case, counter);
		printf("Case #%d: %d\n", curr_case, palindromes[palindrome_end]-palindromes[palindrome_start-1]);
	}
    return 0;
}
