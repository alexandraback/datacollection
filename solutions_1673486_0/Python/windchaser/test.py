# -*- coding: utf8 -*-
import os
import sys

if __name__ == "__main__":
	#input = open("A-sample.txt", "r");
	input = open("A-small-attempt.in", "r");
	#input = open("A-large.in", "r");
	output = open("A-output-small.txt", "w");
	
	caseMax = int(input.readline());
	
	for caseCounter in range(caseMax):
		buf = input.readline();
		buf = buf.split(" ");
		
		numOfTypedChars = int(buf[0]);
		numOfTotalChars = int(buf[1]);
		numOfRemains = numOfTotalChars - numOfTypedChars;

		buf = input.readline();
		buf = buf.split(" ");
		
		rateTypedRight = [];
		
		rateTypeRightAccu = [];
		rateAccumulated = [];
		
		varAccumulated = 0.0;
		
		caseEnterNow = 2 + numOfTotalChars;
		
		for loop in range(numOfTypedChars):
			rate = float(buf[loop]);
			rateTypedRight.append( rate );
			if(0 == loop):
				varAccumulated = rate;
			else:
				varAccumulated = rate * varAccumulated;
			rateAccumulated.append(varAccumulated);
		
		results = [];
		smallest = caseEnterNow;
		for loop in range(numOfTypedChars):
			keyStrokes = (numOfTypedChars - 1 - loop);
			keyStrokes = keyStrokes * 2 + numOfRemains;
			rate = (keyStrokes + 1) * rateAccumulated[loop];
			rate1 = (keyStrokes + 1) * rateAccumulated[loop];
			rate2 = (keyStrokes + numOfTotalChars + 2) * (1.0 - rateAccumulated[loop]);
			rate = rate + (keyStrokes + numOfTotalChars + 2) * (1.0 - rateAccumulated[loop]);
			if(smallest > rate):
				smallest = rate;
		
		strResult = "%.6f" % smallest;
		
		strCase = "Case #%d: " % (caseCounter + 1);
		
		print(strCase + strResult);
		output.write(strCase + strResult + "\r\n");
		
	print("done")