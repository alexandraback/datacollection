// develo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <utility>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <set>

#pragma comment(linker, "/STACK:67108864")

#define LL long long
#define fr(i,n) for(i=0;i<n;i++)
#define INF (2000000000)
#define FOR(n) for(int i = 0;i < n;i++)
#define CLEAR(x) memset(x,0,sizeof(x))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))

using namespace std;

int n;
int a[1000];
int b[1000];
bool aa[1000],bb[1000];

int main ()
{
	freopen("input.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int tt = 1;tt<=t;tt++){
		//CODE
		memset(aa,false,sizeof(aa));
		memset(bb,false,sizeof(bb));
		cin >> n;
		FOR(n){
			cin >> a[i] >> b[i];
		}
		bool tus,psb=true;
		int cnt=0,hid=0;
		while (true){
			psb=true;
			tus=false;
			FOR(n){
				if (!bb[i] && cnt >= b[i]){
					bb[i]=true;
					tus=true;
					if (!aa[i])
						cnt+=2;
					else
						cnt++;
					aa[i]=true;
					hid++;
					break;
				}
			}
			if (!tus){
				psb=false;
				int mps=-1;
				int mid;
			FOR(n){
				if (!aa[i] && cnt>=a[i] && b[i]>mps){
					mps=b[i];
					mid=i;
					psb=true;
				}
			}
			if (!psb)
				break;
			aa[mid]=true;
			cnt++;
			hid++;
			}
			if (!psb)
				break;
		}

		bool bad=false;
		FOR(n){
			if (!bb[i]){
				bad=true;
				break;
			}
		}

		//OUTPUT
		if (!bad)
		cout << "Case #" << tt<<": " << hid<<endl;
		else
		cout << "Case #" << tt<<": " << "Too Bad"<<endl;
	}

	return 0;
}