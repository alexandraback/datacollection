import os

class Solver(object):
    MM = 1000010
    def __init__(self):
        self.d = [0] * self.MM
        for i in range(self.MM):
            self.d[i] = i
        for i in range(1, self.MM):
            si = str(i)
            tr = list(si)
            tr.reverse()
            ri = int(''.join(tr))
            sri = str(ri)
            if len(sri) == len(si) and ri < i:
                self.d[i] = min(self.d[i-1], self.d[ri]) + 1
            else:
                self.d[i] = self.d[i-1] + 1
        pass
    
    def solve(self, inputs):
#         print inputs
        k = int(inputs[0])
        return self.d[k]
            
        
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
    sample_in = '''
3
1
19
23
    '''
    sample_out = '''
Case #1: 1
Case #2: 19
Case #3: 15
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