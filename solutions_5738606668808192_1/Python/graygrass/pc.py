import os
import itertools

class Solver(object):
    def __init__(self):
        pass
    
    def getnum(self, nn, ones, base):
        num = 1
        for w in ones:
            num += base**w
        num += base**(nn-1)
        return num
        pass
    
    def getdiv(self, num):
        if num % 2 == 0:
            return 2
        if num % 3 == 0:
            return 3
        if num % 5 == 0:
            return 5
        if num % 7 == 0:
            return 7
        k = int(num**0.5) + 1
        for i in range(5, k, 2):
            if num % i == 0:
                return i;
        return 1
        pass
    
    def solve(self, inputs):
        N, J = [int(x) for x in inputs[0].split()]
        cnt = 0
        rs = []
        for odd in itertools.combinations(range(1, N-1, 2), 5):
            for even in itertools.combinations(range(2, N-1, 2), 5):
                ones = odd + even
                bp = False
                ds = []
                for base in range(2, 11):
                    num = self.getnum(N, ones, base)
                    div = self.getdiv(num)
                    ds.append(div)
                    if base == 10:
                        ds.insert(0, num)
                    if div == 1 or div == num:
                        bp = True
                        break
                if not bp:
                    cnt += 1
                    rr = str(ds).strip('[]').replace(',', '').replace('L', '')
#                     print rr
                    rs.append(rr)
                if cnt >= J:
                    break
            if cnt >= J:
                break
#         return "found %d"%cnt
        return '\n'+'\n'.join(rs)    
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
    iname = 'C-large.in'
    sample_in = '''1
32 50
    '''
    sample_out = '''
Case #1: 1
Case #2: 1
Case #3: 2
Case #4: 0
Case #5: 3
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