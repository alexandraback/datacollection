#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef struct {
	long long pos;
	long long revTime;
} hiker;

int main() {
	int numCases;
	cin >> numCases;
	
	hiker hikers[2];
	
	for(int x = 1; x <= numCases; x++) {
		int totalHikers = 0;
		bool hasGroups = false;
		long long sameSpeed = 0;
		
		int numGroups;
		cin >> numGroups;
		for(int g = 0; g < numGroups; g++) {
			long long position, numHikers, time;
			cin >> position >> numHikers >> time;
			if(numHikers > 1) {
				hasGroups = true;
			}
			for(long long y = time; y < time + numHikers; y++) {
				hikers[totalHikers].pos = position;
				hikers[totalHikers].revTime = y;
				if(y == sameSpeed || sameSpeed == 0) {
					sameSpeed = y;
				} else {
					sameSpeed = -1;
				}
				totalHikers++;
			}
		}
		if(hasGroups) {
			sameSpeed = -1;
		}
		
		if(totalHikers < 2 || sameSpeed > 0) {
			cout << "Case #" << x << ": 0\n";
			continue;
		}
		
		for(int i = 0; i < totalHikers - 1; i++) {
			for(int j = i + 1; j < totalHikers; j++) {
				if(hikers[i].pos > hikers[j].pos) {
					hiker temp;
					temp.pos = hikers[i].pos;
					temp.revTime = hikers[i].revTime;
					hikers[i].pos = hikers[j].pos;
					hikers[i].revTime = hikers[j].revTime;
					hikers[j].pos = temp.pos;
					hikers[j].revTime = temp.revTime;
				}
			}
		}
		
		long long time = (hikers[0].revTime * (360 - hikers[0].pos));
		long long time2 = (hikers[1].revTime * (360 + (360 - hikers[1].pos)));
		
		if(time2 <= time) {
			cout << "Case #" << x << ": 1\n";
		} else {
			long long time = (hikers[1].revTime * (360 - hikers[1].pos));
			long long time2 = (hikers[0].revTime * (360 + (360 - hikers[0].pos)));
			if(time2 <= time) {
				cout << "Case #" << x << ": 1\n";
			} else {
				cout << "Case #" << x << ": 0\n";
			}
		}
	}
}
