from math import ceil, floor

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
        output_string += "GABRIEL"
    else:
        output_string += "RICHARD"
    output_string += "\n"
    file_out.write(output_string)


def is_tilable(X, M, N):
    A = M * N
    if X > max(M, N):
        return False
    
    if A%X != 0:
        return False
    if X <= 2:
        return True
    elif X >= 7:
        return False
    else:
        if X == 3:
            min_dimension = 1
        else:
            min_dimension = floor(X/2)
        if min(M, N) <= min_dimension:
            return False
    return True
T = readint()
for test_case in range(T):
    (X, M, N) = readlinearray(int)
    print "X, R and C are ", X, M, N
    # X is size of domino
    # M and N are size of board.
    
    result = is_tilable(X, M, N)
    if result:
        print "Gabriel wins"
    else:
        print "Richard wins"
    write_output(f_out, test_case+1, result)
