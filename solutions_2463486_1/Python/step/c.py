import os
import sys

def is_palindrom(s):
	return s == s[::-1]

assert is_palindrom("12321")
assert not is_palindrom("012321")

def isqrt(n):  
    xn = 1  
    xn1 = (xn + n/xn)/2  
    while abs(xn1 - xn) > 1:  
        xn = xn1  
        xn1 = (xn + n/xn)/2  
    while xn1*xn1 > n:  
        xn1 -= 1  
    return xn1 

def get_next_palindrome(strn):
	l = len(strn)
	if l <= 1:
		n = int(strn)
		if n < 9:
			return str(n+1)
		else:
			return "11"

	# print "len", l
	leftpart = strn[0:l/2]

	if l%2 == 0:
		mid = ""
		rightpart = strn[l/2:]
	else:
		mid = strn[l/2]
		rightpart = strn[l/2+1:]

	# print "leftpart",leftpart, "mid",mid,"rightpart",rightpart
	# print "rightpart",rightpart
	revleftpart = leftpart[::-1]
	origleftpart = leftpart

	if rightpart >= revleftpart:
		if mid != '' and mid in "012345678":
			mid = str(int(mid)+1)
		elif mid == '9':
			mid = '0'
			leftpart = str( int(leftpart) + 1 )
			if len(leftpart) != len(origleftpart):
				mid = ''
		else:
			leftpart = str( int(leftpart) + 1 )
			if len(leftpart) > len(rightpart): # riporto
				if mid == '':
					leftpart = leftpart[:-1] # strip last 0
					mid = '0'
				elif mid == '9':
					# nothing to do
					leftpart = leftpart[:-1] # strip last 0
					mid = '0'

			revleftpart = leftpart[::-1]
	revleftpart = leftpart[::-1]


	ret = leftpart + mid+ leftpart[::-1]
	# print "In:", strn, "Out", ret
	assert int(strn) < int(ret)
	return ret

if 0:
	assert get_next_palindrome("10") == "11"
	assert get_next_palindrome("100") == "101"
	assert get_next_palindrome("0") == "1"
	assert get_next_palindrome("1") == "2"
	assert get_next_palindrome("2") == "3"
	assert get_next_palindrome("3") == "4"
	assert get_next_palindrome("4") == "5"
	assert get_next_palindrome("5") == "6"
	assert get_next_palindrome("6") == "7"
	assert get_next_palindrome("7") == "8"
	assert get_next_palindrome("8") == "9"
	assert get_next_palindrome("9") == "11"
	assert get_next_palindrome("11") == "22"
	assert get_next_palindrome("22") == "33"
	assert get_next_palindrome("99") == "101"
	assert get_next_palindrome("989") == "999"
	assert get_next_palindrome("999") == "1001"

for i in xrange(1, 10000):
	si = get_next_palindrome(str(i))
	for j in xrange(i+1, 99999999):
		if is_palindrom( str(j)):
			if si <> str(j):
				print "i",i, "new",si,"old:",j
			assert si == str(j)
			break

# print "OK"
T = int(sys.stdin.readline())

for t in range(T):
	line = sys.stdin.readline()
	(A,B) = [ int(x) for x in line.split() ]
	rA = isqrt(A) - 1
	rB = isqrt(B) + 1

	
	result = 0
	new_res = 0
	next_s = str(rA)
	new_list = []
	old_list = []

	while int(next_s) <= rB:
		next_s = get_next_palindrome( next_s )
		n = int(next_s)
		n2 = n*n
		if n2 >= A and n2<=B:
			if is_palindrom( str(n2) ):
				new_res += 1
				new_list.append(n)

		# print next_s

	if 0:
		for n in xrange(rA,rB):
			n_str = str(n)
			if is_palindrom(n_str):
				n2 = n*n
				if n2 >= A and n2 <=B:
					n2_str = str(n2)
					if is_palindrom(n2_str):
						result += 1
						old_list.append( n )


	result = new_res
	print "Case #%d: %d" % (t+1, result)

    
