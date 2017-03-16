import os

class Solver(object):
    def __init__(self):
        pass
    
    def solve(self, inputs):
        n, ss = inputs[0].split()
        n = int(n) + 1
        ss = [int(x) for x in ss]
        
        std = 0
        ivt = 0
        
        for i in range(n):
            if std < i:
                nivt = i - std
                ivt += nivt
                std += nivt
            std += ss[i]
        
        return ivt
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
    4
4 11111
1 09
5 110011
0 1
    '''
    sample_out = '''
Case #1: 0
Case #2: 1
Case #3: 2
Case #4: 0
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