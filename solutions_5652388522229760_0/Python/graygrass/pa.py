import os

class Solver(object):
    def __init__(self):
        pass
    
    def solve(self, inputs):
        n = int(inputs[0].strip())
        if n == 0:
            return 'INSOMNIA'
        ds = set()
        cnt = 0
        tn = n
        while len(ds) < 10:
            sn = str(tn)
            for c in sn:
                ds.add(c)
            cnt += 1
            tn += n
        return cnt * n
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
    iname = 'A-small-attempt0.in'
#     iname = 'foo'
    sample_in = '''5
0
1
2
11
1692
    '''
    sample_out = '''
Case #1: INSOMNIA
Case #2: 10
Case #3: 90
Case #4: 110
Case #5: 5076
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