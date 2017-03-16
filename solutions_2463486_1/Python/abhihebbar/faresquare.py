import math;
import sys;

class PalindromeGen():
	def __init__(self,start):
		self.initForDigits( len(str(start)))
		while(self.get() < start):
			self.computeNext()
			# print 'Checking if ' + str(self.get()) + ' is OK';

	def initForDigits(self,newDigCount):
		self.nodigits = newDigCount
		if(self.nodigits > 2):
			self.current = [1] + [0]*(self.nodigits-2)  + [1]
		else:
			self.current = [1] * self.nodigits
		
		self.midIdx = int(math.ceil(self.nodigits/2));
		
	def computeNext(self):
		curDig = self.current[self.midIdx];
		
		if(curDig == 9):
			idx = self.midIdx
			while(curDig == 9):
				self.current[idx] = 0;
				self.current[self.nodigits - idx - 1] = 0;

				idx += 1
				
				if(idx >= self.nodigits):
					self.initForDigits(self.nodigits + 1);
					return;
				
				curDig = self.current[idx];
			self.current[idx] += 1;
			self.current[self.nodigits - idx - 1] = self.current[idx];
			return;

		self.current[self.midIdx] += 1;
		self.current[self.nodigits - self.midIdx - 1] = self.current[self.midIdx]; 


	def get(self):
		def toStr(i):
			return str(i)
		return int(''.join(map(toStr, self.current)));

def isPalindrome(no):
	noList = list(str(no))
	nolen = len(noList)
	for i in xrange(0,int(math.floor(nolen/2))):
		if(noList[i] != noList[nolen - i - 1]):
			return False;
	return True;

ip = open(sys.argv[1]);

noTestCases = int(ip.readline())

# print 'No of testcases: ', noTestCases

for i in range(noTestCases):
	tempArr = ip.readline().split(' ');
	start = int(tempArr[0])
	start = int(math.ceil(math.sqrt(start)))
	end = int(tempArr[1])
	end = int(math.floor(math.sqrt(end)))
	
	# print '\tTestCase : ', i+1
	# print '\t\tStart: ', start, ' End: ', end
	palGen = PalindromeGen(start);
	
	noCount = 0
	
	testNum = palGen.get()

	while (testNum <= end):
		# print '\t\tChecking with: ',testNum
		if(isPalindrome(testNum * testNum)):
			# print '\t\t\tWorked'
			noCount += 1;
		palGen.computeNext()
		testNum = palGen.get()

	print 'Case #' + str(i+1) + ': ' + str(noCount)