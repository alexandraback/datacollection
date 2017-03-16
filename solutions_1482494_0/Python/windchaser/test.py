# -*- coding: utf8 -*-
import os
import sys

class LevelSet:
	def __init__(self, req, idx):
		self.req = req;
		self.idx = idx;
	def __lt__(self, other):
		return self.req < other.req;
		
if __name__ == "__main__":
	#input = open("B-sample.txt", "r");
	input = open("B-small-attempt.in", "r");
	#input = open("B-large.in", "r");
	output = open("B-output-small.txt", "w");
	
	caseMax = int(input.readline());
	
	for caseCounter in range(caseMax):
		
		numOfLevels = int(input.readline());
		
		level1set = [];
		level2set = [];
		
		for levelCounter in range(numOfLevels):
			buf = input.readline();
			buf = buf.split(" ");
			req1 = LevelSet(int(buf[0]), levelCounter);
			req2 = LevelSet(int(buf[1]), levelCounter);
			
			level1set.append(req1);
			level2set.append(req2);
			
		level1set.sort();
		level2set.sort();
		
		curStar = 0;
		counterCleared = 0;
		
		while(len(level2set) > 0):
			required = level2set[0].req;
			if(curStar >= required):
				curStar = curStar + 2;
				
				for item in level1set:
					if item.idx == level2set[0].idx:
						level1set.remove(item);
						break;
				#level2set.pop();
				level2set.remove(level2set[0]);
				counterCleared = counterCleared + 1;
			else:
				if(len(level1set) <= 0):
					break;
				required = level1set[0].req;
				if(curStar >= required):
					curStar = curStar + 1;
					level1set.pop();
					counterCleared = counterCleared + 1;
				else:
					break;

		
		if(len(level2set) > 0):
			strResult = "Too Bad";
		else:
			strResult = "%d" % counterCleared;
		
		strCase = "Case #%d: " % (caseCounter + 1);
		
		print(strCase + strResult);
		output.write(strCase + strResult + "\r\n");
		
	print("done");