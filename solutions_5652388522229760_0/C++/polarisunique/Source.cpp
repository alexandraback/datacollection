// Example program
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream myfile("A-small-attempt2.in.txt");
	ofstream file("out.txt");
	int n;
	myfile >> n;
	for (int i = 0; i < n; i++){
		int temp;
		myfile >> temp;
		if (temp == 0){
			file << "Case #" << i+1 << ": " << "INSOMNIA" << endl;
			continue;
		}
		int arr[10];
		for (int a = 0; a < 10; a++){
			arr[a] = 0;
		}
		int count = 0;
		int j = 1;
		while (count < 10){
			int t = temp * j;
			while (t != 0){
				int k = t % 10;
				if (arr[k] == 0){
					arr[k] = 1;
					count++;
				}
				t = t / 10;
			}
			j++;
		}
		file << "Case #" << i + 1 << ": " << temp * (j-1) << endl;
	}
}
