import sys

fname = sys.argv[1]

f = open(fname, "rt")

T = int(f.readline())

def handle_case(f, caseno):
    line = ['....' for i in range(4)]
    for lineno in range(4):
        line[lineno] = f.readline() 
        line[lineno] = line[lineno][:4]
    rows = [set([]) for i in range(4)]
    cols = [set([]) for i in range(4)]
    diag = [set([]) for i in range(2)]
    whole = set([])
    for i in range(4):
        rows[i] = set([y for y in line[i]])
        cols[i] = set([l[i] for l in line])
        whole |= rows[i]
        diag[0].add(line[i][i])
        diag[1].add(line[i][3-i])

        if rows[i] <= set(["T", "X"]):
            print "Case #%d: X won" %caseno
            return
        elif rows[i] <= set(["T", "O"]):
            print "Case #%d: O won" %caseno
            return

    for i in range(4):
        if cols[i] <= set(["T", "X"]):
            print "Case #%d: X won" % caseno
            return
        elif cols[i] <= set(["T", "O"]):
            print "Case #%d: O won" % caseno
            return

    for i in range(2):
        if diag[i] <= set(["T", "X"]):
            print "Case #%d: X won" % caseno
            return
        elif diag[i] <= set(["T", "O"]):
            print "Case #%d: O won" % caseno
            return

    if "." in whole:
        print "Case #%d: Game has not completed" % caseno
        return
    else:
        print "Case #%d: Draw" %caseno




    
    

        

for case in range(T):
    handle_case(f, case+1)
    f.readline()
        

    
