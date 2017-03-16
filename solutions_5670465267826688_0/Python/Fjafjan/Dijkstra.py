from math import ceil

def readint(): return int(raw_input())

def readfloat(): return float(raw_input())

def readstr() : return str(raw_input())

def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res

def readlinearray(foo): return map(foo, raw_input().split())


f_out = open('C-small-practice.out', 'w')
#f_out = open('C-large-practice.out', 'w')

def write_output(file_out, case_nr, possible):
    output_string = "Case #" + str(case_nr) + ": " 
    if possible:
        output_string += "YES"
    else:
        output_string += "NO"
    output_string += "\n"
    file_out.write(output_string)

def quaternion(a, b):
    if a == "1":
        return 1, b
    if b == "1":
        return 1, a
    
    
    if a == 'i':
        if b == 'i':
            return -1, "1"
        if b == 'j':
            return 1, "k"
        if b == 'k':
            return -1, "j"
    if a == 'j':
        if b == 'i':
            return -1, "k"
        if b == 'j':
            return -1, "1"
        if b == 'k':
            return 1, "i"
    if a == 'k':
        if b == 'i':
            return 1, "j"
        if b == 'j':
            return -1, "i"
        if b == 'k':
            return -1, "1"
    

def find_polarity(letters):
    final_polarity = 1
    letter = "1"
    
    for i in range(len(letters)):
        polarity, letter =quaternion(letter, letters[i])
        final_polarity *= polarity
    return final_polarity, letter


def contains_different_letters(letters):
    for i in range(len(letters)):
        if letters[0] != letters[i]:
            return True
    return False

## Tries to find the letters i, j and k in that order in the string. 
def find_ijk(letters, X):
    L = len(letters)
    if L*X > 1000000:
        letters = letters * (1000000./L)
    else:
        letters = letters * X
    ## First we check the substring.
    current_letter = "1"
    current_polarity = 1
    current_check = 0
    checking = ['i', 'j', 'k']
    
#    print "the string we are looking for ijk in is ", letters
    for i in range(len(letters)):
        polarity, current_letter =quaternion(current_letter, letters[i])
        current_polarity *= polarity
#        print "current letter, polarity is ", polarity, current_letter
        if current_letter == checking[current_check] and current_polarity == 1:
#            print "we found letter ", checking[current_check]
            current_check += 1
            current_letter = "1"
            if current_check == 3:
                return True
    return False

def can_be_rewritten(letters, X):
    L = len(letters)
    
    if X * L < 3:
        return False
    if not contains_different_letters(letters):
        return False
    polarity, letter = find_polarity(letters)
#    print "the polarity and resulting letter from this string is ", polarity, letter
    if letter == "1":
        if polarity == 1 or X%2 == 0:
            return False
    elif X%4 == 0 or X%2 != 0:
        return False
    
#    print "the polarity is good, but we need to find ijk"
    ## Now we just need to find ijk in either the substring or in the final string to be 100% sure.
    if find_ijk(letters, X):
        return True
    return False

## let's test our pretty new function
print find_polarity("jij")

T =  readint()


for test_case in range(T):
    L, X = readlinearray(int)
    letters = readstr()
    print letters, X
    result = can_be_rewritten(letters, X)
    if result:
        print "We think we can rewrite this correctly"
    else:
        print "sadness"
    write_output(f_out, test_case + 1, result)
