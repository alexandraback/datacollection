def FirstNonTrivalDivider(n):
    for i in range(2,int(n**0.5)+2):
        if n % i == 0:
            return i;
    return 'DNE'

def StringToNumber(string_number, base):
    number = 0
    for i in range(len(string_number)):
        if string_number[i]=='1':
            number += base**(len(string_number)-i-1)
    return number

def NumberToBinaryString(n):
    binary = bin(n)
    return binary[2:]

    # input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
	n, j = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
	print("Case #{}:".format(i))
	coinjam = []
	for b1 in range(0,n-5):
	    for b2 in range(0,n-5-b1):
	        for b3 in range(0,n-5-b1-b2):
	            for b4 in range(0,n-5-b1-b2-b3):
	                if b1%2 + b2%2 + b3%2 + b4%2 == 0:
	                    a1 = b1 + 1
	                    a2 = a1 + b2 + 1
	                    a3 = a2 + b3 + 1
	                    a4 = a3 + b4 + 1
	                    bstring = NumberToBinaryString(2**(n-1)+2**a4+2**a3+2**a2+2**a1+1)
	                    coinjam += [bstring]
	count = 0
	for i in range(len(coinjam)):
	    bstring = coinjam[i]
	    dividers = []
	    for base in range(2,11):
	        number = StringToNumber(bstring,base)
	        divider = FirstNonTrivalDivider(number)
	        if divider == 'DNE':
	            break
	        else:
	            dividers += [divider]
	    if len(dividers)==9:
	        count += 1
	        outstring = bstring
	        for item in dividers:
	            outstring += ' %d' % item
	        print(outstring)
	        if count == j:
	            break
  # check out .format's specification for more formatting options