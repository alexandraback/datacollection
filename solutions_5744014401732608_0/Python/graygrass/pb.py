import os
import math
import itertools

class Solver(object):
    def __init__(self):
        pass

    def get(self, i, j, k, r, b):
        if j <= i:
            return 0
        if j == b:
            if i <= k+1:
                return 1
            elif i > k+2:
                return 0
            else:
                if int(r) > 0:
                    return 1
                else:
                    return 0
        if j <= k+1:
            return 1
        if j > k+2:
            return 0
        if i == 1:
            return 0
        jj = k+2-j
        if r[jj] == '1':
            return 1
        else:
            return 0
            
    
    def solve(self, inputs):
        b, m = [int(x) for x in inputs[0].strip().split()]
        maxm = 2**(b-2)
        if m > maxm:
            return "IMPOSSIBLE"
        k = int(math.floor(math.log(m, 2)))
        tt = '{0:0%db}'%(k+1)
        r = tt.format(m - 2**k)
        result = []
        for i in range(b):
            row = []
            for j in range(b):
                t = self.get(i+1, j+1, k, r, b)
                row.append(str(t))
            result.append(''.join(row))
        result.insert(0, 'POSSIBLE')
        return '\n'.join(result)
        pass
    
    def feed(self, inputs):
        lines = [x.strip() for x in inputs]
        outputs = []
        test_case_n = int(lines[0])
        cur = 1
        for i in range(test_case_n):
            i = i
            case_line_cnt = 1
            case_inputs = lines[cur:cur+case_line_cnt]
            cur += case_line_cnt
            outputs.append(self.solve(case_inputs))
        return outputs

if __name__ == '__main__':
    iname = 'B-small-attempt7.in'
    sample_in = '''3
5 5
5 4
2 1
4 20
    '''
    sample_out = '''
Case #1: POSSIBLE
01001
00110
00001
00101
00000
Case #2: POSSIBLE
01
00
Case #3: IMPOSSIBLE
    '''
    if os.path.exists(iname):
        with open(iname) as f:
            inputs = f.readlines()
    else:
        inputs = [x.strip() for x in sample_in.split('\n') if x.strip()]
    solver = Solver()
    outputs = solver.feed(inputs)
    fail_flag = False
    if os.path.exists(iname):
        with open(iname+'.out', 'w') as f:
            for i, v in enumerate(outputs):
                print >> f, 'Case #%d: %s'%(i+1, str(v))
    else:
        ans = set([x.strip() for x in sample_out.split('\n') if x.strip()])
        for i, v in enumerate(outputs):
            t = 'Case #%d: %s'%(i+1, str(v))
            if t not in ans:
                print '!!! Wrong:', t
                fail_flag = True
    print '===================================================='
    for i, v in enumerate(outputs):
        print 'Case #%d: %s'%(i+1, str(v))
    print '===================================================='
    print 'done' if not fail_flag else 'fail'
    pass