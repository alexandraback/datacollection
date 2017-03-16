
def ispalin(s) :
	return s == s[::-1] ;

def nextPalindrome(num):
    length=len(str(num))
    oddDigits=(length%2!=0)
    leftHalf=getLeftHalf(num)
    middle=getMiddle(num)
    if oddDigits:
        increment=pow(10, length/2)
        newNum=int(leftHalf+middle+leftHalf[::-1])
    else:
        increment=int(1.1*pow(10, length/2))
        newNum=int(leftHalf+leftHalf[::-1])
    if newNum>num:
        return newNum
    if middle!='9':
        return newNum+increment
    else:
        return nextPalindrome(roundUp(num))
 
def getLeftHalf(num):
    return str(num)[:len(str(num))/2]
 
def getMiddle(num):
    return str(num)[(len(str(num))-1)/2]
 
def roundUp(num):
    length=len(str(num))
    increment=pow(10,((length/2)+1))
    return ((num/increment)+1)*increment
		
		
Limit = 100000000000001;
Limit = int(pow(10,3)+1);
L = [];
n = 1; 
nsq = 1; 
while nsq < Limit :
	nsq = n*n ;
	if ispalin(str(nsq)) :
		L.append(nsq);
	n = nextPalindrome(n);

T = int(raw_input());
for t in range(1,T+1):
	ins = raw_input().split();
	A = int(ins[0]);
	B = int(ins[1]);
	count = 0 ;
	for j in L :
		if A <= j and j <= B :
			count = count + 1; 
	print "Case #" + str(t) + ": " + str(count) ;
