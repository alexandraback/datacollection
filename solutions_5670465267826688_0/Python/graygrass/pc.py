import os
import bisect

def neg(a):
    if isinstance(a, int):
        return -a
    if isinstance(a, list):
        return [-x for x in a]

def cross(a, b):
    if a == b:
        return -1
    if a == neg(b):
        return 1
    c = [a[1]*b[2] - a[2]*b[1],
         a[2]*b[0] - a[0]*b[2],
         a[0]*b[1] - a[1]*b[0]]

    return c

def mul(a, b):
    if isinstance(a, list) and isinstance(b, list):
        return cross(a, b)
    if isinstance(a, list) and isinstance(b, int):
        return [b*x for x in a]
    if isinstance(a, int) and isinstance(b, list):
        return [a*x for x in b]
    if isinstance(a, int) and isinstance(b, int):
        return a*b
        
ii = [1, 0, 0]
jj = [0, 1, 0]
kk = [0, 0, 1]
yes = 'YES'
no = 'NO'

def vec(ch):
    if ch == 'i':
        return ii
    if ch == 'j':
        return jj
    if ch == 'k':
        return kk

class Solver(object):
    def __init__(self):
        pass
    
    def solve(self, inputs):
        
        ll, xx = [int(x) for x in inputs[0].split()]
        if xx >= 12:
            xx = 12 + xx % 12
        
        if xx % 4 == 0:
            return no
        
        ss = inputs[1]*xx
        
        iflag = False
        
        t = 1
        i = 0
        end = len(ss)
        while i < end:
            v = vec(ss[i])
            i += 1
            t = mul(t, v)
            if t == ii:
                iflag = True
                break

        if not iflag:
            return no
        
        t = 1        
        jflag = False
        while i < end:
            v = vec(ss[i])
            i += 1
            t = mul(t, v)
            if t == jj:
                jflag = True
                break
        
        if not jflag:
            return no
        
        t = 1
        while i < end:
            v = vec(ss[i])
            i += 1
            t = mul(t, v)
        
        if t == kk:
            return yes
        else:
            return no
            
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
    iname = 'C-small-attempt2.in'
#     iname = 'foo'
    sample_in = '''
5
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
    '''
    sample_out = '''
Case #1: NO
Case #2: YES
Case #3: NO
Case #4: YES
Case #5: NO
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