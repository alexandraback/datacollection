def readint(): return int(raw_input())

def readfloat(): return float(raw_input())

def readstr() : return str(raw_input())

def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res

def readlinearray(foo): return map(foo, raw_input().split())


f_out = open('A-small-practice.out', 'w')
f_out = open('A-large-practice.out', 'w')

def write_output(file_out, case_nr, guests):
    output_string = "Case #" + str(case_nr) + ": " 
    output_string += str(guests)
    output_string += "\n"
    file_out.write(output_string)


def find_guests(shyness):
    S = len(shyness)
    applauding = 0
    guests = 0
    for i in range(S):
        if applauding < i:
            guests += 1
            applauding += 1
        applauding += int(shyness[i])
#    print "we needed ", guests, " guests"
    return guests

T = readint()

for test_case in range(T):
    s_max, shyness = readlinearray(str)
#    print "S-max,shyness are ", s_max, shyness
    
    guests = find_guests(shyness)
#    print "we think the ans is ", guests 
    
    write_output(f_out, test_case+1, guests)
