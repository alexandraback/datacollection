import os

class Solver(object):
    def __init__(self):
        pass
    
    def solve(self, inputs):
        cc, dd, vv = [int(x) for x in inputs[0].split()]
        dd = [int(x) for x in inputs[1].split()]
        dd.sort()
        cnt = 0
        idx = 0
        if dd[0] != 1:
            dd.insert(0, 1)
            cnt += 1
        idx = 1
        t = cc
        while t < vv:
            if (idx >= len(dd)) or (dd[idx] > t + 1):
                dd.insert(idx, t+1)
                cnt += 1
                t += cc*(t+1)
            else:
                t += cc*dd[idx]
            idx += 1
        return cnt
        
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
    iname = 'C-small-attempt0.in'
#     iname = 'foo'
    sample_in = '''
4
1 2 3
1 2
1 3 6
1 2 5
2 1 3
3
1 6 100
1 5 10 25 50 100
    '''
    sample_out = '''
Case #1: 0
Case #2: 1
Case #3: 1
Case #4: 3
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