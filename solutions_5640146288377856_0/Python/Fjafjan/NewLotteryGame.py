def readint(): return int(raw_input())

def readfloat(): return float(raw_input())

def readstr() : return str(raw_input())

def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())

def write_output(file_out, case_nr, count):
    output_string = "Case #" + str(case_nr) + ": "
    output_string += str(count)
    file_out.write(output_string)
    file_out.write("\n")


f_out = open('A-small-practice.out', 'w')

T =  readint()

def sink_ship(R, C, W):
    count = 0
    
    if R > 1:
        count += (R-1)*(C/W)
    
    while C > W*2:
        count += 1
        C -= W
#    print "The interesting bit is when C = ", C, " for W ", W
    remain = C - W

    from math import log, floor
    if remain <= 1:
        gain = 0
    else:
 #       print "min num of calls for remain ", remain, " is ", log(remain-1, 2)+1
        gain = remain - 1
#        if remain == W and W > 2:
#            gain = W-1
    print "the gain on this is ", gain
    return count + (C - gain)
    
for test_case in range(T):
    [R, C, W] = readlinearray(int)
    print "R, C, W are ", R, C, W
    count = sink_ship(R, C, W)
    print "we think the answer is ", count
    write_output(f_out, test_case + 1, count)
