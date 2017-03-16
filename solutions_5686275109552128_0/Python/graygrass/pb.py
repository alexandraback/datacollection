import os
import math

class Solver(object):
    def __init__(self):
        pass
    
    def add(self, d, n, k=1):
        if n not in d:
            d[n] = k
        else:
            d[n] += k
            
    def sub(self, d, n):
        if n in d:
            if d[n] == 1:
                d.pop(n)
            else:
                d[n] -= 1
                return False
        return True
    
    def solve(self, inputs):
        tmp = [int(x) for x in inputs[1].split()]
        dd = dict()
        for i in tmp:
            self.add(dd, i)
        
        sp = 0
        x = max(dd.keys())
        min = x
        while x > 3:
            sp += dd[x]
            s1 = x / 2
            s2 = x - s1
            self.add(dd, s1, dd[x])
            self.add(dd, s2, dd[x])
            dd.pop(x)
            x = max(dd.keys())
            if sp + x < min:
                min = sp + x
            
        return min
        
        pass
    
    def feed(self, inputs):
        lines = [x.strip() for x in inputs]
        outputs = []
        test_case_n = int(lines[0])
        cur = 1
        for i in range(test_case_n):
            i = i
            case_line_cnt = 2
            case_inputs = lines[cur:cur+case_line_cnt]
            cur += case_line_cnt
            outputs.append(self.solve(case_inputs))
        return outputs

if __name__ == '__main__':
    iname = 'B-small-attempt1.in'
#     iname = 'foo'
    sample_in = '''
3
5
8 8 8 8 8
4
1 2 1 2
1
4
    '''
    sample_out = '''
Case #1: 3
Case #2: 2
Case #3: 3
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