import sys
class wee():
	def __init__(self):
		self.seen={}

	def main(self, inp, out):
	    input = open(inp)
	    output = open(out,'w')
	    caseString=input.readline()
	    if caseString[-1:]=='\n':
		caseString=caseString[:-1]
	    numCases=int(caseString)
	    res=""
	    count = 0
	    for i in range(numCases):
		print count
		count += 1
		self.seen={}
		numbers=input.readline()	
		boxes = input.readline()	
		toys = input.readline()
		if boxes[-1] == "\n":
			boxes = boxes[:-1]
		if toys[-1] == "\n":
			toys = toys[:-1]	
		toyList = toys.split(" ")
		boxList = boxes.split(" ")
		for j in range(len(boxList)):
			boxList[j]=int(boxList[j])
		for j in range(len(toyList)):
			toyList[j]=int(toyList[j])	
	#	print toyList
	#	print boxList	
		res+="Case #"+str(i+1)+": "        	
		res+=str(self.toyBoxes(boxList,toyList,0,0,0))
		res+="\n"
	    output.write(res)
	    output.close()
	


	def toyBoxes(self, toys, boxes, res, subToys=0, subBoxes=0):
#		print self.seen
#		print "Res: ", res
#		print "Toys: ", toys
#		print "Boxess: ", boxes
#		print "\n"
		if toys == [] or boxes == []:
			return res
		toys[0]-=subToys
		boxes[0]-=subBoxes
		numToys=toys[0]
		typeToys = toys[1]
		numBoxes = boxes[0]
		typeBoxes = boxes[1]
		if (tuple(toys), tuple(boxes)) in self.seen:
	#		print seen
			return self.seen[(tuple(toys),tuple(boxes))]
		possible=0
		if typeBoxes == typeToys:
			if numToys < numBoxes:			
				possible= self.toyBoxes(toys[2:], boxes[:], res+numToys,subBoxes=numToys)
			elif numBoxes < numToys:
				possible= self.toyBoxes(toys[:], boxes[2:], res+numBoxes,subToys=numBoxes)
			else:
				possible= self.toyBoxes(toys[2:], boxes[2:], res+numBoxes)
			self.seen[(tuple(toys),tuple(boxes))]=possible
		else:
			self.seen[(tuple(toys),tuple(boxes))]= max(self.toyBoxes(toys[2:],boxes[:],res),self.toyBoxes(toys[:],boxes[2:],res))
		return self.seen[(tuple(toys),tuple(boxes))]
		
				
	
	
	
	
	if __name__=='__main__':
	    myClass = wee()
	    wee.main(sys.argv[0], sys.argv[1])
	
def test(input, out):
    myClass = wee()
    myClass.main(input, out)