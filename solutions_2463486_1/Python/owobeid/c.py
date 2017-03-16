import math
import string

#MAX_NUM = 1000
MAX_NUM = 10**14


def is_palindrome(s):
    return s == s[::-1]


#Calculate squres table
squares_dict = {}
squares_arr = []
i = 1
j = 1
while i <= MAX_NUM:
    if not is_palindrome(str(i)):
        i += 1
        continue
    num = i**2
    if num > MAX_NUM:
        break
    squares_dict[num] = j
    squares_arr.append(num)
    i += 1
    j += 1
L = len(squares_arr)
    
#print " squares = " + str(squares_arr)


T = int(raw_input())
t = 0

while t < T:
    fscnt = 0
    tokens = raw_input().split(' ')
    A = int(tokens[0])
    B = int(tokens[1])
    
    #print "A=" + str(A) + "  B=" + str(B)
    if A == B:
        if A in squares_dict and is_palindrome(str(A)):
            fscnt = 1
    else:
        ndx = 0
        while ndx < L and squares_arr[ndx] < A:
            ndx += 1
        if ndx >= L:
            pass
        else:
            if squares_arr[ndx] < A:
                ndx += 1
           
            while ndx < L and squares_arr[ndx] <= B:
                if is_palindrome(str(squares_arr[ndx])):
                    #print str(squares_arr[ndx])
                    fscnt += 1
                ndx += 1
    print "Case #" +str(t+1) + ": " + str(fscnt)
    t += 1
