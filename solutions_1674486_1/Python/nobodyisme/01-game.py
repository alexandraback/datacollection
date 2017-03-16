import operator
import sys


def solve(clss):
    # chtop = {}
    ptoch = {}
    hubs = set()

    def check(h, ptoch):
        q = [h]
        pathsto = set()
        while q:
            qel = q.pop()
            for ch in ptoch.get(qel, []):
                if ch in pathsto:
                    return True
                else:
                    pathsto.add(ch)
                    q.append(ch)
        return False

    for i, cs in enumerate(clss):
        cl_i = i + 1
        for pc_i in cs:
            # chtop.setdefault(cl_i, []).append(pc_i)
            ptoch.setdefault(pc_i, []).append(cl_i)
            if len(ptoch[pc_i]) > 1:
                hubs.add(pc_i)
    for h in hubs:
        if check(h, ptoch):
            return "Yes"
    return "No"

def main(input_filename, output_filename):
    
    input_f = open(input_filename, "r")
    output_f = open(output_filename, "w")
    
    try:
        TEST_CASES_NUM = int(input_f.readline())
        
        for test_case_i in xrange(TEST_CASES_NUM):

            print test_case_i
            
            cln = [int(_) for _ in input_f.readline().strip().split(' ')]
            clss = []
            for i in xrange(cln[0]):
                inp = [int(_) for _ in input_f.readline().strip().split(' ')]
                n, tn = inp[0], inp[1:]
                clss.append(tn)
            
            res = solve(clss)
            output_f.write("Case #%d: %s\n" % (test_case_i + 1, res))
            
    finally:
        input_f.close()
        output_f.close()


main(sys.argv[1], sys.argv[2])
