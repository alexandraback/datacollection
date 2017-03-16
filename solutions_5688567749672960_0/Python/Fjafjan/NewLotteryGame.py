def readint(): return int(raw_input())

def readfloat(): return float(raw_input())

def readstr() : return str(raw_input())

def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())

def write_output(file_out, case_nr, intersections):
    output_string = "Case #" + str(case_nr) + ": "
    output_string += str(intersections)
    file_out.write(output_string)
    file_out.write("\n")


f_out = open('A-small-practice.out', 'w')

T =  readint()

def reverse(n):
    n = str(n)
    n = n[::-1]
    n = int(n)
    return n
print "try yo reverse ", reverse(2300), reverse(43)


## okay so we use a lookup table and fill that out. and then we just check the Ns. This wont work for large 
## data presumably, whatevsss.

def add_to_lookup(lookup, num):
    if lookup[num] == 1234567890:
        return "FUCK YOU"
    count = lookup[num]
    if reverse(num) < len(lookup) and lookup[reverse(num)] > count+1:
        lookup[reverse(num)] = count+1
    
    if lookup[num+1] > count+1:
        lookup[num+1] = count+1


def min_count(N, lookup, starting_num):
    print "starting num is ", starting_num
    if lookup[starting_num] == 1234567890:
        min_count(N, lookup, starting_num-1)
    
    
    count = lookup[starting_num]
    
    if starting_num == N:
        return starting_num
    ## Reverse, add that value to the lookup, add one, then add that value to the lookp
    
    if reverse(starting_num) < N and lookup[reverse(starting_num)] > count+1:
        lookup[reverse(starting_num)] = count+1
    
    if lookup[starting_num+1] > count+1:
        lookup[starting_num+1] = count+1
    


lookup = [1234567890]*1000001
for i in range(21):
    lookup[i] = i
for i in range(10**6):
    add_to_lookup(lookup,i)
print "minimum count to 30 is ", min_count(1000000, lookup, 1)
print len(lookup)
for test_case in range(T):
    print test_case
        
    
    N = readint()
    print "N is ", N
    write_output(f_out, test_case + 1, lookup[N])
