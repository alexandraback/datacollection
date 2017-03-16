from optparse import OptionParser

def analyze(testcase):
    print testcase
    size, motes = testcase
    #remove motes of size 1
    nb_motes = len(motes)
    if size == 1:
        motes = []
        nb_spe = nb_motes - len(motes)
        nb_motes = len(motes)
    else:
        nb_spe = 0
    #sort
    sorted_motes = sorted(motes)
    
    #adding motes
    add_motes = [0] * nb_motes
    cursize = size
    for i in range(nb_motes):
        n = 0
        while cursize <= sorted_motes[i]:
            cursize += cursize - 1
            n += 1
        add_motes[i] = n
        cursize += sorted_motes[i]
        
    #removing motes
    nb_op_min = None
    for i in range(nb_motes+1):
        nb_op = sum(add_motes[0:i]) + (nb_motes - i)
        #print "a", sum(add_motes[0:i]), (nb_motes - i), nb_op
        if nb_op_min is None or nb_op < nb_op_min:
            nb_op_min = nb_op
    
    return nb_op_min + nb_spe

def parse_input(filename):
    testcases = []
    with open(filename, "rb") as f:
        lines = f.readlines()
    nb = int(lines[0])
    for n in range(nb):
        size_mote, n_motes = [int(s) for s in lines[n*2+1].split(" ")]
        motes = [int(s) for s in lines[n*2+2].split(" ")]
        testcases.append([size_mote, motes])
    return testcases

def print_result(testcases):
    res = ""
    for i, test in enumerate(testcases):
        res += "Case #%d: %s\n" % (i+1, analyze(test))
    return res

if __name__ == "__main__":
    parser = OptionParser()
    (options, args) = parser.parse_args()

    testcases = parse_input("A-small-attempt0.in")
    output = print_result(testcases)
    print output
    
    with open("result_small.txt", "wb") as fout:
        fout.write(output)
