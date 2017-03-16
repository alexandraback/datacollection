import os
import itertools

class Solver(object):
    def __init__(self):
        pass
    
    def solve(self, inputs):
        K, C, S = [int(x) for x in inputs[0].split()]
        if C*S < K:
            return 'IMPOSSIBLE'
        pos = []
        i = 0
        while i < K:
            n = 0
            for cc in range(1, C):
                n = n*K + i
                if i < K-1:
                    i += 1
            pos.append(n*K + i + 1)
            i = i+1
        return str(pos).strip('[]').replace(',', '').replace('L', '')    
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
    iname = 'D-large.in'
    sample_in = '''5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
    '''
    sample_out = '''
Case #1: 2
Case #2: 1
Case #3: IMPOSSIBLE
Case #4: 1 2
Case #5: 2 6
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