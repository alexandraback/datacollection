import os
import bisect

class Solver(object):
    def __init__(self):
        pass
    
    def solve(self, inputs):
        whatever = 'GABRIEL'
        incase = 'RICHARD'
        x, r, c = [int(x) for x in inputs[0].split()]
        if r > c:
            r, c = c, r
        if x == 1:
            return whatever
        if x == 2:
            if (r*c) % 2 == 0:
                return whatever
            else:
                return incase
        if x == 3:
            if r == 1:
                return incase
            elif r == 2:
                if c == 3:
                    return whatever
                else:
                    return incase
            elif r == 3:
                return whatever
            else:
                return incase
        if x == 4:
            if r == 1:
                return incase
            elif r == 2:
                return incase
            elif r == 3:
                if c == 4:
                    return whatever
                else:
                    return incase
            else:
                return whatever
            
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
    iname = 'D-small-attempt1.in'
#     iname = 'foo'
    sample_in = '''
4
2 2 2
2 1 3
4 4 1
3 2 3
    '''
    sample_out = '''
Case #1: GABRIEL
Case #2: RICHARD
Case #3: RICHARD
Case #4: GABRIEL
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