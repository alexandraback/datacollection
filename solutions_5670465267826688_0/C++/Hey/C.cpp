#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;


string operation(string a, char b){
	if (a == "1"){
		if (b == '1')
			return "1";
		else if (b == 'i')
			return "i";
		else if (b == 'j')
			return "j";
		else if (b == 'k')
			return "k";
	}
	else if (a == "i"){
		if (b == '1')
			return "i";
		else if (b == 'i')
			return  "-1";
		else if (b == 'j')
			return "k";
		else if (b == 'k')
			return "-j";
	}
	else if (a == "j"){
		if (b == '1')
			return "j";
		else if (b == 'i')
			return "-k";
		else if (b == 'j')
			return "-1";
		else if (b == 'k')
			return "i";
	}
	else if (a == "k"){
		if (b == '1')
			return "k";
		else if (b == 'i')
			return "j";
		else if (b == 'j')
			return "-i";
		else if (b == 'k')
			return "-1";
	}
	else if (a == "-1"){
		if (b == '1')
			return "-1";
		else if (b == 'i')
			return "-i";
		else if (b == 'j')
			return "-j";
		else if (b == 'k')
			return "-k";
	}
	else if (a == "-i"){
		if (b == '1')
			return "-i";
		else if (b == 'i')
			return  "1";
		else if (b == 'j')
			return "-k";
		else if (b == 'k')
			return "j";
	}
	else if (a == "-j"){
		if (b == '1')
			return "-j";
		else if (b == 'i')
			return "k";
		else if (b == 'j')
			return "1";
		else if (b == 'k')
			return "-i";
	}
	else if (a == "-k"){
		if (b == '1')
			return "-k";
		else if (b == 'i')
			return "-j";
		else if (b == 'j')
			return "i";
		else if (b == 'k')
			return "1";
	}
}

bool decomposition(char can[],int x,int l){
	int i = 0;
	string ji = "1";
	while (can[i]){
		ji = operation(ji,can[i]);
		if (ji=="i"&&i<x*l-2){
			int j = i + 1;
			string ji2 = "1";
			while (can[j]){
				ji2 = operation(ji2, can[j]);
				if (ji2 == "j"&&i<x*l-1){
					int k = j + 1;
					string ji3 = "1";
					while (can[k]){
						ji3 = operation(ji3, can[k]);
						k++;
					}
					if (ji3 == "k")
						return true;
				}
				j++;
			}
		}
		i++;
	}
	return false;
}


int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		//建立放数据的容器
		//建立数据的行列下标索引
		int L,X;
		scanf("%d %d", &L,&X);

		char can[10001] = {};
		char littlecan[10001] = {};
		scanf("%s", littlecan);
		for (int i = 0; i < X; i++)
			strcat(can, littlecan);
		string ji = "1";
		
		for (int i = 0; i < X*L; i++){
				ji = operation(ji, can[i]);
		}
		if (ji != "-1")
			printf("Case #%d: NO\n", t);
		else{
			if (decomposition(can, X, L))
				printf("Case #%d: YES\n", t);
			else
				printf("Case #%d: NO\n", t);
		}

		

	}
}