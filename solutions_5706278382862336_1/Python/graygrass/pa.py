import os
import math

class Solver(object):
    def __init__(self):
        pass
    
    def gcd(self, a, b):
        a, b = max(a, b), min(a, b)
        while b != 0:
            a, b = b, a % b
        return a
    
    def solve(self, inputs):
        p, q = [int(x) for x in inputs[0].split('/')]
        g = self.gcd(q, p)
        qq = q / g
        pp = p / g
        genf = math.log(qq, 2)
        pl = int(math.floor(genf))
        ph = int(math.ceil(genf))
        x = -1
        if (1 << pl) == qq:
            x = pl
        if (1 << ph) == qq:
            x = ph
        if x == -1:
            return "impossible"
        for i in range(x+1):
            if pp >= 2**(x-i):
                return i
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
    iname = 'A-large.in'
#     iname = 'foo'
    sample_in = '''
5
1/2
3/4
1/4
2/23
123/31488
    '''
    sample_out = '''
Case #1: 1
Case #2: 1
Case #3: 2
Case #4: impossible
Case #5: 8
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