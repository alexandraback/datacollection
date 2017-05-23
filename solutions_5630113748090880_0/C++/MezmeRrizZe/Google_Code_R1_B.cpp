#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int hei[2501];
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
int main(){ 
    ofstream fout("A.out"); 
	int cases;
	cin >> cases;
	int n;
	for ( int i = 0 ; i < cases ; i ++ ){
		cin >> n;
		int sum = 0;
		int ret[n];
		for ( int j = 0 ; j <= 2500 ; j ++ ){
			hei[j] = 0;
		}
		for ( int j = 0 ; j < n ; j ++ ){
			ret[j] = 0;
		}
		for ( int j = 0 ; j < 2 * n - 1 ; j ++ ){
			for ( int k = 0 ;  k < n ; k ++ ){
				int temp;
				cin >> temp;
				hei[temp] ++;
			}
		}
		for ( int j = 0 ; j <= 2500 ; j ++ ){
			if ( hei[j] & 2 != 0 ){
				ret[sum] = j;
				sum ++;
			}
		}
		quickSort(ret , 0 , n - 1);
		fout << "Case #" << i + 1 <<": " ;
		for ( int j = 0 ; j < n ; j ++ ){
			fout << ret[j] << " ";
		}
	
		fout << endl;
	}
	
	return 0;
}
