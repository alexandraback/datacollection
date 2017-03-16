import time

OEXT = ".out"
CASE_PRFX = "Case #%s: "

MAXB = 2000000



def circlify(num, cutoff=MAXB):
    numstr = str(num)
    max_opt = len(numstr)
    numstr += numstr
    
    opts = []
    for i in xrange(1, max_opt):
        z = int(numstr[i:i+max_opt])
        if z <= cutoff and z > num and z not in opts:
            opts.append(z)
    
    # only values larger than num (also filters leading zeroes) 
    # and smaller than cutoff
    
    #clean dupes
    return len(opts)

def check(A, B):
    res2 = 0
    start = time.time()
    for t in xrange(A, B):
        res2 += circlify(t, B)
    print res2, time.time()-start  
    return res2

def read_input(filename):
    data = []
    with open(filename, "r") as f:
        cases = int(f.readline())
        for _ in xrange(cases):
            case = f.readline().strip().split()
            data.append((int(case[0]), int(case[1])))
    return data

def make_output(fname, output):
    fname = fname + OEXT
    with open(fname, "w") as f:
        restext = []
        for i, v in enumerate(output):
            restext.append(CASE_PRFX % (i+1,) + str(v) + "\n")
        f.writelines(restext)
    
def main(fname):
    data = read_input(fname)
    output = []
    for case in data:
        output.append(check(case[0], case[1]))
    make_output(fname, output)

#check(1000000, 2000000)
main("large.in")