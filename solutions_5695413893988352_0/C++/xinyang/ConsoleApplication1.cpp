// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include<set>
#include<stack>
#include<cstdio>
#include <unordered_map>
#include <functional>
#define PI 3.14159265
using namespace std;

long long mindif = 1e18;

void update(string c1, string c2, string& a1, string& a2){
	if (abs(stoi(c1) - stoi(c2)) < mindif){
		a1 = c1;
		a2 = c2;
		mindif = abs(stoi(c1) - stoi(c2));
	}
	else if (abs(stoi(c1) - stoi(c2)) == mindif){
		if (c1 < a1){
			a1 = c1;
			a2 = c2;
		}
		else if (c1 == a1 && c2 < a2){
			a1 = c1;
			a2 = c2;
		}
	}
}


int main() {

	std::ios_base::sync_with_stdio(false);
	


	ifstream fin;
	fin.open("B-small-attempt1.in");
	ofstream fout;
	fout.open("B-small-attempt1.out");
	int t;
	fin >> t;
	for (int T = 1; T <= t; T++){
		fout << "Case #" << T << ": ";

		string s1, s2;
		fin >> s1 >> s2;
		int l = s1.length();
		string a1="", a2="";
		int start = 0;
		cout << T << endl;
		mindif = 1e18;
		while (true){
			cout << "T " << a1 << " " << a2 << endl;
			int real = start;
			for (; start < l; start++){
				if (!(s1[start] == '?' && s2[start] == '?')) break;
			}
			for (; real < start - 1; real++){
				s1[real] = '0';
				s2[real] = '0';
			}
			if (start == l){
				if(s1[l-1]=='?') s1[l-1] = '0';
				if (s2[l - 1] == '?') s2[l - 1] = '0';
				a1 = s1;
				a2 = s2;
				break;
			}
			if (s1[start] == '?')
			{
				//small part
				if (s2[start] == '0' && start-real>=1){
					string c1 = s1, c2 = s2;	
					c1[start - 1] = '0';
					c2[start - 1] = '1';
					for (int i = start; i < l; i++){
						if (c1[i] == '?') c1[i] = '9';
						if (c2[i] == '?') c2[i] = '0';
					}
			
					update(c1, c2, a1, a2);
				}
				else if(s2[start] != '0'){
					string c1 = s1, c2 = s2;
		
					if (start>real)
					{
						c1[start - 1] = '0';
						c2[start - 1] = '0';
					}
					c1[start] = c2[start] - 1;
					for (int i = start+1 ; i < l; i++){
						if (c1[i] == '?') c1[i] = '9';
						if (c2[i] == '?') c2[i] = '0';
					}
					
					update(c1, c2, a1, a2);
				}

				//large part
				if (s2[start] == '9' && start - real >= 1){
					string c1 = s1, c2 = s2;
					c1[start - 1] = '1';
					c2[start - 1] = '0';
					for (int i = start; i < l; i++){
						if (c1[i] == '?') c1[i] = '0';
						if (c2[i] == '?') c2[i] = '9';
					}
					update(c1, c2, a1, a2);
				}
				else if (s2[start] != '9'){
					string c1 = s1, c2 = s2;
					if (start>real)
					{
						c1[start - 1] = '0';
						c2[start - 1] = '0';
					}
					c1[start] = c2[start] + 1;
					for (int i = start + 1; i < l; i++){
						if (c1[i] == '?') c1[i] = '0';
						if (c2[i] == '?') c2[i] = '9';
					}
					update(c1, c2, a1, a2);
				}
				//equal part
				{
					if (start>real)
					{
						s1[start - 1] = '0';
						s2[start - 1] = '0';
					}
					s1[start] = s2[start];
					start++;
				}
			}
			else if (s2[start] == '?')
			{
				//small part
				if (s1[start] == '9' && start - real >= 1){
					string c1 = s1, c2 = s2;
					c1[start - 1] = '0';
					c2[start - 1] = '1';
					for (int i = start; i < l; i++){
						if (c1[i] == '?') c1[i] = '9';
						if (c2[i] == '?') c2[i] = '0';
					}
					update(c1, c2, a1, a2);
				}
				else if (s1[start] != '9'){
					string c1 = s1, c2 = s2;
					if (start>real)
					{
						c1[start - 1] = '0';
						c2[start - 1] = '0';
					}
					c2[start] = c1[start] + 1;
					for (int i = start + 1; i < l; i++){
						if (c1[i] == '?') c1[i] = '9';
						if (c2[i] == '?') c2[i] = '0';
					}
					update(c1, c2, a1, a2);
				}

				//large part
				if (s1[start] == '0' && start - real >= 1){
					string c1 = s1, c2 = s2;
					c1[start - 1] = '1';
					c2[start - 1] = '0';
					for (int i = start; i < l; i++){
						if (c1[i] == '?') c1[i] = '0';
						if (c2[i] == '?') c2[i] = '9';
					}
					update(c1, c2, a1, a2);
				}
				else if (s1[start] != '0') {
					string c1 = s1, c2 = s2;
					if (start>real)
					{
						c1[start - 1] = '0';
						c2[start - 1] = '0';
					}
					c2[start] = c1[start] - 1;
					for (int i = start + 1; i < l; i++){
						if (c1[i] == '?') c1[i] = '0';
						if (c2[i] == '?') c2[i] = '9';
					}
					update(c1, c2, a1, a2);
				}
				//equal part
				{
					if (start>real)
					{
						s1[start - 1] = '0';
						s2[start - 1] = '0';
					}
					s2[start] = s1[start];
					start++;
				}
			}
			else{

				//large part
				if (s1[start] > s2[start]){
					string c1 = s1, c2 = s2;
					if (start>real)
					{
						c1[start - 1] = '0';
						c2[start - 1] = '0';
					}
					for (int i = start + 1; i < l; i++){
						if (c1[i] == '?') c1[i] = '0';
						if (c2[i] == '?') c2[i] = '9';
					}
					update(c1, c2, a1, a2);

					c1 = s1, c2 = s2;
					if (start>real)
					{
						c1[start - 1] = '0';
						c2[start - 1] = '1';
						for (int i = start + 1; i < l; i++){
							if (c1[i] == '?') c1[i] = '9';
							if (c2[i] == '?') c2[i] = '0';
						}
						update(c1, c2, a1, a2);
					}
					break;
				}
				//small part
				else if(s1[start] < s2[start]){
					string c1 = s1, c2 = s2;
					if (start>real)
					{
						c1[start - 1] = '0';
						c2[start - 1] = '0';
					}
					for (int i = start + 1; i < l; i++){
						if (c1[i] == '?') c1[i] = '9';
						if (c2[i] == '?') c2[i] = '0';
					}
					update(c1, c2, a1, a2);

					c1 = s1, c2 = s2;
					if (start>real)
					{
						c1[start - 1] = '1';
						c2[start - 1] = '0';
						for (int i = start + 1; i < l; i++){
							if (c1[i] == '?') c1[i] = '0';
							if (c2[i] == '?') c2[i] = '9';
						}
						update(c1, c2, a1, a2);
					}
					break;
				}
				//equal part
				else{
					if (start>real)
					{
						s1[start - 1] = '0';
						s2[start - 1] = '0';
					}
					start++;
				}
			}
			
		}
		fout << a1 << " " << a2 << endl;

	}
	
	system("PAUSE");
	return 0;
}