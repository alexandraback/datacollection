from optparse import OptionParser

def get_parents(parents, i):
    res = set([i])
    for p in parents[i-1]:
        res = res | get_parents(parents, p)
        res.add(p)
    return res
    
def isdiamond_class(parents, i):
    all_parents = set()
    
    for parent_set_i in [get_parents(parents, p) for p in parents[i]]:
        for p in parent_set_i:
            if p in all_parents:
                return True
        all_parents = all_parents | parent_set_i
    return False
    
def isdiamond(parents):
    return (any(isdiamond_class(parents, i) for i in parents))

    
def problem_A(filename):
    with open(filename, 'rU') as fin:
        lines = [l.rstrip("\n") for l in fin.readlines()]
    ntestcases = int(lines[0])
    pos = 1
    for i in range(ntestcases):
        nb_class = int(lines[pos])
        parents = {}
        for j in range(nb_class):
            clsdef = [int(s) for s in lines[pos+j+1].split(" ")]
            nparents, parents[j] = clsdef[0], clsdef[1:]
            assert nparents == len(parents[j])

        pos = pos + nb_class + 1
        print "Case #%d: %s" % (i+1, isdiamond(parents) and "Yes" or "No")





if __name__ == "__main__":
    parser = OptionParser()
    (options, args) = parser.parse_args()

    if len(args) != 1:
        parser.error("incorrect number of arguments")
    problem_A(args[0])
